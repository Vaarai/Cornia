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

#include "./tap_dances.h"

/* define a type containing as many tapdance states as you need */
typedef enum {
  SINGLE_TAP,
  SINGLE_HOLD,
  DOUBLE_TAP,
  DOUBLE_HOLD,
  OTHER_TAP
} td_state_t;

/* Create a global instance of the tapdance state type */
static td_state_t td_state;

void dance_shift_capsword_finished (tap_dance_state_t *state, void *user_data);
void dance_shift_capsword_reset (tap_dance_state_t *state, void *user_data);

tap_dance_action_t tap_dance_actions[] = {
  [TD_SFT_CAPSW] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_shift_capsword_finished, dance_shift_capsword_reset)
};

int cur_dance (tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) 
        { 
            return SINGLE_TAP;
        } else { 
            return SINGLE_HOLD;
        }
    }
    if (state->count == 2) 
    {
        if (state->interrupted || !state->pressed) 
        { 
            return DOUBLE_TAP;
        } else { 
            return DOUBLE_HOLD;
        }
    } else { 
        return OTHER_TAP; 
    }
}

void dance_shift_capsword_finished (tap_dance_state_t *state, void *user_data)
{
    td_state = cur_dance(state);
    switch (td_state) {
        case SINGLE_TAP:
        case SINGLE_HOLD:
            register_code(KC_LSFT);
            break;
        case DOUBLE_TAP:
        case DOUBLE_HOLD:
            caps_word_on();
            break;
        case OTHER_TAP:
            break;
    }
}

void dance_shift_capsword_reset (tap_dance_state_t *state, void *user_data)
{
    switch (td_state) {
        case SINGLE_TAP:
        case SINGLE_HOLD:
            unregister_code(KC_LSFT);
            break;
        case DOUBLE_TAP:
        case DOUBLE_HOLD:
        case OTHER_TAP:
            break;
    }
}