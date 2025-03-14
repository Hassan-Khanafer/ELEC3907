#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>

// TFT LCD connections
#define TFT_RST 53
#define TFT_DC  49
#define TFT_CS  47
#define TFT_MOSI 51
#define TFT_MISO 50
#define TFT_SCK  52

// nRF24L01 connections
#define CE_PIN 41
#define CSN_PIN 40

// Create the display object
Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC, TFT_RST);
RF24 radio(CE_PIN, CSN_PIN);

const byte address[6] = "00001"; // Must match the transmitter

void setup() {
    Serial.begin(9600);
    tft.begin();
    
    // Initialize nRF24L01
    radio.begin();
    radio.openReadingPipe(0, address);
    radio.setPALevel(RF24_PA_HIGH);
    radio.startListening(); // Set as receiver

    Serial.println("Waiting for command...");
}

void loop() {
    if (radio.available()) {
        bool command;
        radio.read(&command, sizeof(command));

        if (command) {
            tft.fillScreen(ILI9341_RED); // Fill the second screen with red
            Serial.println("Command received! Updated display.");
        }
    }
}
