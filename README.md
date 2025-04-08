"# Turntable" 
________________________________________________________________________________________________
Proof of concept to see if I can create a scratch turntable using an ESP-32 (ESP32-A1S).

Set up so far:

![image](https://github.com/user-attachments/assets/4c848ccb-5c22-4d47-b0ec-797f203da7e9)
________________________________________________________________________________________________

________________________________________________________________________________________________

Scripts:

1. KeyStateTest.ino > Test to check connection with ESP32 > Working
2. i2cCheck.ino > Test to check i2c connection > Working
3. readAngleData.ino > Test to Read the AS5600 Angle data and return the results in serial monitor. > Working
4. sdCardCheck.ino > Test to see sd card is communicating > Working
5. i2sSineWaveTest.ino > Test to see if audio/heaphones are working ***Not yet working***
6. AudioPlaybackTest.ino > Test to playback audio file from SD card ***Not yet working***
7. ScratchTest.ino > ***NEED TO STILL WRITE THIS***

________________________________________________________________________________________________


BOM:

TECNOIOT 1pc ESP32 Audio Kit ESP32-A1S ESP32

https://www.amazon.de/dp/B0DF2W3B8K?ref=ppx_yo2ov_dt_b_fed_asin_title

AS5600 12-bit magnetic Encoder

https://www.amazon.de/dp/B0B778L7T3?ref=ppx_yo2ov_dt_b_fed_asin_title

________________________________________________________________________________________________

AS5600 Pin Out:

Update to pins:

VCC > 3v3

GND > GND

SDA (Data Line) → GPIO 18

SCL (Clock Line) → GPIO 23

