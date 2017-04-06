/*
 * liquid_crystal_wrapper.cpp
 *
 * Created: 2017-04-06 17:01:17
 *  Author: Bunchu
 */ 

 #include "LiquidCrystal.h"
 #include "liquid_crystal_wrapper.h"

 extern "C"
 {

	 LiquidCrystal *lcd_get(uint8_t rs, uint8_t enable, uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3)
	 {
		return new LiquidCrystal(rs, enable, d0, d1, d2, d3);
	 }

	 void lcd_free(LiquidCrystal * lcd)
	 {
		delete lcd;
	 }

	 void lcd_begin(LiquidCrystal *lcd, uint8_t cols, uint8_t rows)
	 {
		lcd->begin(cols, rows);
	 }

	 void lcd_clear(LiquidCrystal *lcd)
	 {
		lcd->clear();
	 }

	 void lcd_set_cursor(LiquidCrystal *lcd, uint8_t col, uint8_t row)
	 {
		lcd->setCursor(col, row);
	 }

	 void lcd_print(LiquidCrystal *lcd, const char *text)
	 {
		lcd->print(text);
	 }
 }