/* Copyright 2024 Vaarai
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
#include "./custom_keycodes.h"

enum layers {
  _ALPHA,
  _NAV,
  _NUM,
  _ADJUST,
  _GAME
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_ALPHA] = LAYOUT_split_3x6_3(
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_ESC,    KC_P,    KC_L,    KC_D,    KC_G,    KC_V,                         KC_Q,    KC_F,    KC_O,    KC_U, KC_COMM, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_TAB,    KC_N,    KC_R,    KC_T,    KC_S,    KC_Y,                         KC_J,    KC_H,    KC_A,    KC_E,    KC_I, KC_RALT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,    KC_X,    KC_K,    KC_C,    KC_W,    KC_Z,                         KC_B,    KC_M, KC_QUOT, KC_SCLN,  KC_DOT, KC_RCTL,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                        KC_LSFT, MO(_NAV), KC_SPC,   KC_ENT, MO(_NUM), KC_RSFT

  ),

    [_NAV] = LAYOUT_split_3x6_3(
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, XXXXXXX, XXXXXXX, C(KC_A), XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
  //|--------+--------+ GUI V  +--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, C(KC_X), G(KC_V), C(KC_V), C(KC_C), C(KC_Z),                      XXXXXXX, KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, _______, 
  //|ALT LEFT+--------+ ALT SFT+scrnshot+--------+--------|                    |--------+--------+--------+--------+--------+--------|
   A(KC_LEFT),C(KC_S),S(KC_LALT), CK_SSHT,C(KC_F), C(KC_Y),                      XXXXXXX, KC_HOME, KC_PGDN, KC_PGUP,  KC_END, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______, _______,  _______,MO(_ADJUST),_______
                                      //`--------------------------'  `--------------------------'
  ),

    [_NUM] = LAYOUT_split_3x6_3(
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0, _______,
  //|--------+-- / ---+-- { ---+-- ( ---+-- [ ---+--------|                    |--------+--- ] --+-- ) ---+-- } ---+-- \ ---+--------|
      _______, KC_SLSH, CK_LCBR, CK_LPAR, KC_LBRC, KC_MINS,                      CK_UNSC, KC_RBRC, CK_RPAR, CK_RCBR, KC_BSLS, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX,  KC_GRV, CK_QMRK,  KC_EQL, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                        _______,MO(_ADJUST),_______,    _______, _______, KC_RGUI
                                      //`--------------------------'  `--------------------------'
  ),

    [_ADJUST] = LAYOUT_split_3x6_3(
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,TO(_GAME),
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),
  
    [_GAME] = LAYOUT_split_3x6_3(
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_ESC, XXXXXXX,    KC_Q,    KC_W,    KC_E,    KC_R,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,TG(_GAME),
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_LSFT,    KC_A,    KC_S,    KC_D,    KC_F,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_LCTL,    KC_Z,    KC_X,    KC_C,    KC_V,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX,  KC_SPC, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),
};

// QK_CLEAR_EEPROM

/* ================= OLED SECTION */

void render_logo(void) {
    static const char PROGMEM logo[] = {
        // 'cornia', 32x32px
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 
        0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xe0, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0xf8, 0xff, 0xff, 0xff, 0x3f, 0xff, 0xff, 0xff, 0xfd, 0xe1, 
        0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 
        0x00, 0x00, 0xc0, 0xf8, 0xff, 0xff, 0xff, 0x3f, 0x07, 0x00, 0x00, 0x00, 0x07, 0x3f, 0xff, 0xff, 
        0xff, 0xf8, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x1e, 0x1f, 0x1f, 0x1f, 0x07, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x07, 
        0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x0e, 0x00
    };
    oled_write_raw_P(logo, sizeof(logo));
}

void render_layer_status(void) {    
    // static const char PROGMEM layer_ALPHA[] = {
    //     // 'Layer_ALPHA', 32x32px
    //     0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 
    //     0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    //     0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x88, 0x88, 0xd4, 0xd4, 0xe2, 0xe2, 0xc1, 0xc1, 0x80, 
    //     0x80, 0xc1, 0xc1, 0xe2, 0xe2, 0xd4, 0xd4, 0x88, 0x88, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    //     0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x08, 0x15, 0x15, 0x23, 0x23, 0x47, 0x47, 0x8f, 
    //     0x8f, 0x47, 0x47, 0x23, 0x23, 0x15, 0x15, 0x08, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    //     0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    //     0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    // };
    
    // static const char PROGMEM layer_NAV[] = {
    //     // 'Layer_NAV', 32x32px
    //     0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 
    //     0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    //     0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x88, 0x88, 0x54, 0x54, 0x22, 0x22, 0x41, 0x41, 0x80, 
    //     0x80, 0x41, 0x41, 0x22, 0x22, 0x54, 0x54, 0x88, 0x88, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    //     0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x08, 0x1d, 0x1d, 0x3e, 0x3e, 0x7c, 0x7c, 0xf8, 
    //     0xf8, 0x7c, 0x7c, 0x3e, 0x3e, 0x1d, 0x1d, 0x08, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    //     0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    //     0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    // };
    
    // static const char PROGMEM layer_NUM[] = {
    //     // 'Layer_NUM', 32x32px
    //     0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 
    //     0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    //     0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x88, 0x88, 0x5c, 0x5c, 0x3e, 0x3e, 0x7f, 0x7f, 0xff, 
    //     0xff, 0x7f, 0x7f, 0x3e, 0x3e, 0x5c, 0x5c, 0x88, 0x88, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    //     0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x08, 0x15, 0x15, 0x22, 0x22, 0x44, 0x44, 0x88, 
    //     0x88, 0x44, 0x44, 0x22, 0x22, 0x15, 0x15, 0x08, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    //     0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    //     0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    // };

    // static const char PROGMEM layer_adjust[] = {
    //     // 'Layer_adjust', 32x32px
    //     0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 
    //     0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    //     0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x88, 0x88, 0xd4, 0x5c, 0xb6, 0x6a, 0xd5, 0x6b, 0xd5, 
    //     0xaa, 0xd5, 0x6b, 0xb6, 0x6a, 0xd4, 0x5c, 0x88, 0x88, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    //     0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x08, 0x15, 0x1d, 0x36, 0x2b, 0x56, 0x6d, 0xda, 
    //     0xad, 0x56, 0x6d, 0x36, 0x2b, 0x15, 0x1d, 0x08, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    //     0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    //     0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    // };

    // switch (get_highest_layer(layer_state)) {
    //     case _ALPHA:
    //         oled_write_raw_P(layer_ALPHA, sizeof(layer_ALPHA));
    //         break;
    //     case _NAV:
    //         oled_write_raw_P(layer_NAV, sizeof(layer_NAV));
    //         break;
    //     case _NUM:
    //         oled_write_raw_P(layer_NUM, sizeof(layer_NUM));
    //         break; 
    //     case _ADJUST:
    //         oled_write_raw_P(layer_adjust, sizeof(layer_adjust));
    //         break;
    // }

    switch (get_highest_layer(layer_state)) {
        case _ALPHA:
            oled_write_ln("ALPHA", 0);
            break;
        case _NAV:
            oled_write_ln("NAV", 0);
            break;
        case _NUM:
            oled_write_ln("NUM", 0);
            break;
        case _ADJUST:
            oled_write_ln("ADJUS", 0);
            break;
        case _GAME:
            oled_write_ln("GAME", 0);
            break;
    }
}

void oled_render_boot(bool bootloader) {
    oled_clear();
    oled_set_cursor(0, 2);
    if (bootloader) {
        oled_write_P(PSTR("FLASH"), false);
    } else {
        oled_write_P(PSTR("RESET"), false);
    }
    oled_render_dirty(true);
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) { return OLED_ROTATION_270; }

bool oled_task_user(void) {
    oled_set_cursor(0, 0);
    render_logo();
    oled_set_cursor(0, 7);
    render_layer_status();
    return false;
}

bool shutdown_user(bool jump_to_bootloader) {
    oled_render_boot(jump_to_bootloader);
    return false;
}

/* ================= RGB SECTION */
