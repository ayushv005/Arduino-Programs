/******************************************************************************
* FileName:        TX.ino
* Processor:       AVR ATMEGA328P
* Complier:        ARDUINO
*                  ARDUINO IDE
* Company:         Nvis Technologies Pvt. Ltd.
*
*****************************************************************************
* File Description: 
* This program tellls about :
*                           wireless communication between two xbee, this end act as a transmitter here we use a ultrasonic sensor so we can detect range of the object . 
*                           you will upload this program than it will run continuous in one direction and it will detect the range of object ,when object detect in our range  
*                           than it will transmit data to RX end.
*                                                 
*Change History:
* Name                Date            Changes
* Alok Pindoriya     02/04/16    Initial Version
 ****************************************************************************/


//  define ultrasonic pin (echo ,trig).

const int trigPin = 13;
const int echoPin = 12;
long duration;
int distanceCm, distanceInch;
void setup() {
 Serial.begin(9600);   //serial initlization here we are using 9600 baud rate.
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);

//  initialize digital pin motor as an output
  pinMode(5, OUTPUT);   // Right +ve)
  pinMode(6, OUTPUT);   // Right -ve
  pinMode(7, OUTPUT);   // Left -ve
  pinMode(8, OUTPUT);   // Left +ve
}

//functions for forward,backward,Anti_Rotation,Clock_Rotation and stop movments
void forward()
{
  digitalWrite(5,HIGH);   // Right +ve
  digitalWrite(6,LOW);    // Right -ve
  digitalWrite(7,LOW);    // Left -ve
  digitalWrite(8,HIGH);   // Left +ve
}
void Backward()
{
  digitalWrite(5,LOW);  
  digitalWrite(6,HIGH);   
  digitalWrite(7,HIGH);   
  digitalWrite(8,LOW);   
}
void Anti_Rotation()
{
  digitalWrite(5,HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(6,LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(7,HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(8,LOW);   // turn the LED on (HIGH is the voltage level)
}
void Clock_Rotation()
{
  digitalWrite(5,LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(6,HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(7,LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(8,HIGH);   // turn the LED on (HIGH is the voltage level)
}
void stops()
{
  digitalWrite(5,LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(6,LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(7,LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(8,LOW);   // turn the LED on (HIGH is the voltage level)
}

void loop() {

   int s=0;
  if(Serial.available()>0)
  {
    s=Serial.read();
  }
  
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distanceCm= duration*0.034/2;
distanceInch = duration*0.0133/2;

if(distanceCm<15)
{
  Serial.print('A');
  stops();
  delay(500);
}

forward();
delay(10);
}
