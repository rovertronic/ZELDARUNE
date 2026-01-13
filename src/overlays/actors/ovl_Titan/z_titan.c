/*
 * File: z_titan.c
 * Overlay: ovl_Titan
 * Description: Custom Actor
 */

#include "z_titan.h"

#include "play_state.h"

#include "assets/objects/object_titan/object_titan.h"
#include "assets/objects/object_titan/gTitanIdleAnim.h"
#include "z_lib.h"


#include "libc64/math64.h"
#include "libc64/qrand.h"
#include "gfx.h"
#include "gfx_setupdl.h"
#include "ichain.h"
#include "rand.h"
#include "sfx.h"
#include "sys_matrix.h"
#include "z_en_item00.h"
#include "z_lib.h"
#include "effect.h"
#include "play_state.h"
#include "player.h"


#define FLAGS (ACTOR_FLAG_ATTENTION_ENABLED | ACTOR_FLAG_UPDATE_CULLING_DISABLED)

void Titan_Init(Actor* thisx, PlayState* play);
void Titan_Destroy(Actor* thisx, PlayState* play);
void Titan_Update(Actor* thisx, PlayState* play);
void Titan_Draw(Actor* thisx, PlayState* play);

void Titan_DoNothing(Titan* this, PlayState* play);

ActorProfile Titan_Profile = {
    ACTOR_TITAN,
    ACTORCAT_ENEMY,
    FLAGS,
    OBJECT_TITAN,
    sizeof(Titan),
    (ActorFunc)Titan_Init,
    (ActorFunc)Titan_Destroy,
    (ActorFunc)Titan_Update,
    (ActorFunc)Titan_Draw,
};

static ColliderCylinderInit sCylinderInit = {
    {
        COL_MATERIAL_TREE,
        AT_NONE,
        AC_ON | AC_HARD | AC_TYPE_PLAYER,
        OC1_ON | OC1_TYPE_ALL,
        OC2_TYPE_1,
        COLSHAPE_CYLINDER,
    },
    {
        ELEM_MATERIAL_UNK5,
        { 0x00000000, HIT_SPECIAL_EFFECT_NONE, 0x00 },
        { 0x0FC0074A, HIT_BACKLASH_NONE, 0x00 },
        ATELEM_NONE,
        ACELEM_ON,
        OCELEM_ON,
    },
    { 100, 200, 0, { 0, 0, 0 } },
};

static ColliderCylinderInit sCylinderStarInit = {
    {
        COL_MATERIAL_TREE,
        AT_NONE,
        AC_ON | AC_HARD | AC_TYPE_PLAYER,
        OC1_ON | OC1_TYPE_ALL,
        OC2_TYPE_1,
        COLSHAPE_CYLINDER,
    },
    {
        ELEM_MATERIAL_UNK5,
        { 0x00000000, HIT_SPECIAL_EFFECT_NONE, 0x00 },
        { 0x0FC0074A, HIT_BACKLASH_NONE, 0x00 },
        ATELEM_NONE,
        ACELEM_ON,
        OCELEM_ON,
    },
    { 40, 80, 0, { 0, 0, -50 } },
};

void Titan_Init(Actor* thisx, PlayState* play) {
    Titan* this = (Titan*)thisx;

    this->actionFunc = Titan_DoNothing;

    thisx->focus.pos = thisx->world.pos;
    thisx->focus.pos.y += 150.0f;
    thisx->focus.pos.z -= 20.0f;

    thisx->attentionRangeType = ATTENTION_RANGE_4;

    SkelAnime_Init(play, &this->skelAnime, &gTitanSkelanime, &gTitanSkelanimeGtitanskelanimeactionAnim,
        this->jointTable, this->morphTable, GTITANSKELANIME_NUM_LIMBS);

    thisx->naviEnemyId = NAVI_ENEMY_TITAN;

    Collider_InitCylinder(play, &this->collider);
    Collider_SetCylinder(play, &this->collider, &this->actor, &sCylinderInit);

    Collider_InitCylinder(play, &this->colliderStar);
    Collider_SetCylinder(play, &this->colliderStar, &this->actor, &sCylinderStarInit);

    this->action = 0;
    this->timer = 0;
}

void Titan_Destroy(Actor* thisx, PlayState* play) {
    Titan* this = (Titan*)thisx;
}

void Titan_Update(Actor* thisx, PlayState* play) {
    Player* player = GET_PLAYER(play);
    Titan* this = (Titan*)thisx;

    // Update focus
    thisx->focus.pos = thisx->world.pos;
    thisx->focus.pos.y += 140.0f;
    thisx->focus.pos.z -= 20.0f;

    // Update anim
    SkelAnime_Update(&this->skelAnime);

    // Update Collision
    Collider_UpdateCylinder(&this->actor, &this->collider);
    CollisionCheck_SetAC(play, &play->colChkCtx, &this->collider.base);
    CollisionCheck_SetOC(play, &play->colChkCtx, &this->collider.base);

    Collider_UpdateCylinder(&this->actor, &this->colliderStar);
    this->colliderStar.dim.pos.z -= 100;
    CollisionCheck_SetOC(play, &play->colChkCtx, &this->colliderStar.base);

    //Turn toward player
    s16 angleToPlayer = Actor_WorldYawTowardActor(&this->actor, &GET_PLAYER(play)->actor) - this->actor.world.rot.y;
    s16 turnVelocity;
    if (angleToPlayer > 0) {
        turnVelocity = (angleToPlayer / 42.0f) + 10.0f;
        this->actor.world.rot.y += (turnVelocity * 2);
    } else {
        turnVelocity = (angleToPlayer / 42.0f) - 10.0f;
        this->actor.world.rot.y += (turnVelocity * 2);
    }
    thisx->shape.rot.y = this->actor.world.rot.y;

    // State Machine
    switch(this->action) {
        case 0:
            // Move toward player
            thisx->speed = 2.0f;
            thisx->gravity = 0.0f;
            thisx->world.pos.y = Math_SinS(this->timer * 0x888) * 5.0f;
            Actor_MoveXZGravity(thisx);
            if (this->timer % 30 == 0) {
                SfxSource_PlaySfxAtFixedWorldPos(play, &this->actor.world.pos, 20, NA_SE_EV_ROCK_BROKEN);
            }

            if (this->timer > 140) {
                this->action++;
            }
            break;
        case 1:; // Spawn tites on bookshelves
            int titecount = 0;
            Actor* pointer = play->actorCtx.actorLists[ACTORCAT_BG].head;
            while(pointer != NULL) {
                if ((pointer->id == ACTOR_DESTRUCTIBLE_BOOKSHELVES) && (Rand_ZeroOne() > .9f)) {
                    Actor_Spawn(&play->actorCtx, play,
                    ACTOR_EN_TITE,
                    pointer->world.pos.x, pointer->world.pos.y + 200.0f, pointer->world.pos.z, 
                    0, 0, 0, 0);
                    titecount++;
                }
                if (titecount > 4) {
                    break;
                }
                pointer = pointer->next;
            }
            this->action++;
            break;
        case 2:;
            // Wait for tites to despawn

            if (!Actor_Find(&play->actorCtx, ACTOR_EN_TITE, ACTORCAT_ENEMY)) {
                this->timer = 0;
                this->action = 0;
            }
            break;
    }

    // Inc Timer
    this->timer++;
}

void Titan_Draw(Actor* thisx, PlayState* play) {
    Titan* this = (Titan*)thisx;

    SkelAnime_DrawOpa(play, this->skelAnime.skeleton, this->skelAnime.jointTable,
                      NULL, NULL, this);
}

void Titan_DoNothing(Titan* this, PlayState* play) {

}
