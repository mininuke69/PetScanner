#include <SoftwareSerial.h>
#include <SPI.h>
#include <SD.h>


SoftwareSerial ss(9, 10); // RX, TX
File sdLog;

String barcode;

void setup() {
  Serial.begin(9600);
  ss.begin(9600);
  delay(1000);
  Serial.println("pronto");

//--------------------------------------

  if (!SD.begin(4)) {
    Serial.println("initialization failed!");   //error check
  }
  
  sdLog = SD.open("sdLog.txt");
  if (sdLog) {
    Serial.println("sdLog.txt:");

  Serial.print("barcode.txt: ");
    while (sdLog.available()) {
      barcode = sdLog.read();
      Serial.print(barcode.c_str());
      for(const char* p=barcode.c_str(); *p; ) {
        Serial.print(*p++);
  }
    }
    sdLog.close();
    }
}


void loop() {
  sdLog = SD.open("sdLog.txt");
  
  while (sdLog.available()) {
      barcode = sdLog.read();}
  
  if (ss.available()) {
      barcode += Serial.write(ss.read());
  }

  if (sdLog) {
    sdLog.println(barcode);
    sdLog.close();}
}
