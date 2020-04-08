#include "wireless_network.h"

WirelessNetwork::WirelessNetwork()
{
  RXList = new std::vector<RX*>();
  TXList = new std::vector<TX*>();
  ProcessAgenda = new std::vector<Process*>();
  clock = 0;
  for (int i = 0; i < kDeviceCount; ++i)
  {
    TXList->push_back(new TX(i));
    RXList->push_back(new RX(i));
 
  }
}

WirelessNetwork::~WirelessNetwork()
{
  
}
