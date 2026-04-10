Tinkercad link:
https://www.tinkercad.com/things/kKZXHvGeFie/editel?returnTo=%2Fdashboard&sharecode=8UMXsm-yajZW5qXM4aDOkYebBDRLzm8pSaI8Oi8pHa0&sharecode=8UMXsm-yajZW5qXM4aDOkYebBDRLzm8pSaI8Oi8pHa0
int potPin = A0;

// RGB pins
int redPin = 9;
int greenPin = 10;
int bluePin = 11;

// Blinking LED
int ledPin = 3;

unsigned long previousMillis = 0;
int interval = 500;
bool ledState = LOW;

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  int potValue = analogRead(potPin);

  //  RGB Color Control
  int redValue = map(potValue, 0, 1023, 0, 255);
  int greenValue = map(potValue, 0, 1023, 255, 0);
  int blueValue = map(potValue, 0, 1023, 128, 255);

  analogWrite(redPin, redValue);
  analogWrite(greenPin, greenValue);
  analogWrite(bluePin, blueValue);

  // Blinking Speed Control
  interval = map(potValue, 0, 1023, 100, 1000);

  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    ledState = !ledState;
    digitalWrite(ledPin, ledState);
  }
}
