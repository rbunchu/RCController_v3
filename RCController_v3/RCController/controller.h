#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "tact_switch_board.h"
#include "led_shift_register.h"
#include "liquid_crystal_wrapper.h"

typedef struct controller
{
    tact_switch_board *switches;
    led_shift_register *leds;
	LiquidCrystal *lcd;
} controller;


void controller_initialize(controller *);
void controller_interrupt_buttons();


#endif