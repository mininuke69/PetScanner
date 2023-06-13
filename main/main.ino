#include <SPI.h>
#include <SD.h>
#include <SoftwareSerial.h>
#include <Servo.h>

Servo servo;

File file;
String barcode;
String fromFile;
//SoftwareSerial ss(9, 8); // RX, TX
SoftwareSerial ss(9, 10); // RX (tx op ding) , TX (rx op ding) //10,11

//----------------------------------------

void ScanToken(){
  Serial.println("barcode found in 'whitelisted' database");
  Serial.println("Please scan your token (optional)");
  
  bool scanned = false;
  // 15-second loop, waiting for a token
  if (scanned){
    Serial.println("thanks for scanning your token");
    //add to log or give reward or whatever
  }else{
    Serial.println("you have not scanned your token");
    //do nothing
  }
}

bool Checkbanned(String username){
  //if username is in banned list, return true
  return false;
}

void SDSchrijf(String string, String fileNaam){
  File file;
  file = SD.open(fileNaam, FILE_WRITE);
  file.println(string);
  file.close();
  }

bool SDLees(String fileNaam, String letter){
  File file = SD.open(fileNaam);
  String inhoud = "";
  bool found;
  
  while (file.available()){
    String wholeFile = file.readString();
    int index = wholeFile.indexOf(letter);
    if (index != -1) {
      return true;}
  }
  file.close();
  return false  ;
}

//----------------------------------------

void setup() {
  Serial.begin(9600);
  Serial.println("\npronto");
  ss.begin(9600);

  servo.attach(3);
  servo.write(0);

//--------------------------------------
  Retry:
   if (!SD.begin(4)) {
    Serial.println("initialization failed!");   //error check
    goto Retry;
  }

  //SDSchrijf("z", "a.txt");
  
//---------------------------------------
  /*String gescandeBarcode = ss.readString();
  Serial.println(gescandeBarcode);
  
  bool gevonden = SDLees("a.txt", gescandeBarcode);

  if (gevonden) {
    Serial.println("Gevonden");
    }
  if (not gevonden) {
    Serial.println("Niet gevonden");
    }
  */
}

void loop() {
  if (ss.available()){
    Serial.println("1");
    String data = ss.readString();
    Serial.println("2");
    Serial.println(data);
    bool passed = SDLees("a.txt", data);
    Serial.println("3");

    if (passed){   //code found
      Serial.println("found");//ScanToken();
      ss.end();
      servo.write(100);
      delay(1000);
      servo.write(0);
      ss.begin(9600);
      delay(1000);
      while(ss.available()) {
        ss.read();
        }
    }else{         //code not found
      //AddCode(data);*/
      Serial.println("not found");
    }

  }
}
