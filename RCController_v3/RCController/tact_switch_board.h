#ifndef TACT_SWITCH_BOARD_H
#define TACT_SWITCH_BOARD_H

#include "analog_button.h"
#include "Arduino.h"

typedef struct tact_switch_board 
{
    char data_pin;
    char interrupt_pin;
    analog_button buttons[4];
} tact_switch_board;

void tact_switch_board_init(tact_switch_board *);
analog_button tact_switch_button_pressed(tact_switch_board *, int value);
    
#endif
