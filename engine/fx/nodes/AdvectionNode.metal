#include <metal_stdlib>
using namespace metal;

struct Params { float scale; float flowToUV; };
fragment float4 advect_frag(RasterizerData in [[stage_in]],
                            texture2d<float> src [[texture(0)]],
                            texture2d<float2> flow [[texture(1)]],
                            constant Params& P [[buffer(0)]]) {
  constexpr sampler s(address::clamp_to_edge, filter::linear);
  float2 uv = in.texcoord;
  float2 v = flow.sample(s, uv) * P.flowToUV;
  return src.sample(s, uv - P.scale * v);
}
