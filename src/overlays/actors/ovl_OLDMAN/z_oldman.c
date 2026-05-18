/*
 * File: z_oldman.c
 * Overlay: ovl_OLDMAN
 * Description: Custom Actor
 */

#include "z_oldman.h"

#include "gfx.h"
#include "one_point_cutscene.h"
#include "segmented_address.h"
#include "sequence.h"
#include "sfx.h"
#include "sys_matrix.h"
#include "z_lib.h"
#include "audio.h"
#include "face_reaction.h"
#include "ocarina.h"
#include "play_state.h"
#include "player.h"
#include "save.h"

#include "assets/objects/object_du/object_du.h"

#define FLAGS (0)

void OLDMAN_Init(Actor* thisx, PlayState* play);
void OLDMAN_Destroy(Actor* thisx, PlayState* play);
void OLDMAN_Update(Actor* thisx, PlayState* play);
void OLDMAN_Draw(Actor* thisx, PlayState* play);

void OLDMAN_DoNothing(OLDMAN* this, PlayState* play);

ActorProfile OLDMAN_Profile = {
    ACTOR_OLDMAN,
    ACTORCAT_PROP,
    FLAGS,
    OBJECT_DU,
    sizeof(OLDMAN),
    (ActorFunc)OLDMAN_Init,
    (ActorFunc)OLDMAN_Destroy,
    (ActorFunc)OLDMAN_Update,
    (ActorFunc)OLDMAN_Draw,
};

static AnimationInfo sAnimationInfo[] = {
    { &gDaruniaIdleAnim, 1.0f, 0.0f, -1.0f, ANIMMODE_LOOP, 0.0f },
    { &gDaruniaIdleAnim, 1.0f, 0.0f, -1.0f, ANIMMODE_LOOP, -10.0f },
    { &gDaruniaItemGiveAnim, 1.0f, 0.0f, -1.0f, ANIMMODE_LOOP, -10.0f },
    { &gDaruniaItemGiveIdleAnim, 1.0f, 0.0f, -1.0f, ANIMMODE_LOOP, -10.0f },
    { &gDaruniaHitLinkAnim, 1.0f, 0.0f, -1.0f, ANIMMODE_LOOP, -10.0f },
    { &gDaruniaHitBreastAnim, 1.0f, 0.0f, -1.0f, ANIMMODE_LOOP, -10.0f },
    { &gDaruniaStandUpAfterFallingAnim, 1.0f, 0.0f, -1.0f, ANIMMODE_LOOP, -10.0f },
    { &gDaruniaDancingLoop1Anim, 1.0f, 0.0f, -1.0f, ANIMMODE_ONCE, -10.0f },
    { &gDaruniaDancingLoop1Anim, 1.0f, 0.0f, -1.0f, ANIMMODE_ONCE, 0.0f },
    { &gDaruniaDancingLoop2Anim, 1.0f, 0.0f, -1.0f, ANIMMODE_ONCE, 0.0f },
    { &gDaruniaDancingLoop3Anim, 1.0f, 0.0f, -1.0f, ANIMMODE_ONCE, 0.0f },
    { &gDaruniaWrongSongAnim, 1.0f, 0.0f, -1.0f, ANIMMODE_ONCE, 0.0f },
    { &gDaruniaWrongSongEndAnim, 1.0f, 0.0f, -1.0f, ANIMMODE_LOOP, 0.0f },
    { &gDaruniaDancingLoop4Anim, 1.0f, 0.0f, -1.0f, ANIMMODE_ONCE, 0.0f },
    { &gDaruniaDancingEndAnim, 1.0f, 0.0f, -1.0f, ANIMMODE_ONCE, -6.0f },
};

void OLDMAN_Init(Actor* thisx, PlayState* play) {
    OLDMAN* this = (OLDMAN*)thisx;

    Animation_ChangeByInfo(&this->skelAnime, sAnimationInfo, 0);
    Actor_SetScale(&this->actor, 0.01f);

    SkelAnime_InitFlex(
        play,
        &this->skelAnime,
        &gDaruniaSkel,
        &gDaruniaIdleAnim,
        this->jointTable,
        this->morphTable,
        18
    );

    this->actionFunc = OLDMAN_DoNothing;
}

void OLDMAN_Destroy(Actor* thisx, PlayState* play) {
    OLDMAN* this = (OLDMAN*)thisx;
}

void OLDMAN_Update(Actor* thisx, PlayState* play) {
    OLDMAN* this = (OLDMAN*)thisx;

    this->actionFunc(this, play);
}

void OLDMAN_Draw(Actor* thisx, PlayState* play) {
    OLDMAN* this = (OLDMAN*)thisx;

    OPEN_DISPS(play->state.gfxCtx);
    
    gSPSegment(POLY_OPA_DISP++, 0x08, SEGMENTED_TO_VIRTUAL(gDaruniaEyeOpenTex));
    gSPSegment(POLY_OPA_DISP++, 0x09, SEGMENTED_TO_VIRTUAL(gDaruniaMouthGrinningTex));
    gSPSegment(POLY_OPA_DISP++, 0x0A, SEGMENTED_TO_VIRTUAL(gDaruniaNoseSeriousTex));

    SkelAnime_DrawFlexOpa(play, this->skelAnime.skeleton, this->skelAnime.jointTable, this->skelAnime.dListCount, NULL, NULL, this);
    CLOSE_DISPS(play->state.gfxCtx);
}

void OLDMAN_DoNothing(OLDMAN* this, PlayState* play) {

}
