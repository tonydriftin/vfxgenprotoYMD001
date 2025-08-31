#ifdef PLATFORM_APPLE
#import <Metal/Metal.h>
#import <CoreVideo/CoreVideo.h>
namespace vfx {
void* cvToMetal(void* cvTex) { return cvTex; }
}
#endif
