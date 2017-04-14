#include "analog_joystick.h"


analog_joystick *analog_joystick_create(short analog_x, short analog_y, short action_button)
{
  analog_joystick *joystick = malloc(sizeof(analog_joystick));
  joystick->analog_x = analog_x;
  joystick->analog_y = analog_y;
  joystick->action_button = action_button;
  
  return joystick;
}