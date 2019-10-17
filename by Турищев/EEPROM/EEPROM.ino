#include <EEPROM.h>
int i, d;

void setup() {
    Serial.begin(9600);
}

void loop() {
  // чтение EEPROM и вывод 16 данных в последовательный порт
  Serial.println();
  Serial.print("EEPROM= ");
  i= 0; while(i < 16) {  
  Serial.print((char)EEPROM.read(i));
  i++;    
  }
  
  // проверка есть ли данные для записи
  if ( Serial.available() != 0 ) {
    delay(50);  // ожидание окончания приема данных

    // запись в EEPROM
    i= 0; while(i < 20) {  
    d= Serial.read();
    if (d == -1) d= ' ';  // если символы закончились, заполнение пробелами 
    EEPROM.write(i, (byte)d);   // запись EEPROM
    i++;
    }      
  }  
  delay(500);
}
