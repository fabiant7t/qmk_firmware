/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#undef PRODUCT
#define PRODUCT Dactyl Manuform 4x6 (fabian)

// #define MATRIX_ROW_PINS { F7, B1, B3, B2, B6 }
// #define MATRIX_COL_PINS { D4, C6, D7, E6, B4, B5 }
#undef MATRIX_COL_PINS
#define MATRIX_COL_PINS { D4, D1, D7, E6, B4, B5 }  // D1 instead of C6
#define AUDIO_PIN C6  // Speaker

/* Use I2C or Serial, not both */
#define USE_SERIAL
//#define USE_I2C

/* Select hand configuration */
#define MASTER_LEFT
//#define MASTER_RIGHT

#define EE_HANDS
