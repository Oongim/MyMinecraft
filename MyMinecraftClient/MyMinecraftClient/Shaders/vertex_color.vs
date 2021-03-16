#version 410

in vec3 pos;
in vec2 uv;

uniform mat4 u_Transfrom;
uniform vec2 u_SpriteSize;
uniform vec2 u_SpriteOffset;
uniform bool u_isLeft;

out vec2 fragUV;

void main()
{
   	gl_Position = u_Transfrom * vec4(pos, 1.0);
	if(!u_isLeft)
		fragUV = (vec2(uv.x,1.0-uv.y)+u_SpriteOffset)*u_SpriteSize;
	else
		fragUV = (vec2(1.0-uv.x,1.0-uv.y)+u_SpriteOffset)*u_SpriteSize;
}
