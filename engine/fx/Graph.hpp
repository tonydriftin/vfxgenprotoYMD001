#pragma once
#include "Node.hpp"
#include <vector>

namespace vfx {
class Graph {
public:
  void addNode(NodePtr node);
  void process(Frame& frame);
private:
  std::vector<NodePtr> m_nodes;
};
}
