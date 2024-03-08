#include <SoftwareSerial.h>

#define RS485_TX_EN 2

SoftwareSerial RS485Serial(3, 4); // RX, TX

void setup() {
  pinMode(RS485_TX_EN, OUTPUT);
  digitalWrite(RS485_TX_EN, LOW); // Set to receive mode

  Serial.begin(9600);
  RS485Serial.begin(9600);
}

void loop() {
  // // Request data from slave
  // Serial.println("Requesting data from slave...");

  // digitalWrite(RS485_TX_EN, HIGH); // Set to transmit mode
  // delay(10); // Allow for mode switch

  // Send request to slave
  RS485Serial.println("Request data");

  // Wait for response
  delay(100); // Adjust delay according to the response time of the slave
  
  // Read response from slave
  while (RS485Serial.available()) {
    Serial.write(RS485Serial.read());
  }
  Serial.println(); // Print new line for readability

  delay(1000); // Request data every second
}
