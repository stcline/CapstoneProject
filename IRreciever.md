/*

*/
#include <IRremote.h>

IRrecv IR(3);
int ledPin = 8;

void setup() {
  IR.enableIRIn();
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if(IR.decode()){
    Serial.println(IR.decodedIRData.decodedRawData, HEX);
    if(IR.decodedIRData.decodedRawData == 0xBF40FF00) {
      digitalWrite(ledPin, HIGH);
    }
    if(IR.decodedIRData.decodedRawData == 0xBE41FF00) {
      digitalWrite(ledPin, LOW);
    }
    delay(1500);
    IR.resume();
  }
}
