void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("L0k1 boot OK");
}

void loop() {
  Serial.println("L0k1 is alive");
  delay(1000);
}