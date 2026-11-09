const int soundPin = A0;
const int ledPin = 11; // change to 13 if you want to use inbuilt LED

int threshold = 550; // Tune this - check Serial Monitor
bool ledState = false; // LED is OFF at start
long lastClapTime = 0;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(soundPin, INPUT);
  digitalWrite(ledPin, LOW);
  Serial.println("Clap Switch Ready...");
}

void loop() {
  int soundValue = analogRead(soundPin);
  Serial.println(soundValue);

  // If sound is loud AND 500ms passed since last clap (to avoid double clap)
  if (soundValue > threshold) {
    if (millis() - lastClapTime > 500) {
      
      ledState = !ledState; // TOGGLE
      digitalWrite(ledPin, ledState);
      
      if(ledState) {
        Serial.println("CLAP DETECTED -> LED ON");
      } else {
        Serial.println("CLAP DETECTED -> LED OFF");
      }
      
      lastClapTime = millis();
      delay(200); // small delay
    }
  }
}
