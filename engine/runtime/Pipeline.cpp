#include "Pipeline.hpp"
#include "../novelty/DNA.hpp"

namespace vfx {
Pipeline::Pipeline(int w, int h) : m_w(w), m_h(h) {}

void Pipeline::pushVideoFile(const std::string& path) { (void)path; }
void Pipeline::setPreset(const std::string& dnaJson) { (void)dnaJson; }
void Pipeline::renderFrame(double t) {
  (void)t;
  Frame f; m_graph.process(f);
}
void Pipeline::exportVideo(const std::string& outPath) { (void)outPath; }

extern "C" {
void* vfx_create_pipeline(int width, int height) { return new Pipeline(width, height); }
void  vfx_push_video_file(void* p, const char* path) {
  if (p) static_cast<Pipeline*>(p)->pushVideoFile(path ? path : "");
}
void  vfx_set_preset(void* p, const char* dna_json) {
  if (p) static_cast<Pipeline*>(p)->setPreset(dna_json ? dna_json : "");
}
void  vfx_render_frame(void* p, double t) {
  if (p) static_cast<Pipeline*>(p)->renderFrame(t);
}
void  vfx_export(void* p, const char* out_path) {
  if (p) static_cast<Pipeline*>(p)->exportVideo(out_path ? out_path : "");
}
void  vfx_destroy(void* p) {
  delete static_cast<Pipeline*>(p);
}
}
}
