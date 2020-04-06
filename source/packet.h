#ifndef PACKET_H_
#define PACKET_H_
#include "process.h"

//Packet class is a main information carrier in our simulation system
//Basing on data stored in packet objects, we're able to simulate this system
//TX and RX pairs decide and set properties basing on packets' parameters.

class Packet : public Process
{
public:
  Packet(unsigned int pid, unsigned int txid);  //ID will be passed as a number from the global generated packet count
  ~Packet();                                    //Default "delete" deconstructor
  unsigned int r_;                              //Variable that indicates number of times we tried to check channel availability during RETRANSMISSION
  unsigned int t_;                              //Variable that indicates number of times we tried to check channel availability
  unsigned int packet_id_;                      //Variable that stores very own ID number of the packet
  unsigned int tx_id_;                          //Variable that stores ID of TX/RX between which packet is transmitted
  bool ack_;                                    //Binary flag determining if the packet receipt was successful
  bool received_;                               //Binary flag determining if the packet has been received by RX
  bool retransmission_;                         //Binary flag determining if the packet is currently transmitted or retransmitted
  bool error_;                                  //Binary flag determining if there was an error during the transmission
  bool rejected_;                               //Binary flag determining if the packet was rejected due to too big retransmission count
  bool collision_;                              //Binary flag determinfg if the packet has occured a collision 
  unsigned int const ctiz_time_ = 1;            //Constant time needed to send packet through channel equal to 1ms
  unsigned int const lr_ = 10;                  //Max count of retransmissions 
  void WaitCTIZ(double* clock);                 //Waiting time
  void WaitTillTransmission(double* clock);     //Packet process suspended until it's transmission is started
};

#endif //PACKET_H_