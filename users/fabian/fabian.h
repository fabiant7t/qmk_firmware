#pragma once

#include QMK_KEYBOARD_H

// Layer names
enum userspace_layers {
    _QWERTY = 0,
    _COLEMAK,
    _LOWER,
    _RAISE,
    _ADJUST
};

#include "wrappers.h"
