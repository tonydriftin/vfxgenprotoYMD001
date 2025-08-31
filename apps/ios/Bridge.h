#pragma once
#ifdef __cplusplus
extern "C" {
#endif
void* vfx_create_pipeline(int width, int height);
void  vfx_push_video_file(void* p, const char* path);
void  vfx_set_preset(void* p, const char* dna_json);
void  vfx_render_frame(void* p, double t);
void  vfx_export(void* p, const char* out_path);
void  vfx_destroy(void* p);
#ifdef __cplusplus
}
#endif
