#include <SPI.h>
#include <SD.h>

File sdLog;

String fromFile;

void setup() {
  Serial.begin(9600);
  Serial.println("pronto");

//--------------------------------------

  if (!SD.begin(4)) {
    Serial.println("initialization failed!");   //error check
  }
  
  sdLog = SD.open("gescandeBarcodes.txt");
  if (sdLog) {
    Serial.println("gescandeBarcodes.txt:");
  }

  /*if (sdLog.available()){
      sdLog.write("3800103433425");
      Serial.println("Made new file and added barcode");
      }*/
    
  
  Serial.print("Inhoud gescandeBarcodes.txt: ");
    while (sdLog.available()) {
      fromFile = sdLog.read();
      Serial.print(fromFile.c_str());
      for(const char* p=fromFile.c_str(); *p; ) {
        Serial.print(*p++);
  }
    }
    sdLog.close();
    }



void loop() {
  /*
  sdLog = SD.open("gescandeBarcodes.txt");
  
  while (sdLog.available()) {
      fromFile = sdLog.read();}

  if (sdLog) {
    sdLog.println(fromFile);
    sdLog.close();}*/
}
