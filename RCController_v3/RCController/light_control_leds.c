#include <light_control_leds.h>

light_control_leds * light_control_leds_create(led_shift_register * shift_register)
{
  light_control_leds *leds_control = malloc(sizeof(light_control_leds));
  
  leds_control->avaible_states[0] = LIGHT_LED_OFF;
  leds_control->avaible_states[1] = LIGHT_LED_MIN;
  leds_control->avaible_states[2] = LIGHT_LED_MID;
  leds_control->avaible_states[3] = LIGHT_LED_HIGH;
  leds_control->avaible_states[4] = LIGHT_LED_FULL;
  //points to first element in state array
  leds_control->actual_led_state = leds_control->avaible_states;
  leds_control->shift_register = shift_register;
  
  return leds_control;
}


void light_control_leds_next(light_control_leds * leds)
{
  led_shift_register_off(leds->shift_register, *leds->actual_led_state);
  delay(100);
  if(leds->actual_led_state == &leds->avaible_states[4])
  {
    leds->actual_led_state = leds->avaible_states;
  }
  else
  {
    ++leds->actual_led_state;
  }
  led_shift_register_on(leds->shift_register, *leds->actual_led_state);
}