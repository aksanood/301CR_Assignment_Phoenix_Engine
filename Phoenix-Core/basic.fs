#version 330 core

layout (location = 0) out vec4 outColor;

uniform vec4 colour;
uniform vec2 light_pos;

in DATA
{
	vec4 position;
	vec2 uv;
	float tid;
	vec4 color;
	
}fs_in;

uniform sampler2D textures[32];

void main()
{
	float intensity = 5.0/ length(fs_in.position.xy - light_pos);
	vec4 texcolor = fs_in.color;
	if (fs_in.tid > 0.0)
		{
			int tid = int(fs_in.tid - 0.5 );
			texcolor = texture(textures[tid], fs_in.uv);
			//texcolor = vec4(tid, 0, 0, 1); //test color
		}

		outColor = texcolor  * intensity;
		//outColor = vec4(1,0,1,1);// * intensity;
}
