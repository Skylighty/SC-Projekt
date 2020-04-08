#ifndef PACKET_H_
#define PACKET_H_
#include "process.h"

//Packet class is a main information carrier in our simulation system
//Basing on data stored in packet objects, we're able to simulate this system
//TX and RX pairs decide and set properties basing on packets' parameters.
class Packet : public Process
{
public:
  enum class State                                    //Declaring enum property of a class to determine it's phase during execution
  {
    WAITING,
    SENT,
    RECEIVED,
    SENT_BACK,
    RETRANSMITTED
  };

  Packet(unsigned int pid, unsigned int txid);  //ID will be passed as a number from the global generated packet count
  ~Packet();                                    //Default "delete" deconstructor
  void WaitCTIZ(double* clock);                 //Waiting time
  void WaitTillTransmission(double* clock);     //Packet process suspended until it's transmission is started
  int const kCtiz_time_ = 1;                    //Constant time needed to send packet through channel equal to 1ms
  int const kLr_ = 10;                          //Max count of retransmissions
  //=============================================================
  //------------------------GETTERS------------------------------
  //=============================================================
  inline int Getr() { return this->r_; }
  inline int Gett() { return this->t_; }
  inline int GetPacketID() { return this->packet_id_; }
  inline int GetTxID() { return this->tx_id_; }
  inline bool GetACK() { return this->ack_; }
  inline bool GetReceived() { return this->received_; }
  inline bool GetRetransmission() { return this->retransmission_; }
  inline bool GetError() { return this->error_; }
  inline bool GetRejected() { return this->rejected_; }
  inline bool GetCollision() { return this->collision_; }
  //=============================================================
  //-------------------------SETTERS-----------------------------
  //=============================================================
  inline void Setr(int r) { this->r_ = r; }
  inline void Sett(int t) { this->t_ = t; }
  inline void SetPacketID(int id) { this->packet_id_ = id; }
  inline void SetTxID(int id) { this->tx_id_ = id; }
  inline void SetACK(bool ack) { this->ack_ = ack; }
  inline void SetReceived(bool received) { this->received_ = received; }
  inline void SetRetransmission(bool retransmission) { this->retransmission_ = retransmission; }
  inline void SetError(bool error) { this->error_ = error; }
  inline void SetRejected(bool rejected) { this->rejected_ = rejected; }
  inline void SetCollision(bool collision) { this->collision_ = collision; }
  //---------------------------------------------------------------

private:
  int r_;                                       //Variable that indicates number of retransmissions
  int t_;                                       //Variable that indicates number of times we tried to check channel availability
  int packet_id_;                               //Variable that stores very own ID number of the packet
  int tx_id_;                                   //Variable that stores ID of TX/RX between which packet is transmitted
  bool ack_;                                    //Binary flag determining if the packet receipt was successful
  bool received_;                               //Binary flag determining if the packet has been received by RX
  bool retransmission_;                         //Binary flag determining if the packet is currently transmitted or retransmitted
  bool error_;                                  //Binary flag determining if there was an error during the transmission
  bool rejected_;                               //Binary flag determining if the packet was rejected due to too big retransmission count
  bool collision_;                              //Binary flag determinfg if the packet has occured a collision 
};

#endif //PACKET_H_