/*#version 420 core 

uniform vec2 light_pos;
out vec4 color;

in DATA
{
	vec4 color;
} fs_in;




void main(void)
{
	
	color = fs_in.color;

	//color = vec4(sin(gl_FragCoord.x * 0.25) * 0.5 + 0.5,
		//			cos(gl_FragCoord.y * 0.25) * 0.5 + 0.5,
			//			sin(gl_FragCoord.x * 0.15) * cos(gl_FragCoord.y * 0.15), 1.0);
	
}*/

#version 430 core

in DATA
{
	vec4 color;

} fs_in;

out vec4 color;

void main(void)
{
	color = fs_in.color;
}