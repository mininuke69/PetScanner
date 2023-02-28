#include <SoftwareSerial.h>
#include <SPI.h>
#include <SD.h>


SoftwareSerial barcodeSerial(9, 10); // RX, TX
File sdLog;

int DoNewLine = 1;

String tempBarcode;
String barcode;

void setup() {
  Serial.begin(9600);
  barcodeSerial.begin(9600);
  delay(1000);
  Serial.println("pronto");

//--------------------------------------

  if (!SD.begin(4)) {
    Serial.println("initialization failed!");   //error check
  }
  
  sdLog = SD.open("sdLog.txt");
  if (sdLog) {
    Serial.println("sdLog.txt:");

  Serial.print("barcode.txt (sdLog.txt): ");
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
  
  /*while (sdLog.available()) {
      barcode = sdLog.read();} */
  
  while (barcodeSerial.available()) {
      barcode += Serial.println(barcodeSerial.read());
      Serial.write("barcode: ");
      Serial.println(barcode);
      DoNewLine += 1;
  }

  if (DoNewLine > 13){    
    Serial.println("\n");
    Serial.println("barcode: ");
    Serial.println(barcode.toInt());
    barcode = "";
    DoNewLine = 0;
  }
  

  if (sdLog) {
    sdLog.println(barcode);
    sdLog.close();}
}
