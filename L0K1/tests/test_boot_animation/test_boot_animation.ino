#include <Adafruit_GFX.h>
#include <Adafruit_ST7789.h>
#include <SPI.h>

#define TFT_CS   8
#define TFT_DC   9
#define TFT_RST  10

#define TFT_SCK  12
#define TFT_MOSI 11

#define SCREEN_W 280
#define SCREEN_H 240

#define CX (SCREEN_W / 2)
#define CY (SCREEN_H / 2)


Adafruit_ST7789 tft = Adafruit_ST7789(TFT_CS, TFT_DC, TFT_RST);

#define GREEN  ST77XX_GREEN
#define BLACK  ST77XX_BLACK

void bootAnimation() {
  tft.fillScreen(ST77XX_BLACK);

  // Moon
  for (int r = 5; r < 60; r += 2) {
    tft.fillCircle(CX, CY, r, tft.color565(0, 180, 0));
    delay(20);
    tft.fillCircle(120, 140, r, ST77XX_BLACK);
  }

  // Glitch
  for (int i = 0; i < 80; i++) {
    int x = random(0, SCREEN_W);
    int y = random(0, SCREEN_H);
    int h = random(10, 40);
    tft.drawFastVLine(x, y, h, tft.color565(0, random(120,255), 0));
    delay(10);
  }

  delay(300);
  tft.fillScreen(ST77XX_BLACK);

  // Text
  tft.setTextColor(tft.color565(0, 255, 80));
  tft.setTextSize(6);
  int textWidth = 120;
  int textX = (SCREEN_W - textWidth) / 2;
  int textY = CY - 30;

  for (int x = -textWidth; x < textX; x += 6) {
    tft.fillScreen(BLACK);
    tft.setCursor(x, textY);
    tft.print("L0K1");
    delay(30);
  }

  // Glitch
 for (int i = 0; i < 6; i++) {
  tft.fillScreen(BLACK);
  tft.setCursor(textX + random(-3,3), textY + random(-3,3));
  tft.setTextColor(tft.color565(0, 255, 0));
  tft.print("L0K1");
  delay(40);
  }

  delay(400);
  tft.fillScreen(ST77XX_BLACK);
}


void setup() {
  Serial.begin(115200);
  SPI.begin(TFT_SCK, -1, TFT_MOSI, TFT_CS);

  tft.init(240, 280);
  tft.setRotation(1);

  bootAnimation();

  tft.fillScreen(ST77XX_BLACK);

  tft.setTextColor(ST77XX_GREEN);
  tft.setTextSize(2);
  tft.setCursor((SCREEN_W - 130) / 2, 40);
  tft.println("Welcome to");

  tft.setTextSize(5);
  tft.setCursor((SCREEN_W - 120) / 2, 70);
  tft.println("L0K1");

  tft.setTextSize(1);
  tft.setCursor((SCREEN_W - 140) / 2, 150);
  tft.println("Press OK to continue");

}

void loop() {
}
