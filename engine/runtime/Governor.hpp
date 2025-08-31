#pragma once

namespace vfx {
enum class Preset { Lite, Standard, Pro };

class Governor {
public:
  explicit Governor(Preset p = Preset::Standard) : preset(p) {}
  void apply();
  Preset preset;
};
}
