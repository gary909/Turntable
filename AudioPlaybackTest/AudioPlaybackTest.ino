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

const int chipSelect = 13; // SD Card CS pin (modify if needed)

// Audio Objects
I2SStream i2s;  // I2S Output for ESP32 Audio Kit
EncodedAudioStream decoder(&i2s, new WAVDecoder()); // WAV Decoder
StreamCopy copier; 
File audioFile;

void setup(){
    Serial.begin(115200);
    AudioLogger::instance().begin(Serial);

    // Initialize SD Card
    if (!SD.begin(chipSelect)) {
        Serial.println("SD Card initialization failed!");
        return;
    }
    Serial.println("SD Card initialized.");

    // Open the WAV file
    audioFile = SD.open("/scratch.wav");
    if (!audioFile) {
        Serial.println("Failed to open scratch.wav!");
        return;
    }
    Serial.println("Playing scratch.wav...");

    // Setup I2S Output
    auto config = i2s.defaultConfig(TX_MODE);
    i2s.begin(config);

    // Setup decoder
    decoder.begin();

    // Begin playback
    copier.begin(decoder, audioFile);
}

void loop(){
    if (!copier.copy()) {
        Serial.println("Playback finished.");
        delay(5000);
    }
}