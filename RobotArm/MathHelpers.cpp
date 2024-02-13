#include "MathHelpers.h"

#include <math.h>
#define _USE_MATH_DEFINES

float ConvertDegreesToRadians(int angleInDegrees)
{
  return angleInDegrees * M_PI / 180;
}

int ConvertRadiansToDegrees(float angleInRadians)
{
  return int(angleInRadians / M_PI * 180);
}

int SimplifyDegrees(int angleInDegrees)
{
  const int radianCircle{360};
  while(angleInDegrees < 0)
  {
    angleInDegrees += radianCircle;
  }
  return angleInDegrees % radianCircle;
}

float SimplifyRadians(float angleInRadians)
{
  const float radianCircle{2 * M_PI};
  while(angleInRadians > radianCircle )
  {
    angleInRadians -= radianCircle;
  }

  while(angleInRadians < 0.f)
  {
    angleInRadians += radianCircle;
  }
  return angleInRadians;
}

