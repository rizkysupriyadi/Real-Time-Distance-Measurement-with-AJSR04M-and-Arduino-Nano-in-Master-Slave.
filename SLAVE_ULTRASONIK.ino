#include <SoftwareSerial.h>

#define RS485_TX_EN 2

SoftwareSerial RS485Serial(3, 4); // RX, TX

const int trigPin = 5; // Pin trigger sensor ultrasonik
const int echoPin = 6; // Pin echo sensor ultrasonik

void setup() {
  pinMode(RS485_TX_EN, OUTPUT);
  digitalWrite(RS485_TX_EN, HIGH); // Set to transmit mode

  Serial.begin(9600);
  RS485Serial.begin(9600);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  // Send data from sensor to master
  digitalWrite(RS485_TX_EN, HIGH); // Set to transmit mode
  delay(10); // Allow for mode switch
  
  long duration, distance;
  digitalWrite(trigPin, LOW);  
  delayMicroseconds(2); 
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration * 0.034) / 2;

  RS485Serial.print("Distance: ");
  RS485Serial.print(distance);
  RS485Serial.println(" cm");

  delay(1000); // Kirim setiap detik
}
