const int ledPin = 13;
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
