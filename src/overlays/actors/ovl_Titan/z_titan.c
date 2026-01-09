/*
 * File: z_titan.c
 * Overlay: ovl_Titan
 * Description: Custom Actor
 */

#include "z_titan.h"

#include "play_state.h"

#include "assets/objects/object_titan/object_titan.h"

#define FLAGS (ACTOR_FLAG_ATTENTION_ENABLED)

void Titan_Init(Actor* thisx, PlayState* play);
void Titan_Destroy(Actor* thisx, PlayState* play);
void Titan_Update(Actor* thisx, PlayState* play);
void Titan_Draw(Actor* thisx, PlayState* play);

void Titan_DoNothing(Titan* this, PlayState* play);

ActorProfile Titan_Profile = {
    ACTOR_TITAN,
    ACTORCAT_PROP,
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
}

void Titan_Destroy(Actor* thisx, PlayState* play) {
    Titan* this = (Titan*)thisx;
}

void Titan_Update(Actor* thisx, PlayState* play) {
    Titan* this = (Titan*)thisx;

    this->actionFunc(this, play);
}

void Titan_Draw(Actor* thisx, PlayState* play) {
    Titan* this = (Titan*)thisx;
}

void Titan_DoNothing(Titan* this, PlayState* play) {

}
