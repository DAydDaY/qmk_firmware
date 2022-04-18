/* Copyright 2021 Kyle McCreery
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#define ANIM_SIZE 336

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_all(

      KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                     KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_PSCR, KC_SLCK,          KC_MUTE,
               KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS, KC_BSPC, KC_HOME,
               KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,          KC_PGUP,
               KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,                    KC_PGDN,
      KC_LSFT, KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    MO(1),   MO(1),   KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_RSFT,          KC_UP,
               KC_LCTL, KC_LGUI,          KC_LALT, KC_MENU, KC_SPC,                    KC_SPC,  KC_ALGR,          KC_RGUI, KC_RCTL,                   KC_LEFT, KC_DOWN, KC_RGHT ),

  [1] = LAYOUT_all(

      RESET,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS,
               KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
               KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS,
               KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS,
               KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS,                   KC_TRNS, KC_TRNS, KC_TRNS )
};

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    switch (index) {
        case 0:
            if (clockwise) {
                tap_code(KC_VOLU);
            } else {
                tap_code(KC_VOLD);
            }
        break;
    }
    return true;
}
#endif

#ifdef OLED_DRIVER_ENABLE
/*
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
}

static void render_name(void) {
    static const char PROGMEM mercutio_name[] = {
        //0xB6, 0xB6, 0xB6, 0xB6, 0xB6, 0xB6, 0xB6, 0xB6, 0xB6, 0xB6, 0xB6, 0xB6, 0xB6, 0xB6, 0xB6, 0x95, 0xB5, 0x96, 0xD5, 0xB6, 0xB6,
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
        0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
    };
    oled_write_P(mercutio_name, false);
}
*/

static void render_name(void) {
    static const char PROGMEM oled_logo[ANIM_SIZE] = {
      	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
      	0x70, 0xfc, 0x8e, 0x06, 0xff, 0xff, 0x03, 0x03, 0x06, 0x1e, 0xfc, 0xe0, 0x00, 0xff, 0xff, 0x03, 
      	0x03, 0xc3, 0xff, 0x3f, 0x03, 0xfc, 0xde, 0x06, 0xff, 0xff, 0x03, 0x03, 0x07, 0x0e, 0xfc, 0xf0, 
      	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
      	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
      	0x00, 0x01, 0x03, 0x33, 0xff, 0xff, 0x76, 0xf3, 0xf0, 0x9e, 0x0f, 0x03, 0x00, 0xe3, 0xff, 0x1c, 
      	0x1c, 0x1c, 0x09, 0x01, 0x00, 0x01, 0x03, 0x03, 0xff, 0xff, 0x06, 0x02, 0x00, 0x00, 0xff, 0xff, 
      	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
      	0x60, 0xe0, 0xe0, 0x00, 0x00, 0x20, 0xe0, 0xe0, 0x00, 0xe0, 0xe0, 0x60, 0x60, 0x60, 0x60, 0xe0, 
      	0xe0, 0x20, 0x80, 0xc4, 0xe7, 0xe7, 0xe0, 0x60, 0x63, 0xc7, 0xc6, 0x84, 0x00, 0x07, 0x87, 0xc6, 
      	0xe6, 0xe6, 0xe6, 0x66, 0x66, 0xc0, 0xc0, 0x04, 0x07, 0xe7, 0xe6, 0x26, 0xc6, 0xe7, 0x63, 0xe0, 
      	0xc0, 0x00, 0x00, 0x00, 0x20, 0xe0, 0xe0, 0x00, 0x80, 0xc0, 0xe0, 0x60, 0x60, 0x60, 0xc0, 0x80, 
      	0x00, 0xff, 0xff, 0x60, 0x60, 0x60, 0xff, 0xff, 0x00, 0x3f, 0xff, 0xc0, 0x80, 0x80, 0x3f, 0x3f, 
      	0x00, 0x0f, 0x3f, 0x71, 0xff, 0xff, 0xc0, 0xc0, 0x20, 0x00, 0xff, 0xff, 0x00, 0x1f, 0x3f, 0x71, 
      	0xff, 0xff, 0xc0, 0xc0, 0x00, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0x00, 0x03, 0x07, 0xff, 
      	0xff, 0x38, 0xf0, 0xc0, 0x80, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0x00, 0x08, 0xcc, 0xcf, 0xc7, 
      	0xc0, 0xff, 0xff, 0x00, 0x04, 0x8c, 0xff, 0xff, 0x01, 0xf8, 0xfe, 0xc7, 0xc3, 0xc3, 0xc1, 0xc0, 
      	0xc0, 0x00, 0x00, 0x00, 0xff, 0xff, 0x8e, 0x0e, 0x1e, 0x7f, 0xf3, 0xc1, 0x80, 0x00, 0x00, 0x00, 
      	0xff, 0xff, 0x8e, 0x0e, 0x1e, 0x7f, 0xe3, 0x80, 0x00, 0xff, 0xff, 0x80, 0x00, 0x00, 0x00, 0xff, 
      	0xff, 0x80, 0x00, 0x01, 0x8f, 0xff, 0xff, 0x00, 0x3f, 0x7f, 0xe0, 0xc0, 0xc0, 0xff, 0xff, 0x80
    };

    oled_write_raw_P(oled_logo, ANIM_SIZE);
}

static void render_logo(void) {
    static const char PROGMEM oled_logo[ANIM_SIZE] = {
      	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc3, 0x8c, 0x18, 0x60, 0xc0, 0x00, 0x00, 0x00, 
      	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
      	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
      	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
      	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xc8, 0xf0, 0x81, 0x86, 0xf8, 0x80, 0x03, 0xec, 0x18, 
      	0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0x00, 0x00, 0x00, 0xe0, 0x1e, 0x00, 0x00, 0x80, 0x78, 0x07, 
      	0x00, 0x00, 0xf0, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x07, 0x78, 0x80, 0x00, 0x01, 0x1e, 0xe0, 0x00, 
      	0x00, 0x0e, 0xfe, 0xfe, 0xfc, 0xfc, 0xf8, 0x70, 0x70, 0x60, 0x60, 0xc0, 0x80, 0x80, 0x00, 0x00, 
      	0x00, 0x00, 0x00, 0x00, 0x00, 0x24, 0x3f, 0x87, 0x8f, 0x7f, 0x0f, 0x1f, 0xff, 0x1f, 0x1f, 0x1f, 
      	0x0f, 0x08, 0x08, 0xf8, 0x1f, 0x10, 0x10, 0xf0, 0x3e, 0x21, 0x20, 0xa0, 0x78, 0x47, 0x40, 0x40, 
      	0xf0, 0x9f, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x87, 0xf8, 0xc0, 0x40, 0x41, 0x5e, 
      	0xe0, 0x20, 0x20, 0x2f, 0xff, 0xff, 0xf8, 0xf0, 0xf0, 0xf0, 0xf0, 0xfd, 0xff, 0xff, 0x3f, 0x1e, 
      	0x80, 0xc0, 0x44, 0x24, 0x22, 0x13, 0x19, 0x08, 0x04, 0x04, 0x02, 0x03, 0x01, 0x00, 0x00, 0x00, 
      	0x00, 0x00, 0x0f, 0x00, 0x00, 0xe0, 0x1e, 0x01, 0x00, 0x80, 0x78, 0x07, 0x00, 0x00, 0xf0, 0x0f, 
      	0x01, 0x00, 0xc0, 0x3c, 0x03, 0x00, 0x00, 0x01, 0x1f, 0xf0, 0x00, 0x00, 0x07, 0x78, 0x80, 0x00, 
      	0x01, 0x1e, 0xe0, 0x00, 0x00, 0x0f, 0xff, 0xff, 0xff, 0x7f, 0x1f, 0x0f, 0x03, 0x00, 0x00, 0x00, 
      	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
      	0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x08, 0x07, 0x00, 0x00, 0x70, 0x1f, 0x01, 0x00, 
      	0xc0, 0x3c, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x1f, 0xf0, 0x00, 0x00, 0x07, 0x78, 
      	0x00, 0x00, 0x01, 0x0e, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    };

    oled_write_raw_P(oled_logo, ANIM_SIZE);
}

void oled_task_user(void) {
    oled_set_cursor(0,2);
    //oled_write("    RED\n  HERRING", false);
    render_name();
    oled_set_cursor(0,9);
    render_logo();
}
#endif
