#include "RegionRestrictor.h"

RegionRestrictor::RegionRestrictor(const float maxBaseAngle, const float maxArmLength)
  : m_MaxBaseAngle(maxBaseAngle)
  , m_MaxArmLength(maxArmLength)
{}

Point2f RegionRestrictor::RestrictToBounds(const Point2f &coordinate)
{
  
}