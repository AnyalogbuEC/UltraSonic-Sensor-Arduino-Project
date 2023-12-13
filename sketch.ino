// Ultrasonic Sensor Arduino Project
//
// Written by AnyalogbuEC for demonstration purposes.
// For more information, visit g.dev/Anyalogbu_EC.
// This program measures distance using an ultrasonic sensor.
// Visual indication of distance is provided by an LED.
//
// Components used:
//    1. Arduino board (UNO, Nano) and its corresponding USB cord.
//    2. Ultrasonic sensor (HC-SR04).
//    3. LED for visual indication.
//    4. Jumper wires for establishing connections.
//
// Other components can be included to modify the functionality of the program.

const int trigPin = 9;  // Trig pin of the ultrasonic sensor
const int echoPin = 10; // Echo pin of the ultrasonic sensor
const int ledPin = 13;  // LED pin for visual indication

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // Trigger the ultrasonic sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Measure the pulse duration from the echo pin
  long duration = pulseIn(echoPin, HIGH);

  // Calculate distance in centimeters
  int distance = duration * 0.034 / 2;

  // Print the distance to the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Visual indication using LED
  if (distance < 20) {
    digitalWrite(ledPin, HIGH); // Turn on LED if the object is within 20 cm
  } else {
    digitalWrite(ledPin, LOW); // Turn off LED otherwise
  }

  delay(500); // Adjust the delay based on your project requirements
}
