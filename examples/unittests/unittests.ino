#include <WireMaster.h>
#include <AUnitVerbose.h>

#define SLAVE_ADDRESS	(8)

// write() should return error if beginTransmission() hasn't been called
// This also tests that we're not using Arduino Core Wire.h
test(0_bad_transmit) {
  Wire.begin();
  uint8_t ret = Wire.write(0xF);
  assertEqual(0, ret);
}


test(1_send_one_byte) {
	Wire.begin();
	Wire.beginTransmission(SLAVE_ADDRESS);
	uint8_t ret = Wire.write(0xA);	
	assertEqual(1, ret);			// Should return 1 for success
	ret = Wire.endTransmission();
	assertEqual(0, ret);			// Should return 0 for success!

	// TODO request byte
}


void setup() {
  delay(1000);
  Serial.begin(115200);
  while(!Serial);
}

void loop() {
  aunit::TestRunner::run();
}