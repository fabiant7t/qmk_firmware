#pragma once


// Custom key behavior
#define CTL_ESC CTL_T(KC_ESC)  // Tap for Escape, hold for Control
#define HPR_SPC ALL_T(KC_SPC)  // Tap for Space, hold for Hyper (Super+Ctrl+Alt+Shift)
#define HPR_TAB ALL_T(KC_TAB)  // Tap for Tab, hold for Hyper (Super+Ctrl+Alt+Shift)
#define MEH_GRV MEH_T(KC_GRV)  // Tap for Backtick, hold for Meh (Ctrl+Alt+Shift)
#define SFT_BSP SFT_T(KC_BSPC) // Tap for Backspace, hold for Shift
#define SFT_ENT SFT_T(KC_ENT)  // Tap for Enter, hold for Shift
#define SFT_SPC SFT_T(KC_SPC)  // Tap for Space, hold for Shift
#define UMLAUT  RALT(KC_U)     // Combine Alt and U

// Layer toggles
#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)
#define QWERTY TO(_QWERTY)
#define COLEMAK TO(_COLEMAK)

// The keyboards I build and use are ortholinear.
// Their layout differs, some are 4x12, 5x12, 5x15 or even split (2x4x6 and 2x5x6).
// To propagate _my_ layout to every board without any further adoption, I define
// templates here and reference them in the respective keymaps (thanks @drashna).

// Left pinky modifiers
#define MOD_L0 MEH_GRV
#define MOD_L1 HPR_TAB
#define MOD_L2 CTL_ESC
#define MOD_L3 SFT_BSP

// Right pinky modifiers
#define MOD_R0 KC_MINS
#define MOD_R1 KC_BSPC
#define MOD_R2 KC_QUOT
#define MOD_R3 SFT_ENT

// Lower thumb cluster
#define TC_L5_0 _______
#define TC_L5_1 _______
#define TC_L6_0 _______
#define TC_L6_1 _______
#define TC_R5_0 _______
#define TC_R5_1 _______
#define TC_R6_0 _______
#define TC_R6_1 _______


// Rows of six
#define ___________________QWERTY_L0_____________________ MOD_L0,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5
#define ___________________QWERTY_L1_____________________ MOD_L1,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T
#define ___________________QWERTY_L2_____________________ MOD_L2,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G
#define ___________________QWERTY_L3_____________________ MOD_L3,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B

#define ___________________QWERTY_R0_____________________ KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    MOD_R0
#define ___________________QWERTY_R1_____________________ KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    MOD_R1
#define ___________________QWERTY_R2_____________________ KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, MOD_R2
#define ___________________QWERTY_R3_____________________ KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, MOD_R3

#define ___________________COLEMAK_L0____________________ MOD_L0,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5
#define ___________________COLEMAK_L1____________________ MOD_L1,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G
#define ___________________COLEMAK_L2____________________ MOD_L2,  KC_A,    KC_R,    KC_S,    KC_T,    KC_D
#define ___________________COLEMAK_L3____________________ MOD_L3,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B

#define ___________________COLEMAK_R0____________________ KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    MOD_R0
#define ___________________COLEMAK_R1____________________ KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, MOD_R1
#define ___________________COLEMAK_R2____________________ KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    MOD_R2
#define ___________________COLEMAK_R3____________________ KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, MOD_R3

#define ____________________LOWER_L0_____________________ MEH_GRV, KC_1,    KC_2,    KC_3,    KC_4,    KC_5
#define ____________________LOWER_L1_____________________ KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC
#define ____________________LOWER_L2_____________________ KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5
#define ____________________LOWER_L3_____________________ _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11

#define ____________________LOWER_R0_____________________ KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS
#define ____________________LOWER_R1_____________________ KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC
#define ____________________LOWER_R2_____________________ KC_F6,   KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE
#define ____________________LOWER_R3_____________________ KC_F12,  KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_BTN1

#define ____________________RAISE_L0_____________________ MEH_GRV, KC_1,    KC_2,    KC_3,    KC_4,    KC_5
#define ____________________RAISE_L1_____________________ KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5
#define ____________________RAISE_L2_____________________ KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5
#define ____________________RAISE_L3_____________________ _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11

#define ____________________RAISE_R0_____________________ KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS
#define ____________________RAISE_R1_____________________ KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC
#define ____________________RAISE_R2_____________________ KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS
#define ____________________RAISE_R3_____________________ KC_F12,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_BTN2

#define ____________________ADJUST_L0____________________ _______, _______, _______, _______, _______, _______
#define ____________________ADJUST_L1____________________ _______, RESET,   _______, _______, _______, _______
#define ____________________ADJUST_L2____________________ _______, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM
#define ____________________ADJUST_L3____________________ _______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON

#define ____________________ADJUST_R0____________________ _______, _______, _______, _______, _______, _______
#define ____________________ADJUST_R1____________________ _______, _______, _______, _______, RESET,   _______
#define ____________________ADJUST_R2____________________ KC_ASTG, QWERTY,  COLEMAK, _______, _______, _______
#define ____________________ADJUST_R3____________________ MI_OFF,  _______, _______, _______, _______, _______

#define ___________________GENERIC_L4____________________ KC_LCTL, MEH_GRV, KC_LGUI, KC_LALT, LOWER,   KC_SPC
#define ___________________GENERIC_R4____________________ SFT_ENT, RAISE,   KC_RALT, KC_RGUI, UMLAUT,  KC_RCTL
