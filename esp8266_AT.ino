#include "ESP8266.h"
#include <SoftwareSerial.h>

SoftwareSerial wifiSerial(11, 10); // RX, TX
ESP8266 wifi(wifiSerial);

void setup() {
  Serial.begin(9600);

  wifiSerial.begin(115200); // esp01 default Baud Rate,
  // AT+GMR
  // AT version:0.40.0.0(Aug  < 2015 14:45;58)
  // SDK vession:1.3.0

  Serial.println("Enter AT commands:");
}

void loop() {
  if (wifiSerial.available()) {
    Serial.write(wifiSerial.read());
  }

  if (Serial.available()) {
    wifiSerial.write(Serial.read());
  }
}


