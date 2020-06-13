void bhv_mycam_init(void) {
	cur_obj_scale(0.125f);
	gCurrentObject->header.gfx.node.flags |= GRAPH_RENDER_ACTIVE;
}

s32 myCamTimer = 0;

void bhv_mycam_loop(void) {
	o->header.gfx.angle[1] += 0x300;
	if (o->oDistanceToMario < 200.0f && myCamTimer == 0) {
		myCamTimer = 100;
		cur_obj_disable();
		gMarioState->numCameras++;
	}
	myCamTimer -= 1;
	if (myCamTimer <= 0) {
		cur_obj_enable();
		myCamTimer = 0;
	}
}

extern u8 nextQuote;
#include "src/game/debug.h"
void mower_loop(void) {
	print_text_fmt_int(55, 55, "%d", (u32)o->oDistanceToMario);
	if (o->oDistanceToMario < 500.0f && textState == TEXT_IDLE) {
		nextQuote = (nextQuote != 3 ? 3 : 0);
	}
}

void bush_loop(void) {
	o->header.gfx.angle[1] += 0x300;
	
}