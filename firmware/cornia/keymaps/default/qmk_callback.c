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

#include "./keymap.h"
#include "./oled_routines.h"

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        /* Warframe rocket jump */
        case CK_RKJMP:
            if (record->event.pressed) {
                SEND_STRING(SS_DOWN(X_C));
            } else {
                SEND_STRING(SS_DOWN(X_SPC) SS_DELAY(50) SS_UP(X_C) SS_DELAY(50) SS_UP(X_SPC));
            }
            return false;
        case CK_DPII: /* Increase trackpad DPI */
            if (record->event.pressed) {
                pointing_device_set_cpi(pointing_device_get_cpi()+100);
            }
            return false;
        case CK_DPID: /* Decrease trackpad DPI */
            if (record->event.pressed) {
                pointing_device_set_cpi(pointing_device_get_cpi()-100);
            }
            return false;
    }
    return true;
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_270;
}

bool oled_task_user(void) {
    oled_set_cursor(0, 0);
    render_logo();
    oled_set_cursor(0, 7);
    render_layer_status();
    return false;
}

bool shutdown_user(bool jump_to_bootloader) {
    render_boot(jump_to_bootloader);
    return false;
}
