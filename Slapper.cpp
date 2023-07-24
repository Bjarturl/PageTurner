#include "Slapper.h"
#include <Servo.h>

Servo slapper;

int pos = 0;

Slapper::Slapper(int servoPin, int minPos, int maxPos, int speed) {
  _servoPin = servoPin;
  _minPos = minPos;
  _maxPos = maxPos;
  _speed = speed;
  _targetPos = _maxPos;
  _isMoving = false;
}


void Slapper::setup() {
  pos = _maxPos;
  slapper.attach(_servoPin);
  slapper.write(pos);
  Serial.begin(9600);
}


void Slapper::slap() {
  Serial.println("Slap");
  if(pos == _minPos) {
    _targetPos = _maxPos;
  } else {
    _targetPos = _minPos;
  }
  _isMoving = true;
}

bool Slapper::isRunning() {
  return _isMoving;
}

void Slapper::update() {
  if (_isMoving) {
    int increment = _speed;
    if (pos > _targetPos) {
      increment = -increment;
    }
    pos += increment;
    slapper.write(pos);
    delay(15);
    if (pos == _targetPos) {
      _isMoving = false;
    }
  }
}

void Slapper::increment() {
  _targetPos += 5;
  Serial.print("Slapper at pos: ");
  Serial.println(_targetPos);
}

void Slapper::decrement() {
  _targetPos -= 5;
  Serial.print("Slapper at pos: ");
  Serial.println(_targetPos);
}
