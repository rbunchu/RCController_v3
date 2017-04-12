#include "tact_switch_board.h"

void tact_switch_board_init(tact_switch_board *board)
{
	board->buttons[0] = (analog_button){ .minimum = 692, .maximum = 702, .type = LIGHT_BUTTON};
	board->buttons[1] = (analog_button){ .minimum = 830, .maximum = 840, .type = BUTTON_2};
	board->buttons[2] = (analog_button){ .minimum = 922, .maximum = 932, .type = BUTTON_3};
	board->buttons[3] = (analog_button){ .minimum = 969, .maximum = 979, .type = BUTTON_4};

	pinMode(board->data_pin, INPUT);
}

analog_button tact_switch_button_pressed(tact_switch_board *switches, int value)
{
    for(int index = 0; index < 4; ++index)
    {
	    analog_button button = switches->buttons[index];
	    if(value > button.minimum && value < button.maximum)
	    {
		    return button;
	    }
    }
}
