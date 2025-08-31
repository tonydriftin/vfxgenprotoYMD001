#pragma once
#include <cstdint>

namespace vfx {
struct Frame {
  int width = 0;
  int height = 0;
  void* texture = nullptr;
};
}
