#ifndef ANALOG_BUTTON_H
#define ANALOG_BUTTON_H

#include "types.h"

typedef struct analog_button {
    short minimum;
    short maximum;
    button_type type;
} analog_button;

#endif
