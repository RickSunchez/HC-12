#include <SoftwareSerial.h>

SoftwareSerial mySerial(10, 11); // RX, TX

int ID = 1111;
int recieveID = 0;
bool onRT = false;

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
    if (input.toInt() != recieveID) {
      onRT = true;
      recieveID = input.toInt();
      }

    if (recieveID == ID) {
      digitalWrite(3,HIGH);
      }
    else {
      if (onRT) {
        mySerial.println(recieveID);
        digitalWrite(3,LOW);
        onRT = false;
        }
      }
    Serial.println(input);    
  }
  delay(20);
}
///
