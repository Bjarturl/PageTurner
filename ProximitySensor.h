#ifndef ProximitySensor_h
#define ProximitySensor_h

#include <Arduino.h>

class ProximitySensor {
  public:
    ProximitySensor(int trigPin, int echoPin);
    void setup();
    void getDistance();
  private:
    int _trigPin;
    int _echoPin;
};

#endif
