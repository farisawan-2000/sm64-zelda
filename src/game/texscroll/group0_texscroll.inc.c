#include "actors/group0.h"
#include "actors/myCamera/texscroll.inc.c"
#include "actors/mower/texscroll.inc.c"
#include "actors/bush/texscroll.inc.c"
#include "actors/rake/texscroll.inc.c"
void scroll_textures_group0() {
	scroll_actor_geo_myCamera();

	scroll_actor_geo_mower();

	scroll_actor_geo_bush();

	scroll_actor_geo_rake();

}
