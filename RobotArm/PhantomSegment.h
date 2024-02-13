#ifndef PHANTOM_SEGMENT_H
#define PHANTOM_SEGMENT_H

#include "Vector2f.h"

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