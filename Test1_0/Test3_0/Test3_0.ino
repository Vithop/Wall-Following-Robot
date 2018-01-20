#include <NewPing.h>

const int LED1 = 10;
const int LED2 = 11;
const int LED3 = 9;
const int TRIG = 12;
const int ECHO = 13;
const int MLfoward = A1;
const int MLbackward = A2;
const int MRfoward = A3;
const int MRbackward = A4;
const float distancecm = 20; 
const float maxdistancecm = 500; 
unsigned long echotime;
const float k = 2;
float error = 1;
float leftpower;
float rightpower;

NewPing sonar(TRIG,ECHO,maxdistancecm);

void setup() {
  for (int x = 9; x < 13; x++){
    pinMode(x,OUTPUT);
  }
  pinMode(ECHO,INPUT);
  pinMode(A1,OUTPUT);
  pinMode(A2,OUTPUT);
  pinMode(A3,OUTPUT);
  pinMode(A4,OUTPUT);
  Serial.begin(9600); 
}

void loop() {
  leftpower = 150;
  rightpower = 150;
  digitalWrite(LED3, LOW);
  echotime = sonar.ping_median(7);
  error = sonar.convert_cm(echotime) - distancecm;
  digitalWrite(LED3, HIGH);
  delay(50);
  leftpower = 150+(k*error);
  rightpower = 150 + (-k*error);
  Serial.print("error ;");
  Serial.println(error);
  Serial.print("left ;");
  Serial.println(leftpower);
  Serial.print("right  ;");
  Serial.println(rightpower);
  

  
    if (error < -3){
      digitalWrite(LED1, HIGH);
      digitalWrite(LED2, LOW);
      analogWrite(MLfoward,leftpower);
      analogWrite(MRfoward,150);
      analogWrite(MLbackward,0);
      analogWrite(MRbackward,0);
      Serial.print("close");
      }else if(error > 3){
      digitalWrite(LED1, LOW);
      digitalWrite(LED2, HIGH);
      analogWrite(MLfoward,150);
      analogWrite(MRfoward,rightpower);
      analogWrite(MLbackward,0);
      analogWrite(MRbackward,0);
      Serial.print("far");
    }else{
      digitalWrite(LED1, LOW);
      digitalWrite(LED2, LOW);
      analogWrite(MLfoward,150);
      analogWrite(MRfoward,150);
      analogWrite(MLbackward,0);
      analogWrite(MRbackward,0);
    }
    delay(50);
    analogWrite(MLfoward,0);
    analogWrite(MRfoward,0);
    analogWrite(MLbackward,0);
    analogWrite(MRbackward,0);
}
