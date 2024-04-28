#include "ServoSegment.h"
#include "HardwareSerial.h"
#include "Servo.h"

ServoSegment::ServoSegment(int defaultAngleDeg, bool isServoReversed)
  : m_DefaultAngleDeg{defaultAngleDeg}
  , m_IsServoReversed{isServoReversed}
  , m_pChildSegment{nullptr}
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
  // If no servo attached, return invalid value
  if(!m_pServo->attached())
  {
    return -1;
  }

  const int maxAngle{180};
  const int currentAngle{m_pServo->read()};

  // If the servo is reversed, use the complementary angle
  return m_IsServoReversed ? maxAngle - currentAngle : currentAngle;
}

void ServoSegment::SetAngle(int angle)
{
  if(!m_pServo->attached())
  {
    Serial.println("No servo attached! Angle was not written!");
    return;
  }

  const int maxAngle{180};

  // If the servo is reversed, use the complementary angle
  m_pServo->write(m_IsServoReversed ? maxAngle - angle : angle);
}

void ServoSegment::SetChildSegment(ServoSegment* pChildSegment)
{
  m_pChildSegment = pChildSegment;
}

ServoSegment* ServoSegment::GetChildSegment() const
{
  if(m_pChildSegment)
  {
    return m_pChildSegment;
  }
  return nullptr;
}