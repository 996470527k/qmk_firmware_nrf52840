/* Copyright 2015-2017 Jack Humbert
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
#include "muse.h"
#include "ble_service.h"
#include "rgb_matrix.h"
#include "i2c_master.h"

// extern keymap_config_t keymap_config;
extern rgb_config_t rgb_matrix_config;

enum qs75_layers {
    _DEFAULT,
    _OTHER,
    _SLASH,
    _SCOLON,
    _SPACE,
    _MOUSE,
    _BLUE
};

enum planck_keycodes { DISC = SAFE_RANGE, ADVW, ADVS, SEL0, SEL1, SEL2, DELB, SLEEP, REBOOT };

#define LCTLESC MT(MOD_LCTL, KC_ESC)
#define LTPSC LT(_SPACE, KC_SPC)
#define MOUSEL MO(_MOUSE)
#define OTHERL TG(_OTHER)
#define SCOLONL LT(_SCOLON, KC_SCLN)
#define SLASHL LT(_SLASH, KC_SLSH)
#define CLTQUOT MT(MOD_RCTL, KC_QUOT)
#define BLUETOG MO(_BLUE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_DEFAULT] = LAYOUT(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_J,  KC_L,  KC_M,    KC_F,    KC_P,    KC_SLSH,    KC_LBRC,        KC_RBRC,   KC_BSPC,
        KC_TAB,   KC_5,    KC_6,    KC_Q,    KC_DOT,  KC_O,  KC_R,  KC_S,    KC_U,    KC_Y,    KC_B,          KC_SCLN,        KC_EQL,  KC_BSLS,
        KC_CAPS,   KC_7,    KC_8,    KC_Z,    KC_A,             KC_E,    KC_H,    KC_T,    KC_D,    KC_C,    KC_K,          KC_MINS,           KC_ENT,
        KC_LSFT,      KC_9,    KC_0,    KC_X,     KC_COMM,     KC_I,    KC_N,    KC_W,    KC_V, KC_G,      KC_QUOT,   KC_GRAVE, KC_UP,   OTHERL,
        KC_LCTL,    KC_LALT, KC_LWIN,  MO(1),              RSFT_T(KC_SPC), MO(2),  KC_MENU, KC_RALT,                   KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT,
        _______, _______, _______, _______, _______, _______, _______, _______
                        ),
    [_OTHER]   = LAYOUT(
        _______,  KC_ESC,  KC_F1,  KC_F2,  KC_F3,  KC_1,    KC_2,    KC_3,    KC_4,    KC_LBRC,     _______,    _______,   _______,   _______,
        _______,   _______,  KC_F4,  KC_F5,  KC_F6,  KC_5,   KC_6,    KC_SCLN,  KC_EQL,    KC_RBRC,    _______,   _______,   _______,  _______,
        _______,    _______,   KC_F7,  KC_F8,  KC_F9, KC_7,   KC_8,    KC_MINS,    KC_BSLS,  KC_TAB,    _______,   _______,  _______,
        _______,      RESET,   KC_F10,    KC_F11,     KC_F12,     KC_9,    KC_0,    KC_QUOT,    KC_GRAVE, _______,    _______,   _______, _______,_______,
        _______,    _______, _______, KC_TRNS,              RSFT_T(KC_SPC),       KC_TRNS,  _______, _______, _______,    _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______
                      ),
    [_SLASH]   = LAYOUT(
        _______,   _______, _______,  _______,    _______,    _______,  OUT_USB, OUT_BT, KC_PSCREEN, KC_SCROLLLOCK, KC_PAUSE, _______,_______, _______,
        _______,    _______,    _______,    _______,    _______   , _______,   _______, _______, KC_INSERT, KC_HOME, KC_PGUP, _______,_______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_DELETE, KC_END,KC_PGDOWN,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, ADVS, ADVW,DELB, SLEEP,
        _______, _______, _______, KC_TRNS,              KC_SPC, KC_TRNS,RGB_TOG, RGB_MOD, _______, SEL0, SEL1, SEL2,
        _______, _______, _______, _______, _______, _______, _______, _______
                      ),
    [_SCOLON] = LAYOUT(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_UP,  KC_RSFT,  KC_PGDN,
        KC_LCTL, KC_LGUI, KC_LALT,KC_NLCK, KC_SPC, RGB_MOD, KC_RALT, MO(1),OTHERL, KC_LEFT, KC_DOWN, KC_RGHT,
        _______, _______, _______, _______, _______, _______, _______, _______
                       ),
    [_SPACE]  = LAYOUT(
        KC_GRV, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______, _______, _______,
        _______, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSLS, _______, _______,
        _______, KC_TILD, KC_PIPE, KC_LBRC, KC_RBRC, KC_UNDS, KC_PLUS, KC_MINS, KC_EQL, KC_DOT, KC_SLSH, _______,_______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,_______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______
                      ),

    [_MOUSE] = LAYOUT(
        _______, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, _______, KC_WH_D, KC_MS_U, KC_WH_U, _______, _______,_______, _______,
        _______, RGB_VAI, RGB_VAD, RGB_SPI, RGB_SPD, _______, KC_BTN2, KC_MS_L, KC_MS_D, KC_MS_R, KC_BTN1, _______,_______, _______,
        _______, _______, _______, _______, _______, _______, KC_HOME, KC_ACL0, KC_ACL1, KC_ACL2, _______, _______,_______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,_______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______
                     ),

    [_BLUE] = LAYOUT(
        RESET,   OUT_USB, OUT_BT,  ADVS,    ADVW,    REBOOT,  _______, _______, _______, _______, _______, _______,_______, _______,
        SEL0,    SEL1,    SEL2,    DISC,    DELB   , SLEEP,   _______, _______, _______, _______, _______, _______,_______, _______,
        MAGIC_TOGGLE_NKRO, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,_______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,_______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______
    )
};

void keyboard_post_init_user() {
    #ifdef IS31FL3737
    // Shutdown IS31FL3737 if rgb disabled
    if (!rgb_matrix_config.enable) {
        i2c_stop();
    }
    #endif
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    #ifdef POWER_SAVE_TIMEOUT
        if (record->event.pressed) {
            reset_power_save_counter();
        }
    #endif
    switch (keycode) {
        case DISC:
            if (record->event.pressed) {
                ble_disconnect();
            }
            return false;

        case ADVW:
            if (record->event.pressed) {
                advertising_without_whitelist();
            }
            return false;

        case ADVS:
            if (record->event.pressed) {
                advertising_start(false);
            }
            return false;

        case SEL0:
            if (record->event.pressed) {
                restart_advertising_id(0);
            }
            return false;

        case SEL1:
            if (record->event.pressed) {
                restart_advertising_id(1);
            }
            return false;

        case SEL2:
            if (record->event.pressed) {
                restart_advertising_id(2);
            }
            return false;

        case DELB:
            if (record->event.pressed) {
                advertising_start(true);
            }
            return false;

        case REBOOT:
            if (record->event.pressed) {
                NVIC_SystemReset();
            }

        case RGB_TOG:
            if (record->event.pressed) {
                if (rgb_matrix_config.enable) {
                    i2c_stop();
                } else {
                    i2c_start();
                }
            }
            return true;

        case SLEEP:
            if (!record->event.pressed) {
                deep_sleep_mode_enter();
            }
            return false;
    }
    return true;
}
