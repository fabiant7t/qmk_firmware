#include "fabian.h"


// I opted for an extra row of keys for the outer columns: https://github.com/fabiant7t/dactyl-manuform
// It gives me a proper 4x6 matrix, but those keys are pretty much out of reach and should not be used.
#undef LAYOUT
#define LAYOUT( \
    L00, L01, L02, L03, L04, L05,                    R00, R01, R02, R03, R04, R05, \
    L10, L11, L12, L13, L14, L15,                    R10, R11, R12, R13, R14, R15, \
    L20, L21, L22, L23, L24, L25,                    R20, R21, R22, R23, R24, R25, \
    L30, L31, L32, L33, L34, L35,                    R30, R31, R32, R33, R34, R35, \
                        L44, L45,                    R40, R41, \
                        L42, L43,                    R42, R43 \
) { \
    { L00, L01, L02, L03, L04, L05 }, \
    { L10, L11, L12, L13, L14, L15 }, \
    { L20, L21, L22, L23, L24, L25 }, \
    { L30, L31, L32, L33, L34, L35 }, \
    { XXX, XXX, L42, L43, L44, L45 }, \
\
    { R00, R01, R02, R03, R04, R05 }, \
    { R10, R11, R12, R13, R14, R15 }, \
    { R20, R21, R22, R23, R24, R25 }, \
    { R30, R31, R32, R33, R34, R35 }, \
    { R40, R41, R42, R43, XXX, XXX } \
}

#define LAYOUT_wrapper(...) LAYOUT(__VA_ARGS__)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_wrapper(
        ___________________QWERTY_L1_____________________,               ___________________QWERTY_R1_____________________,
        ___________________QWERTY_L2_____________________,               ___________________QWERTY_R2_____________________,
        ___________________QWERTY_L3_____________________,               ___________________QWERTY_R3_____________________,
        ___________________GENERIC_L4____________________,               ___________________GENERIC_R4____________________,
                                         TC_L5_0, TC_L5_1,               TC_R5_0, TC_R5_1,
                                         TC_L6_0, TC_L6_1,               TC_R6_0, TC_R6_1
    ),
    [_COLEMAK] = LAYOUT_wrapper(
        ___________________COLEMAK_L0____________________,               ___________________COLEMAK_R1____________________,
        ___________________COLEMAK_L2____________________,               ___________________COLEMAK_R2____________________,
        ___________________COLEMAK_L3____________________,               ___________________COLEMAK_R3____________________,
        ___________________GENERIC_L4____________________,               ___________________GENERIC_R4____________________,
                                         TC_L5_0, TC_L5_1,               TC_R5_0, TC_R5_1,
                                         TC_L6_0, TC_L6_1,               TC_R6_0, TC_R6_1
    ),
    [_LOWER] = LAYOUT_wrapper(
        ____________________LOWER_L1_____________________,               ____________________LOWER_R1_____________________,
        ____________________LOWER_L2_____________________,               ____________________LOWER_R2_____________________,
        ____________________LOWER_L3_____________________,               ____________________LOWER_R3_____________________,
        ___________________GENERIC_L4____________________,               ___________________GENERIC_R4____________________,
                                         TC_L5_0, TC_L5_1,               TC_R5_0, TC_R5_1,
                                         TC_L6_0, TC_L6_1,               TC_R6_0, TC_R6_1
    ),
    [_RAISE] = LAYOUT_wrapper(
        ____________________RAISE_L1_____________________,               ____________________RAISE_R1_____________________,
        ____________________RAISE_L2_____________________,               ____________________RAISE_R2_____________________,
        ____________________RAISE_L3_____________________,               ____________________RAISE_R3_____________________,
        ___________________GENERIC_L4____________________,               ___________________GENERIC_R4____________________,
                                         TC_L5_0, TC_L5_1,               TC_R5_0, TC_R5_1,
                                         TC_L6_0, TC_L6_1,               TC_R6_0, TC_R6_1
    ),
    [_ADJUST] = LAYOUT_wrapper(
        ____________________ADJUST_L1____________________,               ____________________ADJUST_R1____________________,
        ____________________ADJUST_L2____________________,               ____________________ADJUST_R2____________________,
        ____________________ADJUST_L3____________________,               ____________________ADJUST_R3____________________,
        ___________________GENERIC_L4____________________,               ___________________GENERIC_R4____________________,
                                         TC_L5_0, TC_L5_1,               TC_R5_0, TC_R5_1,
                                         TC_L6_0, TC_L6_1,               TC_R6_0, TC_R6_1
    )
};

void persistent_default_layer_set(uint16_t default_layer) {
    eeconfig_update_default_layer(default_layer);
    default_layer_set(default_layer);
}
