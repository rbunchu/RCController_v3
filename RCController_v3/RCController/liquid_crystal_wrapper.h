/*
 * liquid_crystal_wrapper.h
 *
 * Created: 2017-04-06 16:55:00
 *  Author: Bunchu
 */ 


#ifndef LIQUID_CRYSTAL_WRAPPER_H_
#define LIQUID_CRYSTAL_WRAPPER_H_

#ifdef __cplusplus
extern "C" {
	#endif
	
	typedef struct LiquidCrystal LiquidCrystal;
	LiquidCrystal * controller_lcd;

	//Here goes c functions
	LiquidCrystal * lcd_get(uint8_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t);
	void lcd_free(LiquidCrystal *);
	void lcd_clear(LiquidCrystal *);
	void lcd_begin(LiquidCrystal *, uint8_t, uint8_t);
	void lcd_set_cursor(LiquidCrystal *, uint8_t, uint8_t);
	void lcd_print(LiquidCrystal *, const char *);
	
	#ifdef __cplusplus
}
#endif


#endif /* LIQUID_CRYSTAL_WRAPPER_H_ */