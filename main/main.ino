#include <SPI.h>
#include <SD.h>

File file;
String barcode;

String fromFile;

String writeToFile(File fileName, String dataToWrite) {
  fileName.println(dataToWrite);
  }

void setup() {
  Serial.begin(9600);
  Serial.println("\npronto");

//--------------------------------------
  Retry:
   if (!SD.begin(4)) {
    Serial.println("initialization failed!");   //error check
    goto Retry;
  }
  Serial.println("PRONTOOOOOOOO!!!!");

  
  
  file = SD.open("BarcodeTest.txt", FILE_WRITE);
  writeToFile(file, barcode);
  file.close();

  }

void loop() {
  // dix-huit, dix-neuf, vingt
}
