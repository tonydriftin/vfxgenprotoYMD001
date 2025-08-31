#pragma once
#include <string>
#include <memory>

namespace vfx {
class Frame;

class Node {
public:
  virtual ~Node() = default;
  virtual void process(Frame& frame) = 0;
  virtual std::string name() const = 0;
};
using NodePtr = std::unique_ptr<Node>;
}
