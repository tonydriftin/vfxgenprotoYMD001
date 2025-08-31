#pragma once
#include <vector>

namespace vfx {
template <typename T>
class BufferPool {
public:
  explicit BufferPool(size_t n) : m_buf(n) {}
  T& get(size_t i) { return m_buf[i % m_buf.size()]; }
private:
  std::vector<T> m_buf;
};
}
