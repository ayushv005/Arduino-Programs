#include <IRremote.h>

 #define lmotorf 10
 #define lmotorb 11
 #define rmotorf 9
 #define rmotorb 8
 #define RECV_PIN 3
 #define statusled 13
 

IRrecv irrecv(RECV_PIN);
decode_results results;

void setup()
{

  irrecv.enableIRIn();
  pinMode(statusled,OUTPUT);
  pinMode(lmotorf,OUTPUT);
  pinMode(lmotorb,OUTPUT);
  pinMode(rmotorf,OUTPUT);
  pinMode(rmotorb,OUTPUT);
  digitalWrite(statusled,LOW);

}

void loop() {

  if (irrecv.decode(&results)) {
  
  digitalWrite(statusled,HIGH);
  
  irrecv.resume();
  
    if (results.value == 0xFF50AF){ // remote forward robot control
    
      digitalWrite(lmotorf,HIGH);
      digitalWrite(rmotorf,HIGH);
      digitalWrite(lmotorb,LOW);
      digitalWrite(rmotorb,LOW);
    
    }
    
    else if(results.value == 0xFF30CF){ // remote left robot control
    
      digitalWrite(lmotorf,HIGH);
      digitalWrite(rmotorf,LOW);
      digitalWrite(lmotorb,LOW);
      digitalWrite(rmotorb,HIGH);
    
    }
    
    else if(results.value == 0xFFB04F){ // remote right robot control
    
      digitalWrite(lmotorf,LOW);
      digitalWrite(rmotorf,HIGH);
      digitalWrite(lmotorb,HIGH);
      digitalWrite(rmotorb,LOW);
    } 
    
    else if(results.value == 0xFFD02F){ // remote backward robot control
    
      digitalWrite(lmotorf,LOW);
      digitalWrite(rmotorf,HIGH);
      digitalWrite(lmotorb,LOW);
      digitalWrite(rmotorb,HIGH);
    
    }
    
    else if(results.value == 0xFF9867){ // remote stop robot control
    
      digitalWrite(lmotorf,LOW);
      digitalWrite(rmotorf,LOW);
      digitalWrite(lmotorb,LOW);
      digitalWrite(rmotorb,LOW);
    }
  
  }

}
