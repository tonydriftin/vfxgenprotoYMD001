#version 300 es
precision mediump float;
in vec2 vUV;
uniform sampler2D uSrc, uFlow;
uniform float uScale, uFlowToUV;
out vec4 oColor;
void main(){
  vec2 v = texture(uFlow, vUV).xy * uFlowToUV;
  oColor = texture(uSrc, vUV - uScale * v);
}
