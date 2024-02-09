#ifndef ROBOT_ARM_H
#define ROBOT_ARM_H

#include "CustomMath.h"

class ServoSegment;
class PhantomSegment;

class RobotArm
{
public:
  RobotArm(ServoSegment* pBaseSegment);
  ~RobotArm();

  void MoveToTarget(Vector2f target);

  Vector2f GetEndPoint();

private:
  ServoSegment* m_pBaseSegment;
  PhantomSegment* m_PhantomSegmentArray;

  int m_NrOfSegments;

  void SetNrOfSegments();
  void LinkPhantomToReal();

  Vector2f GetSegmentToEndVector(int segmentIdx);
  void HoneInOnTarget(Vector2f target);

  void RefreshPhantomSegments();

  void SetRealAngles();

  void PrintAngles();
};

#endif