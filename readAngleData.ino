/*

 /$$$$$$$                            /$$                                                      
| $$__  $$                          | $$                                                      
| $$  \ $$  /$$$$$$   /$$$$$$   /$$$$$$$                                                      
| $$$$$$$/ /$$__  $$ |____  $$ /$$__  $$                                                      
| $$__  $$| $$$$$$$$  /$$$$$$$| $$  | $$                                                      
| $$  \ $$| $$_____/ /$$__  $$| $$  | $$                                                      
| $$  | $$|  $$$$$$$|  $$$$$$$|  $$$$$$$                                                      
|/$$  |__/ \_______/ \_______/ \_______/                                                      
|/$$                                                                                          
|_/$$$$$$  /$$   /$$  /$$$$$$  /$$       /$$$$$$$$       /$$$$$$$   /$$$$$$  /$$$$$$$$/$$$$$$ 
 /$$__  $$| $$$ | $$ /$$__  $$| $$      | $$_____/      | $$__  $$ /$$__  $$|__  $$__/$$__  $$
| $$  \ $$| $$$$| $$| $$  \__/| $$      | $$            | $$  \ $$| $$  \ $$   | $$ | $$  \ $$
| $$$$$$$$| $$ $$ $$| $$ /$$$$| $$      | $$$$$         | $$  | $$| $$$$$$$$   | $$ | $$$$$$$$
| $$__  $$| $$  $$$$| $$|_  $$| $$      | $$__/         | $$  | $$| $$__  $$   | $$ | $$__  $$
| $$  | $$| $$\  $$$| $$  \ $$| $$      | $$            | $$  | $$| $$  | $$   | $$ | $$  | $$
| $$  | $$| $$ \  $$|  $$$$$$/| $$$$$$$$| $$$$$$$$      | $$$$$$$/| $$  | $$   | $$ | $$  | $$
|__/  |__/|__/  \__/ \______/ |________/|________/      |_______/ |__/  |__/   |__/ |__/  |__/
                                                                                              
 *********************************************************************************************
 
 Test to Read the AS5600 Angle data and return the results in serial monitor.
 The magnet needs to be between 0.5 and 3mm above the AS5600 chip.

*********************************************************************************************
*/

#include <Wire.h>

#define AS5600_ADDR 0x36
#define RAW_ANGLE_REGISTER 0x0C  // AS5600 register for raw angle data

void setup() {
    Serial.begin(115200);
    Wire.begin(21, 22); // ESP32 I2C: SDA=GPIO 21, SCL=GPIO 22
    Serial.println("\nAS5600 Angle Reader Initialized...");
}

uint16_t readRawAngle() {
    Wire.beginTransmission(AS5600_ADDR);
    Wire.write(RAW_ANGLE_REGISTER);
    Wire.endTransmission();
    Wire.requestFrom(AS5600_ADDR, 2);

    if (Wire.available() == 2) {
        uint16_t high = Wire.read();
        uint16_t low = Wire.read();
        return (high << 8) | low;  // Convert to 12-bit angle value
    }
    return 0; // Return 0 if no data available
}

void loop() {
    uint16_t rawAngle = readRawAngle();
    float angleDegrees = rawAngle * 360.0 / 4096.0; // Convert 12-bit value to degrees

    Serial.print("Angle: ");
    Serial.println(angleDegrees); // Print angle in degrees
    delay(100); // Adjust delay if needed
}
