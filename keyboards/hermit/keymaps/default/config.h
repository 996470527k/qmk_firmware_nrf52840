#ifndef CONFIG_H
#define CONFIG_H

#include "config_common.h"

/* Bluetooth connection setting*/
#define BLE_HID_MIN_INTERVAL 7.5    /**UNIT_1_25_MS< Minimum connection interval (7.5 ms) */
#define BLE_HID_MAX_INTERVAL 30   /**UNIT_1_25_MS< Maximum connection interval (30 ms). */
#define BLE_HID_SLAVE_LATENCY 6  /**< Slave latency. */
#define BLE_HID_TIMEOUT 430       /**UNIT_10_MS< Connection supervisory timeout (430 ms). */

/* USB Device descriptor parameter */
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0xC475
#define DEVICE_VER      0x0001
#define MANUFACTURER    "99647"
#define PRODUCT         "hermit"
#define DESCRIPTION     "996470527k@gmail.com"

/* key matrix */
#define MATRIX_ROWS 7
#define MATRIX_COLS 15

// NRF52840 pin map: ((port << 5) | (pin & 0x1F))(P1点几的引脚是32加小数部分，P0点几的引脚直接是小数部分，比如P0.08是8，P0.20是20，P1.06是38（32+6））
#define MATRIX_ROW_PINS \
{ 13, 24, 32, 45, 8, 2, 38 }
#define MATRIX_COL_PINS \
{ 43, 42, 3, 29, 30, 31, 26, 41, 6, 12, 7, 36, 22, 20, 34 }

#ifdef RGBLIGHT_ENABLE
	//#define RGB_DI_PIN 28
	//#define RGBLED_NUM 7
	//#define RGBLIGHT_ANIMATIONS
	#define RGB_DI_PIN 28
#ifdef RGB_DI_PIN
#define RGBLIGHT_ANIMATIONS
#define RGBLED_NUM 7
#define RGBLIGHT_LED_MAP { 0,1,2,3,4,5,6}
#define RGBLIGHT_HUE_STEP 8
#define RGBLIGHT_SAT_STEP 8
#define RGBLIGHT_VAL_STEP 8
#define RGBLIGHT_SLEEP
#define RGBLIGHT_LIMIT_VAL 255
#define RGBLIGHT_LAYERS
#endif

#endif

#define DEBOUNCE 20
#define BLUETOOTH_ENABLE


#define PERMISSVIE_HOLD
#define IGNORE_MOD_TAP_INTERRUPT
#define TAPPING_FORCE_HOLD
#define TAPPING_TERM 150
#define ONESHOT_TIMEOUT 120

#ifdef RGB_MATRIX_ENABLE
	#define RGB_MATRIX_KEYPRESSES
	#define RGB_MATRIX_FRAMEBUFFER_EFFECTS
	#define RGB_MATRIX_LED_PROCESS_LIMIT 20
	#define RGB_MATRIX_LED_FLUSH_LIMIT 26
	#define DRIVER_ADDR_1 0b1010000
	#define DRIVER_ADDR_2 0b1011111

	#define DRIVER_COUNT 2
	#define DRIVER_1_LED_TOTAL 48
	#define DRIVER_2_LED_TOTAL 48
	#define DRIVER_LED_TOTAL DRIVER_1_LED_TOTAL + DRIVER_2_LED_TOTAL

	// #define DISABLE_RGB_MATRIX_ALPHAS_MODS
	// #define DISABLE_RGB_MATRIX_GRADIENT_UP_DOWN
	//#define DISABLE_RGB_MATRIX_BREATHING
	//#define DISABLE_RGB_MATRIX_BAND_SAT
	//#define DISABLE_RGB_MATRIX_BAND_PINWHEEL_SAT
	//#define DISABLE_RGB_MATRIX_BAND_SPIRAL_SAT
	//#define DISABLE_RGB_MATRIX_RAINDROPS
	//#define DISABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
	//#define DISABLE_RGB_MATRIX_TYPING_HEATMAP
	//#define DISABLE_RGB_MATRIX_DIGITAL_RAIN
	//#define DISABLE_RGB_MATRIX_SOLID_REACTIVE
	//#define DISABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
	//#define DISABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
	//#define DISABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS
	//#define DISABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS
	//#define DISABLE_RGB_MATRIX_SPLASH
	//#define DISABLE_RGB_MATRIX_SOLID_SPLASH
#endif

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
