Tinkercad link:
https://www.tinkercad.com/things/6deA4FWv42q/editel?returnTo=%2Fdashboard&sharecode=u-o6L7LBuRHU3k4YGaKVmMtXQeBWp5ELoZ2T5M-nx4A
int redpin=2;
int bluepin=3;
int greenpin=4;
int led=7;
void setup(){
  pinMode(redpin,OUTPUT);
  pinMode(bluepin,OUTPUT);
  pinMode(greenpin,OUTPUT);
  pinMode(led,OUTPUT);
}
void loop(){
    int pm=analogRead(A0);
    int converted=map(pm,0,1023,0,255);
    analogWrite(redpin,converted);
    analogWrite(bluepin,converted/2);
    analogWrite(greenpin,converted/4);
    int delaytime=map(pm,0,1023,100,1000);
    digitalWrite(led,HIGH);
    delay(delaytime);
    digitalWrite(led,LOW);
    delay(delaytime);
}
