#ifndef PROCESS_H_
#define PROCESS_H_

class Process
{
public:
  virtual void Execute();
  bool terminated_;
  double* clock;
  int state_;
};

#endif //PROCESS_H_