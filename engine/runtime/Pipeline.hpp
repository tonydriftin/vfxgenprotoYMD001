#pragma once
#include "../fx/Graph.hpp"
#include "Frame.hpp"
#include <string>

namespace vfx {
class Pipeline {
public:
  Pipeline(int w, int h);
  void pushVideoFile(const std::string& path);
  void setPreset(const std::string& dnaJson);
  void renderFrame(double t);
  void exportVideo(const std::string& outPath);
private:
  int m_w, m_h;
  Graph m_graph;
};

extern "C" {
void* vfx_create_pipeline(int width, int height);
void  vfx_push_video_file(void* p, const char* path);
void  vfx_set_preset(void* p, const char* dna_json);
void  vfx_render_frame(void* p, double t);
void  vfx_export(void* p, const char* out_path);
void  vfx_destroy(void* p);
}
}
