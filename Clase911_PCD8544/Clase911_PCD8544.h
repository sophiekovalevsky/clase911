//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//   7-17-2011																														//
//   Spark Fun Electronics 2011 - Nathan Seidle																						//
// 																																	//
//   This code is public domain but you buy me a beer if you use this and we meet someday (Beerware license).						//
//   This code writes a series of images and text to the Nokia 5110 84x48 graphic LCD: http://www.sparkfun.com/products/10168		//
// 																																	//
//   Do not drive the backlight with 5V. It will smoke. However, the backlight on the LCD seems to be 								//
//   happy with direct drive from the 3.3V regulator. Although the PCD8544 controller datasheet recommends 3.3V, 					//
//   the graphic Nokia 5110 LCD can run at 3.3V or 5V. No resistors needed on the signal lines.										//
//   You will need 5 signal lines to connect to the LCD, 3.3 or 5V for power, 3.3V for LED backlight, and 1 for GND.				//
//																																	//
//    ~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·~·		//
//																																	//
//	 10-02-2012 - iPadNanito@gmail.com																								//		
//	 Twitter: @iPadNanito 																											//
//	 http://Electronicavm.wordpress.com
//																								//
//	 05-01-2014 - sophiekovalevsky@fedoraproject.org
//   http://www.clase911.com
//																																//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 
#if defined(ARDUINO) && ARDUINO >= 100
 	#include "Arduino.h"
 #else
	#include "WProgram.h"
#endif

#ifndef NokiaLCD_h
	#define NokiaLCD_h

#define LCD_COMMAND 0
#define LCD_DATA 1

#define LCD_X 84
#define LCD_Y 48

#define LCDEXTENDED 0x21
#define LCDCONTRAST 0xB4	
#define LCDTEMPC 	0x04
#define LCDMODE		0x14
#define LCDBCMODE	0x20
#define LCDCONTROL  0x0C

#define uint uint8_t

class NokiaLCD
{
	public:
	    
	    NokiaLCD(uint SCK, uint MOSI, uint DC, uint RST, uint CS);
		
		void init();
		void write(byte data_or_command, byte data);
		
		void clear(void);
		void setCursor(int x, int y);
		void bitmap(unsigned char bmp[]);
		void sBitmap();
		void character(char character);
		void print(char *characters);

	private: 
		uint _SCK;
		uint _MOSI;
		uint _DC;
		uint _RST;
		uint _CS;
		unsigned char img[(84*48/8)];
};
#endif