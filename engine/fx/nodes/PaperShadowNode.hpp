#pragma once
#include "../Node.hpp"

namespace vfx {
class PaperShadowNode : public Node {
public:
  void process(Frame& frame) override { (void)frame; }
  std::string name() const override { return "PaperShadow"; }
};
}
