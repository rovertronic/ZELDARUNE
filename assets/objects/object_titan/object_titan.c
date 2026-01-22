#include "object_titan.h"
#include "tex_len.h"

Gfx gTitanDL[] = {
    gsSPEndDisplayList(),
};

u64 const gTitanTitleCard[] = {
#include "assets/objects/object_titan/tcnew.ia8.inc.c"
};

#include "gTitanSkelanime.c"

#include "gTitanShield.c"
