#include "HardwareSerial.h"
#include "Servo.h"
#include "ServoTuning.h"

ServoTuning::ServoTuning()
  : m_pServo1{new Servo()}
  , m_pServo2{new Servo()}
  , m_pServo3{new Servo()}
{
  m_pServo1->attach(8);
  m_pServo2->attach(9);
  m_pServo3->attach(10);

  m_pServo1->write(0);
  m_pServo2->write(180);
  m_pServo3->write(0);
}

ServoTuning::~ServoTuning()
{
}

void ServoTuning::Run()
{
    
}