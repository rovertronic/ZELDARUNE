#include "titan_scene.h"

/**
 * Header Child Day (Default)
*/
#define LENGTH_TITAN_ROOM_0_HEADER00_OBJECTLIST 6
#define LENGTH_TITAN_ROOM_0_HEADER00_ACTORLIST 41
SceneCmd titan_room_0_header00[] = {
    SCENE_CMD_ROOM_SHAPE(&titan_room_0_shapeHeader),
    SCENE_CMD_ECHO_SETTINGS(0x00),
    SCENE_CMD_ROOM_BEHAVIOR(0x01, 0x00, false, false),
    SCENE_CMD_SKYBOX_DISABLES(true, true),
    SCENE_CMD_TIME_SETTINGS(255, 255, 0),
    SCENE_CMD_OBJECT_LIST(LENGTH_TITAN_ROOM_0_HEADER00_OBJECTLIST, titan_room_0_header00_objectList),
    SCENE_CMD_ACTOR_LIST(LENGTH_TITAN_ROOM_0_HEADER00_ACTORLIST, titan_room_0_header00_actorList),
    SCENE_CMD_END(),
};

s16 titan_room_0_header00_objectList[LENGTH_TITAN_ROOM_0_HEADER00_OBJECTLIST] = {
    OBJECT_DESTRUCTIBLE_BOOKSHELVES,
    OBJECT_TITAN,
    OBJECT_TITE,
    OBJECT_KIBAKO2,
    OBJECT_DARKBUBBLE,
    OBJECT_REDEYE,
};

ActorEntry titan_room_0_header00_actorList[LENGTH_TITAN_ROOM_0_HEADER00_ACTORLIST] = {
    // Custom Actor
    {
        /* Actor ID   */ ACTOR_DESTRUCTIBLE_BOOKSHELVES,
        /* Position   */ { 200, 0, 0 },
        /* Rotation   */ { DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000) },
        /* Parameters */ 0x0000
    },

    // Custom Actor
    {
        /* Actor ID   */ ACTOR_DESTRUCTIBLE_BOOKSHELVES,
        /* Position   */ { 200, 0, 200 },
        /* Rotation   */ { DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000) },
        /* Parameters */ 0x0000
    },

    // Custom Actor
    {
        /* Actor ID   */ ACTOR_DESTRUCTIBLE_BOOKSHELVES,
        /* Position   */ { 0, 0, 200 },
        /* Rotation   */ { DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000) },
        /* Parameters */ 0x0000
    },

    // Custom Actor
    {
        /* Actor ID   */ ACTOR_DESTRUCTIBLE_BOOKSHELVES,
        /* Position   */ { -200, 0, 200 },
        /* Rotation   */ { DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000) },
        /* Parameters */ 0x0000
    },

    // Custom Actor
    {
        /* Actor ID   */ ACTOR_DESTRUCTIBLE_BOOKSHELVES,
        /* Position   */ { 200, 0, -200 },
        /* Rotation   */ { DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000) },
        /* Parameters */ 0x0000
    },

    // Custom Actor
    {
        /* Actor ID   */ ACTOR_DESTRUCTIBLE_BOOKSHELVES,
        /* Position   */ { 0, 0, -200 },
        /* Rotation   */ { DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000) },
        /* Parameters */ 0x0000
    },

    // Custom Actor
    {
        /* Actor ID   */ ACTOR_DESTRUCTIBLE_BOOKSHELVES,
        /* Position   */ { -200, 0, -200 },
        /* Rotation   */ { DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000) },
        /* Parameters */ 0x0000
    },

    // Custom Actor
    {
        /* Actor ID   */ ACTOR_DESTRUCTIBLE_BOOKSHELVES,
        /* Position   */ { -200, 0, 0 },
        /* Rotation   */ { DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000) },
        /* Parameters */ 0x0000
    },

    // Custom Actor
    {
        /* Actor ID   */ ACTOR_DESTRUCTIBLE_BOOKSHELVES,
        /* Position   */ { 200, 0, -400 },
        /* Rotation   */ { DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000) },
        /* Parameters */ 0x0000
    },

    // Custom Actor
    {
        /* Actor ID   */ ACTOR_DESTRUCTIBLE_BOOKSHELVES,
        /* Position   */ { 0, 0, -400 },
        /* Rotation   */ { DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000) },
        /* Parameters */ 0x0000
    },

    // Custom Actor
    {
        /* Actor ID   */ ACTOR_DESTRUCTIBLE_BOOKSHELVES,
        /* Position   */ { -200, 0, -400 },
        /* Rotation   */ { DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000) },
        /* Parameters */ 0x0000
    },

    // Custom Actor
    {
        /* Actor ID   */ ACTOR_DESTRUCTIBLE_BOOKSHELVES,
        /* Position   */ { 200, 0, 400 },
        /* Rotation   */ { DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000) },
        /* Parameters */ 0x0000
    },

    // Custom Actor
    {
        /* Actor ID   */ ACTOR_DESTRUCTIBLE_BOOKSHELVES,
        /* Position   */ { 0, 0, 400 },
        /* Rotation   */ { DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000) },
        /* Parameters */ 0x0000
    },

    // Custom Actor
    {
        /* Actor ID   */ ACTOR_DESTRUCTIBLE_BOOKSHELVES,
        /* Position   */ { -200, 0, 400 },
        /* Rotation   */ { DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000) },
        /* Parameters */ 0x0000
    },

    // Custom Actor
    {
        /* Actor ID   */ ACTOR_DESTRUCTIBLE_BOOKSHELVES,
        /* Position   */ { -400, 0, 200 },
        /* Rotation   */ { DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000) },
        /* Parameters */ 0x0000
    },

    // Custom Actor
    {
        /* Actor ID   */ ACTOR_DESTRUCTIBLE_BOOKSHELVES,
        /* Position   */ { -400, 0, -200 },
        /* Rotation   */ { DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000) },
        /* Parameters */ 0x0000
    },

    // Custom Actor
    {
        /* Actor ID   */ ACTOR_DESTRUCTIBLE_BOOKSHELVES,
        /* Position   */ { -400, 0, 0 },
        /* Rotation   */ { DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000) },
        /* Parameters */ 0x0000
    },

    // Custom Actor
    {
        /* Actor ID   */ ACTOR_DESTRUCTIBLE_BOOKSHELVES,
        /* Position   */ { -400, 0, -400 },
        /* Rotation   */ { DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000) },
        /* Parameters */ 0x0000
    },

    // Custom Actor
    {
        /* Actor ID   */ ACTOR_DESTRUCTIBLE_BOOKSHELVES,
        /* Position   */ { -400, 0, 400 },
        /* Rotation   */ { DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000) },
        /* Parameters */ 0x0000
    },

    // Custom Actor
    {
        /* Actor ID   */ ACTOR_DESTRUCTIBLE_BOOKSHELVES,
        /* Position   */ { 400, 0, 0 },
        /* Rotation   */ { DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000) },
        /* Parameters */ 0x0000
    },

    // Custom Actor
    {
        /* Actor ID   */ ACTOR_DESTRUCTIBLE_BOOKSHELVES,
        /* Position   */ { 400, 0, 200 },
        /* Rotation   */ { DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000) },
        /* Parameters */ 0x0000
    },

    // Custom Actor
    {
        /* Actor ID   */ ACTOR_DESTRUCTIBLE_BOOKSHELVES,
        /* Position   */ { 400, 0, -200 },
        /* Rotation   */ { DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000) },
        /* Parameters */ 0x0000
    },

    // Custom Actor
    {
        /* Actor ID   */ ACTOR_DESTRUCTIBLE_BOOKSHELVES,
        /* Position   */ { 400, 0, -400 },
        /* Rotation   */ { DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000) },
        /* Parameters */ 0x0000
    },

    // Custom Actor
    {
        /* Actor ID   */ ACTOR_DESTRUCTIBLE_BOOKSHELVES,
        /* Position   */ { 400, 0, 400 },
        /* Rotation   */ { DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000) },
        /* Parameters */ 0x0000
    },

    // Custom Actor
    {
        /* Actor ID   */ ACTOR_DESTRUCTIBLE_BOOKSHELVES,
        /* Position   */ { 0, 0, 0 },
        /* Rotation   */ { DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000) },
        /* Parameters */ 0x0000
    },

    // Custom Actor
    {
        /* Actor ID   */ ACTOR_DESTRUCTIBLE_BOOKSHELVES,
        /* Position   */ { -600, 0, 200 },
        /* Rotation   */ { DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000) },
        /* Parameters */ 0x0000
    },

    // Custom Actor
    {
        /* Actor ID   */ ACTOR_DESTRUCTIBLE_BOOKSHELVES,
        /* Position   */ { -600, 0, 0 },
        /* Rotation   */ { DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000) },
        /* Parameters */ 0x0000
    },

    // Custom Actor
    {
        /* Actor ID   */ ACTOR_DESTRUCTIBLE_BOOKSHELVES,
        /* Position   */ { -600, 0, 400 },
        /* Rotation   */ { DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000) },
        /* Parameters */ 0x0000
    },

    // Custom Actor
    {
        /* Actor ID   */ ACTOR_DESTRUCTIBLE_BOOKSHELVES,
        /* Position   */ { 200, 0, 600 },
        /* Rotation   */ { DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000) },
        /* Parameters */ 0x0000
    },

    // Custom Actor
    {
        /* Actor ID   */ ACTOR_DESTRUCTIBLE_BOOKSHELVES,
        /* Position   */ { 0, 0, 600 },
        /* Rotation   */ { DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000) },
        /* Parameters */ 0x0000
    },

    // Custom Actor
    {
        /* Actor ID   */ ACTOR_DESTRUCTIBLE_BOOKSHELVES,
        /* Position   */ { -400, 0, 600 },
        /* Rotation   */ { DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000) },
        /* Parameters */ 0x0000
    },

    // Custom Actor
    {
        /* Actor ID   */ ACTOR_DESTRUCTIBLE_BOOKSHELVES,
        /* Position   */ { 600, 0, 0 },
        /* Rotation   */ { DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000) },
        /* Parameters */ 0x0000
    },

    // Custom Actor
    {
        /* Actor ID   */ ACTOR_DESTRUCTIBLE_BOOKSHELVES,
        /* Position   */ { 600, 0, -400 },
        /* Rotation   */ { DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000) },
        /* Parameters */ 0x0000
    },

    // Custom Actor
    {
        /* Actor ID   */ ACTOR_DESTRUCTIBLE_BOOKSHELVES,
        /* Position   */ { 600, 0, 400 },
        /* Rotation   */ { DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000) },
        /* Parameters */ 0x0000
    },

    // Custom Actor
    {
        /* Actor ID   */ ACTOR_DESTRUCTIBLE_BOOKSHELVES,
        /* Position   */ { -200, 0, -600 },
        /* Rotation   */ { DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000) },
        /* Parameters */ 0x0000
    },

    // Custom Actor
    {
        /* Actor ID   */ ACTOR_DESTRUCTIBLE_BOOKSHELVES,
        /* Position   */ { -400, 0, -600 },
        /* Rotation   */ { DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000) },
        /* Parameters */ 0x0000
    },

    // Custom Actor
    {
        /* Actor ID   */ ACTOR_DESTRUCTIBLE_BOOKSHELVES,
        /* Position   */ { 400, 0, -600 },
        /* Rotation   */ { DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000) },
        /* Parameters */ 0x0000
    },

    // Custom Actor
    {
        /* Actor ID   */ ACTOR_DARKBUBBLEEMITTER,
        /* Position   */ { -20, -203, 1304 },
        /* Rotation   */ { DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000) },
        /* Parameters */ 0x0001
    },

    // Custom Actor
    {
        /* Actor ID   */ ACTOR_DARKBUBBLEEMITTER,
        /* Position   */ { -1296, -203, -570 },
        /* Rotation   */ { DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000) },
        /* Parameters */ 0x0002
    },

    // Custom Actor
    {
        /* Actor ID   */ ACTOR_DARKBUBBLEEMITTER,
        /* Position   */ { 978, -203, -816 },
        /* Rotation   */ { DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000) },
        /* Parameters */ 0x0003
    },

    // Custom Actor
    {
        /* Actor ID   */ ACTOR_TITAN,
        /* Position   */ { 0, 0, 800 },
        /* Rotation   */ { DEG_TO_BINANG(0.000), DEG_TO_BINANG(180.000), DEG_TO_BINANG(0.000) },
        /* Parameters */ 0x0000
    },
};

