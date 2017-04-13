#ifndef ANALOG_JOYSTICK_H
#define ANALOG_JOYSTICK_H

typedef struct analog_joystick {
  short analog_x;
  short analog_y;
  short action_button;
} analog_joystick;

analog_joystick *analog_joystick_create(short, short, short);

#endif