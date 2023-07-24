#include "Spinner.h"
#include "SpinnerArm.h"
#include "Slapper.h"
#include "ProximitySensor.h"
#include "GlassLifter.h"


const int stepButtonPin = 3;
const int buttonPin = 4;

Spinner spinner(9, 10, 11);
SpinnerArm arm(6);
Slapper pageSlapper(12);
ProximitySensor proximitySensor(2, 5);
GlassLifter lifter(200, 120, 5, 7, 8, 13); 

void setup()
{
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(stepButtonPin, INPUT_PULLUP);
  Serial.begin(9600);
  spinner.setup();
  arm.setup();
  pageSlapper.setup();
  proximitySensor.setup();
  lifter.setup();
}

void loop()
{
  int buttonState = digitalRead(buttonPin);
  int stepButtonState = digitalRead(stepButtonPin);
  static int step = 0;
  char input = Serial.read();  // Check if there is any input from the serial monitor
  static bool waitingForPress = false;
  if(stepButtonState == HIGH) {
    Serial.println("Incrementing current step");
    step++;
    waitingForPress = false;
  } 
  if (waitingForPress && (input == '\n' || buttonState == HIGH))
  {
    waitingForPress = false;
    Serial.print("Executing step ");
    Serial.println(step);
  }

  if(!waitingForPress) {
    switch (step)
    {
    case 1:
      Serial.println("Current action: Lift");
      lifter.lift();
      waitingForPress = true;
      break;
    case 2:
      Serial.println("Current action: Move");
      arm.move();
      waitingForPress = true;
      proximitySensor.getDistance();
      break;
    case 3:
      Serial.println("Current action: Spin");
      spinner.start(450);
      while (spinner.isRunning()) {
        spinner.update();
      }
      waitingForPress = true;
      break;
    case 4:
      Serial.println("Current action: Slap");
      pageSlapper.slap();
    
      while (pageSlapper.isRunning())
      {
        pageSlapper.update();
      }
      waitingForPress = true;
      break;
    case 5:
      Serial.println("Current action: Slap");
      pageSlapper.slap();
    
      while (pageSlapper.isRunning())
      {
        pageSlapper.update();
      }
      waitingForPress = true;
      break;
    case 6:
      Serial.println("Current action: Move");
      arm.move();
      waitingForPress = true;
      break;
    case 7:
      Serial.println("Current action: Lower");
      lifter.lower();
      waitingForPress = true;
      break;
    default:
      step = 0;
      waitingForPress = true;
      break;
    }
  }
}