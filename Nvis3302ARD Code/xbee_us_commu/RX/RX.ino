/******************************************************************************
* FileName:        RX.ino
* Processor:       AVR ATMEGA328P
* Complier:        ARDUINO
*                  ARDUINO IDE
* Company:         Nvis Technologies Pvt. Ltd.
*
*****************************************************************************
* File Description: 
* This program tellls about :
*                           wireless communication between two xbee, this end act as a receiver . you will upload this program 
*                           than it will run continuous in one direction when xbee will receive data from TX end than it will 
*                           stop for few seconds (it will deoends on delay we use in this program) than run again continuous 
*                           in one direction.
*                            
*Change History:
* Name                Date            Changes
* Alok Pindoriya     02/04/16    Initial Version
 ****************************************************************************/

//  initialize digital pin motor as an output
void setup() 
{
  Serial.begin(9600);   //serial initlization here we are using 9600 baud rate.
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
// the loop function runs over and over again forever
void loop()
{
  int s=0;
  if(Serial.available()>0) //here we check serial data on serial port and than read it.
  {
    s=Serial.read();
  }

forward();

if(s=='A')
{
  s=0;
  stops();
  delay(3000);
}

}
