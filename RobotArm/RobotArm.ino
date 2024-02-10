// #include "Servo.h"
#include "CustomMath.h"
#include "Controller.h"
#include "ServoSegment.h"
#include "RobotArm.h"
// #include <math.h>

// #define _USE_MATH_DEFINES

ServoSegment handSegment{90, false};
ServoSegment elbowSegment{90, true, &handSegment};
ServoSegment baseSegment{90, false, &elbowSegment};
RobotArm* fullArm;
Vector2f target;
Controller controller1{A0, A1, 2.f, 200};

unsigned long CalculateDeltaTime();

void setup() {
  Serial.begin(9600);

  baseSegment.AttachServo(8);
  elbowSegment.AttachServo(9);
  handSegment.AttachServo(10);

  fullArm = new RobotArm{&baseSegment};

  target = fullArm->GetEndPoint();
  fullArm->MoveToTarget(target);
}

void loop() 
{
  static bool angleIncreasing = true;
  // put your main code here, to run repeatedly:
  auto deltaTimeMilli{CalculateDeltaTime()};
  float deltaTime{float(deltaTimeMilli)/1000.f};

  controller1.Update(deltaTime, target);
  fullArm->MoveToTarget(target);
}

unsigned long CalculateDeltaTime()
{
  static unsigned long previousTime{};
  unsigned long currentTime{millis()};
  unsigned long deltaTime{currentTime - previousTime};
  previousTime = currentTime;

  return deltaTime;
}