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

const byte address[6] = "00001"; // Communication channel

void setup() {
    Serial.begin(9600);
    tft.begin();
    //tft.fillScreen(ILI9341_RED); // Fill the screen with red

    // Initialize nRF24L01
    radio.begin();
    radio.openWritingPipe(address);
    radio.setPALevel(RF24_PA_HIGH);
    radio.stopListening(); // Set as transmitter
   

    // Send the command to the receiver
    bool command = true; // Dummy data to signal display update
    radio.write(&command, sizeof(command));

    tft.println("Command sent to Receiver!");
}

void loop() {
    // Nothing needed, since the display is set in setup()
}
