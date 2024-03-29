#include "fabian.h"


#define LAYOUT_wrapper(...) LAYOUT_ortho_5x15(__VA_ARGS__)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_wrapper(
        ___________________QWERTY_L0_____________________, _______, _______, _______, ___________________QWERTY_R0_____________________,
        ___________________QWERTY_L1_____________________, _______, _______, _______, ___________________QWERTY_R1_____________________,
        ___________________QWERTY_L2_____________________, _______, _______, _______, ___________________QWERTY_R2_____________________,
        ___________________QWERTY_L3_____________________, _______, _______, _______, ___________________QWERTY_R3_____________________,
        ___________________GENERIC_L4____________________, NAVIG,   _______, _______, ___________________GENERIC_R4____________________
    ),
    [_COLEMAK] = LAYOUT_wrapper(
        ___________________COLEMAK_L0____________________, _______, _______, _______, ___________________COLEMAK_R0____________________,
        ___________________COLEMAK_L1____________________, _______, _______, _______, ___________________COLEMAK_R1____________________,
        ___________________COLEMAK_L2____________________, _______, _______, _______, ___________________COLEMAK_R2____________________,
        ___________________COLEMAK_L3____________________, _______, _______, _______, ___________________COLEMAK_R3____________________,
        ___________________GENERIC_L4____________________, NAVIG,   _______, _______, ___________________GENERIC_R4____________________
    ),
    [_LOWER] = LAYOUT_wrapper(
        ____________________LOWER_L0_____________________, _______, _______, _______, ____________________LOWER_R0_____________________,
        ____________________LOWER_L1_____________________, _______, _______, _______, ____________________LOWER_R1_____________________,
        ____________________LOWER_L2_____________________, _______, _______, _______, ____________________LOWER_R2_____________________,
        ____________________LOWER_L3_____________________, _______, _______, _______, ____________________LOWER_R3_____________________,
        ___________________GENERIC_L4____________________, _______, _______, _______, ___________________GENERIC_R4____________________
    ),
    [_RAISE] = LAYOUT_wrapper(
        ____________________RAISE_L0_____________________, _______, _______, _______, ____________________RAISE_R0_____________________,
        ____________________RAISE_L1_____________________, _______, _______, _______, ____________________RAISE_R1_____________________,
        ____________________RAISE_L2_____________________, _______, _______, _______, ____________________RAISE_R2_____________________,
        ____________________RAISE_L3_____________________, _______, _______, _______, ____________________RAISE_R3_____________________,
        ___________________GENERIC_L4____________________, _______, _______, _______, ___________________GENERIC_R4____________________
    ),
    [_ADJUST] = LAYOUT_wrapper(
        ____________________ADJUST_L0____________________, _______, _______, _______, ____________________ADJUST_R0____________________,
        ____________________ADJUST_L1____________________, _______, _______, _______, ____________________ADJUST_R1____________________,
        ____________________ADJUST_L2____________________, _______, _______, _______, ____________________ADJUST_R2____________________,
        ____________________ADJUST_L3____________________, _______, _______, _______, ____________________ADJUST_R3____________________,
        ___________________GENERIC_L4____________________, _______, _______, _______, ___________________GENERIC_R4____________________
    ),
    [_NAVIG] = LAYOUT_wrapper(
        ____________________NAVIG_L0_____________________, _______, _______, _______, ____________________NAVIG_R0_____________________,
        ____________________NAVIG_L1_____________________, _______, _______, _______, ____________________NAVIG_R1_____________________,
        ____________________NAVIG_L2_____________________, _______, _______, _______, ____________________NAVIG_R2_____________________,
        ____________________NAVIG_L3_____________________, _______, _______, _______, ____________________NAVIG_R3_____________________,
        ___________________GENERIC_L4____________________, _______, _______, _______, ___________________GENERIC_R4____________________
    )
};

void persistent_default_layer_set(uint16_t default_layer) {
    eeconfig_update_default_layer(default_layer);
    default_layer_set(default_layer);
}
