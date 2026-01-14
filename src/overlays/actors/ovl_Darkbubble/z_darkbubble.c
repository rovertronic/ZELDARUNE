/*
 * File: z_darkbubble.c
 * Overlay: ovl_Darkbubble
 * Description: Custom Actor
 */

#include "z_darkbubble.h"

#include "play_state.h"

#include "assets/objects/object_darkbubble/object_darkbubble.h"

#define FLAGS (0)

void Darkbubble_Init(Actor* thisx, PlayState* play);
void Darkbubble_Destroy(Actor* thisx, PlayState* play);
void Darkbubble_Update(Actor* thisx, PlayState* play);
void Darkbubble_Draw(Actor* thisx, PlayState* play);

void Darkbubble_DoNothing(Darkbubble* this, PlayState* play);

ActorProfile Darkbubble_Profile = {
    ACTOR_DARKBUBBLE,
    ACTORCAT_PROP,
    FLAGS,
    OBJECT_DARKBUBBLE,
    sizeof(Darkbubble),
    (ActorFunc)Darkbubble_Init,
    (ActorFunc)Darkbubble_Destroy,
    (ActorFunc)Darkbubble_Update,
    (ActorFunc)Darkbubble_Draw,
};

void Darkbubble_Init(Actor* thisx, PlayState* play) {
    Darkbubble* this = (Darkbubble*)thisx;

    this->actionFunc = Darkbubble_DoNothing;
}

void Darkbubble_Destroy(Actor* thisx, PlayState* play) {
    Darkbubble* this = (Darkbubble*)thisx;
}

void Darkbubble_Update(Actor* thisx, PlayState* play) {
    Darkbubble* this = (Darkbubble*)thisx;

    this->actionFunc(this, play);
}

void Darkbubble_Draw(Actor* thisx, PlayState* play) {
    Darkbubble* this = (Darkbubble*)thisx;

    Gfx_DrawDListOpa(play, gDarkBubble_opaque_dl);
}

void Darkbubble_DoNothing(Darkbubble* this, PlayState* play) {

}
