#ifndef ENUMS_H
#define ENUMS_H

typedef enum button_type {
	LIGHT_BUTTON = 1,
	BUTTON_2 = 2,
	BUTTON_3 = 3,
	/* Button turns on options routine, if routine is in action blocks all actions */
	OPTIONS_BUTTON = 4,
	/* Option buttons near lcd screen */
	BUTTON_OPTION_LEFT = 5,
	BUTTON_OPTION_RIGHT = 6,
	BUTTON_OPTION_UP = 7,
	BUTTON_OPTION_DOWN = 8,
	BUTTON_OPTION_CONFIRM = 9,
	Button_OPTION_RESET = 10
} button_type;

typedef enum info_led_type {
	LIGHT_LED_OFF = 0,
	LIGHT_LED_MIN = 1,
	LED_GREEN_1 = 2,
	LIGHT_LED_MID = 4,
	LED_GREEN_2 = 8,
	LIGHT_LED_HIGH = 16,
	LED_YELLOW_1 = 32,
	LIGHT_LED_FULL = 64,
	LED_YELLOW_2 = 128
} info_led_type;

#endif