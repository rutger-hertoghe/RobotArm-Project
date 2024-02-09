#include "ServoSegment.h"
#include "HardwareSerial.h"
#include "Servo.h"

ServoSegment::ServoSegment(int defaultAngleDeg, bool isServoReversed, ServoSegment* pChildSegment)
  : m_DefaultAngleDeg{defaultAngleDeg}
  , m_pChildSegment{pChildSegment}
  , m_IsServoReversed{isServoReversed}
  , m_SegmentLength{1.f}
{
  m_pServo = new Servo{};
}

ServoSegment::~ServoSegment()
{
  delete m_pServo;
  m_pServo = nullptr;
}

void ServoSegment::AttachServo(int DPWM)
{
  if(!m_pServo)
  {
    Serial.print("ERROR: No servo created to attach a slot to!\n");
    return;
  }
  
  if(m_pServo->attached())
  {
    Serial.print("ERROR: Servo already attached to slot!\n Could not connect to slot ");
    Serial.println(DPWM);
  }

  m_pServo->attach(DPWM);
  SetAngle(m_DefaultAngleDeg);
}

float ServoSegment::GetLength() const
{
  return m_SegmentLength;
}

int ServoSegment::GetAngle() const
{
  if(!m_pServo->attached())
  {
    return -1;
  }
  const int maxAngle{180};
  const int currentAngle{m_pServo->read()};

  if(m_IsServoReversed)
  {
    return maxAngle - currentAngle;
  }

  return currentAngle;
}

void ServoSegment::SetAngle(int angle)
{
  if(!m_pServo->attached())
  {
    Serial.println("No servo attached! Angle was not written!");
    return;
  }

  const int maxAngle{180};
  
  if(m_IsServoReversed)
  {
    m_pServo->write(maxAngle - angle);
    return;
  }

  m_pServo->write(angle);
}

ServoSegment* ServoSegment::GetChildSegment()
{
  if(m_pChildSegment)
  {
    return m_pChildSegment;
  }
  return nullptr;
}