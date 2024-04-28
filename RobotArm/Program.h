#ifndef PROGRAM_H
#define PROGRAM_H

class Program
{
public:
  Program(){};
  ~Program(){};

  // virtual void Init() = 0;
  virtual void Run() = 0;

private:
  // None
};

#endif