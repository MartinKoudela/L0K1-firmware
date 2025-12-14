#include <Adafruit_NeoPixel.h>
#define LED_PIN 18
#define LED_COUNT 8
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin();
  strip.show();
}

void loop() {
  for (int i = 0; i < LED_COUNT; i++) strip.setPixelColor(i, strip.Color(0, 50, 0));
  strip.show();
  delay(500);

  strip.clear();
  strip.show();
  delay(500);
}