#pragma once
#include <cstdint>

namespace vfx {
bool detectSceneChange(const uint8_t* cur, const uint8_t* prev, int width, int height);
}
