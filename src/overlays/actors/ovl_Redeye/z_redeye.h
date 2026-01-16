#ifndef Z_REDEYE_H
#define Z_REDEYE_H

#include "ultra64.h"
#include "actor.h"
#include "play_state.h"

struct Redeye;

typedef void (*RedeyeActionFunc)(struct Redeye*, PlayState*);

typedef struct Redeye {
    Actor actor;
    RedeyeActionFunc actionFunc;
    ColliderJntSph collider;
    ColliderJntSphElement colliderElements[1];
} Redeye;

#endif
