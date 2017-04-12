#include "controller.h"

tact_switch_board controller_tact_switches;

void controller_initialize(controller *self)
{   
    self->switches = &controller_tact_switches;
    self->switches->data_pin = 1;
    self->switches->interrupt_pin = 2;
  
    self->leds = malloc(sizeof(led_shift_register));
    self->leds->data_pin = 53;
    self->leds->clock_pin = 49;
    self->leds->latch_pin = 51;

	pinMode(47, OUTPUT);
	digitalWrite(47, HIGH);

	pinMode(self->leds->data_pin, OUTPUT);
	pinMode(self->leds->clock_pin, OUTPUT);
	pinMode(self->leds->latch_pin, OUTPUT);
	pinMode(self->switches->interrupt_pin, OUTPUT);

	digitalWrite(self->leds->data_pin, LOW);
	digitalWrite(self->leds->clock_pin, LOW);
	digitalWrite(self->leds->latch_pin, LOW);

	attachInterrupt(self->switches->interrupt_pin, controller_interrupt_buttons, RISING);
  
	self->lcd = lcd_get(8, 9, 4, 5, 6, 7);
	lcd_begin(self->lcd, 16, 2);
	lcd_set_cursor(self->lcd, 0, 0);
	lcd_print(self->lcd, "RC Controller");
	lcd_set_cursor(self->lcd, 0, 1);
	lcd_print(self->lcd, "ver. 1.0");
    delay(2000);
	lcd_clear(self->lcd);
	lcd_set_cursor(self->lcd, 0, 0);
	delay(1000);
	led_shift_register_reset(self->leds);
	digitalWrite(47, LOW);
	lcd_print(self->lcd, "Testing LEDs...");
    //Testing controller info leds
    led_shift_register_test(self->leds);
	lcd_clear(self->lcd);
	lcd_print(self->lcd, "WELCOME");
}

void controller_interrupt_buttons()
{

}
