#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <stdint.h>
#include "CustomMath.h"

// #define stickX A0 // GREEN WIRE is X
// #define stickY A1 // BLUE WIRE IS Y


class Controller 
{
public:
  Controller(uint8_t xPin, uint8_t yPin, float sensitivity, int deadZone = 100);

  void Update(float deltaTime, Vector2f& target);

private:
  uint8_t m_xPin;
  uint8_t m_yPin;
  int m_Deadzone;
  float m_Sensitivity; // Units moved per second (1 unit = length of arm segment)
  
  float CalculateMovementStrength(int stickValue);
};

#endif