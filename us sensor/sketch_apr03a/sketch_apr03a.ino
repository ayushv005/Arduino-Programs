/*
  Interfacing ultrasonic sensor with arduino
  - Ayush Verma (101411009)
      
      cmDivisor = 27.6233
      inDivisor = 70.1633
*/

#include "Ultrasonic.h"

  //creating object ultrasonic and defining digital outputs for Trigger - 6, Echo - 7 resp.
Ultrasonic ultrasonic(6,7);

  //declaring digital pins for LED's
const int ledgreen = 13;
const int ledyellow = 12;
const int ledred = 11;

long microsec = 0;
float distanceCM = 0;

void setup () {
  Serial.begin(9600); //initialize serial monitor

  pinMode(ledgreen,OUTPUT);
  pinMode(ledyellow,OUTPUT);
  pinMode(ledred,OUTPUT);
}

void loop () {
  microsec = ultrasonic.timing(); //reading time delay to detect obstacle
  distanceCM = ultrasonic.convert(microsec, Ultrasonic::CM); //Converting time into distance

  ledDistance();  //glow lights acc. to distance

  Serial.print(distanceCM);
  Serial.println(" cm");
  delay(500);  //to delay loop by .5 sec
}


void ledDistance () {

  digitalWrite(ledgreen,LOW);
  digitalWrite(ledyellow,LOW);
  digitalWrite(ledred,LOW);

  //no or very far obstacle
  if (distanceCM > 20) {
    digitalWrite(ledgreen,HIGH);
  }

  if (distanceCM <=20 and distanceCM >= 10) {
    digitalWrite(ledyellow,HIGH);
  }

  if (distanceCM < 10) {
    digitalWrite(ledred,HIGH);
  }
}
