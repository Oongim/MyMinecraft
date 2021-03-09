#version 410

in vec2 fragUV;

uniform sampler2D u_Texture;

out vec4 outColor;

void main()
{
	outColor = texture(u_Texture, fragUV);
}