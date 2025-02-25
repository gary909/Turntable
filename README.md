"# Turntable" 

Proof of concept to see if I can create a scratch turntable using an ESP-32.

Set up so far:

![image](https://github.com/user-attachments/assets/4c848ccb-5c22-4d47-b0ec-797f203da7e9)


BOM:

TECNOIOT 1pc ESP32 Audio Kit ESP32-A1S ESP32

https://www.amazon.de/dp/B0DF2W3B8K?ref=ppx_yo2ov_dt_b_fed_asin_title

AS5600 12-bit magnetic Encoder

https://www.amazon.de/dp/B0B778L7T3?ref=ppx_yo2ov_dt_b_fed_asin_title

AS5600 Pin Out:

![image](https://github.com/user-attachments/assets/acef8033-916b-49b6-8074-f542889a5aec)


Scripts:

1. KeyStateTest.ino > Test to check connection with ESP32
2. i2cCheck.ino > Test to check i2c connection
3. readAngleData.ino > Test to Read the AS5600 Angle data and return the results in serial monitor.
4. sdCardCheck.ino > Test to see sd card is communicating
5. AudioPlaybackTest.ino > Test to playback audio file from SD card
