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

  void MoveToTarget(Vector2f target); // Moves the arm's tip towards the target coordinate

  Vector2f GetEndPoint(); // Gets the vector going directly from the arm's base to its tip.

private:
  ServoSegment* m_pBaseSegment;
  PhantomSegment* m_PhantomSegmentArray;  // Purely digital representations of the segment arms that will serve as intermediaries for calculations
  // ==> AKA: we don't want the arms start jerking before they completely know where to go (~during calculations from RobotArm.cpp)

  int m_NrOfSegments;

  void SetNrOfSegments();         // Deduces the correct number of segments from the base segment.
  void CreatePhantomArms();       // Creates empty phantom arms (see declaration of m_pPhantomSegmentArray)
  void LinkPhantomToReal();       // Links the phantom arms to their physical representations (ServoSegment)
  void RefreshPhantomSegments();  // Makes sure that phantom arms have the same values (a) are their physical counterparts

  Vector2f GetSegmentToEndVector(int segmentIdx); // Gets the vector going from the base of a segment to the arm's tip IN THIS SEGMENT'S LOCAL SPACE (!)
  void HoneInOnTarget(Vector2f target);           // Tries to align the arm's tip to the desired location, multiple iterations needed

  void SetRealAngles();      // Sets the physical servo arms to the values stored in phantom arms (after sufficient iterations of HoneInOnTarget())
  void PrintPhantomAngles(); // Prints the angles currently stored in the phantom arms (FOR TESTING PURPOSES)
};

#endif