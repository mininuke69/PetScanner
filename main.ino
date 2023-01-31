#include <SoftwareSerial.h>

SoftwareSerial ss(9, 10); // RX, TX


void setup() {
  Serial.begin(9600);
  ss.begin(9600);
  delay(1000);
  Serial.println("pronto");
}


void loop() {
  if (ss.available()) {
      Serial.write(ss.read());
  }
}
