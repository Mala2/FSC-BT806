// Example 2 - Receive with an end-marker
#include<Wire.h>
#if defined(ARDUINO_SAMD_ZERO) && defined(SERIAL_PORT_USBVIRTUAL)
  // Required for Serial on Zero based boards
  #define Serial Serial
#endif

const byte numChars = 32;
char receivedChars[numChars];   // an array to store the received data
const int ledPin = 13; // the pin that the LED is attached to

boolean newData = false;

void setup() {
    Serial.begin(115200);
    Serial1.begin(115200); // Initialize hardware serial port, pins 0/1
    Serial.println("<Arduino is ready>");
    pinMode(ledPin, OUTPUT);

}

void loop() {
    recvWithEndMarker();
    showNewData();
  }
    


void recvWithEndMarker() {
    static byte ndx = 0;
    char endMarker = '\n';
    char rc;
    
    while (Serial1.available() > 0 && newData == false) {
        rc = Serial1.read();

        if (rc != endMarker) {
            receivedChars[ndx] = rc;
            ndx++;
            if (ndx >= numChars) {
                ndx = numChars - 1;
            }
        }
        else {
            receivedChars[ndx] = '\0'; // terminate the string
            ndx = 0;
            newData = true;
        }
    }
    
}

void showNewData() {
    if (newData == true) {
        Serial.print(" ... ");
        Serial.println(receivedChars);
        newData = false;
    }
}
