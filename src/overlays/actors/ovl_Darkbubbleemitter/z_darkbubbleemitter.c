/*
 * File: z_darkbubbleemitter.c
 * Overlay: ovl_Darkbubbleemitter
 * Description: Custom Actor
 */

#include "z_darkbubbleemitter.h"

#include "play_state.h"


#define FLAGS (ACTOR_FLAG_UPDATE_CULLING_DISABLED)

void Darkbubbleemitter_Init(Actor* thisx, PlayState* play);
void Darkbubbleemitter_Destroy(Actor* thisx, PlayState* play);
void Darkbubbleemitter_Update(Actor* thisx, PlayState* play);
void Darkbubbleemitter_Draw(Actor* thisx, PlayState* play);

ActorProfile Darkbubbleemitter_Profile = {
    ACTOR_DARKBUBBLEEMITTER,
    ACTORCAT_PROP,
    FLAGS,
    OBJECT_GAMEPLAY_KEEP,
    sizeof(Darkbubbleemitter),
    (ActorFunc)Darkbubbleemitter_Init,
    (ActorFunc)Darkbubbleemitter_Destroy,
    (ActorFunc)Darkbubbleemitter_Update,
    (ActorFunc)Darkbubbleemitter_Draw,
};

void Darkbubbleemitter_Init(Actor* thisx, PlayState* play) {
    Darkbubbleemitter* this = (Darkbubbleemitter*)thisx;
    this->timer = 0;
}

void Darkbubbleemitter_Destroy(Actor* thisx, PlayState* play) {
    Darkbubbleemitter* this = (Darkbubbleemitter*)thisx;
}

void Darkbubbleemitter_Update(Actor* thisx, PlayState* play) {
    Darkbubbleemitter* this = (Darkbubbleemitter*)thisx;

    if (this->timer % 10 == 0) {
        Actor_Spawn(&play->actorCtx, play,
        ACTOR_DARKBUBBLE,
        thisx->world.pos.x, thisx->world.pos.y, thisx->world.pos.z, 
        0, 0, 0, 0);
    }
    this->timer++;
}

void Darkbubbleemitter_Draw(Actor* thisx, PlayState* play) {
    Darkbubbleemitter* this = (Darkbubbleemitter*)thisx;
}
