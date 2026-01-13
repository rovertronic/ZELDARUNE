#ifndef GTITANSKELANIME_H
#define GTITANSKELANIME_H

#include "ultra64.h"
#include "array_count.h"
#include "animation.h"
#include "object_titan.h"

extern u64 gTitanSkelanime_titanFace_i8[];
extern u64 gTitanSkelanime_wing_i8[];
extern Vtx gTitanSkelanime_body_mesh_layer_Opaque_vtx_0[234];
extern Gfx gTitanSkelanime_body_mesh_layer_Opaque_tri_0[];
extern Vtx gTitanSkelanime_wing1_mesh_layer_Opaque_vtx_0[405];
extern Gfx gTitanSkelanime_wing1_mesh_layer_Opaque_tri_0[];
extern Vtx gTitanSkelanime_wing2_mesh_layer_Opaque_vtx_0[405];
extern Gfx gTitanSkelanime_wing2_mesh_layer_Opaque_tri_0[];
extern Vtx gTitanSkelanime_wing3_mesh_layer_Opaque_vtx_0[419];
extern Gfx gTitanSkelanime_wing3_mesh_layer_Opaque_tri_0[];
extern Gfx mat_gTitanSkelanime_f3dlite_material_006_layerOpaque[];
extern Gfx mat_gTitanSkelanime_f3dlite_material_layerOpaque[];
extern Gfx gTitanSkelanime_body_mesh_layer_Opaque[];
extern Gfx gTitanSkelanime_wing1_mesh_layer_Opaque[];
extern Gfx gTitanSkelanime_wing2_mesh_layer_Opaque[];
extern Gfx gTitanSkelanime_wing3_mesh_layer_Opaque[];
extern SkeletonHeader gTitanSkelanime;
#define GTITANSKELANIME_BODY_POS_LIMB 0
#define GTITANSKELANIME_BODY_ROT_LIMB 1
#define GTITANSKELANIME_WING1_LIMB 2
#define GTITANSKELANIME_WING2_LIMB 3
#define GTITANSKELANIME_WING3_LIMB 4
#define GTITANSKELANIME_NUM_LIMBS 5

#endif
