#ifndef TITAN_SCENE_H
#define TITAN_SCENE_H

#include "ultra64.h"
#include "romfile.h"
#include "array_count.h"
#include "sequence.h"
#include "actor_profile.h"
#include "bgcheck.h"
#include "camera.h"
#include "cutscene.h"
#include "cutscene_commands.h"
#include "environment.h"
#include "z_math.h"
#include "object.h"
#include "ocarina.h"
#include "path.h"
#include "player.h"
#include "room.h"
#include "scene.h"
#include "event_manager.h"
#include "animated_materials.h"
#include "save.h"

// For older decomp versions
#ifndef SCENE_CMD_PLAYER_ENTRY_LIST
#define SCENE_CMD_PLAYER_ENTRY_LIST(length, playerEntryList) \
    { SCENE_CMD_ID_SPAWN_LIST, length, CMD_PTR(playerEntryList) }
#undef SCENE_CMD_SPAWN_LIST
#define SCENE_CMD_SPAWN_LIST(spawnList) \
    { SCENE_CMD_ID_ENTRANCE_LIST, 0, CMD_PTR(spawnList) }
#endif

#ifndef BLEND_RATE_AND_FOG_NEAR
#define BLEND_RATE_AND_FOG_NEAR(blendRate, fogNear) (s16)((((blendRate) / 4) << 10) | (fogNear))
#endif

extern SceneCmd titan_scene_header00[];
extern RomFile titan_scene_roomList[];
extern u8 _titan_room_0SegmentRomStart[];
extern u8 _titan_room_0SegmentRomEnd[];
extern ActorEntry titan_scene_header00_playerEntryList[];
extern Spawn titan_scene_header00_entranceList[];
extern EnvLightSettings titan_scene_header00_lightSettings[1];
extern Vec3s titan_scene_camPosData[];
extern BgCamInfo titan_scene_bgCamInfo[];
extern SurfaceType titan_scene_polygonTypes[2];
extern Vec3s titan_scene_vertices[1072];
extern CollisionPoly titan_scene_polygons[1800];
extern CollisionHeader titan_scene_collisionHeader;
extern SceneCmd titan_room_0_header00[];
extern Gfx titan_room_0_shapeHeader_entry_0_opaque[];
extern Gfx titan_room_0_shapeHeader_entry_0_transparent[];
extern u64 titan_room_0_dl_uzu_i8[];
extern u64 titan_room_0_dl_stainglass_rgba16[];
extern u64 titan_room_0_dl_gold_i8[];
extern u64 titan_room_0_dl_gaybook_i8[];
extern u64 titan_room_0_dl_churchbookshelf_rgba16[];
extern u64 titan_room_0_dl_churchfloor_ci8[];
extern u64 titan_room_0_dl_churchfloor_pal_rgba16[];
extern Vtx titan_room_0_dl_bg_mesh_layer_Opaque_vtx_0[519];
extern Gfx titan_room_0_dl_bg_mesh_layer_Opaque_tri_0[];
extern Vtx titan_room_0_dl_bg_mesh_layer_Opaque_vtx_1[629];
extern Gfx titan_room_0_dl_bg_mesh_layer_Opaque_tri_1[];
extern Vtx titan_room_0_dl_bg_mesh_layer_Opaque_vtx_2[533];
extern Gfx titan_room_0_dl_bg_mesh_layer_Opaque_tri_2[];
extern Vtx titan_room_0_dl_bg_mesh_layer_Transparent_vtx_0[132];
extern Gfx titan_room_0_dl_bg_mesh_layer_Transparent_tri_0[];
extern Vtx titan_room_0_dl_books_mesh_layer_Opaque_vtx_0[20];
extern Gfx titan_room_0_dl_books_mesh_layer_Opaque_tri_0[];
extern Vtx titan_room_0_dl_books_mesh_layer_Opaque_vtx_1[203];
extern Gfx titan_room_0_dl_books_mesh_layer_Opaque_tri_1[];
extern Vtx titan_room_0_dl_books_004_mesh_layer_Opaque_vtx_0[20];
extern Gfx titan_room_0_dl_books_004_mesh_layer_Opaque_tri_0[];
extern Vtx titan_room_0_dl_books_004_mesh_layer_Opaque_vtx_1[203];
extern Gfx titan_room_0_dl_books_004_mesh_layer_Opaque_tri_1[];
extern Vtx titan_room_0_dl_books_005_mesh_layer_Opaque_vtx_0[20];
extern Gfx titan_room_0_dl_books_005_mesh_layer_Opaque_tri_0[];
extern Vtx titan_room_0_dl_books_005_mesh_layer_Opaque_vtx_1[203];
extern Gfx titan_room_0_dl_books_005_mesh_layer_Opaque_tri_1[];
extern Vtx titan_room_0_dl_books_007_mesh_layer_Opaque_vtx_0[20];
extern Gfx titan_room_0_dl_books_007_mesh_layer_Opaque_tri_0[];
extern Vtx titan_room_0_dl_books_007_mesh_layer_Opaque_vtx_1[203];
extern Gfx titan_room_0_dl_books_007_mesh_layer_Opaque_tri_1[];
extern Vtx titan_room_0_dl_books_008_mesh_layer_Opaque_vtx_0[20];
extern Gfx titan_room_0_dl_books_008_mesh_layer_Opaque_tri_0[];
extern Vtx titan_room_0_dl_books_008_mesh_layer_Opaque_vtx_1[203];
extern Gfx titan_room_0_dl_books_008_mesh_layer_Opaque_tri_1[];
extern Vtx titan_room_0_dl_books_009_mesh_layer_Opaque_vtx_0[20];
extern Gfx titan_room_0_dl_books_009_mesh_layer_Opaque_tri_0[];
extern Vtx titan_room_0_dl_books_009_mesh_layer_Opaque_vtx_1[203];
extern Gfx titan_room_0_dl_books_009_mesh_layer_Opaque_tri_1[];
extern Vtx titan_room_0_dl_books_011_mesh_layer_Opaque_vtx_0[20];
extern Gfx titan_room_0_dl_books_011_mesh_layer_Opaque_tri_0[];
extern Vtx titan_room_0_dl_books_011_mesh_layer_Opaque_vtx_1[203];
extern Gfx titan_room_0_dl_books_011_mesh_layer_Opaque_tri_1[];
extern Vtx titan_room_0_dl_books_012_mesh_layer_Opaque_vtx_0[20];
extern Gfx titan_room_0_dl_books_012_mesh_layer_Opaque_tri_0[];
extern Vtx titan_room_0_dl_books_012_mesh_layer_Opaque_vtx_1[203];
extern Gfx titan_room_0_dl_books_012_mesh_layer_Opaque_tri_1[];
extern Vtx titan_room_0_dl_books_013_mesh_layer_Opaque_vtx_0[20];
extern Gfx titan_room_0_dl_books_013_mesh_layer_Opaque_tri_0[];
extern Vtx titan_room_0_dl_books_013_mesh_layer_Opaque_vtx_1[203];
extern Gfx titan_room_0_dl_books_013_mesh_layer_Opaque_tri_1[];
extern Vtx titan_room_0_dl_books_014_mesh_layer_Opaque_vtx_0[20];
extern Gfx titan_room_0_dl_books_014_mesh_layer_Opaque_tri_0[];
extern Vtx titan_room_0_dl_books_014_mesh_layer_Opaque_vtx_1[203];
extern Gfx titan_room_0_dl_books_014_mesh_layer_Opaque_tri_1[];
extern Gfx mat_titan_room_0_dl_f3dlite_material_002_layerOpaque[];
extern Gfx mat_titan_room_0_dl_f3dlite_material_003_layerTransparent[];
extern Gfx mat_titan_room_0_dl_f3dlite_material_004_layerOpaque[];
extern Gfx mat_titan_room_0_dl_f3dlite_material_005_layerOpaque[];
extern Gfx mat_titan_room_0_dl_f3dlite_material_layerOpaque[];
extern Gfx mat_titan_room_0_dl_f3dlite_material_001_layerOpaque[];
extern Gfx titan_room_0_dl_bg_mesh_layer_Opaque[];
extern Gfx titan_room_0_dl_bg_mesh_layer_Transparent[];
extern Gfx titan_room_0_dl_books_mesh_layer_Opaque[];
extern Gfx titan_room_0_dl_books_004_mesh_layer_Opaque[];
extern Gfx titan_room_0_dl_books_005_mesh_layer_Opaque[];
extern Gfx titan_room_0_dl_books_007_mesh_layer_Opaque[];
extern Gfx titan_room_0_dl_books_008_mesh_layer_Opaque[];
extern Gfx titan_room_0_dl_books_009_mesh_layer_Opaque[];
extern Gfx titan_room_0_dl_books_011_mesh_layer_Opaque[];
extern Gfx titan_room_0_dl_books_012_mesh_layer_Opaque[];
extern Gfx titan_room_0_dl_books_013_mesh_layer_Opaque[];
extern Gfx titan_room_0_dl_books_014_mesh_layer_Opaque[];
extern RoomShapeNormal titan_room_0_shapeHeader;
extern RoomShapeDListsEntry titan_room_0_shapeDListsEntry[1];

#endif
