#pragma once
#include "../Node.hpp"

namespace vfx {
class AdvectionNode : public Node {
public:
  void process(Frame& frame) override { (void)frame; }
  std::string name() const override { return "Advection"; }
};
}
