#version 410

in vec3 pos;
in vec2 uv;

uniform vec3 u_Trans;
uniform vec2 u_SpriteSize;
uniform vec2 u_SpriteOffset;

out vec2 fragUV;

void main()
{
   	gl_Position = vec4(pos+u_Trans, 1.0);
	fragUV = (vec2(uv.x,1.0-uv.y)+u_SpriteOffset)*u_SpriteSize;
}
