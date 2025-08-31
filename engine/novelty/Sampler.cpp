#include "Sampler.hpp"

namespace vfx {
uint32_t Sampler::next() {
  m_state ^= m_state << 13;
  m_state ^= m_state >> 7;
  m_state ^= m_state << 17;
  return static_cast<uint32_t>(m_state);
}

float Sampler::nextFloat() {
  return next() / static_cast<float>(0xFFFFFFFFu);
}

void Sampler::mutate(uint64_t seed) {
  m_state ^= seed;
}
}
