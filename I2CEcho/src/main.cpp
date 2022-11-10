#include <Arduino.h>
#include <Wire.h>

const byte slaveAddr = 0x44;
int registerAddr;

void receiveRegister(int x);
void respondData();

void setup() {
  Wire.begin(slaveAddr);
  Wire.setClock(100000L);
  Wire.onReceive(receiveRegister);
}

void loop() {
  delay(1000);
}

void receiveRegister(int x){
  registerAddr = Wire.read();
}

void respondData() {
  Wire.write(registerAddr);
}