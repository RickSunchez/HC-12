#include <SoftwareSerial.h>

SoftwareSerial mySerial(10, 11); // RX, TX

String command_line;

void setup() {
  Serial.begin(9600);

  mySerial.begin(9600);
}

void loop() { // run over and over
  if (mySerial.available()) {
    char c = mySerial.read();
    command_line += c;

    if (c == '\n') {
      Serial.println(command_line);
      command_line = "";
      }
  }
  if (Serial.available()) {
    mySerial.write(Serial.read());
  }
}
