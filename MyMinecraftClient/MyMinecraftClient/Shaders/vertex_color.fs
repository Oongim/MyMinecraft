#version 410

in vec2 fragUV;

uniform sampler2D u_Texture;
uniform vec4 u_Col;

out vec4 outColor;

void main()
{
	outColor = texture(u_Texture, fragUV);
	if(outColor.a < 0.8) discard;
	outColor.a = u_Col.a;
}