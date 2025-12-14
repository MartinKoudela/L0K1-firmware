#include <Adafruit_GFX.h>
#include <Adafruit_ST7789.h>
#include <SPI.h>

#define TFT_CS   8
#define TFT_DC   9
#define TFT_RST  10
#define TFT_SCK  12
#define TFT_MOSI 11

#define BTN_UP 1
#define BTN_DOWN 2
#define BTN_OK 4
#define BTN_LEFT 5
#define BTN_RIGHT 6

#define SCREEN_W 280
#define SCREEN_H 240

#define CX (SCREEN_W / 2)
#define CY (SCREEN_H / 2)

#define GREEN  ST77XX_GREEN
#define BLACK  ST77XX_BLACK

Adafruit_ST7789 tft = Adafruit_ST7789(TFT_CS, TFT_DC, TFT_RST);

enum AppState {
  STATE_WELCOME,
  STATE_DASHBOARD,
  STATE_MENU,
  STATE_SETTINGS
};

AppState currentState = STATE_WELCOME;

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

void handleInput() {
  if (digitalRead(BTN_OK) == LOW && currentState == STATE_WELCOME) {
    currentState = STATE_DASHBOARD;
    drawDashboard();
  } else if (digitalRead(BTN_UP) == LOW && currentState == STATE_DASHBOARD) {
    currentState = STATE_MENU;
    drawMenu();
  } else if (digitalRead(BTN_DOWN) == LOW && currentState == STATE_DASHBOARD ) {
    currentState = STATE_SETTINGS;
    drawSettings();
  }
}

void drawWelcome() {
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

void drawMenu() {
  tft.fillScreen(ST77XX_BLACK);
  tft.setTextColor(ST77XX_GREEN);
  tft.setTextSize(2);
  tft.setCursor(40, 60);
  tft.println("THIS IS MENU");
}

void drawDashboard() {
  tft.fillScreen(ST77XX_BLACK);
  tft.setTextColor(ST77XX_GREEN);
  tft.setTextSize(2);
  tft.setCursor(40, 60);
  tft.println("THIS IS DASHBOARD");
}

void drawDashboard() {
  tft.fillScreen(ST77XX_BLACK);
  tft.setTextColor(ST77XX_GREEN);
  tft.setTextSize(2);
  tft.setCursor(40, 60);
  tft.println("THIS IS DASHBOARD");
}

void drawSettings() {
  tft.fillScreen(ST77XX_BLACK);
  tft.setTextColor(ST77XX_GREEN);
  tft.setTextSize(2);
  tft.setCursor(40, 60);
  tft.println("THIS IS DASHBOARD");
}

void setup() {
  Serial.begin(115200);
  SPI.begin(TFT_SCK, -1, TFT_MOSI, TFT_CS);

  pinMode(BTN_UP, INPUT_PULLUP);
  pinMode(BTN_DOWN, INPUT_PULLUP);
  pinMode(BTN_OK, INPUT_PULLUP);

  tft.init(240, 280);
  tft.setRotation(1);

  bootAnimation();
  drawWelcome();
}

void loop() {
  handleInput();
}
