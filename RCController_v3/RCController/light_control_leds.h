#ifndef LIGHT_CONTROL_LEDS_H
#define LIGHT_CONTROL_LEDS_H

#include "types.h"
#include "led_shift_register.h"

typedef struct light_control_leds
{
  led_shift_register *shift_register;
  info_led_type *actual_led_state;
  info_led_type avaible_states[5];
} light_control_leds;


/*
* Initialize structure with avaible states and sets state to default
*/
light_control_leds *light_control_leds_create(led_shift_register *);
/*
* Turns off actual lit led and turns on next in a row. If last led is lit then next all leds will be turned off
*/
void light_control_leds_next(light_control_leds *);


#endif