
/******************************************************************************
* FileName:        led_test.ino
* Dependencies:
* Processor:       AVR ATMEGA328P
* Complier:        ARDUINO
*                  ARDUINO IDE
* Company:         Nvis Technologies Pvt. Ltd.
*
*****************************************************************************
* File Description: 
* This program tellls about :
*                           it is a basic program to interface leds with arduino. 
*                           here we on and off  leds for 2 seconds.
*                           
*                            
*Change History:
* Name                Date            Changes
* Alok Pindoriya     02/04/16    Initial Version
 ****************************************************************************/


//define led pins
int led1=5;
int led2=6;
int led3=7;
int led4=8;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pins as an output.
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(led1, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(led2, HIGH);
  digitalWrite(led3, HIGH);
  digitalWrite(led4, HIGH);
  delay(2000);              // wait for a second
  digitalWrite(led1, LOW);    // turn the LED off by making the voltage LOW
   digitalWrite(led2, LOW); 
    digitalWrite(led3, LOW); 
     digitalWrite(led4, LOW); 
  delay(2000);              // wait for a second  
}
