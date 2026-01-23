/*
 * File: z_destructible_bookshelves.c
 * Overlay: ovl_Destructible_Bookshelves
 * Description: Custom Actor
 */

#include "z_destructible_bookshelves.h"

#include "libc64/math64.h"
#include "libc64/qrand.h"
#include "effect.h"

#include "assets/objects/gameplay_keep/gameplay_keep.h"
#include "z_lib.h"
#include "assets/objects/object_kibako2/object_kibako2.h"
#include "overlays/effects/ovl_Effect_Ss_Kakera/z_eff_ss_kakera.h"
#include "sfx.h"


#include "assets/objects/object_destructible_bookshelves/object_destructible_bookshelves.h"
#include "assets/objects/object_destructible_bookshelves/gBookshelvesCollision_collision.h"

#define FLAGS 0

void Destructible_Bookshelves_Init(Actor* thisx, PlayState* play);
void Destructible_Bookshelves_Destroy(Actor* thisx, PlayState* play);
void Destructible_Bookshelves_Update(Actor* thisx, PlayState* play);
void Destructible_Bookshelves_Draw(Actor* thisx, PlayState* play);

void Destructible_Bookshelves_DoNothing(Destructible_Bookshelves* this, PlayState* play);

int sDownedBookshelves = 0;

ActorProfile Destructible_Bookshelves_Profile = {
    ACTOR_DESTRUCTIBLE_BOOKSHELVES,
    ACTORCAT_BG,
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

    CollisionHeader * colHeader = NULL;

    DynaPolyActor_Init(&this->dyna, 0);
    CollisionHeader_GetVirtual(&gBookshelvesCollision_collisionHeader, &colHeader);
    this->dyna.bgId = DynaPoly_SetBgActor(play, &play->colCtx.dyna, &this->dyna.actor, colHeader);
    ActorShape_Init(&this->dyna.actor.shape, 0.0f, NULL, 0.0f);
    
    // Set random rotation
    int randomRotation = Rand_ZeroOne() * 3.0f;
    thisx->shape.rot.y = randomRotation * 0x4000;

    // Init my vars
    this->action = 0;
    this->timer = 0;

    // I know this happens 16 times, but don't really have a better idea lol
    sDownedBookshelves = 0;
}

void Destructible_Bookshelves_Destroy(Actor* thisx, PlayState* play) {
    Destructible_Bookshelves* this = (Destructible_Bookshelves*)thisx;

    DynaPoly_DeleteBgActor(play, &play->colCtx.dyna, this->dyna.bgId);
}

void ObjBookshelves_BreakEffect(Destructible_Bookshelves * this, PlayState* play) {
    Vec3f* thisPos;
    Vec3f pos;
    Vec3f velocity;
    s16 angle;
    s32 i;

    thisPos = &this->dyna.actor.world.pos;

    SfxSource_PlaySfxAtFixedWorldPos(play, &this->dyna.actor.world.pos, 20, NA_SE_EV_WOODBOX_BREAK);
    this->dyna.actor.flags |= ACTOR_FLAG_UPDATE_CULLING_DISABLED;

    for (i = 0, angle = 0; i < 0x10; i++, angle += 0x4E20) {
        f32 sn = Math_SinS(angle);
        f32 cs = Math_CosS(angle);
        f32 temp_rand;
        s32 phi_s0;

        temp_rand = Rand_ZeroOne() * 30.0f;
        pos.x = sn * temp_rand;
        pos.y = (Rand_ZeroOne() * 10.0f) + 2.0f;
        pos.z = cs * temp_rand;
        velocity.x = pos.x * 2.0f;
        velocity.y = (Rand_ZeroOne() * 10.0f) + 20.0f;
        velocity.z = pos.z * 2.0f;
        pos.x += thisPos->x;
        pos.y += thisPos->y;
        pos.z += thisPos->z;
        temp_rand = Rand_ZeroOne();
        if (temp_rand < 0.05f) {
            phi_s0 = 0x60;
        } else if (temp_rand < 0.7f) {
            phi_s0 = 0x40;
        } else {
            phi_s0 = 0x20;
        }
        EffectSsKakera_Spawn(play, &pos, &velocity, &pos, -200, phi_s0, 28, 2, 0, (Rand_ZeroOne() * 30.0f) + 5.0f, 0, 0,
                             70, KAKERA_COLOR_NONE, OBJECT_KIBAKO2, gLargeCrateFragmentDL);
    }
    //func_80033480(play, thisPos, 90.0f, 6, 100, 160, 1);
}

void Destructible_Bookshelves_Update(Actor* thisx, PlayState* play) {
    Destructible_Bookshelves* this = (Destructible_Bookshelves*)thisx;

    switch(this->action) {
        case 0:
            if (Actor_FindNearby(play, thisx, ACTOR_TITAN, ACTORCAT_ENEMY, 160.0f)) {
                sDownedBookshelves++;

                ObjBookshelves_BreakEffect(this, play);

                this->action++;
                thisx->world.pos.y -= 500.0f;
                this->timer = 0;
            }
            break;
        case 1:
            // Move up for dist check
            thisx->world.pos.y = 0.0f;
            if (Actor_FindNearby(play, thisx, ACTOR_TITAN, ACTORCAT_ENEMY, 250.0f)) {
                this->timer = 0;
            }
            thisx->world.pos.y = -500.0f;
            if (sDownedBookshelves < 10) {
                this->timer = 0;
            }
            if (this->timer > 200) {
                if (Rand_ZeroOne() > .95f) {
                    this->action++;
                }
                this->timer = 0;
            }
            break;
        case 2:  //Rize bak up
            thisx->world.pos.y *= .95f;
            if (thisx->world.pos.y > -1.f) {
                this->action = 0;
                sDownedBookshelves--;
            }
            break;
    }

    this->timer++;

    this->actionFunc(this, play);
}

void Destructible_Bookshelves_Draw(Actor* thisx, PlayState* play) {
    Destructible_Bookshelves* this = (Destructible_Bookshelves*)thisx;

    if (this->action != 1) {
        Gfx_DrawDListOpa(play, gBookshelves_opaque_dl);
    }
}

void Destructible_Bookshelves_DoNothing(Destructible_Bookshelves* this, PlayState* play) {

}
