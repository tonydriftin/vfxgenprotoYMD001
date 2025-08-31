#include "../../engine/runtime/Pipeline.hpp"
#include <iostream>

int main(int argc, char** argv) {
    if (argc < 3) {
        std::cout << "usage: vfxcli in.mp4 out.mp4\n";
        return 0;
    }
    vfx::Pipeline p(640, 480);
    p.pushVideoFile(argv[1]);
    p.exportVideo(argv[2]);
    return 0;
}
