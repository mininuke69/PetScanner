#include <SoftwareSerial.h>
#include <SPI.h>
#include <SD.h>

SoftwareSerial ss(9, 10); // RX, TX


void setup() {
  Serial.begin(9600);
  ss.begin(9600);
  Serial.println("setup successful");
}


void loop() {
  if (ss.available()) {Serial.write(ss.read());}



}
