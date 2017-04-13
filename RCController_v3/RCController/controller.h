#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "tact_switch_board.h"
#include "led_shift_register.h"
#include "light_control_leds.h"
#include "liquid_crystal_wrapper.h"
#include "analog_joystic.h"

typedef struct controller
{
  tact_switch_board *switches;
	light_control_leds *light_leds;
  led_shift_register *leds;
	LiquidCrystal *lcd;
	analog_joystic *joystic_left;
	analog_joystic *joystic_right;
} controller;

extern controller rc_controller;

void controller_initialize(controller *);
void controller_interrupt_buttons();


#endif