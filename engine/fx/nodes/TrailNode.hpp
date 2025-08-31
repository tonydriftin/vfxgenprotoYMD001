#pragma once
#include "../Node.hpp"

namespace vfx {
struct TrailParams { int taps = 3; float scale = 1.0f; float decay = 1.0f; };

class TrailNode : public Node {
public:
  void process(Frame& frame) override { (void)frame; }
  std::string name() const override { return "Trail"; }
};
}
