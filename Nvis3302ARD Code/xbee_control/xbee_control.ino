/******************************************************************************
* FileName:        xbee_control.ino
* Dependencies:
* Processor:       AVR ATMEGA328P
* Complier:        ARDUINO
*                  ARDUINO IDE
* Company:         Nvis Technologies Pvt. Ltd.
*
*****************************************************************************
* File Description: 
* This program tellls about :
*                           here we perform a client server communication , receive instruction from server xbee and follow instructions 
*                           by all clients xbees
*                            
*                           
*                           
*                            
*Change History:
* Name                Date            Changes
* Alok Pindoriya     02/04/16    Initial Version
 ****************************************************************************/

//  initialize digital pin motor as an output

int LMotorP = 5;
int LMotorN = 6;

int RMotorP = 7;
int RMotorN = 8;

#define trigPin 13 
#define echoPin 12

int maximumRange = 200; // Maximum range needed
int minimumRange = 0; // Minimum range needed
long duration, distance; // Duration used to calculate distance



String inputString = "";         // a string to hold incoming data
boolean stringComplete = true;  // whether the string is complete

void setup()
{
  Serial.begin(9600);
  inputString.reserve(200);

  pinMode(LMotorP, OUTPUT);
  pinMode(LMotorN, OUTPUT);
  pinMode(RMotorP, OUTPUT);
  pinMode(RMotorN, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  MotorStop();
}

void loop()
{
  if (stringComplete) {
    Serial.println(inputString); 
  
    if(inputString[0] == 'W')
    {
      MotorForward();
    }
    else if(inputString[0] == 'S')
    {
      MotorReverse();
    }
    else if(inputString[0] == 'A')
    {
      MotorLeft();
    
    }
    else if(inputString[0] == 'D')
    {
      MotorRight();
     
    }
    else if(inputString[0] == 'B')
    {
      MotorStop();
    }
  

    // clear the string:
    inputString = "";
    stringComplete = false;
  }

   
}

void serialEvent() {
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read(); 
    inputString += inChar;
    if (inChar == '\n') 
      stringComplete = true;
  }
}


void MotorForward()
{

  digitalWrite(LMotorP, HIGH);
  digitalWrite(LMotorN, LOW);

  digitalWrite(RMotorP, LOW);
  digitalWrite(RMotorN, HIGH);

}

void MotorReverse()
{
  digitalWrite(LMotorP, LOW);
  digitalWrite(LMotorN, HIGH);

  digitalWrite(RMotorP, HIGH);
  digitalWrite(RMotorN, LOW);
}

void MotorLeft()
{
  digitalWrite(LMotorP, LOW);
  digitalWrite(LMotorN, HIGH);

  digitalWrite(RMotorP, LOW);
  digitalWrite(RMotorN, HIGH);
}

void MotorRight()
{
  digitalWrite(LMotorP, HIGH);
  digitalWrite(LMotorN, LOW);

  digitalWrite(RMotorP, HIGH);
  digitalWrite(RMotorN, LOW);
}

void MotorStop()
{
  digitalWrite(LMotorP, LOW);
  digitalWrite(LMotorN, LOW);

  digitalWrite(RMotorP, LOW);
  digitalWrite(RMotorN, LOW);
}










