#include "RegionRestrictor.h"

RegionRestrictor::RegionRestrictor(const float maxBaseAngleRadians, const float maxArmLength)
  : m_MaxBaseAngleRadians(maxBaseAngleRadians)
  , m_MaxArmLength(maxArmLength)
{
}

const Vector2f RegionRestrictor::RestrictToBounds(const Vector2f& vector) const
{
  auto magnitude = vector.GetMagnitude();
  auto newVec = vector;

  auto angle = atan2(newVec.y, newVec.x);
  if(angle > m_MaxBaseAngleRadians)
  {
    newVec = Vector2f{m_MaxBaseAngleRadians, magnitude};
  }
  else if(angle < 0)
  {
    newVec = Vector2f{0, magnitude};
  }

  if(magnitude >= m_MaxArmLength)
  {
    newVec.Normalize() *= m_MaxArmLength;
  }

  return newVec;
}