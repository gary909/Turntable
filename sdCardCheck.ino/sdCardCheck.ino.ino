/* 
 ________  ________          ________  ________  ________  ________     
|\   ____\|\   ___ \        |\   ____\|\   __  \|\   __  \|\   ___ \    
\ \  \___|\ \  \_|\ \       \ \  \___|\ \  \|\  \ \  \|\  \ \  \_|\ \   
 \ \_____  \ \  \ \\ \       \ \  \    \ \   __  \ \   _  _\ \  \ \\ \  
  \|____|\  \ \  \_\\ \       \ \  \____\ \  \ \  \ \  \\  \\ \  \_\\ \ 
    ____\_\  \ \_______\       \ \_______\ \__\ \__\ \__\\ _\\ \_______\
   |\_________\|_______|        \|_______|\|__|\|__|\|__|\|__|\|_______|
   \|_________|                                                         
                                                                        
************************************************************************
SD CARD CHECK
This checks if we have correct access to the ESP32 audio dev kits SD 
card reader.

Changes to Pins:

SDA (Data Line) → GPIO 18
SCL (Clock Line) → GPIO 23

Once uploaded, open serial monitor and check message.  No message?
Hit the reset button.
************************************************************************
*/

#include <SPI.h>
#include <SD.h>

#define SD_CS  13
#define SD_MOSI 15
#define SD_MISO 2
#define SD_SCK  14

SPIClass spi = SPIClass(VSPI); // Define SPI instance for SD card

void setup() {
    Serial.begin(115200);
    delay(2000);  // Allow Serial Monitor to start
    Serial.println("\n🛠️ ESP32 Booted. Starting SD Card Test...");

    // Setup SPI with correct SD card pins
    spi.begin(SD_SCK, SD_MISO, SD_MOSI, SD_CS);

    // Try initializing SD card in SPI mode
    if (!SD.begin(SD_CS, spi, 4000000, "/sd", 5)) {
        Serial.println("⚠️ ERROR: SD Card initialization failed!");
        return;
    }

    Serial.println("✅ SD Card initialized successfully!");
    
    // Check if the file exists
    Serial.println("Checking for scratch.wav...");
    if (!SD.exists("/scratch.wav")) {
        Serial.println("⚠️ ERROR: File 'scratch.wav' not found on SD card!");
        return;
    }

    Serial.println("✅ 'scratch.wav' exists on SD card!");
}

void loop() {
    // Nothing in loop, just testing SD card initialization
}
