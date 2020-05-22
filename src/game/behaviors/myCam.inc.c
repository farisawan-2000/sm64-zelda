void bhv_mycam_init(void) {
	cur_obj_scale(0.5f);
}

void bhv_mycam_loop(void) {
	o->header.gfx.angle[1] += 0x300;
}