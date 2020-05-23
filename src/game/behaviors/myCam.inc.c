void bhv_mycam_init(void) {
	cur_obj_scale(0.125f);
	gCurrentObject->header.gfx.node.flags |= GRAPH_RENDER_ACTIVE;
}

void bhv_mycam_loop(void) {
	o->header.gfx.angle[1] += 0x300;
	if (o->oDistanceToMario < 200.0f) {
		obj_mark_for_deletion(o);
		gMarioState->numCameras++;
	}
}