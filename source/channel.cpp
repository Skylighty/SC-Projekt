#include "channel.h"

Channel::Channel()
{
  busy_ = false;
  serviced_packet_ = nullptr;
}
