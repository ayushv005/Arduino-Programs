/*
  Interfacing ultrasonic sensor with arduino
  - Ayush Vema (101411009)
*/
const int trig = 6;
const int echo = 7;

const int ledgreen = 13;
const int ledyellow = 12;
const int ledred = 11;

long duration;
float inches, cm;
float cmDivisor=29.0 , inDivisor=79.0;

void setup()  {
  Serial.begin(9600);
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  
  pinMode(ledgreen, OUTPUT);
  pinMode(ledyellow, OUTPUT);
  pinMode(ledred, OUTPUT);
}

void loop() {
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(5);
  digitalWrite(trig, LOW);
  duration = pulseIn(echo, HIGH); //returns time duration taken

  inches = duration / inDivisor / 2.0; //converts the time duration to inches
  cm = duration / cmDivisor / 2.0; //converts the time duration to cm

  ledDistance();  //glow lights acc. to distance

  Serial.print(cm);
  Serial.println(" cm");
  delay(500);  //to delay loop by .5 sec
}

void ledDistance () {

  digitalWrite(ledgreen,LOW);
  digitalWrite(ledyellow,LOW);
  digitalWrite(ledred,LOW);

  //no or very far obstacle
  if (cm > 20) {
    digitalWrite(ledgreen,HIGH);
  }

  if (cm <=20 and cm >= 10) {
    digitalWrite(ledyellow,HIGH);
  }

  if (cm < 10) {
    digitalWrite(ledred,HIGH);
  }
}
