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

#define SCREEN_W 280
#define SCREEN_H 240

#define CX (SCREEN_W / 2)
#define CY (SCREEN_H / 2)

Adafruit_ST7789 tft = Adafruit_ST7789(TFT_CS, TFT_DC, TFT_RST);

enum AppState {
  STATE_WELCOME,
  STATE_MENU,
  
};

AppState currentState = STATE_WELCOME;

void recent_btn() {
  tft.fillRect(10, 200, 120, 20, ST77XX_BLACK);

  tft.setTextColor(ST77XX_GREEN);
  tft.setTextSize(1);
  tft.setCursor(10, 200);

  if (digitalRead(BTN_UP) == LOW) {
    tft.println("UP");
    delay(500);
  }
  else if (digitalRead(BTN_DOWN) == LOW) {
    tft.println("DOWN");
    delay(300);
  }
  else if (digitalRead(BTN_OK) == LOW) {
    tft.println("OK");
    delay(700);
  }
}

void handleInput() {
  if (digitalRead(BTN_OK) == LOW) {
    delay(200); // debounce

    if (currentState == STATE_WELCOME) {
      currentState = STATE_MENU;
      drawMenu();
    }
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


void setup() {
  Serial.begin(115200);
  SPI.begin(TFT_SCK, -1, TFT_MOSI, TFT_CS);

  pinMode(BTN_UP, INPUT_PULLUP);
  pinMode(BTN_DOWN, INPUT_PULLUP);
  pinMode(BTN_OK, INPUT_PULLUP);

  tft.init(240, 280);
  tft.setRotation(1);

  drawWelcome();
}

void loop() {
  handleInput();
  recent_btn(); 
}
