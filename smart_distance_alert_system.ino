Tinkercad link:
https://www.tinkercad.com/things/aEzhju2ZEiJ/editel?returnTo=%2Fdashboard&sharecode=udvX5iNwpVKh5hZT0j1_oxtGFWsSAcIaKaJk6ivDndM
const int trigPin=9;
const int echoPin=10;
const int ledPin=13;
const int buzzerPin=8;
long duration;
int distance;
void setup(){
  pinMode(trigPin,OUTPUT);
  pinMode(ledPin,OUTPUT);
  pinMode(buzzerPin,OUTPUT);
  Serial.begin(9600);
}
void loop(){
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  duration=pulseIn(echoPin,HIGH);
  distance=duration*0.034/2;
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  if(distance<20){
    digitalWrite(ledPin,HIGH);
    digitalWrite(buzzerPin,HIGH);
  }
  else{
    digitalWrite(ledPin,LOW);
    digitalWrite(buzzerPin,LOW);
  }
  delay(200);
}
