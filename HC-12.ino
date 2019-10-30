#include <SoftwareSerial.h>

SoftwareSerial mySerial(10, 11); // RX, TX

short ID = 44;
short currentQuery = 0;
bool callbackWait = false;
short switchPin = 4;
short LEDpin = 3;

String command_line;

void setup() {
  Serial.begin(9600);
  pinMode(LEDpin, OUTPUT);
  pinMode(switchPin, INPUT);
  mySerial.begin(9600);
}

void loop() { // run over and over
  if(digitalRead(switchPin) == HIGH) {
    digitalWrite(LEDpin, HIGH);
    //881122345555
    String out = "88" + String(ID) + "11" + "4" + "0" + "0000";
    mySerial.println(out);
    delay(1000);
    } else {
    digitalWrite(LEDpin, LOW);
    }
  
  if(Serial.available() > 0){
    String input = Serial.readString();
    String query = "88" + String(ID) + input + "0" + random(1, 999);
    if (input.substring(2).toInt() == 1) {
      callbackWait = true;
      }
    
    mySerial.println(query);   
  }
 
  if(mySerial.available() > 1){
    String input = mySerial.readString();
    if ( (input.substring(0,2).toInt() == 88) && (input.length() >= 7) ) {
      short fromID = input.substring(2,4).toInt();
      short toID   = input.substring(4,6).toInt();
      short comm   = input.substring(6,7).toInt();
      short reTX   = input.substring(7,8).toInt();
      short qID    = input.substring(8).toInt();

      if (qID != currentQuery) {
        currentQuery = qID; //SAVE CURRENT QUERY
        
        if (toID == ID) {
            if (comm == 0) digitalWrite(LEDpin,LOW);
            if (comm == 2 || comm == 1) digitalWrite(LEDpin,HIGH);
            if (comm == 1) {
              String callback = "88" + String(ID) + String(fromID) + String(3) + String(random(999, 9999));
              mySerial.println(callback);
              } //IF RECIEVE COMMAND 1
            if (comm == 3 && callbackWait) {
              String answer = "Find module: " + String(fromID);
              Serial.println("*******************");
              Serial.println(answer);
              Serial.println("*******************");
              callbackWait = false;
              } //IF RECIEVE COMMAND 3
          } //toID == ID

        if (toID != ID) {
          String TXquery = "88" + String(fromID) + String(toID) + String(comm) + "1" + String(qID);
          mySerial.println(TXquery);
          } //toID != ID
          
        } //CURRENT QUERY
      } //CONTROL SET + LENGTH

    //Serial.println(input);    
  }
  delay(20);
}
// command: 881122345555
// 88 - control set
// 11 - ID, from signal is
// 22 - ID, to signal is
// 3 - command:
// * 1 - find + light on
// * 0 - light off
// * 2 - light on
// * 3 - finded!
// * 4 - registration
// 4 - retranslate:
// * 0 - false
// * 1 - true
// 5555 - query ID
