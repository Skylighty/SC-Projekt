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
public:
  RX(int id);
  ~RX();
  void ClaimPacket(Channel* channel);            //Function supposed to get packet from channel to RX
  void CheckPacket();                       //Function that checks if packet is damaged etc.
  void SendBack(Channel *channel);               //Function supposed to send packet with ACK flag set back
  void WaitACKTransmission(double* clock);  //Waits transmission time of ACK
  void WaitTillPacket(double* clock);       //Waits until RX receives packet
  //
  //-----------------------GET--&--SET-----------------------------
  inline int GetRxID() { return this->rx_id_; }
  inline Packet* GetReceivedPacket() { return this->received_packet_; }
  inline void SetRxID(int id) { this->rx_id_ = id; }
  inline void SetReceivedPacket(Packet* packet) { this->received_packet_ = packet; }
  //---------------------------------------------------------------

  enum State                                //Declaring enum property of a class to determine it's phase during execution
  {
    WAITING,
    RECEIVED,
    CHECK,
    SENT_ACK
  };

private:
  int rx_id_;                               //Variable that stores very own id number of RX unit
  Packet* received_packet_;                 //Variable stores packet received from channel
};

#endif //RX_H_
