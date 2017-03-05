  // line follower arduino
  
  #define lmotorf 11
  #define lmotorb 10
  #define rmotorf 9
  #define rmotorb 8

void setup() {
  pinMode(lmotorf,OUTPUT);
  pinMode(lmotorb,OUTPUT);
  pinMode(rmotorf,OUTPUT);
  pinMode(rmotorb,OUTPUT);
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  Serial.begin(9600);

}

void loop() {
  int lsensor=analogRead(A0);
  int rsensor=analogRead(A1);
  Serial.println(lsensor);
  Serial.println(rsensor);
  
 
  if((lsensor<=500)&&(rsensor<=500)) //both on white
  {
    digitalWrite(lmotorf,HIGH);
    digitalWrite(rmotorf,HIGH);
    digitalWrite(lmotorb,LOW);
    digitalWrite(rmotorb,LOW);
  }
  else if((lsensor>=500)&&(rsensor<=500)) //left on black
  {
    digitalWrite(lmotorf,LOW);
    digitalWrite(rmotorf,HIGH);
    digitalWrite(lmotorb,HIGH);
    digitalWrite(rmotorb,LOW);
  }
  else if((lsensor<=500)&&(rsensor>=500)) //right on black
  {
    digitalWrite(lmotorf,HIGH);
    digitalWrite(rmotorf,LOW);
    digitalWrite(lmotorb,LOW);
    digitalWrite(rmotorb,HIGH);
  }
  else //both on black
  {
    digitalWrite(lmotorf,LOW);
    digitalWrite(rmotorf,LOW);
    digitalWrite(lmotorb,LOW);
    digitalWrite(rmotorb,LOW);
  }
}
