#include <SoftwareSerial.h>

SoftwareSerial mySerial(10, 11); // RX, TX

int ID = 1111;
bool onReTrans = false;

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
    int recieveID = input.toInt();

    if (recieveID == ID && !onReTrans) {
      digitalWrite(3,HIGH);
      }
    else {
      mySerial.println(recieveID);
      digitalWrite(3,LOW);
      onReTrans = true;
      }
    Serial.println(input);    
  }
  delay(20);
}
///
