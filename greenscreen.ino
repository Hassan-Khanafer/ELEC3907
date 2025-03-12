#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>
#include <SPI.h>

// TFT LCD connections (for Arduino Mega)
#define TFT_RST 53
#define TFT_DC  49
#define TFT_CS  47
#define TFT_MOSI 51
#define TFT_MISO 50
#define TFT_SCK  52
#define TFT_LED 3.3V // Note: LED is connected directly to 3.3V, so no code needed to control it.

// Create the display object
Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC, TFT_MOSI, TFT_SCK, TFT_RST, TFT_MISO);

void setup() {
  Serial.begin(9600);
  tft.begin();
  tft.fillScreen(ILI9341_RED); // Fill the screen with green
}

void loop() {
  // Nothing to do here, as the screen is already filled in setup()
}
