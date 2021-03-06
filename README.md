# FSC-BT806 Feasycom
This is a code for BT806 "Bluetooth 5.0 CSR8675" from feasycom that you can find at this link: https://www.feasycom.net/dual-mode-bluetooth-module/bluetooth-5-0-csr8675-aptx-audio-module-fsc.html


[![FSC-BT806 Feasycom](https://www.feasycom.net/uploads/201813049/small/bluetooth-5-0-csr8675-aptx-audio-module-fsc34572430494.jpg)](https://www.feasycom.net/dual-mode-bluetooth-module/bluetooth-5-0-csr8675-aptx-audio-module-fsc.html)

[*FSC-BT806 Feasycom*](https://www.feasycom.net/dual-mode-bluetooth-module/bluetooth-5-0-csr8675-aptx-audio-module-fsc.html)


[![FSC-BT806 Feasycom](https://www.feasycom.net/uploads/202013049/small/audio-bluetooth-module-csr8675-development25165022888.jpg)](https://www.feasycom.net/bluetooth-development-board/bluetooth-audio-development-board/audio-bluetooth-module-csr8675-development.html)

[*FSC-BT806 Feasycom (Development Board) (DB102-BT806)*](https://www.feasycom.net/bluetooth-development-board/bluetooth-audio-development-board/audio-bluetooth-module-csr8675-development.html)

With this code you can communicate with BT806 via UART to read most of the device status:

-Enable and disable LED,13 upon Playing/Paused

-Get the GATTSTAT status

-Get the HFPSTAT-Hands-Free Profile status

-Get the A2DPSTAT-Advanced Audio Distribution Profile status

-Get the AVRCPSTAT-Audio/Video Remote Control Profile status

-Get the PBSTAT-Bluetooth phone book access protocol CLIent status

-Get the SPPSTAT-Serial Port Profile status

-Get the DEVSTAT-Device status

-Get the HFPSIG-HFP Signal Strength status

-Get the HFPROAM-HFP Roaming status

-Get the HFPDEV-HFP Device Info Roaming status


Repository Contents
-------------------

ONLY_READ_STATUS.ino to translate the ASCII (Commands) to understandable status

READ_ALL.ino. to read all the incoming ASCII (Commands)

Run by Arduino IDE. 


Guide
-------------------

Please refer to the datasheet to locate TX,RX pins 13,14 on (Development Board) (DB102-BT806)
Make sure the baud rate 115200
