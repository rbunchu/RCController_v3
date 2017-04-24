#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "tact_switch_board.h"
#include "led_shift_register.h"
#include "light_control_leds.h"
#include "liquid_crystal_wrapper.h"
#include "analog_joystick.h"
#ifdef DEBUG
#include "hardware_serial_wrapper.h"
#endif

typedef struct controller
{
	tact_switch_board *switches;
	light_control_leds *light_leds;
	led_shift_register *leds;
	LiquidCrystal *lcd;
	analog_joystick *joystic_left;
	analog_joystick *joystic_right;
	#ifdef DEBUG
	HardwareSerial *logger;
	#endif
} controller;

extern controller rc_controller;

void controller_initialize(controller *);
void controller_interrupt_buttons();
void controller_interrupt_joystick_left();
void controller_interrupt_joystick_right();
void controller_clear(controller *);


#endif