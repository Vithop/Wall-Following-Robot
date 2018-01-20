#include <NewPing.h>

const int LED1 = 10;
const int LED2 = 11;
const int LED3 = 9;
const int TRIG = 12;
const int ECHO = 13;
const float distancecm = 20; 
const float maxdistancecm = 500; 
unsigned long echotime;

NewPing sonar(TRIG,ECHO,maxdistancecm);

void setup() {
  Serial.begin(9600);
  for (int x = 9; x < 13; x++){
    pinMode(x,OUTPUT);
  }
  pinMode(ECHO,INPUT);
}

void loop() {
    echotime = sonar.ping_median(10);
    Serial.println(echotime);
    if (sonar.convert_cm(echotime) < distancecm){
      digitalWrite(LED1, HIGH);
      digitalWrite(LED2, LOW);
    }else if(sonar.convert_cm(echotime) > distancecm){
      digitalWrite(LED1, LOW);
      digitalWrite(LED2, HIGH);
    }else{
      digitalWrite(LED1, HIGH);
      digitalWrite(LED2, HIGH);
      digitalWrite(LED3, HIGH);
    }
}
