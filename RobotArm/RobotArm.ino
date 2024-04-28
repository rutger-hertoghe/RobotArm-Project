#include "Program.h"
#include "Operate2D.h"
#include "ServoTuning.h"

Program* programToRun;
void setup() 
{
  Serial.begin(9600);
  programToRun = new Operate2D{};
}

void loop() 
{
  programToRun->Run();
}