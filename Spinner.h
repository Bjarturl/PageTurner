#ifndef Spinner_h
#define Spinner_h

#include <Arduino.h>

class Spinner {
  public:
    Spinner(int controlPin1, int controlPin2, int enablePin);
    void setup();
    void start(unsigned long duration);
    void stop();
    void toggleEnablePin();
    void update();
    bool isRunning() const;
  private:
    int _controlPin1;
    int _controlPin2;
    int _enablePin;
    bool _isEnabled;
    bool _isRunning;
    unsigned long _startTime;
    unsigned long _duration;
};

#endif
