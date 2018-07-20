// Wire Slave Repeater
// by Charlie Matlack 2018

// This code is designed as an I2C troubleshooting tool
// When it receives data, it 
// 1) prints it out to the serial console, and
// 2) sends it back to the master, upon request

// Based on Wire Slave Receiver
// by Nicholas Zambetti <http://www.zambetti.com>

#include <Wire.h>

#define SLAVE_ADDRESS   (8)

uint8_t buffer[BUFFER_LENGTH];  // defined in Wire library
uint8_t bufferIndex = 0;
uint8_t bufferLength = 0;


// called whenever data is received from master
void receiveEvent(int howMany) {
  while (Wire.available()) { // loop through all but the last
    char c = Wire.read(); // receive byte as a character
    Serial.print(c);         // print the character
  }
}

// called whenever data requested by master
void requestEvent() {
  // TODO pop oldest byte from buffer and send
}

void setup() {
  Wire.begin(SLAVE_ADDRESS);
  Wire.onReceive(receiveEvent); 
  Wire.onRequest(requestEvent);
  Serial.begin(115200);         // start serial for output
}

void loop() {
  delay(10);
  Serial.flush();
}