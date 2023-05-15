#include <AFMotor.h> 
AF_DCMotor frm(1);
AF_DCMotor flm(2);
AF_DCMotor brm(4);
AF_DCMotor blm(3);
#define rsensor A3
#define lsensor A5
#define trigPin A0
#define echoPin A1
int distance;
void setup() {
  frm.setSpeed(230);
  flm.setSpeed(230);
  brm.setSpeed(230);
  blm.setSpeed(230);
  Serial.begin(9600);
  pinMode (rsensor,INPUT);
  pinMode (rsensor,INPUT);
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 
  

}
 int dis(){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  int duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
  return distance;
  }

void loop() {
 if(dis()> 10){

 linefollower();
 }
 else{ brm.run(RELEASE);
    blm.run(RELEASE);
    frm.run(RELEASE);
    flm.run(RELEASE);}
 
}
void linefollower(){
   if(digitalRead(rsensor)==1 && digitalRead(lsensor)==1 || digitalRead(rsensor)==0 && digitalRead(lsensor)==0){
    brm.run(FORWARD);
    blm.run(FORWARD);
    frm.run(FORWARD);
    flm.run(FORWARD);
    }
  else if(digitalRead(rsensor)==1 && digitalRead(lsensor)==0){
    frm.setSpeed(180);
    flm.setSpeed(180);
    brm.setSpeed(180);
    blm.setSpeed(180);
     brm.run(BACKWARD);
    blm.run(FORWARD);
    frm.run(BACKWARD);
    flm.run(FORWARD); 
    
  }
  else if (digitalRead(rsensor)==0 && digitalRead(lsensor)==1){
     frm.setSpeed(180);
    flm.setSpeed(180);
    brm.setSpeed(180);
    blm.setSpeed(180);
      brm.run(FORWARD);
    blm.run(BACKWARD);
    frm.run(FORWARD);
    flm.run(BACKWARD);
  }
 


}