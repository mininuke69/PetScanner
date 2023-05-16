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

bool SDLees(String fileNaam){
  File file = SD.open(fileNaam);
  String inhoud = "";
  char letter = '0717610243697';
  bool found;
  
  /*while (file.available()) {
    char a = file.read();
    found = file.find(letter); //!!!!!!! exit here   !!!!!!!
  }*/

  found = file.find(letter);
  file.close();
  return found;
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

  //SDSchrijf("z", "a.txt");
  
  Serial.println("Barcode naar file geprint");
//---------------------------------------

  bool gevonden = SDLees("a.txt");

  if (gevonden) {
    Serial.println("Gevonden");
    }
  if (not gevonden) {
    Serial.println("Niet gevonden");
    }
  
}

void loop() {
  // dix-huit, dix-neuf, vingt
}
