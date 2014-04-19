#include <Keypad.h> 
//Incluimos la librería que nos ayudará
//A utilizar las resistencias internas de pull-up del arduino
//Entre otras características
 
int count = 0;
char pass [3] = {'6', '3', '5'}; //Ingresamos la contraseña
const int amarilloPin = 9; //Espera la contraseña
const int rojoPin = 10; //Sistema Inicializado
const int verdePin = 11; //Contraseña correcta
const int audioPin = 12; //Pin para el sonido del buzzer
const int duracion = 200;
const byte ROWS = 4; 
const byte COLS = 3; 
char keys[ROWS][COLS] = {
{'1','2','3'},
{'4','5','6'},
{'7','8','9'},
{'*','0','#'}
};
byte rowPins[ROWS] = {2,3,4,5}; //Asignamos y conectamos los pines-filas-salida del keypad. Fila: 1,2,3,4
byte colPins[COLS] = {6,7,8}; //Asigamos y conectamos los pines-colum-salida del keypad. Columna: 1,2,3
 
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
 
void setup() { //Iniciamos las salidas y entradas 
	pinMode(audioPin, OUTPUT);
	pinMode(amarilloPin, OUTPUT);
	pinMode(rojoPin, OUTPUT);
	pinMode(verdePin, OUTPUT);
	inicializacion();
}
 
void loop()	{
	char key = keypad.getKey();
	if (key != NO_KEY) {
		if (key == '#') {
			codeespera();
			int entrada = 0;
			while (count < 3 ) {
				char key = keypad.getKey();
				if (key != NO_KEY) {
					entrada += 1;
					tone(audioPin, 1080, 100);
					delay(duracion);
					noTone(audioPin);
					if (key == pass[count])count += 1;
					if ( count == 3 ) desbloqueo();
					if ((key == '#') || (entrada == 3)) {
						inicializacion();
						break;
					}
				}
			}
		}
	}
}
 
//Esta función es de inicialización
//Generamos pulsos para el zumbador a una frecuencia 
//Encendemos/apgamos los leds dependiendo del estado
 
void inicializacion () {
	count = 0;
	digitalWrite(rojoPin, HIGH);
	digitalWrite(amarilloPin, LOW);
	digitalWrite(verdePin, LOW);
	tone(audioPin, 1080, 100);
	delay(duracion);
	noTone(audioPin);
	tone(audioPin, 980, 100);
	delay(duracion);
	noTone(audioPin);
	tone(audioPin, 770, 100);
	delay(duracion);
	noTone(audioPin);
}
 
//Esta función es cuando vamos a ingresar la contraseña
void codeespera() {
	count = 0;
	tone(audioPin, 1500, 100);
	delay(duracion);
	noTone(audioPin);
	tone(audioPin, 1500, 100);
	delay(duracion);
	noTone(audioPin);
	tone(audioPin, 1500, 100);
	delay(duracion);
	noTone(audioPin);
	digitalWrite(rojoPin, LOW);
	digitalWrite(amarilloPin, HIGH);
	digitalWrite(verdePin, LOW);
}
 
//Esta función nos servirá cuando se ha ingresado la contraseña
//Correctamente
void desbloqueo() {
	digitalWrite(rojoPin, LOW);
	digitalWrite(amarilloPin, LOW);
	while ( true ) {
		digitalWrite(verdePin, HIGH);
		tone(audioPin, 2000, 100);
		delay(duracion);
		noTone(audioPin);
		digitalWrite(verdePin, LOW);
		tone(audioPin, 2000, 100);
		delay(duracion);
		noTone(audioPin);
	}
}