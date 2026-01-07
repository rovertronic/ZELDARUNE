#include "titan_scene.h"

RoomShapeNormal titan_room_0_shapeHeader = {
    ROOM_SHAPE_TYPE_NORMAL,
    ARRAY_COUNT(titan_room_0_shapeDListsEntry),
    titan_room_0_shapeDListsEntry,
    titan_room_0_shapeDListsEntry + ARRAY_COUNT(titan_room_0_shapeDListsEntry)
};

RoomShapeDListsEntry titan_room_0_shapeDListsEntry[1] = {
    { titan_room_0_shapeHeader_entry_0_opaque, titan_room_0_shapeHeader_entry_0_transparent }
};

