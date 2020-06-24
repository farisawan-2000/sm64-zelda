// #define m gMarioState
extern u8 isPowerUpInUse;
extern void warp_mario(struct MarioState *m, u8 timer, u8 node);
void bhv_mycam_init(void) {
	cur_obj_scale(0.125f);
	gCurrentObject->header.gfx.node.flags |= GRAPH_RENDER_ACTIVE;
}

s32 myCamTimer = 0;

void bhv_mycam_loop(void) {
	struct Object *d = cur_obj_nearest_object_with_behavior(bhv2D);
	o->oFaceAngleYaw += 0x300;
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
	if (d && !isPowerUpInUse) {
		u8 flag = d->oBehParams >> 24;
		if (flag) {
			o->oPosX = d->oPosX;
		} else {
			o->oPosZ = d->oPosZ;
		}
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
		if (o->oDistanceToMario < 500.0f && currentQuote != 3 && m->ridingMower != 1 && gCurrLevelNum == LEVEL_BOB) {
			nextQuote = (nextQuote != 3 ? 3 : 0);
		}
		if (o->oDistanceToMario < 500.0f && currentQuote != 5 && m->ridingMower != 1 && gCurrLevelNum == LEVEL_WF) {
			nextQuote = (nextQuote != 5 ? 5 : 0);
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
	}
}

void lock_mario(void) {
	u16 flag = (o->oBehParams >> 24) & 0xFF;
	struct Object *cam = cur_obj_nearest_object_with_behavior(bhvMyCamera);
	// u16 pos = o->oBehParams >> 16;
	if (!isPowerUpInUse) {	
		if (flag) {
			gMarioState->pos[0] = o->oPosX;
		} else {
			gMarioState->pos[2] = o->oPosZ;
		}
	} else {
		if (flag) {
			o->oPosX = gMarioState->pos[0];
		} else {
			o->oPosZ = gMarioState->pos[2];
		}
	}
}

#define RAKE_FALLING 1
#define RAKE_PRIME 0
#define RAKE_SPEED 0x1000

void rake_loop(void) {
	struct MarioState *m = gMarioState;
	if (m->ridingMower == 0){
		if (o->oDistanceToMario  < 150.f && o->oBehParams2ndByte != RAKE_FALLING) {
			o->oFaceAnglePitch -= RAKE_SPEED;
		} else {
			o->oFaceAnglePitch += RAKE_SPEED;
		}
	} else {
		if (o->oDistanceToMario  < 250.f && o->oBehParams2ndByte != RAKE_FALLING) {
			o->oFaceAnglePitch -= RAKE_SPEED;
		} else {
			o->oFaceAnglePitch += RAKE_SPEED;
		}
	}

	if (o->oFaceAnglePitch < -0x4000) {
		o->oFaceAnglePitch = -0x4000;
			if (gCurrLevelNum == LEVEL_WF){
				gMarioObject->oInteractStatus |= INT_STATUS_MARIO_UNK2;
				gMarioStates->forwardVel = -450.0f;
            	gMarioStates->vel[1] = 950.0f;
            	m->pos[1] += 105.f;
            	m->numDeaths = 42069;
			}
			else{
				drop_and_set_mario_action(m, ACT_HARD_BACKWARD_GROUND_KB, 0);
				m->forwardVel = -30.0f;
			}

		o->oBehParams2ndByte = RAKE_FALLING;
	}
	if (o->oFaceAnglePitch > 0){
		o->oFaceAnglePitch = 0;
		o->oBehParams2ndByte = RAKE_PRIME;
		if (m->numDeaths == 42069) {
			struct Object *y = cur_obj_nearest_object_with_behavior(bhvWarps74);
			vec3f_copy(m->pos, y->header.gfx.pos);
			vec3f_copy(m->marioObj->header.gfx.pos, y->header.gfx.pos);
			m->vel[1] = 0;
			m->forwardVel = 0;
			m->numDeaths = 0;
		}
	}
}

void bhv_keyinit(void) {
	cur_obj_scale(0.125f);
	if (o->oBehParams2ndByte == 1) {
		cur_obj_disable();
	}
}

void key(void) {
	o->oFaceAngleYaw += 0x300;
	o->oFaceAnglePitch = 0x9000;
	if (o->oDistanceToMario  < 300.f && o->header.gfx.node.flags & GRAPH_RENDER_ACTIVE) {
		obj_mark_for_deletion(o);
		gMarioState->numStars++;
		warp_mario(gMarioState, 20, 0x1);
		gMarioState->ridingMower = 0;
	}
	if (numBushes == 0 && o->oBehParams2ndByte == 1) {
		cur_obj_enable();
	}

}

void warp(void) {
	f32 dist = (o->oBehParams >> 24) * 10;
	if (o->oDistanceToMario < dist) {
		warp_mario(gMarioState, 20, o->oBehParams2ndByte);
		o->oBehParams = o->oBehParams & 0x00FFFFFF;
		gMarioState->ridingMower = 0;
	}
}

void bhvKeycardLoop(void)
{
	if (o->header.gfx.sharedChild == NULL){ 
		warp();
	}
	else {
		key();
	}
}

