#ifndef Z_OLDMAN_H
#define Z_OLDMAN_H

#include "ultra64.h"
#include "actor.h"
#include "play_state.h"

struct OLDMAN;

typedef void (*OLDMANActionFunc)(struct OLDMAN*, PlayState*);

typedef struct OLDMAN {
    Actor actor;
    OLDMANActionFunc actionFunc;
    SkelAnime skelAnime;

    Vec3s jointTable[50];
    Vec3s morphTable[50];
} OLDMAN;

#endif
