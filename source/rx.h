#ifndef RX_H_
#define RX_H_
#include "process.h"
#include "packet.h"
#include "channel.h"

//Class should simulate workflow of Receiver.
//Really simple - just receives packet, checks if there were errors on the way
//and if the packet if damaged, and basing on that - sets ACK flag, sends back.

class RX : public Process
{
  RX();
  ~RX();
  Packet* received_packet_;                 //Variable stores packet received from channel
  void ClaimPacket(Channel* ch);            //Function supposed to get packet from channel to RX
  void CheckPacket();                       //Function that checks if packet is damaged etc.
  void SendBack(Channel *ch);               //Function supposed to send packet with ACK flag set back
  void WaitACKTransmission(double* clock);  //Waits transmission time of ACK
  void WaitTillPacket(double* clock);       //Waits until RX receives packet
};

#endif //RX_H_
