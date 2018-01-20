#include <NewPing.h>

const int LED1 = 10;
const int LED2 = 11;
const int TRIG = 12;
const int ECHO = 13;
const int MLfoward = A1;
const int MLbackward = A2;
const int MRfoward = A3;
const int MRbackward = A4;
const float distancecm = 20; 
const float maxdistancecm = 500; 
unsigned long currenttime = 0;
unsigned long past_time = 0;
int x = 0;


NewPing sonar(TRIG,ECHO,maxdistancecm);

void setup() {
  for (int x = 10; x < 13; x++){
    pinMode(x,OUTPUT);
  }
  pinMode(ECHO,INPUT);
  pinMode(A1,OUTPUT);
  pinMode(A2,OUTPUT);
  pinMode(A3,OUTPUT);
  pinMode(A4,OUTPUT);
}

void loop() {
  currenttime = millis();
  if ((currenttime - past_time) > 5000){
    x++;
    past_time = currenttime;
  }
    if (x == 3){
      digitalWrite(LED1, HIGH);
      digitalWrite(LED2, LOW);
      analogWrite(MLfoward,0);
      analogWrite(MRfoward,255);
      analogWrite(MLbackward,255);
      analogWrite(MRbackward,0);
      x = 0;
    }else if(x == 2){
      digitalWrite(LED1, LOW);
      digitalWrite(LED2, HIGH);
      analogWrite(MLfoward,255);
      analogWrite(MRfoward,0);
      analogWrite(MLbackward,0);
      analogWrite(MRbackward,255);
    }else if (x == 1){
      digitalWrite(LED1, LOW);
      digitalWrite(LED2, LOW);
      analogWrite(MLfoward,0);
      analogWrite(MRfoward,0);
      analogWrite(MLbackward,255);
      analogWrite(MRbackward,255);
    }else{
      digitalWrite(LED1, HIGH);
      digitalWrite(LED2, HIGH);
      analogWrite(MLfoward,255);
      analogWrite(MRfoward,255);
      analogWrite(MLbackward,0);
      analogWrite(MRbackward,0);
    }
}
