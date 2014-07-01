#include <Clase911_PCD6544.h>

NokiaLCD NokiaLCD(3,4,5,6,7); // (SCK, MOSI, DC, RST, CS)

void setup()
{
  Serial.begin(9600);
  NokiaLCD.init();   // Init screen.
  NokiaLCD.clear();  // Clear screen.
}

void loop()
{
  NokiaLCD.setCursor(1,1);
  NokiaLCD.print("Hello World!");
  
  NokiaLCD.setCursor(4,2);
  NokiaLCD.print("Nokia 5510");
  
  NokiaLCD.setCursor(30,3);
  NokiaLCD.print("with");

  NokiaLCD.setCursor(15,4);
  NokiaLCD.print("Arduino");
}

// NokiaLCD NokiaLCD(SCK, MOSI, DC, RST, CS);   Connection pin to Arduino: (SCK, MOSI, DC, RST, CS)

// NokiaLCD.init();                             Init LCD, set contrast and start mode.

// NokiaLCD.clear();                            Clear the entire screen.

// NokiaLCD.setCursor(0,0);                     Set cursor on screen (row x, column y). Each character is 5 pix 

// NokiaLCD.character('A');                     Write a character.

// NokiaLCD.print("Text here");                 Write text string.

// NokiaLCD.bitmap(char array);                 Draw a byte array in screen.

// NokiaLCD.sBitmap();                          Wait for a byte array from serial port and draw it in screen. 

