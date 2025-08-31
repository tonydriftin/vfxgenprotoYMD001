#include "Constraints.hpp"
#include <algorithm>

namespace vfx {
float Constraints::clamp(float v, float lo, float hi) {
  return std::max(lo, std::min(hi, v));
}
}
