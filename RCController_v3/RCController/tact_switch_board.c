#include "tact_switch_board.h"

tact_switch_board controller_tact_switches = {
    .buttons = {
        {
            .minimum = 692,
            .maximum = 702,
            .type = LIGHT_BUTTON
            
        },
        {
            .minimum = 830,
            .maximum = 840,
            .type = BUTTON_2
        },
        {
            .minimum = 922,
            .maximum = 932,
            .type = BUTTON_3
        },
        {
            .minimum = 969,
            .maximum = 979,
            .type = BUTTON_4
        }
    }
};


analog_button button_pressed(tact_switch_board *switches, short value)
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
