#include <ultra64.h>

#include "sm64.h"
#include "game/level_update.h"
#include "game/debug.h"
#include "game/camera.h"
#include "game/mario.h"
#include "behavior_script.h"
#include "surface_collision.h"
#include "surface_load.h"
#include "game/object_list_processor.h"
#include "math_util.h"
struct Surface *epic(struct SurfaceNode *surfaceNode, s32 x, s32 y, s32 z,
                                            f32 *pheight) {
    register struct Surface *surf;
    register s32 x1, z1, x2, z2, x3, z3;
    f32 nx, ny, nz;
    f32 oo;
    f32 height;
    struct Surface *floor = NULL;

    // Iterate through the list of floors until there are no more floors.
    while (surfaceNode != NULL) {
        surf = surfaceNode->surface;
        surfaceNode = surfaceNode->next;
        // Determine if we are checking for the camera or not.
        if (gCurrentObject == gMarioObject && gMarioObject != NULL
            && gMarioState->flags & MARIO_VANISH_CAP && surf->type == SURFACE_VANISH_CAP_WALLS) {
            continue;
        }

        if (gCurrentObject == NULL) {
            continue;
        }
        if (gMarioObject == NULL) {
            continue;
        }
    }

    //! (Surface Cucking) Since only the first floor is returned and not the highest,
    //  higher floors can be "cucked" by lower floors.
    return floor;
}