#ifndef CONFIG_H
#define CONFIG_H

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0xC475
#define DEVICE_VER      0x0001
#define MANUFACTURER    "Tsiank"
#define PRODUCT         "Ciank67_ug"
#define DESCRIPTION     "Dvorak right-handed keyboard ws2812 underglow"

/* key matrix */
#define MATRIX_ROWS 5
#define MATRIX_COLS 14

// NRF52840 pin map: ((port << 5) | (pin & 0x1F))(P1点几的引脚是32加小数部分，P0点几的引脚直接是小数部分，比如P0.08是8，P0.20是20，P1.06是38（32+6））
#define MATRIX_ROW_PINS \
{ 26, 29, 2, 45, 43}
#define MATRIX_COL_PINS \
{ 41, 28, 12, 42, 7, 3, 38, 36, 34, 32, 24, 22, 13, 20 }

#define RGB_DI_PIN 6
#define RGBLED_NUM 7
#define RGBLIGHT_ANIMATIONS

#define DEBOUNCE 20
#define BLUETOOTH_ENABLE


#define PERMISSVIE_HOLD
#define IGNORE_MOD_TAP_INTERRUPT
#define TAPPING_FORCE_HOLD
#define TAPPING_TERM 150
#define ONESHOT_TIMEOUT 120




#define KEYBOARD_SCAN_INTERVAL 6
// The pin number for SCL pin
#define I2C1_SCL 15
// The pin number for SDA pin
#define I2C1_SDA 17
// Enter sleep modes after 600 seconds
#define POWER_SAVE_TIMEOUT 6000
// #define BLE_NKRO
// Force NKRO
// #define FORCE_NKRO
#define NKRO_EPSIZE 22
// Enable watchdog
// #define KBD_WDT_ENABLE
#define MAX_ENDPOINTS 8

/*
 * MIDI options
 */

/* Prevent use of disabled MIDI features in the keymap */
//#define MIDI_ENABLE_STRICT 1

/* enable basic MIDI features:
   - MIDI notes can be sent when in Music mode is on
*/

//#define MIDI_BASIC

/* enable advanced MIDI features:
   - MIDI notes can be added to the keymap
   - Octave shift and transpose
   - Virtual sustain, portamento, and modulation wheel
   - etc.
*/
//#define MIDI_ADVANCED

/* override number of MIDI tone keycodes (each octave adds 12 keycodes and allocates 12 bytes) */
//#define MIDI_TONE_KEYCODE_OCTAVES 6

#endif
