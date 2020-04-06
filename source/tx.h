#ifndef TX_H_
#define TX_H_
#include <queue>
#include "process.h"
#include "packet.h"
#include "channel.h"

//Class TX resembles transmitter. This class is supposed to create a transmitter object
//and fully simulate it's work.

class TX : public Process
{
public:
  TX(unsigned int id);                //Transmitter class constructor
  ~TX();                              //Transmitter class deconstructor
  unsigned int tx_id_;                //Variable without a sign that is equal to very own TX number, so we're sure that program won't mistake one TX with another
  unsigned int const tx_count_ = 4;   //Const variable without sign that is equal to the numbers of transmitters in our whole system
  Packet* current_packet_;            //Variable which contains a packet that currently is to-be-transmitted by TX
  std::queue<Packet*> packet_buffer_; //Buffer of packets which is contained within every TX unit/object
  void GeneratePacket();              //Function supposed to generate a new packet and put it in FIFO queue packet_buffer_
  void StartTransmission(Channel* ch);// Function that passes the _current_packet_
  void GetPacket();                   //Function that gets the packet from buffer
  void Handshake(Channel* ch);        //Function that checks if whole transmission was successful and clears the packet pointers
  bool IsChannelBusy(Channel* ch);    //Function that checks availability of the channel
  //================================================
  //TODO:Implement time-----------------------------
  void WaitCTP(double *clock);        //Function that suspends TX process for CTP time (time required to check channel availability again)
  void WaitCGP(double* clock);        //Function that suspends TX process for CGP time (time required to generate new packet)
  void WaitCRP(double* clock);        //Function that suspends TX process for CRP time (time required to check channel availability in RETRANSMISSION)
  void WaitTillACK(double* clock);    //Function that suspends TX process until it receives back a packet with ACK flag equal to 'true'
  //TODO:Implement time------------------------------
  //=================================================
};

#endif //TX_H_
