const GeoLayout keycard_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_ANIMATED_PART(1, 0, 0, 0, keycard_Cube_mesh),
		GEO_DISPLAY_LIST(0, keycard_material_revert_render_settings),
		GEO_DISPLAY_LIST(1, keycard_material_revert_render_settings),
		GEO_DISPLAY_LIST(2, keycard_material_revert_render_settings),
		GEO_DISPLAY_LIST(3, keycard_material_revert_render_settings),
		GEO_DISPLAY_LIST(4, keycard_material_revert_render_settings),
		GEO_DISPLAY_LIST(5, keycard_material_revert_render_settings),
		GEO_DISPLAY_LIST(6, keycard_material_revert_render_settings),
		GEO_DISPLAY_LIST(7, keycard_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
