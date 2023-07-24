#include "ProximitySensor.h"

int distance;
int duration;

ProximitySensor::ProximitySensor(int trigPin, int echoPin) {
  _trigPin = trigPin;
  _echoPin = echoPin;
}

void ProximitySensor::setup() {
  pinMode(_trigPin, OUTPUT);
  pinMode(_echoPin, INPUT);
  Serial.begin(9600);
}

void ProximitySensor::getDistance() {
      // Clears the trigPin
    digitalWrite(_trigPin, LOW);
    delayMicroseconds(2);
 
    // Set HIGH trigPin
    digitalWrite(_trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(_trigPin, LOW);
 
    // Reads the echoPin in microseconds
    duration = pulseIn(_echoPin, HIGH);
 
    // Calculating the distance
    distance = duration * 0.034 / 2;
     Serial.println(distance);
}
