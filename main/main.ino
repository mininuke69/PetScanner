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
  String inhoud = "";
  char letter = '978020137962';
  file = SD.open(fileNaam);
  while (file.available()) {
    Serial.println("ver");
    char a = file.read();
    boolean found = file.find(letter);
    if (found) {
      inhoud = "Gevonden!";
      Serial.println("gevonden");
    } 
    if (not found) {
        inhoud = "Niet gevonden!";
        Serial.println("niet gevonden");
    }
    //inhoud = inhoud + "x" + file.read();
    //inhoud = inhoud + file.read(); //https://cplusplus.com/reference/cstdlib/itoa/
    //Serial.print(file.readString());
    //strncat(inhoud, file.read(), 2);
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
