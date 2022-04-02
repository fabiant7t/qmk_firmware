#include "fabian.h"


__attribute__ ((weak))
layer_state_t layer_state_set_keymap (layer_state_t state) {
  return state;
}

layer_state_t layer_state_set_user (layer_state_t state) {
  state = update_tri_layer_state(state, _RAISE, _LOWER, _ADJUST);
  return layer_state_set_keymap (state);
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
  autoshift_disable();
  return state;
}
