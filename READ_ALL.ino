// Example 2 - Receive with an end-marker

const byte numChars = 32;
char receivedChars[numChars];   // an array to store the received data
const int ledPin = 13; // the pin that the LED is attached to

boolean newData = false;

void setup() {
    Serial.begin(115200);
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
    
    while (Serial.available() > 0 && newData == false) {
        rc = Serial.read();

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
