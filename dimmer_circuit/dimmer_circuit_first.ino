/*
Kiara Navarro
sophiekovalevsky arroba fedoraproject.org
www.clase911.com
*/

// Define the arduino pins
int led = 5;
int led2 = 6;
int led3 = 7;

void setup() {
  pinMode(led, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3,OUTPUT);
}

void loop() {
  digitalWrite(led, LOW);   
  digitalWrite(led2, LOW);    
  digitalWrite(led3, LOW);
  delay(100);
  digitalWrite(led, LOW);   
  digitalWrite(led2, LOW);    
  digitalWrite(led3, HIGH);  
  delay(100);
  digitalWrite(led, LOW);  
  digitalWrite(led2, HIGH);    
  digitalWrite(led3, LOW);  
  delay(100);
  digitalWrite(led, LOW);  
  digitalWrite(led2, HIGH);    
  digitalWrite(led3, HIGH);  
  delay(100);
  digitalWrite(led, HIGH);  
  digitalWrite(led2, LOW);    
  digitalWrite(led3, LOW);  
  delay(100);
  digitalWrite(led, HIGH);  
  digitalWrite(led2, LOW);    
  digitalWrite(led3, HIGH);  
  delay(100);
  digitalWrite(led, HIGH);  
  digitalWrite(led2, HIGH);    
  digitalWrite(led3, LOW);  
  delay(100);
  digitalWrite(led, HIGH);  
  digitalWrite(led2, HIGH);    
  digitalWrite(led3, HIGH);  
  delay(100);
}