#include <SoftwareSerial.h>
 
#define BT_RXD 3
#define BT_TXD 2
SoftwareSerial bluetooth(BT_TXD, BT_RXD);

#define MODE_ON 1
#define MODE_OFF 0
int mode = MODE_OFF;
 
void setup(){
  Serial.begin(9600);
  bluetooth.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  
  if (mode == MODE_ON) {
    digitalWrite(LED_BUILTIN, HIGH);
  } else {
    digitalWrite(LED_BUILTIN, LOW);
  }
  
  if (bluetooth.available()) {
    mode = bluetooth.read();
    Serial.write(mode);
    bluetooth.print(mode);
  }
  
  if (Serial.available()) {
    bluetooth.write(Serial.read());
  }
}
