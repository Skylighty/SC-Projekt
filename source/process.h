#ifndef PROCESS_H_
#define PROCESS_H_

class Process
{
public:
  virtual void Execute(){}  //Virtual method individual for every process explaining how it should work
  bool terminated_;         //Variable informing if the process should end it's 'cycle of life'
  double* clock;            //Pointer to the global clock
  int phase_;               //Variable supposed to indicate the current phase of every process
};

#endif //PROCESS_H_