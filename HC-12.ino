#include <SoftwareSerial.h>

SoftwareSerial mySerial(10, 11); // RX, TX

void setup() {
  Serial.begin(9600);

  mySerial.begin(9600);
}

void loop() { // run over and over
  if (mySerial.available()) {
    String answer = mySerial.readString();

    if (answer.substring(0,4) == "888") {
        Serial.println(answer);
      }
  }
  if (Serial.available()) {
    mySerial.write(Serial.read());
  }
}