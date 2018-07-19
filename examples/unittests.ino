#include <WireMaster.h>
#include <AUnitVerbose.h>


// write() should return error if beginTransmission() hasn't been called
// This also tests that we're not using Arduino Core Wire.h
test(0_bad_transmit) {
  uint8_t ret = Wire.write(0xF);
  assertEqual(0, ret);
}



void setup() {
  delay(1000);
  Serial.begin(115200);
  while(!Serial);
}

void loop() {
  Wire.begin();
  aunit::TestRunner::run();
}