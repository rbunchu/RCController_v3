#include "controller.h"

tact_switch_board controller_tact_switches;

void controller_initialize(controller *self)
{   
    self->switches = &controller_tact_switches;
    self->switches->data_pin = 1;
    self->switches->interrupt_pin = 2;
  
    self->leds = (led_shift_register*)(sizeof(led_shift_register));
    self->leds->data_pin = 53;
    self->leds->clock_pin = 49;
    self->leds->latch_pin = 51;
  
    /*lcd.begin(16,2);
    lcd.setCursor(0, 0);
    lcd.print("RC Controller");
    lcd.setCursor(0, 1);
    lcd.print("ver. 1.0");*/
    delay(2000);
    /*lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Testing LEDs...");*/
    //Testign controller info leds
    led_shift_register_test(self->leds);
    /*lcd.clear();
    lcd.print("WELCOME");*/
}
