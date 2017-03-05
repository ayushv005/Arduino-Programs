  // line follower arduino
  
  #define lmotorf 10
  #define lmotorb 11
  #define rmotorf 9
  #define rmotorb 8
  #define trigPin 5
  #define echoPin 6
  
void setup() {
  pinMode(lmotorf,OUTPUT);
  pinMode(lmotorb,OUTPUT);
  pinMode(rmotorf,OUTPUT);
  pinMode(rmotorb,OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  Serial.begin(9600);

}

void loop() {
  int lsensor=analogRead(A0);
  int rsensor=analogRead(A1);
  //Serial.println(lsensor);
  //Serial.println(rsensor);

  // prog for US to calc dist
  long duration, distance;
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2.0) / 29.1;
  Serial.println(distance);
 if(distance>10)
 {
  if((lsensor<=500)&&(rsensor<=500)) //both on white
  {
    digitalWrite(lmotorf,HIGH);
    digitalWrite(rmotorf,HIGH);
    digitalWrite(lmotorb,LOW);
    digitalWrite(rmotorb,LOW);
  }
  else if((lsensor>=500)&&(rsensor<=500)) //left on black
  {
    digitalWrite(lmotorf,HIGH);
    digitalWrite(rmotorf,LOW);
    digitalWrite(lmotorb,LOW);
    digitalWrite(rmotorb,HIGH);
  }
  else if((lsensor<=500)&&(rsensor>=500)) //right on black
  {
    digitalWrite(lmotorf,LOW);
    digitalWrite(rmotorf,HIGH);
    digitalWrite(lmotorb,HIGH);
    digitalWrite(rmotorb,LOW);
  }
  else //both on black
  {
    digitalWrite(lmotorf,LOW);
    digitalWrite(rmotorf,LOW);
    digitalWrite(lmotorb,LOW);
    digitalWrite(rmotorb,LOW);
  }
 }
 else
 {
    digitalWrite(lmotorf,LOW);
    digitalWrite(rmotorf,LOW);
    digitalWrite(lmotorb,LOW);
    digitalWrite(rmotorb,LOW);
 }
}
