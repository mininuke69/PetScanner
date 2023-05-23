#include <SPI.h>
#include <SD.h>
#include <SoftwareSerial.h>


bool CheckData(String data){
  return random(0, 2);
}


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


void AddCode(String code){
  Serial.println("barcode not found in 'whitelisted' database");
  Serial.println("please scan your token to confirm add request");

  String user = "";
  bool scanned = false;
  //*token scanning loop*
  user = "Vlad";
  
  
  if (scanned){
    if (!Checkbanned(user)){
      //add the code and username
      Serial.print("code '");
      Serial.print(code);
      Serial.println("' added");
    }
  }else{
    //token not scanned, do not add
    Serial.println("code not added, reason: token not scanned");
  }

}








void setup() {
  Serial.begin(9600);

}

void loop() {
  
  if (Serial.available()){
    String data = Serial.readString();
    bool passed = CheckData(data);

    if (passed){   //code found
      ScanToken();
    }else{         //code not found
      AddCode(data);
    }

  }

}
