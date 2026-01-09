#ifndef Z_TITAN_H
#define Z_TITAN_H

#include "ultra64.h"
#include "actor.h"
#include "play_state.h"

struct Titan;

typedef void (*TitanActionFunc)(struct Titan*, PlayState*);

typedef struct Titan {
    Actor actor;
    TitanActionFunc actionFunc;
} Titan;

#endif
