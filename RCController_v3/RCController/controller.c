#include "controller.h"

void controller_initialize(controller *self)
{   
    self->switches = malloc(sizeof(tact_switch_board));
    self->switches->data_pin = 1;
    self->switches->interrupt_pin = 2;
	tact_switch_board_init(self->switches);
  
    self->leds = malloc(sizeof(led_shift_register));
    self->leds->data_pin = 53;
    self->leds->clock_pin = 49;
    self->leds->latch_pin = 51;
	self->leds->output_enable = 47;

	led_shift_register_init(self->leds);

	pinMode(self->switches->interrupt_pin, OUTPUT);
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
	led_shift_register_reset(self->leds);
	digitalWrite(self->leds->output_enable, LOW);
	lcd_print(self->lcd, "Testing LEDs...");
    //Testing controller info leds
    led_shift_register_test(self->leds);
	lcd_clear(self->lcd);
	lcd_print(self->lcd, "WELCOME");
}

void controller_interrupt_buttons()
{
	int value = analogRead(rc_controller.switches->data_pin);
	analog_button button = tact_switch_button_pressed(rc_controller.switches, value);
}
