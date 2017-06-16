#ifndef ANALOG_JOYSTICK_H
#define ANALOG_JOYSTICK_H

#include <stdlib.h>

typedef struct analog_joystick {
  short analog_x;
  short analog_y;
  /*
  * This button must be connected to interrupt pin
  */
  short action_button;
} analog_joystick;

analog_joystick *analog_joystick_create(short, short, short);

#endif