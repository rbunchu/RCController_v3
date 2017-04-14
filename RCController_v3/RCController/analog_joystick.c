#include "analog_joystic.h"


analog_joystic *analog_joystic_create(short analog_x, short analog_y, short action_button)
{
  analog_joystic *joystick = mallock(sizeof(analog_joystic));
  joystick->analog_x = analog_x;
  joystick->analog_y = analog_y;
  joystick->action_button = action_button;
  
  return analog_joystic;
}