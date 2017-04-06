#include "led_shift_register.h"

static void led_shift_register_write(led_shift_register *, short);


void led_shift_register_test(led_shift_register *shift_register)
{
	shift_register->led_state = 1;
    for(shift_register->led_state; shift_register->led_state <= 128; shift_register->led_state = shift_register->led_state * 2)
    {
      led_shift_register_write(shift_register, shift_register->led_state);
	  delay(200);
    }
    
    led_shift_register_reset(shift_register);
}

void led_shift_register_reset(led_shift_register *shift_register)
{
    shift_register->led_state = 0;
    led_shift_register_write(shift_register, shift_register->led_state);
}

void led_shift_register_on(led_shift_register* shift_register, info_led_type led)
{
  shift_register->led_state = shift_register->led_state & (short)led;
  led_shift_register_write(shift_register, shift_register->led_state);
}

void led_shift_register_off(led_shift_register* shift_register, info_led_type led)
{
  shift_register->led_state = shift_register->led_state & (!(short)led);
  led_shift_register_write(shift_register, shift_register->led_state);
}

void led_shift_register_write(led_shift_register *shift_register, short value)
{
    digitalWrite(shift_register->latch_pin, LOW);
    shiftOut(shift_register->data_pin, shift_register->clock_pin, MSBFIRST, value);
    digitalWrite(shift_register->latch_pin, HIGH);
}