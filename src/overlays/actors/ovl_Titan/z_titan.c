/*
 * File: z_titan.c
 * Overlay: ovl_Titan
 * Description: Custom Actor
 */

#include "z_titan.h"

#include "play_state.h"

#include "overlays/actors/ovl_Darkbubble/z_darkbubble.h"
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
#include "sram.h"
#include "save.h"

#define FLAGS (ACTOR_FLAG_ATTENTION_ENABLED | ACTOR_FLAG_UPDATE_CULLING_DISABLED)

void Titan_Init(Actor* thisx, PlayState* play);
void Titan_Destroy(Actor* thisx, PlayState* play);
void Titan_Update(Actor* thisx, PlayState* play);
void Titan_Draw(Actor* thisx, PlayState* play);

void Titan_DoNothing(Titan* this, PlayState* play);

static DamageTable sDamageTableStar[] = {
    /* Deku nut      */ DMG_ENTRY(0, 0),
    /* Deku stick    */ DMG_ENTRY(2, 0),
    /* Slingshot     */ DMG_ENTRY(1, 0),
    /* Explosive     */ DMG_ENTRY(4, 0),
    /* Boomerang     */ DMG_ENTRY(0, 0),
    /* Normal arrow  */ DMG_ENTRY(2, 0),
    /* Hammer swing  */ DMG_ENTRY(2, 0),
    /* Hookshot      */ DMG_ENTRY(2, 0),
    /* Kokiri sword  */ DMG_ENTRY(1, 0),
    /* Master sword  */ DMG_ENTRY(2, 0),
    /* Giant's Knife */ DMG_ENTRY(4, 0),
    /* Fire arrow    */ DMG_ENTRY(2, 0),
    /* Ice arrow     */ DMG_ENTRY(4, 0),
    /* Light arrow   */ DMG_ENTRY(2, 1),
    /* Unk arrow 1   */ DMG_ENTRY(2, 0),
    /* Unk arrow 2   */ DMG_ENTRY(2, 0),
    /* Unk arrow 3   */ DMG_ENTRY(2, 0),
    /* Fire magic    */ DMG_ENTRY(0, 0),
    /* Ice magic     */ DMG_ENTRY(3, 0),
    /* Light magic   */ DMG_ENTRY(0, 0),
    /* Shield        */ DMG_ENTRY(0, 0),
    /* Mirror Ray    */ DMG_ENTRY(0, 0),
    /* Kokiri spin   */ DMG_ENTRY(1, 0),
    /* Giant spin    */ DMG_ENTRY(4, 0),
    /* Master spin   */ DMG_ENTRY(2, 0),
    /* Kokiri jump   */ DMG_ENTRY(2, 0),
    /* Giant jump    */ DMG_ENTRY(8, 0),
    /* Master jump   */ DMG_ENTRY(4, 0),
    /* Unknown 1     */ DMG_ENTRY(0, 0),
    /* Unblockable   */ DMG_ENTRY(0, 0),
    /* Hammer jump   */ DMG_ENTRY(4, 0),
    /* Unknown 2     */ DMG_ENTRY(0, 0),
};

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
        COL_MATERIAL_HIT3,
        AT_ON | AT_TYPE_ENEMY,
        AC_ON | AC_TYPE_PLAYER,
        OC1_ON | OC1_TYPE_ALL,
        OC2_TYPE_1,
        COLSHAPE_CYLINDER,
    },
    {
        ELEM_MATERIAL_UNK0,
        { 0xFFCFFFFF, HIT_SPECIAL_EFFECT_NONE, 0x08 },
        { 0xFFCFFFFF, HIT_BACKLASH_NONE, 0x00 },
        ATELEM_ON | ATELEM_SFX_NORMAL,
        ACELEM_ON,
        OCELEM_ON,
    },
    { 100, 250, 0, { 0, 0, 0 } },
};

static ColliderCylinderInit sCylinderStarInit = {
    {
        COL_MATERIAL_METAL,
        AT_ON | AT_TYPE_ENEMY,
        AC_ON | AC_HARD | AC_TYPE_PLAYER,
        OC1_ON | OC1_TYPE_ALL,
        OC2_TYPE_1,
        COLSHAPE_CYLINDER,
    },
    {
        ELEM_MATERIAL_UNK0,
        { 0xFFCFFFFF, HIT_SPECIAL_EFFECT_NONE, 0x08 },
        { 0xFFCFFFFF, HIT_BACKLASH_NONE, 0x00 },
        ATELEM_ON | ATELEM_SFX_NORMAL,
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
    this->hittimer = 0;
    this->phase = 0;

    this->shield = 38;
    this->walkAnimTimer = 0;

    thisx->colChkInfo.health = 100;

    Actor_Spawn(&play->actorCtx, play,
    ACTOR_REDEYE,
    thisx->world.pos.x, thisx->world.pos.y, thisx->world.pos.z, 
    0, 0, 0, 0);
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
            thisx->speed = 1.7f;
            thisx->gravity = 0.0f;

            // Walk bob
            this->walkAnimTimer++;
            thisx->world.pos.y = Math_SinS(this->walkAnimTimer * 0x888) * 5.0f;
            Actor_MoveXZGravity(thisx);
            if (this->timer % 30 == 0) {
                SfxSource_PlaySfxAtFixedWorldPos(play, &this->actor.world.pos, 20, NA_SE_EV_ROCK_BROKEN);
            }

            // Do not spawn tites if magic is high
            if (gSaveContext.save.info.playerData.magic > 40) {
                this->timer = 0;
            }

            if (this->timer > 180) {
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
                if (titecount > 3) {
                    break;
                }
                pointer = pointer->next;
            }
            this->action++;
            break;
        case 2:;
            // Wait for tites to despawn

            if (Actor_Find(&play->actorCtx, ACTOR_EN_TITE, ACTORCAT_ENEMY)) {
                this->timer = 0;
            }
            if (this->timer > 40) {
                this->action = 0;
            }
            break;
        case 3://Disable shield
            if (this->shield > 0) {
                this->shield--;
            } else {
                this->action = 4;
                this->timer = 0;
            }
            break;
        case 4: // Vulnerable
            if (thisx->colChkInfo.health < 100 - ((this->phase+1) * 25)) {
                this->action = 5;
                this->timer = 0;
            }
            // ehhh big maybe
            //if (this->timer > 200) {
            //    this->action = 5;
            //    this->timer = 0;   
            //}
            break;
        case 5://Enable Shield
            if (this->shield < 38) {
                this->shield++;
            }
            if (this->timer > 40) {
                this->action = 0;
                this->timer = 0;
                this->phase ++;
            }
            break;
    }

    // Collision
    thisx->colChkInfo.damageTable = sDamageTableStar;

    if (this->colliderStar.base.acFlags & AC_HIT) {
        if (thisx->colChkInfo.damageReaction == 1) {
            Actor_ApplyDamage(thisx);
            this->colliderStar.base.acFlags &= ~AC_HIT;
            this->action = 3;
        }
    }

    if (this->collider.base.acFlags & AC_HIT) {
        this->hittimer = 0;
        this->collider.base.acFlags &= ~AC_HIT;

        if (this->shield == 0) {
            Actor_SetColorFilter(thisx, COLORFILTER_COLORFLAG_RED, 255, COLORFILTER_BUFFLAG_OPA, 8);
            Actor_ApplyDamage(thisx);
        }

    }
    this->hittimer++;

    // Update Collision
    Collider_UpdateCylinder(&this->actor, &this->collider);
    if (this->hittimer > 5) {
        CollisionCheck_SetAC(play, &play->colChkCtx, &this->collider.base);
    }
    CollisionCheck_SetOC(play, &play->colChkCtx, &this->collider.base);

    Collider_UpdateCylinder(&this->actor, &this->colliderStar);
    this->colliderStar.dim.pos.z += Math_CosS(thisx->world.rot.y) * 140;
    this->colliderStar.dim.pos.x += Math_SinS(thisx->world.rot.y) * 140;
    this->colliderStar.dim.pos.y += 80;

    if (this->shield > 0) {
        CollisionCheck_SetOC(play, &play->colChkCtx, &this->colliderStar.base);
        CollisionCheck_SetAC(play, &play->colChkCtx, &this->colliderStar.base);
    }

    // Shadow "Blood" the more damage it takes

    int bubbleCount = 0;
    Actor* pointer = play->actorCtx.actorLists[ACTORCAT_PROP].head;
    while(pointer != NULL) {
        if ((pointer->id == ACTOR_DARKBUBBLE)) {
            bubbleCount++;
        }
        pointer = pointer->next;
    }

    if ((bubbleCount < 100) && (this->timer % 4 == 0) && (Rand_ZeroOne() > play->titanGlobalHealth * .01f)) {
        s16 randAngle = Rand_ZeroOne() * 0xFFFF;

        Darkbubble * darkBubble = (Darkbubble *)Actor_Spawn(&play->actorCtx, play,
        ACTOR_DARKBUBBLE,
        thisx->world.pos.x + Math_SinS(randAngle) * 80.0f , thisx->world.pos.y - 90.0f, thisx->world.pos.z + Math_CosS(randAngle) * 80.0f, 
        0, 0, 0, 0);

        darkBubble->baseScale = .4f;

    }

    // Inc Timer
    this->timer++;

    play->titanGlobalHealth = thisx->colChkInfo.health;
}

void Titan_Draw(Actor* thisx, PlayState* play) {
    Titan* this = (Titan*)thisx;

    OPEN_DISPS(play->state.gfxCtx);

    SkelAnime_DrawOpa(play, this->skelAnime.skeleton, this->skelAnime.jointTable,
                      NULL, NULL, this);

    gDPSetPrimColor(POLY_OPA_DISP++, 0, 0, 255, 255, 255, this->shield );

    Gfx_DrawDListOpa(play, gTitanShield_transparent_dl);

    CLOSE_DISPS(play->state.gfxCtx);
}

void Titan_DoNothing(Titan* this, PlayState* play) {

}
