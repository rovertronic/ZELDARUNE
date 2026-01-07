#ifndef Z_DESTRUCTIBLE_BOOKSHELVES_H
#define Z_DESTRUCTIBLE_BOOKSHELVES_H

#include "ultra64.h"
#include "actor.h"
#include "play_state.h"

struct Destructible_Bookshelves;

typedef void (*Destructible_BookshelvesActionFunc)(struct Destructible_Bookshelves*, PlayState*);

typedef struct Destructible_Bookshelves {
    Actor actor;
    Destructible_BookshelvesActionFunc actionFunc;
} Destructible_Bookshelves;

#endif
