#include <SPI.h>
#include <SD.h>

File file;
String barcode;
String fromFile;

void setup() {
  Serial.begin(9600);
  Serial.println("\npronto");

  Retry:
   if (!SD.begin(4)) {
    Serial.println("initialization failed!");   //error check
    goto Retry;
  }

  Serial.println("Verbinding gemaakt met de SD kaart");

  file = SD.open("a.txt");

  if (file) {
    Serial.println("Het bestand is geopend");
  }

  while (file.available()) {
      Serial.write(file.read());
    }

  file.close();

}

void loop() {
  // put your main code here, to run repeatedly:

}
