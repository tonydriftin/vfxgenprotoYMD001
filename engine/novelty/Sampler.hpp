#pragma once
#include <cstdint>

namespace vfx {
class Sampler {
public:
  explicit Sampler(uint64_t seed = 1) : m_state(seed) {}
  uint32_t next();
  float nextFloat();
  void mutate(uint64_t seed);
private:
  uint64_t m_state;
};
}
