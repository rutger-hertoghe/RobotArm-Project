#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <stdint.h>
#include "Structs.h"

class Controller 
{
public:
  Controller(uint8_t xPin, uint8_t yPin, float sensitivity);

  void Update(float deltaTime);
  void PrintCoordinates() const;

  const Point2f GetDesiredCoordinate() const;

private:
  uint8_t m_xPin;
  uint8_t m_yPin;
  int m_StickMidpoint;
  int m_Deadzone;
  float m_Sensitivity; // Units moved per second (1 unit = length of arm segment)
  Point2f m_DesiredCoordinate;
};

#endif