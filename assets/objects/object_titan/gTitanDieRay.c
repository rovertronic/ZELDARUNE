#include "gTitanDieRay.h"

Vtx gTitanDieRay_gTitanDieRay_mesh_layer_Transparent_vtx_cull[8] = {
	{{ {-10876, -5675, -10876}, 0, {0, 0}, {0, 0, 0, 0} }},
	{{ {-10876, -5675, 10876}, 0, {0, 0}, {0, 0, 0, 0} }},
	{{ {-10876, 22774, 10876}, 0, {0, 0}, {0, 0, 0, 0} }},
	{{ {-10876, 22774, -10876}, 0, {0, 0}, {0, 0, 0, 0} }},
	{{ {10876, -5675, -10876}, 0, {0, 0}, {0, 0, 0, 0} }},
	{{ {10876, -5675, 10876}, 0, {0, 0}, {0, 0, 0, 0} }},
	{{ {10876, 22774, 10876}, 0, {0, 0}, {0, 0, 0, 0} }},
	{{ {10876, 22774, -10876}, 0, {0, 0}, {0, 0, 0, 0} }},
};

Vtx gTitanDieRay_gTitanDieRay_mesh_layer_Transparent_vtx_0[32] = {
	{{ {0, -5675, -10876}, 0, {479, 1084}, {49, 0, 139, 255} }},
	{{ {0, 22774, -10876}, 0, {479, -173}, {49, 0, 139, 255} }},
	{{ {7691, 22774, -7691}, 0, {947, -173}, {49, 0, 139, 255} }},
	{{ {7691, -5675, -7691}, 0, {947, 1084}, {49, 0, 139, 255} }},
	{{ {7691, -5675, -7691}, 0, {947, 1084}, {117, 0, 207, 255} }},
	{{ {7691, 22774, -7691}, 0, {947, -173}, {117, 0, 207, 255} }},
	{{ {10876, 22774, 0}, 0, {1140, -173}, {117, 0, 207, 255} }},
	{{ {10876, -5675, 0}, 0, {1140, 1084}, {117, 0, 207, 255} }},
	{{ {10876, -5675, 0}, 0, {1140, 1084}, {117, 0, 49, 255} }},
	{{ {10876, 22774, 0}, 0, {1140, -173}, {117, 0, 49, 255} }},
	{{ {7691, 22774, 7691}, 0, {947, -173}, {117, 0, 49, 255} }},
	{{ {7691, -5675, 7691}, 0, {947, 1084}, {117, 0, 49, 255} }},
	{{ {7691, -5675, 7691}, 0, {947, 1084}, {49, 0, 117, 255} }},
	{{ {7691, 22774, 7691}, 0, {947, -173}, {49, 0, 117, 255} }},
	{{ {0, 22774, 10876}, 0, {479, -173}, {49, 0, 117, 255} }},
	{{ {0, -5675, 10876}, 0, {479, 1084}, {49, 0, 117, 255} }},
	{{ {0, -5675, 10876}, 0, {479, 1084}, {207, 0, 117, 255} }},
	{{ {0, 22774, 10876}, 0, {479, -173}, {207, 0, 117, 255} }},
	{{ {-7691, 22774, 7691}, 0, {12, -173}, {207, 0, 117, 255} }},
	{{ {-7691, -5675, 7691}, 0, {12, 1084}, {207, 0, 117, 255} }},
	{{ {-7691, -5675, 7691}, 0, {12, 1084}, {139, 0, 49, 255} }},
	{{ {-7691, 22774, 7691}, 0, {12, -173}, {139, 0, 49, 255} }},
	{{ {-10876, 22774, 0}, 0, {-182, -173}, {139, 0, 49, 255} }},
	{{ {-10876, -5675, 0}, 0, {-182, 1084}, {139, 0, 49, 255} }},
	{{ {-10876, -5675, 0}, 0, {-182, 1084}, {139, 0, 207, 255} }},
	{{ {-10876, 22774, 0}, 0, {-182, -173}, {139, 0, 207, 255} }},
	{{ {-7691, 22774, -7691}, 0, {12, -173}, {139, 0, 207, 255} }},
	{{ {-7691, -5675, -7691}, 0, {12, 1084}, {139, 0, 207, 255} }},
	{{ {-7691, -5675, -7691}, 0, {12, 1084}, {207, 0, 139, 255} }},
	{{ {-7691, 22774, -7691}, 0, {12, -173}, {207, 0, 139, 255} }},
	{{ {0, 22774, -10876}, 0, {479, -173}, {207, 0, 139, 255} }},
	{{ {0, -5675, -10876}, 0, {479, 1084}, {207, 0, 139, 255} }},
};

Gfx gTitanDieRay_gTitanDieRay_mesh_layer_Transparent_tri_0[] = {
	gsSPVertex(gTitanDieRay_gTitanDieRay_mesh_layer_Transparent_vtx_0 + 0, 32, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
	gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
	gsSP2Triangles(8, 9, 10, 0, 8, 10, 11, 0),
	gsSP2Triangles(12, 13, 14, 0, 12, 14, 15, 0),
	gsSP2Triangles(16, 17, 18, 0, 16, 18, 19, 0),
	gsSP2Triangles(20, 21, 22, 0, 20, 22, 23, 0),
	gsSP2Triangles(24, 25, 26, 0, 24, 26, 27, 0),
	gsSP2Triangles(28, 29, 30, 0, 28, 30, 31, 0),
	gsSPEndDisplayList(),
};

Gfx mat_gTitanDieRay_dieRay_layerTransparent[] = {
	gsSPLoadGeometryMode(G_LIGHTING | G_CULL_BACK | G_SHADING_SMOOTH | G_ZBUFFER | G_FOG | G_SHADE),
	gsDPPipeSync(),
	gsDPSetCombineLERP(0, 0, 0, 1, 0, 0, 0, PRIMITIVE, COMBINED, 0, PRIMITIVE, 0, 0, 0, 0, ENVIRONMENT),
	gsSPSetOtherMode(G_SETOTHERMODE_H, 4, 20, G_CD_MAGICSQ | G_CYC_2CYCLE | G_AD_NOISE | G_TD_CLAMP | G_TC_FILT | G_TP_PERSP | G_PM_NPRIMITIVE | G_TT_NONE | G_TF_BILERP | G_TL_TILE | G_CK_NONE),
	gsSPSetOtherMode(G_SETOTHERMODE_L, 0, 32, G_ZS_PIXEL | G_RM_FOG_SHADE_A | G_RM_AA_ZB_XLU_SURF2 | G_AC_NONE),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsSPEndDisplayList(),
};

Gfx gTitanDieRay_transparent_dl[] = {
	gsSPClearGeometryMode(G_LIGHTING),
	gsSPVertex(gTitanDieRay_gTitanDieRay_mesh_layer_Transparent_vtx_cull + 0, 8, 0),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPCullDisplayList(0, 7),
	gsSPDisplayList(mat_gTitanDieRay_dieRay_layerTransparent),
	gsSPDisplayList(gTitanDieRay_gTitanDieRay_mesh_layer_Transparent_tri_0),
	gsSPEndDisplayList(),
};

