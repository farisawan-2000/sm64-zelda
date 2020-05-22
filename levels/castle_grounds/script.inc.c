	AREA(1, castle_grounds_area_1_level),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x01, LEVEL_CASTLE_GROUNDS, 2, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_NONE, -1401, 141, 3229, 0, 0, 0, 0x0a010000, bhvWarp),
		OBJECT(MODEL_NONE, -85, 452, -201, 0, 0, 0, 0x000A0000, bhvFadingWarp),
		MARIO_POS(0x01, 0, 7, 141, -6),
		TERRAIN(castle_grounds_area_1_collision),
		MACRO_OBJECTS(castle_grounds_area_1_Area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_EVENT_PIRANHA_PLANT),
		TERRAIN_TYPE(TERRAIN_GRASS),
	END_AREA(),

	AREA(2, castle_grounds_area_2_level),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(0xF1, 52, -1860, -16, 0, 0, 0, 0x00000000, bhv1Up),
		OBJECT(MODEL_NONE, 8, -1860, -1887, 0, 0, 0, 0x000A0000, bhvWarps74),
		TERRAIN(castle_grounds_area_2_collision),
		MACRO_OBJECTS(castle_grounds_area_2_Area_2_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_EVENT_PIRANHA_PLANT),
		TERRAIN_TYPE(TERRAIN_GRASS),
	END_AREA(),

