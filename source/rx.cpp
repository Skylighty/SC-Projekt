#include "rx.h"

void RX::ClaimPacket(Channel* ch)
{
  this->received_packet_ = ch->serviced_packet_;
  ch->serviced_packet_ = nullptr;
  this->received_packet_->received_ = true;
}

void RX::CheckPacket()
{
  if (this->received_packet_->collision_ == false || this->received_packet_->error_ == false)
  {
    this->received_packet_->ack_ = true;
  }
  else
  {
    this->received_packet_->ack_ = false;
    this->received_packet_->retransmission_ = true;
  }
}

void RX::SendBack(Channel* ch)
{
  ch->serviced_packet_ = this->received_packet_;
  this->received_packet_ = nullptr;

}

