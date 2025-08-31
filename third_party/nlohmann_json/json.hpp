#pragma once
#include <string>
namespace nlohmann {
class json {
public:
  json() = default;
  static json parse(const std::string&) { return json(); }
  template<typename T>
  T get() const { return T(); }
  json& operator[](const std::string&) { return *this; }
  const json& operator[](const std::string&) const { return *this; }
};
}
