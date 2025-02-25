/*

Test to see sd card is communicating

*/

#include <SPI.h>
#include <SD.h>
#include "Wire.h"  // Include I2C for ES8388 Codec

// ✅ Correct SD Card SPI Pins for ESP32-A1S
#define SD_CS  13
#define SD_MOSI 15
#define SD_MISO 2
#define SD_SCK  14

void setup() {
    Serial.begin(115200);
    Serial.println("\nInitializing SD card...");

    // 🛠️ Fix I2C communication for ES8388 codec
    Wire.begin(18, 23); // Correct I2C pins for ESP32 Audio Kit ES8388

    // 🛠️ Initialize SD Card with correct SPI pins
    if (!SD.begin(SD_CS, SPI, 4000000, "/sd", 5)) {
        Serial.println("⚠️ ERROR: SD Card initialization failed!");
        return;
    }
    Serial.println("✅ SD Card initialized successfully!");

    // Check for scratch.wav file
    Serial.println("Checking for scratch.wav...");
    if (!SD.exists("/scratch.wav")) {
        Serial.println("⚠️ ERROR: File 'scratch.wav' not found on SD card!");
        return;
    }

    Serial.println("✅ 'scratch.wav' exists on SD card!");
    Serial.println("Attempting to open file...");

    File audioFile = SD.open("/scratch.wav");
    if (!audioFile) {
        Serial.println("⚠️ ERROR: Unable to open 'scratch.wav'!");
        return;
    }

    Serial.println("✅ Successfully opened 'scratch.wav'!");
    Serial.println("File size: " + String(audioFile.size()) + " bytes");

    audioFile.close();
    Serial.println("✅ File test complete. Ready for playback!");
}

void loop() {
    // Nothing in loop, this is just a test
}
