#include "tx.h"

TX::TX(unsigned int id)
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
  Packet p = Packet(0,this->tx_id_); 
  Packet* ptr; 
  ptr = &p;   //Pointer is set to point at the newly created packet object
  if (packet_buffer_.empty() && this->current_packet_ == nullptr)
    this->current_packet_ = ptr;
  else
    this->packet_buffer_.push(ptr); //Pointer is being pushed to the FIFO queue 
}

//-------------------------------------------------------
//Function starts transmission or retransmission
//passing the packet object to the channel.
//If retransmissions limit is exceeded - packet is rejected and deleted.
//------------------------------------------------------
void TX::StartTransmission(Channel* ch)
{
  if (this->current_packet_->r_ > 10)
  {
    this->current_packet_->rejected_ = true;
    delete this->current_packet_;
  }
  if (this->current_packet_->retransmission_ == true)
  {
    this->current_packet_->r_++;
    this->current_packet_->retransmission_ = false;
    this->current_packet_->received_ = false;
    this->current_packet_->collision_ = false;
    this->current_packet_->error_ = false;
    ch->busy_ = true;                                                                    //Starts transmission so simultaneously sets channel as busy
    ch->serviced_packet_ = this->current_packet_;                                       //Passes packet from TX to the Channel object
    //this->current_packet_ == nullptr; <- May be necessary if we want to model out collisions
  }
}

//----------------------------------------------------
//Function sets packet that is first in packet buffer
//as packet currently serviced by TX
//----------------------------------------------------
void TX::GetPacket()
{
  this->current_packet_ = this->packet_buffer_.front();
  this->packet_buffer_.pop();
}

//------------------------------------------------------
//Function checks if the receipt of packet on the RX side
// was successful - if so - can start whole cycle again
//------------------------------------------------------
void TX::Handshake(Channel* ch)
{
  this->current_packet_ = ch->serviced_packet_;
  if (this->current_packet_->ack_==true && this->current_packet_->received_ == true)
  {
    this->current_packet_ = nullptr;
    ch->serviced_packet_ = nullptr;
  }
}

//----------------------------------------------------
//Function checks if the channel is busy
//and increments channel-free checks storing variable
//----------------------------------------------------
bool TX::IsChannelBusy(Channel* ch)
{
  this->current_packet_->t_++; //Increments the number of channel-free checks 
  if (ch->busy_ == true) { return true; } 
  else { return false; }
}
