#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

enum custom_layers {
  _BASE,
  _QWERTY,
  _COLEMAK,
  _LOWER,
  _RAISE,
  _ADJUST,
};

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  LOWER,
  RAISE,
  ADJUST,
  DYNAMIC_MACRO_RANGE,
};

#include "dynamic_macro.h"

#define KC__ KC_TRNS
#define KC_COLE COLEMAK
#define KC_LOWR LOWER
#define KC_QWER QWERTY
#define KC_RASE RAISE
#define KC_RECB DYN_REC_START1
#define KC_RECE DYN_REC_STOP
#define KC_RECP DYN_MACRO_PLAY1
#define KC_RSET RESET
#define KC_MEHG MEH_T(KC_GRV)             // Tap for Backtick, hold for Meh (Ctrl+Alt+Shift)
#define KC_HTAB ALL_T(KC_TAB)             // Tap for Tab, hold for Hyper (Super+Ctrl+Alt+Shift)
#define KC_CTLE CTL_T(KC_ESC)             // Tap for Escape, hold for Control
#define KC_SBSP SFT_T(KC_BSPC)            // Tap for Backspace, hold for Shift
#define KC_SENT KC_SFTENT                 // Tap for Enter, hold for Shift


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_BASE] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     MEHG, 1  , 2  , 3  , 4  , 5  ,                6  , 7  , 8  , 9  , 0  ,MINS,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     HTAB, _  , _  , _  , _  , _  ,                _  , _  , _  , _  , _  ,BSPC,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     CTLE, _  , _  , _  , _  , _  ,                _  , _  , _  , _  , _  ,QUOT,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
     SBSP, _  , _  , _  , _  , _  , _  ,      _  , _  , _  ,COMM,DOT ,SLSH,SENT,
  //`----+----+----+----+----+----+----/    \----+----+----+----+----+----+----'
                       LALT,LOWR,SPC ,         SPC ,RASE,RALT
  //                  `----+----+----'        `----+----+----'
  ),

  [_QWERTY] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
      _  , _  , _  , _  , _  , _  ,                _  , _  , _  , _  , _  , _  ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
      _  , Q  , W  , E  , R  , T  ,                Y  , U  , I  , O  , P  , _  ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
      _  , A  , S  , D  , F  , G  ,                H  , J  , K  , L  ,SCLN, _  ,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
      _  , Z  , X  , C  , V  , B  , _  ,      _  , N  , M  , _  , _  , _  , _  ,
  //`----+----+----+----+----+----+----/    \----+----+----+----+----+----+----'
                        _  , _  , _  ,          _  , _  , _
  //                  `----+----+----'        `----+----+----'
  ),

  [_COLEMAK] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
      _  , _  , _  , _  , _  , _  ,                _  , _  , _  , _  , _  , _  ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
      _  , Q  , W  , F  , P  , G  ,                J  , L  , U  , Y  ,SCLN, _  ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
      _  , A  , R  , S  , T  , D  ,                H  , N  , E  , I  , O  , _  ,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
      _  , Z  , X  , C  , V  , B  , _  ,      _  , K  , M  , _  , _  , _  , _  ,
  //`----+----+----+----+----+----+----/    \----+----+----+----+----+----+----'
                        _  , _  , _  ,          _  , _  , _
  //                  `----+----+----'        `----+----+----'
  ),

  [_LOWER] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
      _  , _  , _  , _  , _  , _  ,                _  , _  , _  , _  , _  , _  ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     TILD,EXLM, AT ,HASH,DLR ,PERC,               CIRC,AMPR,ASTR,LPRN,RPRN, _  ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     DEL , F1 , F2 , F3 , F4 , F5 ,                F6 ,UNDS,PLUS,LCBR,RCBR,PIPE,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
      _  , F7 , F8 , F9 ,F10 ,F11 , _  ,      _  ,F12 ,MS_L,MS_D,MS_U,MS_R,BTN1,
  //`----+----+----+----+----+----+----/    \----+----+----+----+----+----+----'
                        _  , _  , _   ,          _  , _  , _
  //                  `----+----+----'        `----+----+----'
  ),

  [_RAISE] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
      _  , _  , _  , _  , _  , _  ,                _  , _  , _  , _  , _  , _  ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     GRV , 1  , 2  , 3  , 4  , 5  ,                6  , 7  , 8  , 9  , 0  , _  ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     DEL , F1 , F2 , F3 , F4 , F5 ,                F6 ,MINS,EQL ,LBRC,RBRC,BSLS,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
      _  , F7 , F8 , F9 ,F10 ,F11 , _  ,      _  ,F12 ,LEFT,DOWN, UP ,RGHT,BTN2,
  //`----+----+----+----+----+----+----/    \----+----+----+----+----+----+----'
                        _  , _  , _   ,          _  , _  , _
  //                  `----+----+----'        `----+----+----'
  ),

  [_ADJUST] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
      _  , _  , _  , _  , _  , _  ,                _  , _  , _  , _  , _  , _  ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
      _  ,RSET, _  , _  , _  , _  ,                _  , _  , _  , _  ,RSET, _  ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
      _  , _  , _  , _  , _  , _  ,                _  ,QWER,COLE, _  , _  , _  ,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
      _  , _  , _  , _  , _  , _  , _  ,      _  , _  ,RECB,RECE,RECP, _  , _  ,
  //`----+----+----+----+----+----+----/    \----+----+----+----+----+----+----'
                        _  , _  , _  ,          _  , _  , _
  //                  `----+----+----'        `----+----+----'
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (!process_record_dynamic_macro(keycode, record)) {
    return false;
  }

  switch (keycode) {
    case COLEMAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_COLEMAK);
      }
      return false;
      break;
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
 }
