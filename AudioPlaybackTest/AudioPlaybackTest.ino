/*
                    _ _         _______        _   
     /\            | (_)       |__   __|      | |  
    /  \  _   _  __| |_  ___      | | ___  ___| |_ 
   / /\ \| | | |/ _` | |/ _ \     | |/ _ \/ __| __|
  / ____ \ |_| | (_| | | (_) |    | |  __/\__ \ |_ 
 /_/    \_\__,_|\__,_|_|\___/     |_|\___||___/\__|
                                                   
                                                   
********************************************************************
install 'Arduino Audio Tools' library in Arduino IDE<
https://github.com/pschatzmann/arduino-audio-tools
download the library as zip and call include Library -> zip library

add a file named scratch.wav to the root directory of your SD card.

scratch.wav
File format: .wav
Bitrate: 16-bit PCM (recommended for ESP32)
Sample rate: 22kHz
Mono
File location: /scratch.wav (root directory, not inside a folder)
*********************************************************************
*/

#include <SPI.h>
#include <SD.h>
#include "AudioTools.h"
#include "AudioTools/AudioCodecs/CodecWAV.h"

// ✅ Correct SD Card SPI Pins for ESP32-A1S
#define SD_CS  13
#define SD_MOSI 15
#define SD_MISO 2
#define SD_SCK  14

SPIClass spi = SPIClass(VSPI);  // Define SPI instance for SD card

// 🎵 Audio Objects
I2SStream i2s;
EncodedAudioStream decoder(&i2s, new WAVDecoder());
StreamCopy copier;
File audioFile;

void setup() {
    Serial.begin(115200);
    delay(2000);
    Serial.println("\n🛠️ ESP32 Booted. Starting WAV Playback Test...");

    // Initialize SPI with correct SD card pins
    spi.begin(SD_SCK, SD_MISO, SD_MOSI, SD_CS);

    // ✅ Initialize SD Card
    if (!SD.begin(SD_CS, spi, 4000000, "/sd", 5)) {
        Serial.println("⚠️ ERROR: SD Card initialization failed!");
        return;
    }
    Serial.println("✅ SD Card initialized!");

    // ✅ Open WAV file
    audioFile = SD.open("/scratch.wav");
    if (!audioFile) {
        Serial.println("⚠️ ERROR: Unable to open 'scratch.wav'!");
        return;
    }
    Serial.println("✅ Playing scratch.wav...");

    // 🎵 Configure I2S Output
    auto config = i2s.defaultConfig(TX_MODE);
    i2s.begin(config);

    // 🎵 Start decoding and playback
    decoder.begin();
    copier.begin(decoder, audioFile);
}

void loop() {
    if (!copier.copy()) {
        Serial.println("Playback finished.");
        delay(5000);
    }
}
