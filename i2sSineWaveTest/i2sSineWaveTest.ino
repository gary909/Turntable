/*

$$\             $$\ $$\             $$\ $$\             $$\ $$\       
\$$\           $$  |\$$\           $$  |\$$\           $$  |\$$\      
 \$$\         $$  /  \$$\         $$  /  \$$\         $$  /  \$$\     
  \$$\       $$  /    \$$\       $$  /    \$$\       $$  /    \$$\    
   \$$\     $$  /      \$$\     $$  /      \$$\     $$  /      \$$\   
    \$$\   $$  /        \$$\   $$  /        \$$\   $$  /        \$$\  
     \$$\ $$  /          \$$\ $$  /          \$$\ $$  /          \$$\ 
      \__|\__/            \__|\__/            \__|\__/            \__|
                                                                      
**********************************************************************
SINE WAV TEST FOR HEADPHONES - Not yet working
**********************************************************************
*/

#include "AudioTools.h"

// ✅ I2S Audio Output
I2SStream i2s;
SineWaveGenerator<int16_t> sine(22050, 30000);  // 22kHz sample rate, 1kHz sine tone

void setup() {
    Serial.begin(115200);
    Serial.println("🛠️ Starting I2S Sine Wave Test...");

    // ✅ Correct I2S configuration for ESP32-A1S (ES8388)
    auto config = i2s.defaultConfig(TX_MODE);
    config.sample_rate = 22050;
    config.channels = 1;
    config.bits_per_sample = 16;
    i2s.begin(config);

    Serial.println("✅ Playing 1kHz sine wave...");
}

void loop() {
    int16_t sample = sine.readSample();  // ✅ Get 16-bit sample
    i2s.write(reinterpret_cast<uint8_t*>(&sample), sizeof(sample));  // ✅ Send to I2S
}
