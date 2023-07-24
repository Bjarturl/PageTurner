#ifndef Slapper_h
#define Slapper_h

#include <Arduino.h>

class Slapper {
  public:
    Slapper(int servoPin, int minPos = 75, int maxPos = 180, int speed = 3);
    void setup();
    void slap();
    void increment();
    void decrement();
    bool isRunning();
    void update();
  private:
    int _servoPin;
    int _minPos;
    int _maxPos;
    int _speed;
    int _targetPos;
    bool _isMoving;
};

#endif
