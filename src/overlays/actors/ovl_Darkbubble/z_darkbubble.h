#ifndef Z_DARKBUBBLE_H
#define Z_DARKBUBBLE_H

#include "ultra64.h"
#include "actor.h"
#include "play_state.h"

struct Darkbubble;

typedef void (*DarkbubbleActionFunc)(struct Darkbubble*, PlayState*);

typedef struct Darkbubble {
    Actor actor;
    int timer;
    f32 baseScale;
} Darkbubble;

#endif
