#pragma once
#include <vector>
#include <cstdint>

namespace vfx {
struct ROI { int x; int y; int w; int h; };

class TierA {
public:
  TierA(int width, int height);
  float diffEnergy(const uint8_t* cur, const uint8_t* prev) const;
  std::vector<ROI> computeROI(const uint8_t* cur, const uint8_t* prev) const;
private:
  int m_width;
  int m_height;
};
}
