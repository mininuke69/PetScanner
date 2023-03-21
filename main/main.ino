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
  
  Serial.println("Verbinding gemaakt met de SD kaart");

  barcode = "give";

  Serial.println(barcode);
  file = SD.open("a.txt", FILE_WRITE);
  file.println(barcode);
  file.close();
  Serial.println("Barcode naar file geprint");
}

void loop() {
  // dix-huit, dix-neuf, vingt
}
