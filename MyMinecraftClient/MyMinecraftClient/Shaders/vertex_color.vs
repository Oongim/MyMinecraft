#version 410

in vec3 pos;
in vec2 uv;

uniform vec3 u_Trans;

out vec2 fragUV;

void main()
{
   	gl_Position = vec4(pos+u_Trans, 1.0);
	fragUV = uv;
}
