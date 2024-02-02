#ifndef REGION_RESTRICTOR_H
#define REGION_RESTRICTOR_H

#include "Structs.h"

class RegionRestrictor
{
public:
  RegionRestrictor(const float maxBaseAngleRadians, const float maxArmLength);

  const Vector2f RestrictToBounds(const Vector2f& coordinate) const;
private:
  const float m_MaxBaseAngleRadians;
  const float m_MaxArmLength;
};


#endif