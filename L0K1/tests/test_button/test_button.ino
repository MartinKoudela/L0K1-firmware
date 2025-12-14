#define BTN_UP 1
#define BTN_DOWN 2
#define BTN_OK 4

// #define BTN_LEFT 4
// #define BTN_RIGHT 5

void setup() {
  Serial.begin(115200);
  pinMode(BTN_UP, INPUT_PULLUP);
  pinMode(BTN_DOWN, INPUT_PULLUP);
  pinMode(BTN_OK, INPUT_PULLUP);

  // pinMode(BTN_RIGHT, INPUT_PULLUP);
  // pinMode(BTN_LEFT, INPUT_PULLUP);

}

void loop() {
  if (digitalRead(BTN_UP) == LOW) {
    Serial.println("UP BUTTON PRESSED");
    delay(300); // debounce
  } else if (digitalRead(BTN_DOWN) == LOW) {
    Serial.println("DOWN BUTTON PRESSED");
    delay(300); // debounce
  } else if (digitalRead(BTN_OK) == LOW) {
    Serial.println("OK BUTTON PRESSED");
    delay(300); // debounce
  }
}