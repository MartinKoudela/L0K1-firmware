#include <Adafruit_NeoPixel.h>

#define LED_PIN 18
#define LED_COUNT 8

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin();
  strip.clear();
  strip.show();
}

void loop() {
  // Loki theme 
  strip.setPixelColor(0, strip.Color(0, 40, 10));
  strip.setPixelColor(1, strip.Color(0, 80, 20));
  strip.setPixelColor(2, strip.Color(10, 120, 30));
  strip.setPixelColor(3, strip.Color(0, 60, 30));
  strip.setPixelColor(4, strip.Color(0, 100, 50));
  strip.setPixelColor(5, strip.Color(5, 150, 40));
  strip.setPixelColor(6, strip.Color(0, 60, 60));
  strip.setPixelColor(7, strip.Color(10, 200, 80));

  strip.show();
  delay(700);

  strip.clear();
  strip.show();
  delay(400);
}