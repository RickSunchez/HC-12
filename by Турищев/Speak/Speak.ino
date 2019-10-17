 
#include <SoftwareSerial.h>

SoftwareSerial mySerial(11, 10); // RX, TX

String command_line;
void setup() {
  Serial.begin(9600);
  while (!Serial) {}
  mySerial.begin(9600);
  String split = command_line;
  String word3 = getValue(split, ';', 2);
  Serial.println(word3);  // is
  Serial.println(split);
  split.replace(word3,"not array");
  Serial.println(split);
  pinMode(3, OUTPUT);
}

void loop() {
  if (mySerial.available()) {
    char c = mySerial.read();
    command_line += c;

    if (c == '\n') {
      Serial.println(command_line);

      if (command_line.indexOf("on")+1) {
         analogWrite(3, 50);
        }

      if (command_line.indexOf("off")+1) {
         analogWrite(3, 0);
        }
      command_line = "";
      }
  }
  if (Serial.available()) {
    mySerial.write(Serial.read());
  }
  
}

String getValue(String data, char separator, int index){
  int found = 0;
  int strIndex[] = {0, -1};
  int maxIndex = data.length()-1;
  for( int i=0; i<=maxIndex && found<=index; i++ ){
    if( data.charAt(i)==separator || i==maxIndex ){
        found++;
        strIndex[0] = strIndex[1]+1;
        strIndex[1] = (i == maxIndex) ? i+1 : i;

    }

  }
  return found > index ? data.substring( strIndex[0], strIndex[1] ) : "";

}
