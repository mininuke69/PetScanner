#include <SPI.h>
#include <SD.h>
#include <SoftwareSerial.h>
#include <Servo.h>

/* Pins:
barcode scanner:
vcc -> 5v green
gnd -> gnd black
ss (9, 10) -> (tx purple, rx blue)

card reader
3v3 -> 3v3 purple
gnd -> gnd black
CS -> pin 4 orange
SCK -> pin 13 green
MISO -> pin 12 blue
MOSI -> door 2k2 ohm pin 11 yellow

servo
data -> pin 3 orange
gnd -> gnd black
+ -> extern + red 6V
*/

//pins def

#define SERVO_DATA_PIN 3
#define SD_CS 4
#define SERVO_OPEN_ANGLE 0
#define SERVO_CLOSED_ANGLE 100

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
      return true;
    }
  }
  file.close();
  return false;
}

//----------------------------------------

void setup() {
  Serial.begin(9600);
  Serial.println("\npronto");
  ss.begin(9600);

  servo.attach(SERVO_DATA_PIN);
  servo.write(SERVO_CLOSED_ANGLE);

//--------------------------------------
  Retry:
   if (!SD.begin(SD_CS)) {
    Serial.println("initialization failed!");
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
    String data = ss.readString();
    bool passed = SDLees("a.txt", data);

    if (passed){   //code found
      Serial.println(data);
      Serial.println("found");//ScanToken();
      ss.end();
      servo.write(SERVO_OPEN_ANGLE);
      delay(4000);
      servo.write(SERVO_CLOSED_ANGLE);
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
