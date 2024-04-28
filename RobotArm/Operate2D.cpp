#include "Arduino.h"

#include "Operate2D.h"
#include "MathHelpers.h"
#include "Controller.h"
#include "ServoSegment.h"
#include "RobotArm.h"


Operate2D::Operate2D()
    : m_pHandSegment{new ServoSegment{90, false}}
    , m_pElbowSegment{new ServoSegment{90, false}}
    , m_pBaseSegment{new ServoSegment{90, false}}
    , m_pController{new Controller{A0, A1, 2.f, 200}}
{
  m_pElbowSegment->SetChildSegment(m_pHandSegment);
  m_pBaseSegment->SetChildSegment(m_pElbowSegment);

  m_pBaseSegment->AttachServo(8);
  m_pElbowSegment->AttachServo(9);
  m_pHandSegment->AttachServo(10);

  m_pFullArm = new RobotArm{m_pBaseSegment};

  m_Target = m_pFullArm->GetEndPoint();
  // m_Target.Print();
  m_pFullArm->MoveToTarget(m_Target);
}

Operate2D::~Operate2D()
{
    delete m_pController;

    delete m_pFullArm;

    delete m_pBaseSegment;
    delete m_pElbowSegment;
    delete m_pHandSegment;
}

void Operate2D::Run()
{
  auto deltaTimeMilli{CalculateDeltaTime()};
  float deltaTime{float(deltaTimeMilli)/1000.f};

  m_pController->Update(deltaTime, m_Target);
  m_pFullArm->MoveToTarget(m_Target);
  //m_Target.Print();
}

unsigned long Operate2D::CalculateDeltaTime()
{
  static unsigned long previousTime{};
  unsigned long currentTime{millis()};
  unsigned long deltaTime{currentTime - previousTime};
  previousTime = currentTime;

  return deltaTime;
}