#include <SoftwareSerial.h>
#include <SPI.h>
#include <SD.h>

SoftwareSerial ss(9, 8); // RX, TX
File EAN_file;
File log_file;



void setup() {
  Serial.begin(9600);
  ss.begin(9600);

  if (!SD.begin(10)) {
    Serial.println("initialization failed!");
    while (1);
  }    


  EAN_file = SD.open("L/EAN_file.txt", FILE_WRITE);
  log_file = SD.open("L/log_file.txt", FILE_WRITE);

  log_file.println("this is line 1");
  log_file.println("this is line 2");
  log_file.close();



  
  Serial.println("setup successful");
}


void loop() {
  if (ss.available()) {Serial.write(ss.read());}
}
