#include <metal_stdlib>
using namespace metal;

fragment float4 paper_frag(RasterizerData in [[stage_in]],
                           texture2d<float> src [[texture(0)]]) {
  constexpr sampler s(address::clamp_to_edge, filter::linear);
  float3 col = src.sample(s, in.texcoord).rgb;
  float shadow = 0.5;
  return float4(col * shadow, 1.0);
}
