#include "controller.h"

void controller_initialize(controller *self)
{  
	self->switches = tact_switch_board_create(1, 2);
  self->leds = led_shift_register_create(53, 49, 51, 47);	
	self->light_leds = light_control_leds_create(self->leds);	
	self->joystic_left = analog_joystick_create(1, 5, 6);
	self->joystic_right = analog_joystick_create(1, 7, 4);

	pinMode(self->switches->interrupt_pin, OUTPUT);
	pinMode(self->joystic_left->action_button, OUTPUT);
	pinMode(self->joystic_right->action_button, OUTPUT);
	attachInterrupt(self->switches->interrupt_pin, controller_interrupt_buttons, RISING);
	attachInterrupt(self->joystic_left->action_button, controller_interrupt_joystick_left, RISING);
	attachInterrupt(self->joystic_right->action_button, controller_interrupt_joystic_right, RISING);
  
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
	
	switch(analog_button.type)
	{
		case LIGHT_BUTTON:
			light_control_leds_next(rc_controller.light_leds);
			break;
		case OPTIONS_BUTTON:
			break;
		default:
			break;
	}
}
/*
* Joystick right interrupt routine
*/
void controller_interrupt_joystic_right()
{
	
}

/*
* Joystick left interrupt routine
*/
void controller_interrupt_joystick_left()
{
	
}

/*
* Free all resource's
*/
void controller_clear(controller * ctrl)
{
	free(ctrl->joystic_right);
	free(ctrl->joystic_left);
	free(ctrl->light_leds);
	free(ctrl->leds);
	free(ctrl->switches);
}
