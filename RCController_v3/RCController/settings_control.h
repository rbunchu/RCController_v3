#ifndef SETTINGS_CONTROL_H
#define SETTINGS_CONTROL_H


typdef struct settings_control
{
  analog_button action_button[6];
  
} settings_control;

settings_control * settings_control_create(void);

#endif