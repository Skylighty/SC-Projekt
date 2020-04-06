#ifndef CHANNEL_H_
#define CHANNEL_H_
#include "packet.h"

//Channel is defined as class, however it's NOT a process,
//because in my opinion channel is just a medium and it's passive element of the network,
//so we just need to know whether it's busy or not.


class Channel
{
public:
  Channel();                  //Object constructor
  ~Channel();                 //Object deconstructor
  bool busy_;                 //Binary variable determining if the channel is currently busy or not
  Packet* serviced_packet_;   //Contains a pointer to the packet that currently is in the channel
};
#endif //CHANNEL_H_