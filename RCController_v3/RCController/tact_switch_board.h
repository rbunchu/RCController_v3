#ifndef TACT_SWITCH_BOARD_H
#define TACT_SWITCH_BOARD_H

#include "analog_button.h"

typedef struct tact_switch_board 
{
    char data_pin;
    char interrupt_pin;
    analog_button buttons[4];
} tact_switch_board;

extern tact_switch_board controller_tact_switches;
    
#endif
