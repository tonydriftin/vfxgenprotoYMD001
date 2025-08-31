#version 300 es
precision mediump float;
in vec2 vUV;
uniform sampler2D uSrc;
out vec4 oColor;
void main(){
  vec3 col = texture(uSrc, vUV).rgb;
  float shadow = 0.5;
  oColor = vec4(col * shadow, 1.0);
}
