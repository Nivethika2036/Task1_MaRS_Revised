Tinkercad link:
https://www.tinkercad.com/things/epJkqn19Fl0/editel?returnTo=%2Fdashboard&sharecode=fl3mKRnWmZk4lpPXgULvw_H-Sp9weoNKX4jBC0VATrU&sharecode=fl3mKRnWmZk4lpPXgULvw_H-Sp9weoNKX4jBC0VATrUconst int ledPin = 13;
const int buttonPin = 2;

unsigned long startTime;
unsigned long reactionTime;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(ledPin, LOW);

  Serial.println("Wait for the LED...");
  delay(random(2000, 5000));

  digitalWrite(ledPin, HIGH);
  startTime = millis();

  while (digitalRead(buttonPin) == LOW);

  reactionTime = millis() - startTime;

  Serial.print("Reaction Time: ");
  Serial.print(reactionTime);
  Serial.println(" ms");

  delay(3000);
}
