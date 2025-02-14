#include QMK_KEYBOARD_H
#include "version.h"

#define BAS1 0 // default layer
#define BAS2 1
#define LOWR 2
#define RAIS 3

enum custom_keycodes {
  VRSN = SAFE_RANGE,
};

enum base_layer {
    _BASE_1,
    _BASE_2
};

uint8_t current_base_layer = _BASE_1;

// Custom key behavior
#define CTL_ESC CTL_T(KC_ESC)  // Tap for Escape, hold for Control
#define RGUISPC RGUI_T(KC_SPC) // Tap for Space, hold for right GUI
#define HPR_TAB HYPR_T(KC_TAB) // Tap for Tab, hold for Hyper (Super+Ctrl+Alt+Shift)
#define HPR_SPC HYPR_T(KC_SPC) // Tap for Space, hold for Hyper (Super+Ctrl+Alt+Shift)
#define MEH_GRV MEH_T(KC_GRV)  // Tap for Backtick, hold for Meh (Ctrl+Alt+Shift)
#define SFT_BSP SFT_T(KC_BSPC) // Tap for Backspace, hold for Shift
#define SFT_ENT SFT_T(KC_ENT)  // Tap for Enter, hold for Shift
#define SFT_SPC SFT_T(KC_SPC)  // Tap for Space, hold for Shift
#define UMLAUT  RALT(KC_U)     // Combine Alt and U
#define BAS_TOG MO(1)
//
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | Grv    |   1  |   2  |   3  |   4  |   5  |BasTog|           |      |   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  |      |           |      |   Y  |   U  |   I  |   O  |   P  |  Bspc  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | CapsLck|   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |   '    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | LCtl |  Grv | LGui | LAlt | Lower|                                       |Raise | RAlt | RGui |Umlaut| RCtl |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,---------------.
 *                                        | LGui | Del  |       | Alt  |Ctrl/Esc|
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Home |       | PgUp |        |      |
 *                                 | Spc  |Backsp|------|       |------|  Tab   |SftEnt|
 *                                 |      |ace   | End  |       | PgDn |        |      |
 *                                 `--------------------'       `----------------------'
 */
[BAS1] = LAYOUT_ergodox(
        // left hand
        KC_GRV,         KC_1,         KC_2,   KC_3,   KC_4,   KC_5,   BAS_TOG,
        KC_TAB,         KC_Q,         KC_W,   KC_E,   KC_R,   KC_T,   KC_TRNS,
        KC_CAPS,        KC_A,         KC_S,   KC_D,   KC_F,   KC_G,
        KC_LSFT,        KC_Z,         KC_X,   KC_C,   KC_V,   KC_B,   KC_TRNS,
        KC_LCTL,        KC_GRV,       KC_LGUI,KC_LALT,MO(LOWR),
                                              KC_LGUI,        KC_DEL,
                                                              KC_HOME,
                                              KC_SPC, KC_BSPC,KC_END,
        // right hand
             KC_TRNS,     KC_6,   KC_7,    KC_8,   KC_9,   KC_0,      KC_MINS,
             KC_TRNS,     KC_Y,   KC_U,    KC_I,   KC_O,   KC_P,      KC_BSPC,
                          KC_H,   KC_J,    KC_K,   KC_L,   KC_SCLN,   KC_QUOT,
             KC_TRNS,     KC_N,   KC_M,    KC_COMM,KC_DOT, KC_SLSH,   KC_RSFT,
                                  MO(RAIS),KC_RALT,KC_RGUI,UMLAUT,    KC_RCTL,
             KC_LALT,        CTL_ESC,
             KC_PGUP,
             KC_PGDN,KC_TAB, SFT_ENT
    ),
/*
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | MehGrv |   1  |   2  |   3  |   4  |   5  |BasTog|           |      |   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | HprTab |   Q  |   W  |   E  |   R  |   T  |      |           |      |   Y  |   U  |   I  |   O  |   P  |  Bspc  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | CtlEsc |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |   '    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | SftBsp |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  | SftEnt |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | LCtl |MehGrv| LGui | LAlt | Lower|                                       |Raise | RAlt | RGui |Umlaut| RCtl |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,---------------.
 *                                        | LGui | Del  |       | Alt  |Ctrl/Esc|
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Home |       | PgUp |        |      |
 *                                 |HprSpc|Backsp|------|       |------|  Tab   |SftEnt|
 *                                 |      |ace   | End  |       | PgDn |        |      |
 *                                 `--------------------'       `----------------------'
 */
[BAS2] = LAYOUT_ergodox(
        // left hand
        MEH_GRV,        KC_1,         KC_2,   KC_3,   KC_4,   KC_5,   BAS_TOG,
        HPR_TAB,        KC_Q,         KC_W,   KC_E,   KC_R,   KC_T,   KC_TRNS,
        CTL_ESC,        KC_A,         KC_S,   KC_D,   KC_F,   KC_G,
        SFT_BSP,        KC_Z,         KC_X,   KC_C,   KC_V,   KC_B,   KC_TRNS,
        KC_LCTL,        MEH_GRV,      KC_LGUI,KC_LALT,MO(LOWR),
                                              KC_LGUI,        KC_DEL,
                                                              KC_HOME,
                                              HPR_SPC,KC_BSPC,KC_END,
        // right hand
             KC_TRNS,     KC_6,   KC_7,    KC_8,   KC_9,   KC_0,      KC_MINS,
             KC_TRNS,     KC_Y,   KC_U,    KC_I,   KC_O,   KC_P,      KC_BSPC,
                          KC_H,   KC_J,    KC_K,   KC_L,   KC_SCLN,   KC_QUOT,
             KC_TRNS,     KC_N,   KC_M,    KC_COMM,KC_DOT, KC_SLSH,   SFT_ENT,
                                  MO(RAIS),KC_RALT,KC_RGUI,UMLAUT,    KC_RCTL,
             KC_LALT,        CTL_ESC,
             KC_PGUP,
             KC_PGDN,KC_TAB, SFT_ENT
    ),
/*
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |   ~    |   !  |   @  |   #  |   $  |   %  |      |           |      |   ^  |   &  |   *  |   (  |   )  |  Del   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |  Del   |  F1  |  F2  |  F3  |  F4  |  F5  |------|           |------|  F6  |   _  |   +  |   {  |   }  |   |    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |  F7  |  F8  |  F9  | F10  | F11  |      |           |      |  F12 | MS_L | MS_D | MS_U | MS_R |KC_BTN1 |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,---------------.
 *                                        |      |      |       |      |        |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      |      |       |      |        |      |
 *                                 |      |      |------|       |------|        |      |
 *                                 |      |      |      |       |      |        |      |
 *                                 `--------------------'       `----------------------'
 */
[LOWR] = LAYOUT_ergodox(
        // left hand
        XXXXXXX,        XXXXXXX,      XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
        KC_TILD,        KC_EXLM,      KC_AT,  KC_HASH,KC_DLR, KC_PERC,XXXXXXX,
        KC_DEL,         KC_F1,        KC_F2,  KC_F3,  KC_F4,  KC_F5,
        XXXXXXX,        KC_F7,        KC_F8,  KC_F9,  KC_F10, KC_F11, XXXXXXX,
        XXXXXXX,        XXXXXXX,      XXXXXXX,XXXXXXX,XXXXXXX,
                                              XXXXXXX,        XXXXXXX,
                                                              XXXXXXX,
                                              XXXXXXX,XXXXXXX,XXXXXXX,
        // right hand
             XXXXXXX,     XXXXXXX,XXXXXXX, XXXXXXX,XXXXXXX,XXXXXXX,   XXXXXXX,
             XXXXXXX,     KC_CIRC,KC_AMPR, KC_ASTR,KC_LPRN,KC_RPRN,   KC_DEL,
                          KC_F6,  KC_UNDS, KC_PLUS,KC_LCBR,KC_RCBR,   KC_PIPE,
             XXXXXXX,     KC_F12, KC_MS_L, KC_MS_D,KC_MS_U,KC_MS_R,   KC_BTN1,
                                  XXXXXXX, XXXXXXX,XXXXXXX,XXXXXXX,   XXXXXXX,
             XXXXXXX,         XXXXXXX,
             XXXXXXX,
             XXXXXXX,XXXXXXX, XXXXXXX
    ),
/*
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |   `    |   1  |   2  |   3  |   4  |   5  |      |           |      |   6  |   7  |   8  |   9  |   0  |  Del   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |  Del   |  F1  |  F2  |  F3  |  F4  |  F5  |------|           |------|  F6  |   -  |   =  |   [  |   ]  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |  F7  |  F8  |  F9  | F10  | F11  |      |           |      |  F12 | Left | Down |  Up  |Right |KC_BTN2 |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,---------------.
 *                                        |      |      |       |      |        |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      |      |       |      |        |      |
 *                                 |      |      |------|       |------|        |      |
 *                                 |      |      |      |       |      |        |      |
 *                                 `--------------------'       `----------------------'
 */
[RAIS] = LAYOUT_ergodox(
        // left hand
        XXXXXXX,        XXXXXXX,      XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
        KC_GRV,         KC_1,         KC_2,   KC_3,   KC_4,   KC_5,   XXXXXXX,
        KC_DEL,         KC_F1,        KC_F2,  KC_F3,  KC_F4,  KC_F5,
        XXXXXXX,        KC_F7,        KC_F8,  KC_F9,  KC_F10, KC_F11, XXXXXXX,
        XXXXXXX,        XXXXXXX,      XXXXXXX,XXXXXXX,XXXXXXX,
                                              XXXXXXX,        XXXXXXX,
                                                              XXXXXXX,
                                              XXXXXXX,XXXXXXX,XXXXXXX,
        // right hand
             XXXXXXX,     XXXXXXX,XXXXXXX, XXXXXXX,XXXXXXX,XXXXXXX,   XXXXXXX,
             XXXXXXX,     KC_6,   KC_7,    KC_8,   KC_9,   KC_0,      KC_DEL,
                          KC_F6,  KC_MINS, KC_EQL ,KC_LBRC,KC_RBRC,   KC_BSLS,
             XXXXXXX,     KC_F12, KC_LEFT, KC_DOWN,KC_UP,  KC_RGHT,   KC_BTN2,
                                  XXXXXXX, XXXXXXX,XXXXXXX,XXXXXXX,   XXXXXXX,
             XXXXXXX,         XXXXXXX,
             XXXXXXX,
             XXXXXXX,XXXXXXX, XXXXXXX
    ),
};

void set_base_layer(uint8_t base_layer) {
    eeconfig_update_user(base_layer); // Save to EEPROM

    layer_off(BAS1);
    layer_off(BAS2);

    switch (base_layer) {
        case _BASE_1:
            layer_on(BAS1);
            break;
        case _BASE_2:
            layer_on(BAS2);
            break;
    }
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
    case BAS_TOG:
        if (record->event.pressed) {
            current_base_layer++;
            if (current_base_layer > _BASE_2) {
                current_base_layer = _BASE_1;  // cycle back to 1
            }
            set_base_layer(current_base_layer);
        }
        return false;
  }
  return true;
}

bool led_update_user(led_t led_state) {
    // stub any kb level behaviour
    return false;
}

void keyboard_post_init_user(void) {
    current_base_layer = eeconfig_read_user();
    set_base_layer(current_base_layer);
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {
    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();

    switch (get_highest_layer(layer_state)) {
      // TODO: Make this relevant to the ErgoDox EZ.
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        default:
            // none
            break;
    }
};
