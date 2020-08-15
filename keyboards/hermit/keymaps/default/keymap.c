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
//#include "muse.h"
#include "ble_service.h"

#ifdef RGB_MATRIX_ENABLE
#include "rgb_matrix.h"
#include "i2c_master.h"

extern rgb_config_t rgb_matrix_config;
#endif

// extern keymap_config_t keymap_config;

#ifdef RGBLIGHT_ENABLE
extern rgblight_config_t rgblight_config;
#endif


enum hermit_layers {
    _MAIN,
    _FN,
    _RGBST,
    _MOUSE
};


enum planck_keycodes { DISC = SAFE_RANGE, ADVW, ADVS, SEL0, SEL1, SEL2, DELB, SLEEP, REBOOT, RGBRST};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

     [_MAIN] = LAYOUT(
        KC_GESC  ,  KC_F1    ,  KC_F2    ,  KC_F3    ,  KC_F4    ,  KC_F5    ,  KC_F6    ,  KC_F7    ,  KC_F8    ,  KC_F9    ,  KC_F10   ,  KC_F11   ,  KC_F12   ,  KC_PSCR  ,  KC_PWR   ,
        KC_GRV   ,  KC_1     ,  KC_2     ,  KC_3     ,  KC_4     ,  KC_5     ,  KC_6     ,  KC_7     ,  KC_8     ,  KC_9     ,  KC_0     ,  KC_MINS  ,  KC_EQL   ,  KC_BSPC  ,  KC_PAUS  ,
        KC_TAB   ,  KC_Q     ,  KC_W     ,  KC_E     ,  KC_R     ,  KC_T     ,  KC_Y     ,  KC_U     ,  KC_I     ,  KC_O     ,  KC_P     ,  KC_LBRC  ,  KC_RBRC  ,  KC_BSLS  ,  KC_DEL   ,
        KC_CAPS  ,  KC_A     ,  KC_S     ,  KC_D     ,  KC_F     ,  KC_G     ,  KC_H     ,  KC_J     ,  KC_K     ,  KC_L     ,  KC_SCLN  ,  KC_QUOT  ,  KC_ENT   ,  KC_P4    ,  KC_P5    ,
        KC_LSFT  ,  KC_Z     ,  KC_X     ,  KC_C     ,  KC_V     ,  KC_B     ,  KC_N     ,  KC_M     ,  KC_COMM  ,  KC_DOT   ,  KC_SLSH  ,  KC_RSFT  ,  KC_UP    ,  KC_P1    ,  KC_P2    ,
        KC_LCTL  ,  KC_LGUI  ,  KC_LALT  ,  KC_SPC   ,  KC_RALT  ,  MO(1)    ,  KC_MENU  ,  KC_LEFT  ,  KC_DOWN  ,  KC_RGHT  ,  KC_P0    ,  KC_PDOT  ,  KC_P3    ,  KC_P6    ,  KC_P9    ,
        KC_SPC   ,  KC_SPC   ,  KC_VOLU  ,  KC_VOLD  ,  KC_WAKE  ,  KC_NLCK  ,  KC_PSLS  ,  KC_PAST  ,  KC_PMNS  ,  KC_PPLS  ,  KC_ENT   ,  KC_P7    ,  KC_P8
                           ),
    [_FN]   = LAYOUT(
        RESET    ,   OUT_USB  ,   OUT_BT     ,   OUT_AUTO  ,   REBOOT      ,   SLEEP    ,   MAGIC_TOGGLE_NKRO  ,   _______  ,   _______  ,   _______  ,   _______   ,   _______  ,   KC_INSERT  ,   _______   ,   _______    ,
        _______  ,   RGB_M_P  ,   RGBM_MOD   ,   RGB_MOD   ,   DELB        ,   DISC     ,   _______            ,   _______  ,   _______  ,   _______  ,   RGBM_TOG  ,   _______  ,   _______    ,   KC_HOME   ,   KC_PGUP    ,
        _______  ,   RGB_TOG  ,   RGB_M_B    ,   RGB_M_SW  ,   RGB_M_T     ,   ADVS     ,   _______            ,   _______  ,   _______  ,   _______  ,   _______   ,   _______  ,   _______    ,   KC_END    ,   KC_PGDOWN  ,
        _______  ,   RGBRST   ,   RGBM_RMOD  ,   RGB_RMOD  ,   RGB_M_G     ,   ADVW     ,   _______            ,   _______  ,   _______  ,   _______  ,   _______   ,   _______  ,   _______    ,   _______   ,   _______    ,
        _______  ,   RGB_M_R  ,   RGB_M_SN   ,   RGB_M_K   ,   RGB_M_X     ,   KC_TRNS  ,   _______            ,   _______  ,   _______  ,   _______  ,   _______   ,   _______  ,   RGB_VAI    ,   _______   ,   _______    ,
        _______  ,   _______  ,   _______    ,   KC_SPC    ,   TO(_RGBST)  ,   KC_TRNS  ,   TO(_MOUSE)         ,   _______  ,   RGB_VAD  ,   _______  ,   _______   ,   _______  ,   _______    ,   _______   ,   _______    ,
        _______  ,   _______    ,   _______   ,    _______    ,   _______  ,   _______            ,   _______  ,   _______  ,   _______  ,   _______   ,   _______   ,   _______   ,   _______
                      ),
    [_RGBST] = LAYOUT(
        _______  ,   RGBM_HUI  ,   RGBM_HUD  ,   RGBM_SAI  ,   RGBM_SAD   ,   RGBM_VAI  ,   RGBM_VAD  ,   RGBM_SPI  ,   RGBM_SPD  ,   _______  ,   _______  ,   _______  ,   _______  ,   _______  ,   _______  ,
        _______  ,   RGB_HUI   ,   RGB_HUD   ,   RGB_SAI   ,   RGB_SAD    ,   RGB_VAI   ,   RGB_VAD   ,   RGB_SPI   ,   RGB_SPD   ,   _______  ,   _______  ,   _______  ,   _______  ,   _______  ,   _______  ,
        _______  ,   RGB_M_P   ,   RGB_M_B   ,   RGB_M_R   ,   RGB_M_SW   ,   RGB_M_SN  ,   RGB_M_K   ,   RGB_M_X   ,   RGB_M_G   ,   RGB_M_T  ,   _______  ,   _______  ,   _______  ,   _______  ,   _______  ,
        _______  ,   _______   ,   _______   ,   _______   ,   _______    ,   _______   ,   _______   ,   _______   ,   _______   ,   _______  ,   _______  ,   _______  ,   _______  ,   _______  ,   _______  ,
        _______  ,   _______   ,   _______   ,   _______   ,   _______    ,   _______   ,   _______   ,   _______   ,   _______   ,   _______  ,   _______  ,   _______  ,   _______  ,   _______  ,   _______  ,
        _______  ,   _______   ,   _______   ,   _______   ,   TO(_MAIN)  ,   _______   ,   _______   ,   _______   ,   _______   ,   _______  ,   _______  ,   _______  ,   _______  ,   _______  ,   _______  ,
        _______   ,   _______   ,   _______   ,   _______    ,   _______   ,   _______   ,   _______   ,   _______   ,   _______  ,   _______  ,   _______  ,   _______  ,   _______
                     ),
    [_MOUSE] = LAYOUT(
        _______  ,   KC_PWR       ,   KC_MUTE     ,   KC_VOLU         ,   KC_VOLD     ,   KC_MNXT     ,   KC_MPRV    ,   KC_MSTP  ,   KC_MPLY  ,   _______  ,   _______  ,   _______  ,   _______  ,   _______  ,   _______  ,
        _______  ,   KC_MS_BTN1   ,   KC_MS_BTN2  ,   KC_MS_BTN3      ,   KC_MS_BTN4  ,   KC_MS_BTN5  ,   _______    ,   _______  ,   _______  ,   _______  ,   _______  ,   _______  ,   _______  ,   _______  ,   _______  ,
        _______  ,   KC_MS_WH_UP  ,   KC_MS_UP    ,   KC_MS_WH_DOWN   ,   _______     ,   _______     ,   _______    ,   _______  ,   _______  ,   _______  ,   _______  ,   _______  ,   _______  ,   _______  ,   _______  ,
        _______  ,   KC_MS_LEFT   ,   KC_MS_DOWN  ,   KC_MS_RIGHT     ,   KC_FIND     ,   _______     ,   _______    ,   _______  ,   _______  ,   _______  ,   _______  ,   _______  ,   _______  ,   _______  ,   _______  ,
        _______  ,   KC_UNDO      ,   KC_CUT      ,   KC_COPY         ,   KC_PASTE    ,   _______     ,   _______    ,   _______  ,   _______  ,   _______  ,   _______  ,   _______  ,   _______  ,   _______  ,   _______  ,
        _______  ,   _______      ,   _______     ,   KC_MY_COMPUTER  ,   _______     ,   _______     ,   TO(_MAIN)  ,   _______  ,   _______  ,   _______  ,   _______  ,   _______  ,   _______  ,   _______  ,   _______  ,
        _______      ,   _______     ,   _______         ,   _______     ,   _______     ,   _______    ,   _______  ,   _______  ,   _______  ,   _______  ,   _______  ,   _______  ,   _______
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

    case RGBRST:
      #ifdef RGBLIGHT_ENABLE
        if (record->event.pressed) {
          eeconfig_update_rgblight_default();
          rgblight_enable();
        }
      #endif
      break;

        case RGBM_TOG:
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

void rgb_matrix_indicators_user(void) {
	  uint8_t this_led = host_keyboard_leds();
	  if (!g_suspend_state) {
	    switch (biton32(layer_state)) {
          case _MAIN:
            rgb_matrix_set_color(102,0xFF, 0x77, 0xBF);
          break;
          case _FN:
            rgb_matrix_set_color(99,0xFF, 0x77, 0xBF);
          break;
	      case _RGBST:
	        rgb_matrix_set_color(100,0xFF, 0x77, 0xBF);
          break;
	      case _MOUSE:
	        rgb_matrix_set_color(101,0xFF, 0x60, 0x40);
          break;
      }
      }
     if ( this_led & (1<<USB_LED_CAPS_LOCK)) {
          rgb_matrix_set_color(96, 0xFF, 0xFF, 0xFF);
      }
     if ( this_led & (1<<USB_LED_NUM_LOCK)) {
          rgb_matrix_set_color(97, 0xFF, 0xFF, 0xFF);
      }
     if ( this_led & (1<<USB_LED_SCROLL_LOCK)) {
          rgb_matrix_set_color(98, 0xFF, 0xFF, 0xFF);
      }
}

