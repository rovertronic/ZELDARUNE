/*
 * File: z_titan.c
 * Overlay: ovl_Titan
 * Description: Custom Actor
 */

#include "z_titan.h"

#include "play_state.h"

#include "assets/objects/object_titan/object_titan.h"
#include "assets/objects/object_titan/gTitanIdleAnim.h"

#define FLAGS (ACTOR_FLAG_ATTENTION_ENABLED)

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

void Titan_Init(Actor* thisx, PlayState* play) {
    Titan* this = (Titan*)thisx;

    this->actionFunc = Titan_DoNothing;
    thisx->focus.pos.y += 150.0f;
    thisx->focus.pos.x += 20.0f;

    thisx->attentionRangeType = ATTENTION_RANGE_4;

    SkelAnime_Init(play, &this->skelAnime, &gTitanSkelanime, &gTitanSkelanimeGtitanskelanimeactionAnim,
        this->jointTable, this->morphTable, GTITANSKELANIME_NUM_LIMBS);

    thisx->naviEnemyId = NAVI_ENEMY_TITAN;
}

void Titan_Destroy(Actor* thisx, PlayState* play) {
    Titan* this = (Titan*)thisx;
}

void Titan_Update(Actor* thisx, PlayState* play) {
    Titan* this = (Titan*)thisx;

    SkelAnime_Update(&this->skelAnime);
    this->actionFunc(this, play);
}

void Titan_Draw(Actor* thisx, PlayState* play) {
    Titan* this = (Titan*)thisx;

    SkelAnime_DrawOpa(play, this->skelAnime.skeleton, this->skelAnime.jointTable,
                      NULL, NULL, this);
}

void Titan_DoNothing(Titan* this, PlayState* play) {

}
