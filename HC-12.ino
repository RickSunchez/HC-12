#include <SoftwareSerial.h>

SoftwareSerial mySerial(10, 11); // RX, TX

int ID = 1111;

String command_line;

void setup() {
  Serial.begin(9600);
  pinMode(3, OUTPUT);
  mySerial.begin(9600);
}

void loop() { // run over and over
  if(Serial.available() > 0){
    String input = Serial.readString();
    mySerial.println(input);    
  }
 
  if(mySerial.available() > 1){
    String input = mySerial.readString();
    int recieveID = input.parseInt();

    if (recieveID == ID) {
      digitalWrite(3,HIGH);
      }
    Serial.println(input);    
  }
  delay(20);
}
