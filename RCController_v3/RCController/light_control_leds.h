#ifndef LIGHT_CONTROL_LEDS_H
#define LIGHT_CONTROL_LEDS_H

#include "types.h"
#include "led_shift_register.h"

typedef struct light_control_leds
{
  info_led_type *actual_led_state;
  info_led_type avaible_states[5];
} light_control_leds;

static void light_control_leds_next(light_control_leds *, led_shift_register *);
/*
* Initialize structure with avaible states and sets state to default
*/
static void light_control_leds_init(light_control_leds *);


#endif