#include "rx.h"

RX::RX(int id)
{
  rx_id_ = id;
  received_packet_ = nullptr;
}

RX::~RX()
{
}

void RX::ClaimPacket(Channel* channel)
{

}

void RX::CheckPacket()
{

}

void RX::SendBack(Channel* channel)
{

}

