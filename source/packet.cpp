#include "packet.h"

Packet::Packet(unsigned int pid, unsigned int txid)
{
  r_ = 0;                   //Initial number of retransmissions is 0, of course
  t_ = 0;                   //Same goes for number of channel busy checks
  packet_id_ = pid;         //Passed by argument - global count
  tx_id_ = txid;            //Passed by GeneratePacket() function, by TX object
  retransmission_ = false;  //Initially - packet is not being retransmitted yet
  rejected_ = false;        //Initially - packet hasn't been rejected yet
  received_ = false;        //Initially - packet hasn't been received by any RX yet
  collision_ = false;       //Initially - collision couln't have happened yet
  ack_ = false;             //Initially - packet hasn't been claimed by RX which can set it to true
  error_ = false;
}

Packet::~Packet()
{
}
