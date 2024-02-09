#include "PhantomSegment.h"
#include "ServoSegment.h"
#include "HardwareSerial.h"

PhantomSegment::PhantomSegment(ServoSegment* _pRepresentingSegment)
  : pRepresentingSegment{_pRepresentingSegment}
{
  angle = pRepresentingSegment->GetAngle();
  length = pRepresentingSegment->GetLength();
}

Vector2f PhantomSegment::GetLocalVector() const
{
  return Vector2f{angle, length};
}

void PhantomSegment::Refresh()
{
  angle = pRepresentingSegment->GetAngle();
}