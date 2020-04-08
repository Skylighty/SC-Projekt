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
  TX(int id);                         //Transmitter class constructor
  ~TX();                              //Transmitter class deconstructor
  void GeneratePacket();              //Function supposed to generate a new packet and put it in FIFO queue packet_buffer_
  void StartTransmission(Channel* channel);// Function that passes the _current_packet_
  void GetPacket();                   //Function that gets the packet from buffer
  bool Handshake(Channel* channel);        //Function that checks if whole transmission was successful and clears the packet pointers
  double GenerateT();                //Function supposed to generate T random value 
  double GenerateR();                //Function supposed to generate R random value
  bool IsChannelBusy(Channel* channel);    //Function that checks availability of the channel
  int const kTx_count_ = 4;           //Const variable without sign that is equal to the numbers of transmitters in our whole system
  //
  //================================================
  //TODO:Implement time-----------------------------
  void WaitCTP(double *clock);        //Function that suspends TX process for CTP time (packet transmission time)
  void WaitCGP(double* clock);        //Function that suspends TX process for CGP time (time required to generate new packet)
  void WaitCP(double* clock);         //Function that suspends TX process for CP time (time 
  void WaitCRP(double* clock);        //Function that suspends TX process for CRP time (time required to check channel availability in RETRANSMISSION)
  void WaitTillACK(double* clock);    //Function that suspends TX process until it receives back a packet with ACK flag equal to 'true'
  //TODO:Implement time------------------------------
  //=================================================
  //--------------GETTERS--&--OPERATIONS-------------
  //=================================================
  inline int GetTxID() { return this->tx_id_; }
  inline Packet* GetCurrentPacket() { return this->current_packet_; }
  inline void PushPacketToBuffer(Packet* packet) { this->packet_buffer_.push(packet); }
  inline void PopPacketFromBuffer() { this->packet_buffer_.pop(); }
  inline Packet* FrontPacketFromBuffer() {return this->packet_buffer_.front(); }
  //----------------SETTERS-------------------------
  inline void SetTxID(int id) { this->tx_id_ = id; }
  inline void SetCurrentPacket(Packet* packet) { this->current_packet_ = packet; }
  //------------------------------------------------
  enum class State                          //Declaring enum property of a class to determine it's phase during execution
  {
    NOT_READY,
    READY,
    FROZEN,
    FEEDBACK,
    RETRANSMISSION
  };                       

private:
  int tx_id_;                         //Variable without a sign that is equal to very own TX number, so we're sure that program won't mistake one TX with another
  Packet* current_packet_;            //Variable which contains a packet that currently is to-be-transmitted by TX
  std::queue<Packet*> packet_buffer_; //Buffer of packets which is contained within every TX unit/object
};


#endif //TX_H_
