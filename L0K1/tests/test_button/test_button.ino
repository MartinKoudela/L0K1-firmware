#define BTN_PIN 4

void setup() {
  Serial.begin(115200);
  pinMode(BTN_PIN, INPUT_PULLUP);

}

void loop() {
  if (digitalRead(BTN_PIN) == LOW) {
    Serial.println("BUTTON PRESSED");
    delay(300); // debounce
  }
}