#include "analog_joystic.h"


analog_joystic analog_joystic_create(short analog_x, short analog_y, short action_button)
{
  return (analog_joystic) {
    .analog_x = analog_x,
    .analog_y = analog_y,
    .action_button = action_button
  };
}