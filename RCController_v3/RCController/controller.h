#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "tact_switch_board.h"
#include "led_shift_register.h"
//#include "LiquidCrystal.h"

typedef struct controller
{
    tact_switch_board *switches;
    led_shift_register *leds;
} controller;


void controller_initialize(controller *);
//static LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

#endif