#include "types.h"
#include "include/segment_symbols.h"
#include "memory.h"
#include "engine/math_util.h"
#include "src/engine/behavior_script.h"
#include "texscroll.h"


#include "src/game/texscroll/bob_texscroll.inc.c"
#include "src/game/texscroll/castle_grounds_texscroll.inc.c"
#include "src/game/texscroll/group0_texscroll.inc.c"
void scroll_textures() {
	if(sSegmentROMTable[0x7] == (uintptr_t)_bob_segment_7SegmentRomStart) {
		scroll_textures_bob();
	}

	if(sSegmentROMTable[0x7] == (uintptr_t)_castle_grounds_segment_7SegmentRomStart) {
		scroll_textures_castle_grounds();
	}

	if(sSegmentROMTable[0x4] == (uintptr_t)_group0_mio0SegmentRomStart) {
		scroll_textures_group0();
	}

}
