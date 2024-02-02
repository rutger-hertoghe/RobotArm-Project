#include "Servo.h"
#include "Structs.h"
#include "Controller.h"
#include "RegionRestrictor.h"
// #include <math.h>

// #define _USE_MATH_DEFINES

// #define stickX A0 // GREEN WIRE is X
// #define stickY A1 // BLUE WIRE IS Y

Servo baseJoint;
Servo elbowJoint;
Controller controller1{A0, A1, 1.f};
RegionRestrictor regionRestrictor{M_PI/2, 2};

unsigned long CalculateDeltaTime();

void setup() {
  Serial.begin(9600);
  // SET CORRECT DIGITAL PWM!
  baseJoint.attach(9);
  elbowJoint.attach(8);
  // IMPORTANT: 80 is the middle value for both arms
  // SAFE VALUES BASE JOINT: 0 - 160
  baseJoint.read(); // Lower values make the arm go forward
  // SAFE VALUES ELBOW JOINT: 0 (full extension) - 150(BJ: 80)/ 160(BJ: 160)
  elbowJoint.read(); // Lower values extend the arm, higher values flex the arm
}

void loop() 
{
  // put your main code here, to run repeatedly:
  auto deltaTimeMilli{CalculateDeltaTime()};
  float deltaTime{float(deltaTimeMilli)/1000.f};

  controller1.Update(deltaTime);
  controller1.SetDesiredCoordinate(regionRestrictor.RestrictToBounds(controller1.GetDesiredCoordinate()));
  controller1.GetDesiredCoordinate().Print();
}

unsigned long CalculateDeltaTime()
{
  static unsigned long previousTime{};
  unsigned long currentTime{millis()};
  unsigned long deltaTime{currentTime - previousTime};
  previousTime = currentTime;

  return deltaTime;
}