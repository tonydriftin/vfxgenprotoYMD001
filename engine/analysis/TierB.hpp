#pragma once
#include <vector>
#include <cstdint>

namespace vfx {
struct FlowVec { float x; float y; };
using FlowField = std::vector<FlowVec>;

class TierB {
public:
  FlowField compute(const uint8_t* roi, int width, int height) const;
};
}
