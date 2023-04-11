#include <SPI.h>
#include <SD.h>
#include <SoftwareSerial.h>

File file;
String barcode;
String fromFile;
SoftwareSerial ss(9, 8); // RX, TX

//----------------------------------------

void SDSchrijf(String string, String fileNaam){
  File file;
  file = SD.open(fileNaam, FILE_WRITE);
  file.println(string);
  file.close();
  }

String SDLees(String fileNaam){
  File file;
  String inhoud;
  file = SD.open(fileNaam);
  while (file.available()) {
    //inhoud = inhoud + "x" + String(file.read());
    inhoud = inhoud + file.read(); //https://cplusplus.com/reference/cstdlib/itoa/
  }
  file.close();
  return inhoud;
}

//----------------------------------------

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

  SDSchrijf("string", "a.txt");
  
  Serial.println("Barcode naar file geprint");
//---------------------------------------

  Serial.println(SDLees("a.txt"));
}

void loop() {
  // dix-huit, dix-neuf, vingt
}
