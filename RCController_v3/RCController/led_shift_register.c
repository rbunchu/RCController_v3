#include "led_shift_register.h"

static void led_shift_register_write(led_shift_register *, short);
static void led_shift_register_init(led_shift_register *);

led_shift_register *led_shift_register_create(short data_pin, short clock_pin, short latch_pin, short output_enable)
{
	led_shift_register *shift_register = malloc(sizeof(led_shift_register));
	shift_register->data_pin = data_pin;
	shift_register->clock_pin = clock_pin;
	shift_register->latch_pin = latch_pin;
	shift_register->output_enable = output_enable;
	
	led_shift_register_init(shift_register);
	return shift_register;
}

void led_shift_register_init(led_shift_register * shift_register)
{
	pinMode(shift_register->output_enable, OUTPUT);
	digitalWrite(shift_register->output_enable, HIGH);

	pinMode(shift_register->clock_pin, OUTPUT);
	pinMode(shift_register->data_pin, OUTPUT);
	pinMode(shift_register->latch_pin, OUTPUT);

	digitalWrite(shift_register->clock_pin, LOW);
	digitalWrite(shift_register->data_pin, LOW);
	digitalWrite(shift_register->latch_pin, LOW);
}

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