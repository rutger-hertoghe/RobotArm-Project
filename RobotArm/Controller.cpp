#include <wiring_private.h>
#include <HardwareSerial.h>
#include "Controller.h"

Controller::Controller(uint8_t xPin, uint8_t yPin, float sensitivity)
  : m_xPin{xPin}
  , m_yPin{yPin}
  , m_Sensitivity{sensitivity}
  , m_StickMidpoint{512}
  , m_Deadzone{300}
{}

void Controller::Update(float deltaTime, Vector2f& target)
{
  int analogX{analogRead(m_xPin)};
  int analogY{analogRead(m_yPin)};

  float displacement{m_Sensitivity * deltaTime};

  if(analogX >= m_StickMidpoint + m_Deadzone)
  {
    target.x += displacement;
  }
  else if (analogX <= m_StickMidpoint - m_Deadzone)
  {
    target.x -= displacement;
  }
  
  // -/+ are reversed for Y because down on the Y stick gives a higher value (~reversed)
  if(analogY>= m_StickMidpoint + m_Deadzone)
  {
    target.y -= displacement;
  }
  else if (analogY <= m_StickMidpoint - m_Deadzone)
  {
    target.y += displacement;
  }
}
