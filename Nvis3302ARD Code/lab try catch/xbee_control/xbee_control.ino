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

char inChar='x';

void setup()
{
  Serial.begin(9600);
 
  pinMode(LMotorP, OUTPUT);
  pinMode(LMotorN, OUTPUT);
  pinMode(RMotorP, OUTPUT);
  pinMode(RMotorN, OUTPUT);

  MotorStop();
}

void loop()
{
    if (Serial.available() > 0)
      inChar = (char)Serial.read(); 
    if (1) {
    Serial.println(inChar); 
  
    if(inChar == 'W')
    {
      MotorForward();
    }
    else if(inChar == 'S')
    {
      MotorReverse();
    }
    else if(inChar == 'D')
    {
      MotorLeft();
    }
    else if(inChar == 'A')
    {
      MotorRight();   
    }
    else if(inChar == 'B')
    {
      MotorStop();
    }
 
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










