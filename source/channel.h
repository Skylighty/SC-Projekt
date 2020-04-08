#ifndef CHANNEL_H_
#define CHANNEL_H_
#include "packet.h"
#include <vector>

//Channel is defined as class, however it's NOT a process,
//because in my opinion channel is just a medium and it's passive element of the network,
//so we just need to know whether it's busy or not.


class Channel
{
public:
  Channel();                                //Object constructor
  ~Channel();                               //Object deconstructor
  inline bool GetChannelBusy() { return this->busy_; }
  inline void PushPacketToChannel(Packet* packet) { this->packets_in_channel_.push_back(packet); }
  inline void PopPacketFromChannel() { this->packets_in_channel_.pop_back(); }
  inline void SetChannelBusy(bool decision) { this->busy_ = decision; }
  private:
  bool busy_;                               //Binary variable determining if the channel is currently busy or not
  std::vector<Packet*> packets_in_channel_;    //Contains a pointer to the packet that currently is in the channel


};
#endif //CHANNEL_H_