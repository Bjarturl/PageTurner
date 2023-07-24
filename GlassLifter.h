#ifndef GlassLifter_h
#define GlassLifter_h

#include <Arduino.h>
#include <Stepper.h>

class GlassLifter {
  public:
    GlassLifter(int numSteps, int speed, int motorPin1, int motorPin2, int motorPin3, int motorPin4);
    void setup();
    void lift();
    void lower();
  private:
    int _numSteps;
    int _speed;
    Stepper _stepper;
};

#endif
