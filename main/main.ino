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



// DEFINE PINS
#define servo_data_pin 3
#define scanner_rx_pin 9
#define scanner_tx_pin 10
#define sd_chipselect_pin 4
#define servo_open_angle 0
#define servo_closed_angle 180

#define fileName "a.txt"

Servo servo;

File file;
String wholeFile;
String barcode;
String fromFile;
SoftwareSerial ss(scanner_rx_pin, scanner_tx_pin); // RX (tx op ding) , TX (rx op ding) //10,11



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

bool SDLees(String letter){  
  int index = wholeFile.indexOf(letter);
  if (index != -1) {
    return true;
  }
  file.close();
  return false;
}

//----------------------------------------

void setup() {
  Serial.begin(9600);
  Serial.println("\npronto");
  ss.begin(9600);

  servo.attach(servo_data_pin);
  servo.write(0);

//--------------------------------------
  Retry:
   if (!SD.begin(sd_chipselect_pin)) {
    Serial.println("initialization failed!");   //error check
    goto Retry;
  }

  File file = SD.open(fileName);
  wholeFile = file.readString();
}

void loop() {
  if (ss.available()){
    Serial.println("1");
    //String data = ss.readString();
    String data = ss.readStringUntil('-');
    Serial.println("2");
    Serial.println(data);
    bool passed = SDLees(data);
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
