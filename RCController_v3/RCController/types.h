#ifndef TYPES_H
#define TYPES_H

typedef enum {
	LIGHT_BUTTON = 1,
	BUTTON_2 = 2,
	BUTTON_3 = 3,
	BUTTON_4 = 4
} button_type;

typedef enum {
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