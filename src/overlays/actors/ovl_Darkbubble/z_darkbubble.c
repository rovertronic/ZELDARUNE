/*
 * File: z_darkbubble.c
 * Overlay: ovl_Darkbubble
 * Description: Custom Actor
 */

#include "z_darkbubble.h"

#include "play_state.h"

#include "z_lib.h"
#include "libc64/math64.h"
#include "libc64/qrand.h"

#include "assets/objects/object_darkbubble/object_darkbubble.h"

#define FLAGS (ACTOR_FLAG_UPDATE_CULLING_DISABLED)

void Darkbubble_Init(Actor* thisx, PlayState* play);
void Darkbubble_Destroy(Actor* thisx, PlayState* play);
void Darkbubble_Update(Actor* thisx, PlayState* play);
void Darkbubble_Draw(Actor* thisx, PlayState* play);

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
    this->timer = 0;
    this->baseScale = 1.0f;
    thisx->cullingVolumeDistance = 20000;
}

void Darkbubble_Destroy(Actor* thisx, PlayState* play) {
    Darkbubble* this = (Darkbubble*)thisx;
}

void Darkbubble_Update(Actor* thisx, PlayState* play) {
    Darkbubble* this = (Darkbubble*)thisx;

    thisx->world.pos.y += 5.0f;
    thisx->world.pos.x += Math_SinS(this->timer * 0x1000) * 10.0f;

    thisx->scale.x = this->baseScale * (0.015f + (Math_SinS(this->timer * 0x300         ) * .005f) + (this->timer * .0001f));
    thisx->scale.y = this->baseScale * (0.015f + (Math_CosS(this->timer * 0x700 + 0x2000) * .005f) + (this->timer * .0001f));
    thisx->scale.z = this->baseScale * (0.015f + (Math_CosS(this->timer * 0x300         ) * .005f) + (this->timer * .0001f));

    if (this->timer > 200) {
        Actor_Kill(thisx);
    }
    this->timer++;
}

void Darkbubble_Draw(Actor* thisx, PlayState* play) {
    Darkbubble* this = (Darkbubble*)thisx;

    Gfx_DrawDListOpa(play, gDarkBubble_opaque_dl);
}
