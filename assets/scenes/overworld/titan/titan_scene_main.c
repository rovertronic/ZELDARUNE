#include "titan_scene.h"

/**
 * Header Child Day (Default)
*/
SceneCmd titan_scene_header00[] = {
    SCENE_CMD_COL_HEADER(&titan_scene_collisionHeader),
    SCENE_CMD_ROOM_LIST(1, titan_scene_roomList),
    SCENE_CMD_SOUND_SETTINGS(0x00, 0x00, NA_BGM_NO_MUSIC),
    SCENE_CMD_MISC_SETTINGS(0x00, 0x00),
    SCENE_CMD_SPECIAL_FILES(0x00, OBJECT_GAMEPLAY_DANGEON_KEEP),
    SCENE_CMD_SKYBOX_SETTINGS(0x00, 0x00, LIGHT_MODE_SETTINGS),
    SCENE_CMD_ENV_LIGHT_SETTINGS(1, titan_scene_header00_lightSettings),
    SCENE_CMD_SPAWN_LIST(titan_scene_header00_entranceList),
    SCENE_CMD_PLAYER_ENTRY_LIST(1, titan_scene_header00_playerEntryList),
    SCENE_CMD_END(),
};

RomFile titan_scene_roomList[] = {
    { (uintptr_t)_titan_room_0SegmentRomStart, (uintptr_t)_titan_room_0SegmentRomEnd },
};

ActorEntry titan_scene_header00_playerEntryList[] = {
    // Link / Spawn point
    {
        /* Actor ID   */ ACTOR_PLAYER,
        /* Position   */ { 0, 0, 0 },
        /* Rotation   */ { DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000) },
        /* Parameters */ 0xFFF
    },
};

Spawn titan_scene_header00_entranceList[] = {
    // { Spawn Actor List Index, Room Index }
    { 0, 0 },
};

EnvLightSettings titan_scene_header00_lightSettings[1] = {
    // Indoor No. 1
    {
        {    81,    81,   143 },   // Ambient Color
        {    73,   -73,    73 },   // Diffuse0 Direction
        {   106,   161,   219 },   // Diffuse0 Color
        {   -73,    73,   -73 },   // Diffuse1 Direction
        {    79,    79,   133 },   // Diffuse1 Color
        {     0,     0,     0 },   // Fog Color
        BLEND_RATE_AND_FOG_NEAR(1, 993), // Blend Rate & Fog Near
        12800,                     // Fog Far
    },
};

