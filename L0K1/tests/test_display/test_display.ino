#include <Adafruit_GFX.h>
#include <Adafruit_ST7789.h>
#include <SPI.h>

#define TFT_CS   10
#define TFT_DC   9
#define TFT_RST  8

Adafruit_ST7789 tft = Adafruit_ST7789(TFT_CS, TFT_DC, TFT_RST);

void setup() {
  Serial.begin(115200);
  Serial.println("ST7789 test");

  SPI.begin(12, -1, 11, TFT_CS); 

  tft.init(240, 280); 
  tft.setRotation(3);
  tft.fillScreen(ST77XX_BLACK);

  tft.setTextColor(ST77XX_GREEN);
  tft.setTextSize(3);
  tft.setCursor(20, 40);
  tft.println("Welcome to");

  tft.setTextSize(6);
  tft.setCursor(20, 80);
  tft.println("L0K1");
}

void loop() {




}