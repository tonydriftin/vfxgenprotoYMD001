#pragma once
#include <string>
#include <cstdint>
#include <unordered_map>
#include "../../third_party/nlohmann_json/json.hpp"

namespace vfx {
struct DNA {
  int v = 1;
  std::string category;
  uint64_t seed = 0;
};

DNA fromJSON(const std::string& jsonStr);
}
