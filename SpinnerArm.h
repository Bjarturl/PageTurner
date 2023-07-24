#ifndef SpinnerArm_h
#define SpinnerArm_h

#include <Arduino.h>

class SpinnerArm {
  public:
    SpinnerArm(int servoPin, int minPos = 30, int maxPos = 100, int speed = 5);
    void setup();
    void move();
    void increment();
    void decrement();
    int getPosition();
    int getMinPosition();
    int getMaxPosition();
    void setPosition(int position);
  private:
    int _servoPin;
    int _minPos;
    int _maxPos;
    int _speed;
};

#endif
