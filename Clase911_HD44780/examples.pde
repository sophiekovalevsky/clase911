/*
Kiara Navarro
sophiekovalevsky arroba fedoraproject.org
www.clase911.com
*/
 
#include <LiquidCrystal.h> //Incluímos la librería
 
// Pinaje (LCD hacia Arduino)
// LCD pin 1 VSS a tierra
// LCD pin 2 VDD a 5 V
// LCD pin 3 Constraste a tierra (Utilizar potenciómetro)
// LCD pin 4 RS hacia el pin 12
// LCD pin 5 R/W hacia el pin 11
// LCD pin 6 Enable hacia el pin 10
// LCD pin 11 hacia el pin 5 
// LCD pin 12 hacia el pin 4
// LCD pin 13 hacia el pin 3
// LCD pin 14 hacia el pin 2
// LCD pin 15 Retroiluminación hacia el pin 13 (Utilizar resistencia)
// LCD pin 16 Tierra de retroiluminación a tierra
 
LiquidCrystal lcd(12, 11, 10, 5, 4, 3, 2);
 
int retroiluminacion = 13; // Pin 13 de retroiluminación 
 
void setup() {
	pinMode(retroiluminacion, OUTPUT);
	digitalWrite(retroiluminacion, HIGH); // Colocamos un 1 lógico al pin 13 
	lcd.begin(16,2);               // Definimos el área de la pantalla.
	lcd.clear();                   // Limpiamos pantalla
	lcd.setCursor(0,0);            // Colocamos el cursor en la posición 0,0
	lcd.print("Welcome to C911");  // Imprimos la data
	lcd.setCursor(0,1);            // Colocamos el cursos en la posición 0,1
	lcd.print("www.clase911.com"); // Imprimos la data
}
 
void loop() {

}