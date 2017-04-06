/*
 * LcdDisplay.h
 *
 * Created: 2017-04-05 20:06:00
 *  Author: Bunchu
 */ 


#ifndef LCDDISPLAY_H_
#define LCDDISPLAY_H_

#include <inttypes.h>

typedef struct lcd_display
{
	uint8_t rs;
	uint8_t enable;
	uint8_t d_0;
	uint8_t d_1;
	uint8_t d_2;
	uint8_t d_3;
	uint8_t d_4;
} lcd_display;




#endif /* LCDDISPLAY_H_ */