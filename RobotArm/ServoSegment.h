#ifndef SERVO_ARM_H
#define SERVO_ARM_H

#include "CustomMath.h"

class Servo;

class ServoSegment
{
public:
  /* defaultAngleDeg: The angle that the Servo should default to;
     isServoReversed: If the physical servo is on the left side of the forward axis, this needs to be true
     pChildSegment: This is the next segment on the arm that is closer to its tip, if there is one */
  explicit ServoSegment(int defaultAngleDeg, bool isServoReversed, ServoSegment* pChildSegment = nullptr);
  // Declared & defined destructor (see .cpp) because ServoSegment has ownership over a Servo object
  ~ServoSegment();

  // ServoSegments can not be copied or moved
  ServoSegment(const ServoSegment& other) = delete;
  ServoSegment& operator=(const ServoSegment& other) = delete;
  ServoSegment(ServoSegment&& other) = delete;
  ServoSegment& operator=(ServoSegment&& other) = delete;

  // Attach a pin, analogous to how the Servo.h library does this
  void AttachServo(int DPWM);

  int GetAngle() const;
  void SetAngle(int angle);
  float GetLength() const;
  ServoSegment* GetChildSegment() const; // TODO: might be redundant/confusing, better to give RobotArm full ownership of the arm

private:
  const int m_DefaultAngleDeg;

  float m_SegmentLength;

  bool m_IsServoReversed;

  Servo* m_pServo;
  ServoSegment* m_pChildSegment; // TODO: ServoSegment might not need a pointer to its child segment

};

#endif