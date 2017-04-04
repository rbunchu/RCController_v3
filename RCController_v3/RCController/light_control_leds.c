#include "light_control_leds.h"

static void light_control_leds_init(light_control_leds * leds_control)
{
  leds_control->avaible_states[0] = LIGHT_LED_OFF;
  leds_control->avaible_states[1] = LIGHT_LED_MIN;
  leds_control->avaible_states[2] = LIGHT_LED_MID;
  leds_control->avaible_states[3] = LIGHT_LED_HIGH;
  leds_control->avaible_states[4] = LIGHT_LED_FULL;
  //points to first element in state array
  leds_control->actual_led_state = leds_control->avaible_states;
}


void light_control_leds_next(light_control_leds * leds, led_shift_register * shift_register)
{
  //Turn off actual state
  //Move to next state
  //Turn on next state
}