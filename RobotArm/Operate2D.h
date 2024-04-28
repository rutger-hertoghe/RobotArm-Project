#ifndef OPERATE_2D_H
#define OPERATE_2D_H

#include "Program.h"
#include "Vector2f.h"

class ServoSegment;
class RobotArm;
class Controller;

class Operate2D : public Program
{
  public:
    Operate2D();
    ~Operate2D();

    // void Init() override;
    void Run() override;

  private:
    Vector2f m_Target;
    ServoSegment* m_pHandSegment;
    ServoSegment* m_pElbowSegment;
    ServoSegment* m_pBaseSegment;

    RobotArm* m_pFullArm;

    Controller* m_pController;

    unsigned long CalculateDeltaTime();
};

#endif