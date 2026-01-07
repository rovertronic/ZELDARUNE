/*
 * File: z_destructible_bookshelves.c
 * Overlay: ovl_Destructible_Bookshelves
 * Description: Custom Actor
 */

#include "z_destructible_bookshelves.h"

#include "play_state.h"
#include "assets/objects/gameplay_keep/gameplay_keep.h"

#include "assets/objects/object_destructible_bookshelves/object_destructible_bookshelves.h"

#define FLAGS 0

void Destructible_Bookshelves_Init(Actor* thisx, PlayState* play);
void Destructible_Bookshelves_Destroy(Actor* thisx, PlayState* play);
void Destructible_Bookshelves_Update(Actor* thisx, PlayState* play);
void Destructible_Bookshelves_Draw(Actor* thisx, PlayState* play);

void Destructible_Bookshelves_DoNothing(Destructible_Bookshelves* this, PlayState* play);

ActorProfile Destructible_Bookshelves_Profile = {
    ACTOR_DESTRUCTIBLE_BOOKSHELVES,
    ACTORCAT_PROP,
    FLAGS,
    OBJECT_DESTRUCTIBLE_BOOKSHELVES,
    sizeof(Destructible_Bookshelves),
    (ActorFunc)Destructible_Bookshelves_Init,
    (ActorFunc)Destructible_Bookshelves_Destroy,
    (ActorFunc)Destructible_Bookshelves_Update,
    (ActorFunc)Destructible_Bookshelves_Draw,
};

void Destructible_Bookshelves_Init(Actor* thisx, PlayState* play) {
    Destructible_Bookshelves* this = (Destructible_Bookshelves*)thisx;

    this->actionFunc = Destructible_Bookshelves_DoNothing;
}

void Destructible_Bookshelves_Destroy(Actor* thisx, PlayState* play) {
    Destructible_Bookshelves* this = (Destructible_Bookshelves*)thisx;
}

void Destructible_Bookshelves_Update(Actor* thisx, PlayState* play) {
    Destructible_Bookshelves* this = (Destructible_Bookshelves*)thisx;

    this->actionFunc(this, play);
}

void Destructible_Bookshelves_Draw(Actor* thisx, PlayState* play) {
    Destructible_Bookshelves* this = (Destructible_Bookshelves*)thisx;
    Gfx_DrawDListOpa(play, gBookshelves_opaque_dl);
}

void Destructible_Bookshelves_DoNothing(Destructible_Bookshelves* this, PlayState* play) {

}
