#ifndef SERVO_TUNING_H
#define SERVO_TUNING_H

#include "Program.h"

class Servo;

class ServoTuning : public Program
{
public:
    ServoTuning();
    ~ServoTuning();

    void Run() override;

private:
  Servo* m_pServo1;
  Servo* m_pServo2;
  Servo* m_pServo3;
};

#endif