#ifndef PHANTOM_SEGMENT_H
#define PHANTOM_SEGMENT_H

#include "CustomMath.h"

class ServoSegment;

struct PhantomSegment
{
  PhantomSegment(ServoSegment* _pRepresentingSegment = nullptr);

  int angle;
  float length;
  ServoSegment* pRepresentingSegment;

  void Refresh();

  Vector2f GetLocalVector() const;
};

#endif