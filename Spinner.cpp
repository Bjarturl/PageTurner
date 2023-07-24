#include "Spinner.h"

const int SPIN_SPEED = 150;

Spinner::Spinner(int controlPin1, int controlPin2, int enablePin) {
    _controlPin1 = controlPin1;
    _controlPin2 = controlPin2;
    _enablePin = enablePin;
}

void Spinner::setup() {
    pinMode(_controlPin1, OUTPUT);
    pinMode(_controlPin2, OUTPUT);
    pinMode(_enablePin, OUTPUT);
    digitalWrite(_enablePin, LOW);
    digitalWrite(_controlPin1, HIGH);
    digitalWrite(_controlPin2, LOW);
    _isEnabled = false;
    _isRunning = false;
}

void Spinner::start(unsigned long duration) {
    Serial.println("Spin");
    _duration = duration;
    _startTime = millis();
    _isEnabled = true;
    _isRunning = true;
    analogWrite(_enablePin, SPIN_SPEED);
}

void Spinner::stop() {
    _isEnabled = false;
    _isRunning = false;
    analogWrite(_enablePin, 0);
}

void Spinner::toggleEnablePin() {
    _isEnabled = !_isEnabled;
    digitalWrite(_enablePin, _isEnabled ? HIGH : LOW);
}

void Spinner::update() {
    if (_isRunning && millis() - _startTime >= _duration) {
        stop();
    }
}

bool Spinner::isRunning() const {
    return _isRunning;
}
