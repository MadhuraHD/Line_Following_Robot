const byte dir1 = 10;   
const byte dir2 = 11;   
const byte pwm1 = 13;  
const byte pwm2 = 12;  
int c=0;
unsigned long  currenttime,mili; 
void setup() {
  for(byte i=23;i<=30;i++) {
    pinMode(i,INPUT);
  }
//  for(byte i=2;i<=9;i++) {
//    pinMode(i,INPUT);
  for(byte i=10;i<=13;i++) {
    pinMode(i,OUTPUT);
  }
   digitalWrite(pwm1,LOW);
  digitalWrite(pwm2,LOW);
 Serial.begin(9600);
  }
void loop() {
  currenttime=micros();
  if((digitalRead(27) && digitalRead(28) && digitalRead(29) && digitalRead(30))&&(digitalRead(5) && digitalRead(4) && digitalRead(3) && digitalRead(2)))
    turnright();

  if((digitalRead(23) && digitalRead(24) && digitalRead(25) && digitalRead(26))&&(digitalRead(9) && digitalRead(8) && digitalRead(7) && digitalRead(6)))
    turnleft();
  
   else if((digitalRead(26) && digitalRead(27))&&(digitalRead(6) && digitalRead(5)))
  moveForward();

  else if((digitalRead(23)  || digitalRead(24))&&(digitalRead(2) || digitalRead(3)))
  moveLeft();
  
 else if((digitalRead(24)  || digitalRead(25))&&(digitalRead(3) || digitalRead(4)))
  moveLeft();
  
  else if((digitalRead(30)  || digitalRead(29))&&(digitalRead(9) || digitalRead(8)))
  moveRight();
  
  else if((digitalRead(29)  || digitalRead(28))&&(digitalRead(8)  || digitalRead(7)))
  moveRight();
 
 // else if((digitalRead() || digitalRead())&&(digitalRead() || digitalRead()))
  //moveForward();

  
else turnback();
  

mili=micros()-currenttime;
Serial.println(mili);
}
void moveLeft() {
  digitalWrite(pwm1,LOW);
  digitalWrite(pwm2,LOW);
  digitalWrite(dir1,HIGH);
  digitalWrite(dir2,LOW);
  analogWrite(pwm1,70);
  analogWrite(pwm2,100);
  c=1;
}

void moveRight() {
  digitalWrite(pwm1,LOW);
  digitalWrite(pwm2,LOW);
  digitalWrite(dir1,HIGH);
  digitalWrite(dir2,LOW);
  analogWrite(pwm1,100);
  analogWrite(pwm2,70);
  c=2;
}


void moveForward() {
  digitalWrite(pwm1,LOW);
  digitalWrite(pwm2,LOW);
  digitalWrite(dir1,HIGH);
  digitalWrite(dir2,LOW);
  analogWrite(pwm1,95);
  analogWrite(pwm2,100);
  c=3;
}
void turnback() {
  digitalWrite(pwm1,LOW);
  digitalWrite(pwm2,LOW);
  digitalWrite(dir1,HIGH);
  digitalWrite(dir2,HIGH);
  analogWrite(pwm1,100);
  analogWrite(pwm2,100);
  c=5;
}
void turnright(){
  digitalWrite(pwm1,LOW);
  digitalWrite(pwm2,LOW);
  digitalWrite(dir1,LOW);
  digitalWrite(dir2,LOW);
  analogWrite(pwm1,200);
  analogWrite(pwm2,200);
  delay(450);
  c=6;
  }
  void turnleft(){
      digitalWrite(pwm1,LOW);
  digitalWrite(pwm2,LOW);
  digitalWrite(dir1,HIGH);
  digitalWrite(dir2,LOW);
  analogWrite(pwm1,200);
  analogWrite(pwm2,200);
  delay(450);
  }
