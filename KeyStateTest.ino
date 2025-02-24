/*

 .-') _     ('-.    .-')    .-') _    
(  OO) )  _(  OO)  ( OO ). (  OO) )   
/     '._(,------.(_)---\_)/     '._  
|'--...__)|  .---'/    _ | |'--...__) 
'--.  .--'|  |    \  :` `. '--.  .--' 
   |  |  (|  '--.  '..`''.)   |  |    
   |  |   |  .--' .-._)   \   |  |    
   |  |   |  `---.\       /   |  |    
   `--'   `------' `-----'    `--'    

    ESP32 connected? Run this test to see: open serial monitor and press
    button 1.  If the the serial monitor changes from 1 to zero, you're 
    communicating OK.
*/

void setup() {
    Serial.begin(115200);
    pinMode(36, INPUT);  // Initialize GPIO 36 (KEY1) as an input
}

void loop() {
    int buttonState = digitalRead(36);  // Read the state of KEY1
    Serial.println(buttonState);        // Print the state to the Serial Monitor
    delay(500);                         // Wait for half a second
}
