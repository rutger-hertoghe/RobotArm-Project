#ifndef SERVO_ARM_H
#define SERVO_ARM_H

#include "CustomMath.h"

class Servo;

class ServoSegment
{
public:
  // minAngle: the angle that aligns with the LOCAL X-Axis
  explicit ServoSegment(int defaultAngleDeg, bool isServoReversed, ServoSegment* pChildSegment = nullptr);
  ~ServoSegment();

  ServoSegment(const ServoSegment& other) = delete;
  ServoSegment& operator=(const ServoSegment& other) = delete;
  ServoSegment(ServoSegment&& other) = delete;
  ServoSegment& operator=(ServoSegment&& other) = delete;

  void AttachServo(int DPWM);

  int GetAngle() const;
  void SetAngle(int angle);

  float GetLength() const;

  ServoSegment* GetChildSegment();

private:
  const int m_DefaultAngleDeg;

  float m_SegmentLength;

  bool m_IsServoReversed;

  Servo* m_pServo;
  ServoSegment* m_pChildSegment;

};

#endif