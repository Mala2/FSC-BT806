int ledPin = 13;
char* readLine(char c)
{ // parameter 'c' ==> character that was read
  // return NULL ==> line not ready yet
  // return pointer ==> points to received lineBuffer
  static char lineBuffer[25]; // define maximum string length + terminating '\0'
  static byte counter=0;
  if (counter==0) memset(lineBuffer,0,sizeof(lineBuffer));// clear buffer before using it
  if (c<32) // non printable control character, line finished
  {
    if (counter==0) return NULL;
    counter=0;
    return lineBuffer;
  }
  else if (counter<sizeof(lineBuffer)-1) // printable character received and we have room for it
  {
    lineBuffer[counter]=c; // insert character into lineBuffer
    counter++; // increment character counter
  }
  return NULL;
}

 
void setup() 
{ 
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT); 
} 
 
void loop() 
{ 
  if (Serial.available())
  {
    char c=Serial.read();
    char* command= readLine(c);
    if (command!=NULL)
    {
      if (strstr(command,"+PLAYSTAT=1")!=NULL) {
      Serial.println("PLAY");
      digitalWrite(ledPin, HIGH);}

      
      else if (strstr(command,"+PLAYSTAT=2")!=NULL) {
      Serial.println("PAUSED");
      digitalWrite(ledPin, LOW);}
///GATTSTAT
      else if (strstr(command,"+GATTSTAT=0")!=NULL) {
      Serial.println("Unsupported");}
      
      else if (strstr(command,"+GATTSTAT=1")!=NULL) {
      Serial.println("Standby");}

      else if (strstr(command,"+GATTSTAT=2")!=NULL) {
      Serial.println("Connecting");}

      else if (strstr(command,"+GATTSTAT=3")!=NULL) {
      Serial.println("Connected");}
///HFPSTAT-Hands-Free Profile
      else if (strstr(command,"+HFPSTAT=0")!=NULL) {
      Serial.println("Hands-Free Profile:Unsupported");}

      else if (strstr(command,"+HFPSTAT=1")!=NULL) {
      Serial.println("Hands-Free Profile:Standby");}

      else if (strstr(command,"+HFPSTAT=2")!=NULL) {
      Serial.println("Hands-Free Profile:Connecting");}

      else if (strstr(command,"+HFPSTAT=3")!=NULL) {
      Serial.println("Hands-Free Profile:Connected");}

      else if (strstr(command,"+HFPSTAT=4")!=NULL) {
      Serial.println("Hands-Free Profile:Outgoing call");}

      else if (strstr(command,"+HFPSTAT=5")!=NULL) {
      Serial.println("Hands-Free Profile:Incoming all");}

      else if (strstr(command,"+HFPSTAT=6")!=NULL) {
      Serial.println("Hands-Free Profile:Active call");}
///A2DPSTAT-Advanced Audio Distribution Profile
      else if (strstr(command,"+A2DPSTAT=0")!=NULL) {
      Serial.println("Advanced Audio Distribution Profile:Unsupported");}

      else if (strstr(command,"+A2DPSTAT=1")!=NULL) {
      Serial.println("Advanced Audio Distribution Profile:Standby");}

      else if (strstr(command,"+A2DPSTAT=2")!=NULL) {
      Serial.println("Advanced Audio Distribution Profile:Connecting");}

      else if (strstr(command,"+A2DPSTAT=3")!=NULL) {
      Serial.println("Advanced Audio Distribution Profile:Connected");}

      else if (strstr(command,"+A2DPSTAT=4")!=NULL) {
      Serial.println("Advanced Audio Distribution Profile:Streaming");}
///AVRCPSTAT-Audio/Video Remote Control Profile
      else if (strstr(command,"+AVRCPSTAT=0")!=NULL) {
      Serial.println("Audio/Video Remote Control Profile:Unsupported");}

      else if (strstr(command,"+AVRCPSTAT=1")!=NULL) {
      Serial.println("Audio/Video Remote Control Profile:Standby");}

      else if (strstr(command,"+AVRCPSTAT=2")!=NULL) {
      Serial.println("Audio/Video Remote Control Profile:Connecting");}

      else if (strstr(command,"+AVRCPSTAT=3")!=NULL) {
      Serial.println("Audio/Video Remote Control Profile:Connected");}
///PBSTAT-Bluetooth phone book access protocol CLIent
      else if (strstr(command,"+PBSTAT=0")!=NULL) {
      Serial.println("Bluetooth phone book access protocol CLIent:Unsupported");}

      else if (strstr(command,"+PBSTAT=1")!=NULL) {
      Serial.println("Bluetooth phone book access protocol CLIent:Standby");}

      else if (strstr(command,"+PBSTAT=2")!=NULL) {
      Serial.println("Bluetooth phone book access protocol CLIent:Connecting");}

      else if (strstr(command,"+PBSTAT=3")!=NULL) {
      Serial.println("Bluetooth phone book access protocol CLIent:Connected");}

      else if (strstr(command,"+PBSTAT=4")!=NULL) {
      Serial.println("Bluetooth phone book access protocol CLIent:Downloading");}
///SPPSTAT-Serial Port Profile
      else if (strstr(command,"+SPPSTAT=0")!=NULL) {
      Serial.println("Serial Port Profile:Unsupported");}

      else if (strstr(command,"+SPPSTAT=1")!=NULL) {
      Serial.println("Serial Port Profile:Standby");}

      else if (strstr(command,"+SPPSTAT=2")!=NULL) {
      Serial.println("Serial Port Profile:Connecting");}

      else if (strstr(command,"+SPPSTAT=3")!=NULL) {
      Serial.println("Serial Port Profile:Connected");}
///DEVSTAT-Device status
      else if (strstr(command,"+DEVSTAT=7")!=NULL) {
      Serial.println("Module is power on, discoverable and advertising ");}
///HFPSIG-HFP Signal Strength
      else if (strstr(command,"+HFPSIG=1")!=NULL) {
      Serial.println("HFP Signal Strength:0 out of 5");}
      
      else if (strstr(command,"+HFPSIG=1")!=NULL) {
      Serial.println("HFP Signal Strength:1 out of 5");}

      else if (strstr(command,"+HFPSIG=2")!=NULL) {
      Serial.println("HFP Signal Strength:2 out of 5");}

      else if (strstr(command,"+HFPSIG=3")!=NULL) {
      Serial.println("HFP Signal Strength:3 out of 5");}

      else if (strstr(command,"+HFPSIG=4")!=NULL) {
      Serial.println("HFP Signal Strength:4 out of 5");}

      else if (strstr(command,"+HFPSIG=5")!=NULL) {
      Serial.println("HFP Signal Strength:5 out of 5");}
///HFPROAM-HFP Roaming state
      else if (strstr(command,"+HFPROAM=0")!=NULL) {
      Serial.println("HFP Roaming state: off");}
      
      else if (strstr(command,"+HFPROAM=1")!=NULL) {
      Serial.println("HFP Roaming state: on");}
///HFPDEV-HFP Device Info
      else if (strstr(command,"+HFPDEV=")!=NULL) {
      Serial.println("PHONE CONNECTED");}
      
  }
}}
