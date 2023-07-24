#include "SpinnerArm.h"
#include <Servo.h>

Servo spinnerArm;

int servoPos = 0;

SpinnerArm::SpinnerArm(int servoPin, int minPos, int maxPos, int speed) {
  _servoPin = servoPin;
  _minPos = minPos;
  _maxPos = maxPos;
  _speed = speed;
}


void SpinnerArm::setup() {
  servoPos = _maxPos;
  spinnerArm.attach(_servoPin);
  spinnerArm.write(servoPos);
  Serial.begin(9600);
}


void SpinnerArm::move() {
  Serial.println("Move");
  if(servoPos == _minPos) {
    for (int i = servoPos; i <= _maxPos; i += _speed) {
      spinnerArm.write(i);
      delay(15);
    }
    servoPos = _maxPos; 
  } else {
    for (int i = servoPos; i >= _minPos; i -= _speed) {
      spinnerArm.write(i);
      delay(15);
    }
    servoPos = _minPos; 
  }
}


void SpinnerArm::increment() {
  servoPos += _speed;
  spinnerArm.write(servoPos);
  Serial.print("SpinnerArm at pos: ");
  Serial.println(servoPos);
}
void SpinnerArm::decrement() {
  servoPos -= _speed;
  spinnerArm.write(servoPos);
  Serial.print("SpinnerArm at pos: ");
  Serial.println(servoPos);
}

int SpinnerArm::getPosition() {
  return servoPos;
}

int SpinnerArm::getMinPosition() {
  return _minPos;
}

int SpinnerArm::getMaxPosition() {
  return _maxPos;
}

void SpinnerArm::setPosition(int position) {
  if(position >= _minPos && position <= _maxPos) {
    servoPos = position;
    spinnerArm.write(servoPos);
    Serial.print("SpinnerArm set to pos: ");
    Serial.println(servoPos);
  } else {
    Serial.println("Invalid position");
  }
}
