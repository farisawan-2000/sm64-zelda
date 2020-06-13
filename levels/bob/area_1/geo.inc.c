const GeoLayout bob_area_1_myLevel[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_ANIMATED_PART(1, 0, 0, 0, NULL),
		GEO_OPEN_NODE(),
			GEO_ANIMATED_PART(1, 0, 0, 0, NULL),
			GEO_OPEN_NODE(),
				GEO_ANIMATED_PART(1, 0, 0, 0, bob_Cube_mesh),
				GEO_ANIMATED_PART(1, -2129, 226, 2129, bob_Cylinder_mesh),
				GEO_ANIMATED_PART(1, 2133, 226, 2129, bob_Cylinder_001_mesh),
				GEO_ANIMATED_PART(1, -1778, -74, 4381, bob_Cylinder_002_mesh),
				GEO_ANIMATED_PART(1, 1837, -74, 4381, bob_Cylinder_003_mesh),
				GEO_ANIMATED_PART(1, -2129, 226, 2129, bob_Cylinder_004_mesh),
				GEO_ANIMATED_PART(1, -8510, -428, -27870, bob_Cylinder_005_mesh),
				GEO_ANIMATED_PART(1, -144, -428, -27870, bob_Cylinder_006_mesh),
				GEO_ANIMATED_PART(1, -144, -428, -27870, bob_Cylinder_007_mesh),
				GEO_ANIMATED_PART(1, -144, -428, -32125, bob_Cylinder_008_mesh),
				GEO_ANIMATED_PART(1, -144, -428, -32125, bob_Cylinder_009_mesh),
				GEO_ANIMATED_PART(1, -1099, -428, -32125, bob_Cylinder_011_mesh),
				GEO_ANIMATED_PART(1, 3150, -428, -32125, bob_Cylinder_012_mesh),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout bob_area_1_level[] = {
	GEO_NODE_SCREEN_AREA(10, SCREEN_WIDTH/2, SCREEN_HEIGHT/2, SCREEN_WIDTH/2, SCREEN_HEIGHT/2),
	GEO_OPEN_NODE(),
		GEO_ZBUFFER(0),
		GEO_OPEN_NODE(),
			GEO_NODE_ORTHO(100.0000),
			GEO_OPEN_NODE(),
				GEO_BACKGROUND_COLOR(0x077F),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_ZBUFFER(1),
		GEO_OPEN_NODE(),
			GEO_CAMERA_FRUSTUM_WITH_FUNC(45.0000, 100, 30000, geo_camera_fov),
			GEO_OPEN_NODE(),
				GEO_CAMERA(1, 0, 0, 0, 0, -213, 0, geo_camera_main),
				GEO_OPEN_NODE(),
					GEO_BRANCH(1, bob_area_1_myLevel),
					GEO_RENDER_OBJ(),
					GEO_ASM(0, geo_envfx_main),
				GEO_CLOSE_NODE(),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(0, bob_material_revert_render_settings),
		GEO_DISPLAY_LIST(1, bob_material_revert_render_settings),
		GEO_DISPLAY_LIST(2, bob_material_revert_render_settings),
		GEO_DISPLAY_LIST(3, bob_material_revert_render_settings),
		GEO_DISPLAY_LIST(4, bob_material_revert_render_settings),
		GEO_DISPLAY_LIST(5, bob_material_revert_render_settings),
		GEO_DISPLAY_LIST(6, bob_material_revert_render_settings),
		GEO_DISPLAY_LIST(7, bob_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
