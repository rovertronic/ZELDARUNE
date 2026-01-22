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

#include "assets/objects/object_redeye/object_redeye.h"

#define FLAGS (0)

void Redeye_Init(Actor* thisx, PlayState* play);
void Redeye_Destroy(Actor* thisx, PlayState* play);
void Redeye_Update(Actor* thisx, PlayState* play);
void Redeye_Draw(Actor* thisx, PlayState* play);

void Redeye_DoNothing(Redeye* this, PlayState* play);

ActorProfile Redeye_Profile = {
    ACTOR_REDEYE,
    ACTORCAT_PROP,
    FLAGS,
    OBJECT_REDEYE,
    sizeof(Redeye),
    (ActorFunc)Redeye_Init,
    (ActorFunc)Redeye_Destroy,
    (ActorFunc)Redeye_Update,
    (ActorFunc)Redeye_Draw,
};

void Redeye_Init(Actor* thisx, PlayState* play) {
    Redeye* this = (Redeye*)thisx;

    //Collider_InitJntSph(play, &this->collider);
    //Collider_SetJntSph(play, &this->collider, &this->actor, &sJntSphInit, this->colliderElements);
    //EnGoroiwa_UpdateCollider(this);
    //this->collider.elements[0].dim.worldSphere.radius = 58;

    this->actionFunc = Redeye_DoNothing;
}

void Redeye_Destroy(Actor* thisx, PlayState* play) {
    Redeye* this = (Redeye*)thisx;
}

void Redeye_Update(Actor* thisx, PlayState* play) {
    Redeye* this = (Redeye*)thisx;

    this->actionFunc(this, play);
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
