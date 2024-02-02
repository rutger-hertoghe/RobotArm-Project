#include "ServoSegment.h"

ServoSegment::ServoSegment(int attachedDPWM, int minAngleDeg, int maxAngleDeg, ServoSegment* pParent)
  : m_MaxAngleDeg{maxAngleDeg}
  , m_MinAngleDeg{minAngleDeg}
  , m_pParentSegment{pParent}
  , m_SegmentLength{1.f}
{
  m_Servo.attach(attachedDPWM);
  m_CurrentAngleDeg = m_Servo.read();
}

int ServoSegment::GetAbsoluteAngleInDegrees() const
{
  if(m_pParentSegment)
  {
    m_pParentSegment.GetAbsoluteAngleInDegrees
  }
}