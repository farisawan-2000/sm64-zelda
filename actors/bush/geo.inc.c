const GeoLayout bush_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_ANIMATED_PART(1, 0, 0, 0, bush_Icosphere_mesh),
		GEO_DISPLAY_LIST(0, bush_material_revert_render_settings),
		GEO_DISPLAY_LIST(1, bush_material_revert_render_settings),
		GEO_DISPLAY_LIST(2, bush_material_revert_render_settings),
		GEO_DISPLAY_LIST(3, bush_material_revert_render_settings),
		GEO_DISPLAY_LIST(4, bush_material_revert_render_settings),
		GEO_DISPLAY_LIST(5, bush_material_revert_render_settings),
		GEO_DISPLAY_LIST(6, bush_material_revert_render_settings),
		GEO_DISPLAY_LIST(7, bush_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};