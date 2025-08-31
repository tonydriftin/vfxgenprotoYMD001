#version 300 es
precision mediump float;
in vec2 vUV;
uniform sampler2D uSrc, uFlow;
uniform float uFlowToUV, uScale, uDecay;
uniform int uTaps;
out vec4 oColor;
void main(){
  vec2 v = texture(uFlow, vUV).xy * uFlowToUV;
  vec3 acc = vec3(0.0); float wsum=0.0;
  for (int i=0;i<uTaps;i++){
    float t = float(i)/max(uTaps-1,1);
    vec2 suv = vUV - t * uScale * v;
    float w = exp(-t * uDecay);
    acc += w * texture(uSrc, suv).rgb; wsum += w;
  }
  oColor = vec4(acc / max(wsum, 1e-4), 1.0);
}
