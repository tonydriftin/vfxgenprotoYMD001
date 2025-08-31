#include <metal_stdlib>
using namespace metal;

struct Params {
  float flowToUV;
  float scale;
  float decay;
  int   taps;
};

fragment float4 trail_frag(RasterizerData in [[stage_in]],
                           texture2d<float> src  [[texture(0)]],
                           texture2d<float2> flow[[texture(1)]],
                           constant Params& P    [[buffer(0)]]) {
  constexpr sampler s(address::clamp_to_edge, filter::linear);
  float2 uv = in.texcoord;
  float2 v  = flow.sample(s, uv) * P.flowToUV;
  float3 acc = float3(0.0);
  float wsum = 0.0;
  for (int i=0;i<P.taps;i++){
    float t = float(i)/max(P.taps-1,1);
    float2 suv = uv - t * P.scale * v;
    float  w   = exp(-t * P.decay);
    acc += w * src.sample(s, suv).rgb;
    wsum += w;
  }
  return float4(acc / max(wsum, 1e-4), 1.0);
}
