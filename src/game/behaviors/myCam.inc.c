// #define m gMarioState
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


void mower_ride(struct Object *b, struct MarioState *m) {
	b->oPosX = m->pos[0];
	b->oPosY = m->pos[1] + 125.0f;
	b->oPosZ = m->pos[2];
	// b->header.gfx.angle[1] = m->faceAngle[1];
	// // vec3f_set(o->header.gfx.angle, 0, m->faceAngle[1], 0);
	// m->forwardVel = 30.f;
}
extern u8 nextQuote, currentQuote;
#include "src/game/debug.h"
void mower_loop(void) {
	struct MarioState *m = gMarioState;
	if (o) {
		// print_text_fmt_int(55, 55, "%d", m->ridingMower);
		if (o->oDistanceToMario < 500.0f && currentQuote != 3 && m->ridingMower != 1) {
			nextQuote = (nextQuote != 3 ? 3 : 0);
		}
		if (o->oDistanceToMario < 550.f && gPlayer1Controller->buttonPressed & L_TRIG) {
			m->ridingMower ^= 1;
		}
		if (m->ridingMower) {
			// f32 temp = o->header.gfx.pos[1];
			mower_ride(o, m);
			
			// o->header.gfx.pos[1] = temp;
			// o->header.gfx.angle[1] = m->faceAngle[1];
			o->oFaceAngleYaw = m->faceAngle[1] + 0x8000;
			m->forwardVel = 30.f;
		}
		if ((m->action == ACT_HARD_BACKWARD_GROUND_KB) && (m->ridingMower == 1)) {
			m->ridingMower = 0;
			obj_yeet(46.0f);
			o->oPosX = o->oHomeX;
			o->oPosY = o->oHomeY;
			o->oPosZ = o->oHomeZ;
			cur_obj_enable();
		}
	}

}
int numBushes = 52;
void bush_loop(void) {
	struct Object *mower = cur_obj_nearest_object_with_behavior(bhvMower);
	f32 dist = lateral_dist_between_objects(o, mower);
	// o->oFaceAngleYaw += 0x300;
	if (dist < 300.0f) {
		obj_explode_and_spawn_coins(46.0f, 0);
		numBushes--;
		if (numBushes == 0) {
			spawn_object(o, 0xF4, bhvMessagePanel);
		}
	}
}
#define RAKE_FALLING 1
#define RAKE_PRIME 0
#define RAKE_SPEED 0x1000

void rake_loop(void) {
	struct MarioState *m = gMarioState;
	if (o->oDistanceToMario < 150.f && o->oBehParams2ndByte != RAKE_FALLING) {
		o->oFaceAnglePitch -= RAKE_SPEED;
	} else {
		o->oFaceAnglePitch += RAKE_SPEED;
	}

	if (o->oFaceAnglePitch < -0x4000) {
		o->oFaceAnglePitch = -0x4000;
			drop_and_set_mario_action(m, ACT_HARD_BACKWARD_GROUND_KB, 0);
			if (m->ridingMower == 1){
				m->forwardVel = -5000.0f;
				m->vel[1] = 300.f;
			}
			else
				m->forwardVel = -30.0f;

		o->oBehParams2ndByte = RAKE_FALLING;
	}
	if (o->oFaceAnglePitch > 0){
		o->oFaceAnglePitch = 0;
		o->oBehParams2ndByte = RAKE_PRIME;
	}
}
