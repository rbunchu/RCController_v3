#include <tact_switch_board.h>

tact_switch_board *tact_switch_board_create(char data_pin, char interrupt_pin)
{
	tact_switch_board *circuit = malloc(sizeof(tact_switch_board));
	circuit->data_pin = data_pin;
	circuit->interrupt_pin = interrupt_pin;
	
	circuit->buttons[0] = (analog_button){ .minimum = 692, .maximum = 702, .type = LIGHT_BUTTON};
	circuit->buttons[1] = (analog_button){ .minimum = 830, .maximum = 840, .type = BUTTON_2};
	circuit->buttons[2] = (analog_button){ .minimum = 922, .maximum = 932, .type = BUTTON_3};
	circuit->buttons[3] = (analog_button){ .minimum = 969, .maximum = 979, .type = OPTIONS_BUTTON};

	pinMode(circuit->data_pin, INPUT);

	return circuit;
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
