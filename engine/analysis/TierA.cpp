#include "TierA.hpp"
#include <algorithm>

namespace vfx {
TierA::TierA(int width, int height) : m_width(width), m_height(height) {}

float TierA::diffEnergy(const uint8_t* cur, const uint8_t* prev) const {
  if (!cur || !prev) return 0.f;
  size_t total = static_cast<size_t>(m_width) * m_height;
  float sum = 0.f;
  for (size_t i = 0; i < total; ++i) {
    sum += std::abs(int(cur[i]) - int(prev[i]));
  }
  return sum / static_cast<float>(total);
}

std::vector<ROI> TierA::computeROI(const uint8_t* cur, const uint8_t* prev) const {
  (void)cur; (void)prev;
  // Stub: return empty ROI list for now
  return {};
}
}
