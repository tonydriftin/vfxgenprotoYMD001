#ifdef PLATFORM_APPLE
#import <Foundation/Foundation.h>
namespace vfx {
void decodeFile(const char* path) { (void)path; }
void encodeFile(const char* path) { (void)path; }
}
#endif
