#include <wiring_private.h>
#include <HardwareSerial.h>
#include "Controller.h"

#define STICK_MIDPOINT 512

Controller::Controller(uint8_t xPin, uint8_t yPin, float sensitivity, int deadZone)
  : m_xPin{xPin}
  , m_yPin{yPin}
  , m_Sensitivity{sensitivity}
  , m_Deadzone{deadZone}
{}

void Controller::Update(float deltaTime, Vector2f& target)
{
  // Read pins
  int analogX{analogRead(m_xPin)};
  int analogY{analogRead(m_yPin)};

  // Shift values to center
  analogX -= STICK_MIDPOINT;
  analogY -= STICK_MIDPOINT;

  // Calculate the maximum movement possible in this timestamp based on the stick sensitivity
  const float maximumDisplacement{m_Sensitivity * deltaTime};

  // Calculate actual movement values based on stick input values
  const float xDisplacement{float(analogX)/1024.f * maximumDisplacement};
  const float yDisplacement{float(analogY)/1024.f * maximumDisplacement};

  // Actual movement of the target
  if(abs(analogX) > m_Deadzone)
  {
    target.x += xDisplacement;
  }
  
  // -/+ are reversed for Y because down on the Y stick gives a higher value (~reversed)
  if(abs(analogY) > m_Deadzone)
  {
    target.y -= yDisplacement;
  } 
}

float CalculateMovementStrength(int stickValue)
{
  // Make midpoint the actual center
  stickValue -= STICK_MIDPOINT;

  // Scale to float between -1 & 1
  float strength{stickValue / STICK_MIDPOINT};
  return strength;
}
