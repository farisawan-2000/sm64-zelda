#define NC_MODE_NORMAL            0x0
#define NC_MODE_FIXED             0x1
#define NC_MODE_2D                0x2
#define NC_MODE_8D                0x3
#define NC_MODE_FIXED_NOMOVE      0x4
#define NC_MODE_NOTURN            0x5
// #define NEWCAM_DEBUG


extern void newcam_display_options();
extern void newcam_text(s16, s16, u8[], u8);
extern void newcam_check_pause_buttons();

extern u8 newcam_option_open;

extern u8 newcam_sensitivityX; //How quick the camera works.
extern u8 newcam_sensitivityY;
extern u8 newcam_invertX;
extern u8 newcam_invertY;
extern u8 newcam_panlevel; //How much the camera sticks out a bit in the direction you're looking.
extern u8 newcam_aggression; //How much the camera tries to centre itself to Mario's facing and movement.
extern u8 newcam_active; // basically the thing that governs if newcam is on.
extern u16 sSoundMode;
extern u8 newcam_analogue;
extern u8 newcam_intendedmode;

extern u8 newcam_options[][64];

extern u8 newcam_mode;
extern s16 newcam_yaw;
extern s16 newcam_tilt;
extern u32 newcam_distance_target;

