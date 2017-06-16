#ifndef LED_SHIFT_REGISTER_H
#define LED_SHIFT_REGISTER_H

#include <Arduino.h>
#include <enums.h>

typedef struct led_shift_register
{
    short data_pin;
    short clock_pin;
    short latch_pin;
    short led_state;
	short output_enable;
} led_shift_register;

/*
*   Start testing all leds in sequens from led connected to first output of shift register
*   to the last output. 8 Leds in total
*/
void led_shift_register_test(led_shift_register *);
led_shift_register *led_shift_register_create(short, short, short, short);
void led_shift_register_reset(led_shift_register *);
void led_shift_register_on(led_shift_register*, info_led_type);
void led_shift_register_off(led_shift_register*, info_led_type);


#endif