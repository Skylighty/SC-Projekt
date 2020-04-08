#ifndef WIRELESS_NETWORK_H_
#define WIRELESS_NETWORK_H_
#include "tx.h"
#include "rx.h"
#include "process.h"
#include <vector>

class WirelessNetwork
{
public:
  WirelessNetwork();
  ~WirelessNetwork();
private:
  std::vector<TX*>* TXList;
  std::vector<RX*>* RXList;
  std::vector<Process*>* ProcessAgenda;
  int const kDeviceCount = 4;
  double clock;
};


#endif //WIRELESS_NETWORK_H_
