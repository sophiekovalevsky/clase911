/*
Kiara Navarro
sophiekovalevsky arroba fedoraproject dot org
www.clase911.com
*/


#define echoPin 10
#define triggerPin 9
#define ledPin 13

int delaymili = 500;
int maximumRangeCm = 200;
int minimumRangeCm = 0;


long duration, distanceCm;

void setup() {
	Serial.begin(9600);
	pinMode(triggerPin, OUTPUT);
	pinMode(echoPin, INPUT);
	pinMode(ledPin, OUTPUT);
}

void loop() {
	initTrigger();

	duration = pulseIn(echoPin, HIGH);
	distanceCm = microsecCm(duration);

	if (distanceCm >= maximumRangeCm || distanceCm <= minimumRangeCm) {
		Serial.println("Out of range");
		digitalWrite(ledPin, HIGH); 
	}
	else {
		digitalWrite(ledPin, LOW);
		Serial.print("Distance in cm: ");
		Serial.println(distanceCm);
		delay(delaymili);
	}
}

long microsecCm(long microsecond) {
	return microsecond / 58;
}

void initTrigger() {
	digitalWrite(triggerPin, LOW);
	delayMicroseconds(2);
	digitalWrite(triggerPin, HIGH);
	delayMicroseconds(10);
	digitalWrite(triggerPin, LOW);
}