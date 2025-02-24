/*


 /$$  /$$$$$$                  /$$$$$$$$                    /$$    
|__/ /$$__  $$                |__  $$__/                   | $$    
 /$$|__/  \ $$  /$$$$$$$         | $$  /$$$$$$   /$$$$$$$ /$$$$$$  
| $$  /$$$$$$/ /$$_____/         | $$ /$$__  $$ /$$_____/|_  $$_/  
| $$ /$$____/ | $$               | $$| $$$$$$$$|  $$$$$$   | $$    
| $$| $$      | $$               | $$| $$_____/ \____  $$  | $$ /$$
| $$| $$$$$$$$|  $$$$$$$         | $$|  $$$$$$$ /$$$$$$$/  |  $$$$/
|__/|________/ \_______/         |__/ \_______/|_______/    \___/  
                                                                   
AS5600 i2c communication check.  Upload and open serial monitor, 
if you see: 

Scanning for I2C devices...
Found I2C device at 0x36
                                                                   
...then you're golden!

*/

#include <Wire.h>

void setup() {
    Serial.begin(115200);
    Wire.begin(21, 22); // SDA, SCL for ESP32
    Serial.println("\nI2C Scanner Running...");
}

void loop() {
    Serial.println("Scanning for I2C devices...");
    byte count = 0;
    
    for (byte address = 1; address < 127; address++) {
        Wire.beginTransmission(address);
        if (Wire.endTransmission() == 0) {
            Serial.print("Found I2C device at 0x");
            Serial.println(address, HEX);
            count++;
        }
    }
    
    if (count == 0) {
        Serial.println("No I2C devices found!");
    }
    
    delay(2000);
}
