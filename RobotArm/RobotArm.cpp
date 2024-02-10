#include "RobotArm.h"
#include "ServoSegment.h"
#include "PhantomSegment.h"
#include "HardwareSerial.h"

RobotArm::RobotArm(ServoSegment* pBaseSegment)
  : m_pBaseSegment{pBaseSegment}
  , m_NrOfSegments{0}
{
  SetNrOfSegments();
  CreatePhantomArms();
  LinkPhantomToReal();
}

RobotArm::~RobotArm()
{
  delete[] m_PhantomSegmentArray;
}

void RobotArm::SetNrOfSegments()
{
  ServoSegment* pCurrentSegment = m_pBaseSegment;

  while(pCurrentSegment)
  {
    m_NrOfSegments += 1;
    pCurrentSegment = pCurrentSegment->GetChildSegment();
  }
}

void RobotArm::CreatePhantomArms()
{
  m_PhantomSegmentArray = new PhantomSegment[m_NrOfSegments];
}

void RobotArm::LinkPhantomToReal()
{
  auto currentSegment{m_pBaseSegment};
  for(int i = 0; i < m_NrOfSegments; ++i)
  {
    m_PhantomSegmentArray[i] = PhantomSegment{currentSegment};
    currentSegment = currentSegment->GetChildSegment();
  }
}

void RobotArm::RefreshPhantomSegments()
{
  for(int i{0}; i < m_NrOfSegments; ++i)
  {
    m_PhantomSegmentArray[i].Refresh();
  }
}

Vector2f RobotArm::GetEndPoint()
{
  return GetSegmentToEndVector(0);
}

void RobotArm::SetRealAngles()
{
  for(int i{0}; i < m_NrOfSegments; ++i)
  {
    m_PhantomSegmentArray[i].pRepresentingSegment->SetAngle(m_PhantomSegmentArray[i].angle);
  }
}

void RobotArm::MoveToTarget(Vector2f target, int nrOfIterations)
{
  RefreshPhantomSegments();

  // const int nrOfIterations{10};
  
  for(int iteration{0}; iteration < nrOfIterations; ++iteration)
  {
    HoneInOnTarget(target);
  }
  
  SetRealAngles();
}

void RobotArm::HoneInOnTarget(Vector2f target)
{
  for(int segmentIdx{0}; segmentIdx < m_NrOfSegments; ++segmentIdx)
  {
    auto& currentSegment{m_PhantomSegmentArray[segmentIdx]};
    Vector2f vecToEnd{GetSegmentToEndVector(segmentIdx)};

    // Dot product to find delta radians
    auto angleInRadians{acos(target.Dot(vecToEnd) / (target.GetMagnitude() * vecToEnd.GetMagnitude()))};
    auto angleInDegrees{ConvertRadiansToDegrees(angleInRadians)};

    // Cross product to find handedness of rotation
    float crossProduct{vecToEnd.Cross(target)};
    float sign{crossProduct > 0.f ? 1.f : -1.f};

    int angleDiff{sign * angleInDegrees};
    currentSegment.angle = currentSegment.angle + angleDiff;

    target -= currentSegment.GetLocalVector();
    target.RotateByDegrees(180 - currentSegment.angle);
  }
}

void RobotArm::PrintPhantomAngles()
{
  for(int i{0}; i < m_NrOfSegments; ++i)
  {
    Serial.print(m_PhantomSegmentArray[i].angle);
    Serial.print(", ");
  }
  Serial.println("");
}

Vector2f RobotArm::GetSegmentToEndVector(int segmentIdx)
{
  Vector2f totalVec{0.f, 0.f};
  float lastWorldRotation{0};

  for(; segmentIdx < m_NrOfSegments; ++segmentIdx)
  {
    const auto& currentSegment{m_PhantomSegmentArray[segmentIdx]};
    auto segmentVector{currentSegment.GetLocalVector()};
    // Put vector in world space
    segmentVector.RotateByDegrees(lastWorldRotation);

    totalVec += segmentVector;

    // Reverse the segmentVector, as the new axis will align with the reversed vector
    segmentVector *= -1;
    // Get the rotation so that we can place the local vector in world space on the next iteration
    lastWorldRotation = segmentVector.GetAngleInDegrees();
  }
  
  return totalVec;
}