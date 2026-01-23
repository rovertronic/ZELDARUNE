/*
 * File: z_redeye.c
 * Overlay: ovl_Redeye
 * Description: Custom Actor
 */

#include "z_redeye.h"

#include "play_state.h"
#include "sys_matrix.h"
#include "gfx.h"
#include "gfx_setupdl.h"
#include "array_count.h"
#include "z_math.h"
#include "libc64/math64.h"
#include "z_lib.h"

/*Fucking stupid

src/overlays/actors/ovl_Redeye/z_redeye.c: In function ‘Redeye_Update’:
src/overlays/actors/ovl_Redeye/z_redeye.c:89:5: error: unknown type name ‘Player’; use ‘struct’ keyword to refer to the type
   89 |     Player* player = GET_PLAYER(play);

This is why i pasted all this shit from z_titan
not enough time
*/
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
#include "segmented_address.h"
#include "seqcmd.h"
#include "sequence.h"
#include "sfx.h"

#include "assets/objects/object_redeye/object_redeye.h"

#define FLAGS (ACTOR_FLAG_UPDATE_CULLING_DISABLED)

void Redeye_Init(Actor* thisx, PlayState* play);
void Redeye_Destroy(Actor* thisx, PlayState* play);
void Redeye_Update(Actor* thisx, PlayState* play);
void Redeye_Draw(Actor* thisx, PlayState* play);

void Redeye_DoNothing(Redeye* this, PlayState* play);

ActorProfile Redeye_Profile = {
    ACTOR_REDEYE,
    ACTORCAT_ENEMY,
    FLAGS,
    OBJECT_REDEYE,
    sizeof(Redeye),
    (ActorFunc)Redeye_Init,
    (ActorFunc)Redeye_Destroy,
    (ActorFunc)Redeye_Update,
    (ActorFunc)Redeye_Draw,
};

static ColliderJntSphElementInit sJntSphElementsInit[] = {
    {
        {
            ELEM_MATERIAL_UNK0,
            { 0xFFCFFFFF, HIT_SPECIAL_EFFECT_NONE, 0x04 },
            { 0xFFCFFFFF, HIT_BACKLASH_NONE, 0x00 },
            ATELEM_ON | ATELEM_SFX_NORMAL,
            ACELEM_ON | ACELEM_HOOKABLE,
            OCELEM_ON,
        },
        { 0, { { 0, 0, 0 }, 58 }, 100 },
    },
};

static ColliderJntSphInit sJntSphInit = {
    {
        COL_MATERIAL_HIT6,
        AT_ON | AT_TYPE_ENEMY,
        AC_ON | AC_TYPE_PLAYER,
        OC1_ON | OC1_TYPE_ALL,
        OC2_TYPE_1,
        COLSHAPE_JNTSPH,
    },
    ARRAY_COUNT(sJntSphElementsInit),
    sJntSphElementsInit,
};

void Redeye_Init(Actor* thisx, PlayState* play) {
    Redeye* this = (Redeye*)thisx;

    Collider_InitJntSph(play, &this->collider);
    Collider_SetJntSph(play, &this->collider, &this->actor, &sJntSphInit, this->colliderElements);
    this->collider.elements[0].dim.worldSphere.radius = 25;

    thisx->world.pos.y += 15.0f;

    this->vel.x = 0;
    this->vel.y = 0;
    this->vel.z = 0;

    this->actionFunc = Redeye_DoNothing;
}

void Redeye_Destroy(Actor* thisx, PlayState* play) {
    Redeye* this = (Redeye*)thisx;
}

void Redeye_Update(Actor* thisx, PlayState* play) {
    Redeye* this = (Redeye*)thisx;
    Player* player = GET_PLAYER(play);

    Actor * pa = &player->actor;

    if (thisx->xyzDistToPlayerSq > 80000.0f) {
        this->vel.x += CLAMP((pa->world.pos.x - thisx->world.pos.x) * 0.02f,-2.0f,2.0f);
        this->vel.z += CLAMP((pa->world.pos.z - thisx->world.pos.z) * 0.02f,-2.0f,2.0f);

        //always dampe. never goon
        this->vel.x *= .99f;
        this->vel.z *= .99f;
    }

    thisx->world.pos.x += this->vel.x*.3f;
    thisx->world.pos.z += this->vel.z*.3f;

    this->actionFunc(this, play);

    thisx->shape.rot.x += 0x200;




    Sphere16* worldSphere = &this->collider.elements[0].dim.worldSphere;

    worldSphere->center.x = this->actor.world.pos.x;
    worldSphere->center.y = this->actor.world.pos.y;
    worldSphere->center.z = this->actor.world.pos.z;

    CollisionCheck_SetAT(play, &play->colChkCtx, &this->collider.base);
    //CollisionCheck_SetOC(play, &play->colChkCtx, &this->collider.base);

    if (this->collider.elements[0].base.acElemFlags & ACELEM_HIT) {
        Actor_Kill(thisx);
    }
    if (this->collider.base.atFlags & AT_HIT) {
        Actor_Kill(thisx);
    }
}

void Redeye_Draw(Actor* thisx, PlayState* play) {
    Redeye* this = (Redeye*)thisx;

    Gfx_DrawDListOpa(play, gRedeyeBody_opaque_dl);

    OPEN_DISPS(play->state.gfxCtx);

        Gfx_SetupDL_25Opa(play->state.gfxCtx);
        Matrix_ReplaceRotation(&play->billboardMtxF);
        MATRIX_FINALIZE_AND_LOAD(POLY_OPA_DISP++, play->state.gfxCtx);
        gSPDisplayList(POLY_OPA_DISP++, gRedeyeEye_opaque_dl);

    CLOSE_DISPS(play->state.gfxCtx);
}

void Redeye_DoNothing(Redeye* this, PlayState* play) {

}
