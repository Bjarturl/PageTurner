#include "GlassLifter.h"

GlassLifter::GlassLifter(int numSteps, int speed, int motorPin1, int motorPin2, int motorPin3, int motorPin4)
  : _numSteps(numSteps),
    _speed(speed),
    _stepper(numSteps, motorPin1, motorPin2, motorPin3, motorPin4)
{
}

void GlassLifter::setup() {
  _stepper.setSpeed(_speed);
}

void GlassLifter::lift() {
  unsigned long startTime = millis();
  while (millis() - startTime < 5000) {
    _stepper.step(-_numSteps);
  }
}

void GlassLifter::lower() {
  unsigned long startTime = millis();
  while (millis() - startTime < 5000) {
    _stepper.step(_numSteps);
  }
}
