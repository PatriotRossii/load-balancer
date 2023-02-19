#pragma once

#include <iostream>

#include <boost/asio/ip/tcp.hpp>
#include <load_balancer/server/target_info.hpp>

namespace eoanermine {

namespace load_balancer {

class Algorithm {
public:
  enum class Type { ROUND_ROBIN, CONSTANT };
  virtual TargetInfo &getNext() = 0;
  virtual ~Algorithm();
};

std::istream &operator>>(std::istream &in, Algorithm::Type &algorithm);
std::ostream &operator<<(std::ostream &out, const Algorithm::Type &algorithm);

struct AlgorithmInfo {
  Algorithm::Type type;
  std::size_t targetIdx;
};

} // namespace load_balancer

} // namespace eoanermine