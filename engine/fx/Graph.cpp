#include "Graph.hpp"
#include "../runtime/Frame.hpp"

namespace vfx {
void Graph::addNode(NodePtr node) {
  m_nodes.emplace_back(std::move(node));
}

void Graph::process(Frame& frame) {
  for (auto& n : m_nodes) {
    n->process(frame);
  }
}
}
