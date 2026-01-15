#ifndef Z_DARKBUBBLEEMITTER_H
#define Z_DARKBUBBLEEMITTER_H

#include "ultra64.h"
#include "actor.h"
#include "play_state.h"

struct Darkbubbleemitter;

typedef void (*DarkbubbleemitterActionFunc)(struct Darkbubbleemitter*, PlayState*);

typedef struct Darkbubbleemitter {
    Actor actor;
    int timer;
} Darkbubbleemitter;

#endif
