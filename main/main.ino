#include <SPI.h>
#include <SD.h>
#include <SoftwareSerial.h>

File file;
String barcode;
String fromFile;
SoftwareSerial ss(9, 8); // RX, TX


void setup() {
  Serial.begin(9600);
  Serial.println("\npronto");
  ss.begin(9600);

//--------------------------------------
  Retry:
   if (!SD.begin(4)) {
    Serial.println("initialization failed!");   //error check
    goto Retry;
  }
  Serial.println("PRONTOOOOOOOO!!!!");

  /*if (ss.available()) {
    barcode = ss.readString();}*/

  barcode = "9715600243697";
  
  Serial.println(barcode);
  file = SD.open("BarcodeTest.txt", FILE_WRITE);
  file.println(barcode);
  file.close();

  }

void loop() {
  // dix-huit, dix-neuf, vingt
}
