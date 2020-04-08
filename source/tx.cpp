#include "tx.h"

TX::TX(int id)
{
  tx_id_ = id;                  //The TX very own ID must be passed as an argument, to be sure that we wont duplicate it
  current_packet_ = nullptr;    //And no packet is serviced by TX
  packet_buffer_ = {};          //Buffer/queue is set as empty as the object is created
}

//----------------------------------------------------------
//Function creates new packet object with a pointer to it
//and sets it as TX's currently serviced packet if buffer is empty and current_packet_ variable is NULL
//otherwise it pushes the packet to FIFO packet queue of TX
//----------------------------------------------------------
void TX::GeneratePacket()
{ //0 is temporary in constructor; //TODO:Implement this
 
}

//-------------------------------------------------------
//Function starts transmission or retransmission
//passing the packet object to the channel.
//If retransmissions limit is exceeded - packet is rejected and deleted.
//------------------------------------------------------
void TX::StartTransmission(Channel* channel)
{

}

//----------------------------------------------------
//Function sets packet that is first in packet buffer
//as packet currently serviced by TX
//----------------------------------------------------
void TX::GetPacket()
{

}

//------------------------------------------------------
//Function checks if the receipt of packet on the RX side
// was successful - if so - can start whole cycle again
//------------------------------------------------------
bool TX::Handshake(Channel* channel)
{
  return false;
}

//----------------------------------------------------
//Function checks if the channel is busy
//and increments channel-free checks storing variable
//----------------------------------------------------
bool TX::IsChannelBusy(Channel* channel)
{
  return channel->GetChannelBusy();
}
