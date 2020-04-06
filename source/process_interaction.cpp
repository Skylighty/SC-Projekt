#include <cstdlib>
#include <ctime>
#include <cmath>
#include <vector>
#include <queue>
#include "process.h"
#include "channel.h"
#include "packet.h"
#include "rx.h"
#include "tx.h"

// Declarations of lists, necessary for simulation to happen
std::vector<Process*> process_queue; //Queue of processes to be executed or suspended
std::vector<TX*> tx_list; //Bi-linear list of TXs
std::vector<RX*> rx_list; //Bi-linear list of RXs

// Declaration of TXs objects   | K = 4
TX* t1;
TX* t2;
TX* t3;
TX* t4;

// Declaration of the Channel object
Channel* transmission_medium;

// Declaration of RXs objects   | K = 4
RX* r1;
RX* r2;
RX* r3;
RX* r4;

// Time containing and manangement variables
double const total_time = 60000; //Global variable which indicates a time of whole simulation
double* simulation_time; //Global variable that starts with 0 - current time in simulation

int main(int argc, char* argv[])
{
  double clock = 0; //Initialization of a variable which contains time
  simulation_time = &clock; //Pointer set to a variable declared line above

  return 0;
}
