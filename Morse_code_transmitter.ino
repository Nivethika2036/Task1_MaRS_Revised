#Tinkercad Link
https://www.tinkercad.com/things/5KYabKtfd24/editel?returnTo=%2Fdashboard&sharecode=2iwCFytZetqjYnryyRzOncSAvwmqVtY9jRu1d32k6rs
const int ledPin = 13;
const int buzzerPin = 8;

int unit = 200; // basic time unit

// Morse code for A-Z
String morse[26] = {
  ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..",   // A-I
  ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", // J-R
  "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."         // S-Z
};

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);

  Serial.println("Enter text (A-Z):");
}

void loop() {
  if (Serial.available()) {
    String text = Serial.readStringUntil('\n');
    text.toUpperCase();

    for (int i = 0; i < text.length(); i++) {
      char c = text[i];

      if (c >= 'A' && c <= 'Z') {
        String code = morse[c - 'A'];
        Serial.print(c);
        Serial.print(": ");
        Serial.println(code);

        playMorse(code);
        delay(unit * 3); // space between letters
      }
      else if (c == ' ') {
        delay(unit * 7); // space between words
      }
    }
  }
}

void playMorse(String code) {
  for (int i = 0; i < code.length(); i++) {
    
    if (code[i] == '.') {
      signal(unit); // dot
    } 
    else if (code[i] == '-') {
      signal(unit * 3); // dash
    }

    delay(unit); // gap between symbols
  }
}

void signal(int duration) {
  digitalWrite(ledPin, HIGH);

  delay(duration);

  digitalWrite(ledPin, LOW);

  delay(unit);
}
