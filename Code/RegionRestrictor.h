#ifndef REGION_RESTRICTOR_H
#define REGION_RESTRICTOR_H

#include "Structs.h"

class RegionRestrictor
{
public:
  RegionRestrictor(const float maxBaseAngle, const float maxArmLength);

  Point2f RestrictToBounds(const Point2f& coordinate);
  Point2f RestrictToBounds(const Vector2f& coordinate);
private:
  const float m_MaxBaseAngle;
  const float m_MaxArmLength;
};


#endif