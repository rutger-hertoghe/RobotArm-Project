#ifndef SERVO_ARM_H
#define SERVO_ARM_H

#include "Servo.h"

class ServoSegment
{
public:
  // minAngle: the angle that aligns with the LOCAL X-Axis
  explicit ServoSegment(int attachedDPWM, int minAngleDeg, int maxAngleDeg, ServoSegment* pParent = nullptr);

  int GetAbsoluteAngleInDegrees() const;

private:
  Servo m_Servo;
  ServoSegment* m_pParentSegment;

  const int m_MaxAngleDeg;
  const int m_MinAngleDeg;
  int m_CurrentAngleDeg;

  float m_SegmentLength;
};

#endif