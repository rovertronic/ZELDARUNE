#include "titan_scene.h"

Vec3s titan_scene_camPosData[] = {
    {     80,    173,   -173 },
    { 0x1718, 0xF2C0, 0x0000 },
    {   3960,     -1,     -1 },
};

BgCamInfo titan_scene_bgCamInfo[] = {
    { CAM_SET_NORMAL0, 3, &titan_scene_camPosData[0] },
};

SurfaceType titan_scene_polygonTypes[1] = {
    { SURFACETYPE0(0, 0, 0x00, 0, 0x00, 0x0C, 0, 0), SURFACETYPE1(0x00, 0x00, 0, 0, 0, 0, 0, 0) },
};

Vec3s titan_scene_vertices[4] = {
    {  -1506,   -317,   1506 },
    {   1506,   -317,   1506 },
    {   1506,   -317,  -1506 },
    {  -1506,   -317,  -1506 },
};

CollisionPoly titan_scene_polygons[2] = {
    { 0, COLPOLY_VTX(0, COLPOLY_IGNORE_NONE), COLPOLY_VTX(1, COLPOLY_IGNORE_NONE), COLPOLY_VTX_INDEX(2), { COLPOLY_SNORMAL(0.0), COLPOLY_SNORMAL(1.0), COLPOLY_SNORMAL(7.549790126404332e-08) }, 317 },
    { 0, COLPOLY_VTX(0, COLPOLY_IGNORE_NONE), COLPOLY_VTX(2, COLPOLY_IGNORE_NONE), COLPOLY_VTX_INDEX(3), { COLPOLY_SNORMAL(0.0), COLPOLY_SNORMAL(1.0), COLPOLY_SNORMAL(7.549790126404332e-08) }, 317 },
};

CollisionHeader titan_scene_collisionHeader = {
    { -1506, -317, -1506 },
    { 1506, -317, 1506 },
    ARRAY_COUNT(titan_scene_vertices), titan_scene_vertices,
    ARRAY_COUNT(titan_scene_polygons), titan_scene_polygons,
    titan_scene_polygonTypes,
    titan_scene_bgCamInfo,
    0, NULL
};

