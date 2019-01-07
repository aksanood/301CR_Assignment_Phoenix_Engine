/*#version 420 core

layout (location = 0) in vec4 position;
layout (location = 1) in vec3 normal;
layout (location = 2) in vec2 tex_cord;
layout (location = 3) in vec4 offset;
layout (location = 4) in vec4 color;
layout (location = 5) in int material_id;

attribute vec3 pos;
uniform mat4 transform;

out DATA
{
	vec4 color;
} vs_out;


void main(void)
{
	
	
	//assigning colors to each verticies
	const vec4 colors[] = vec4[3] (vec4(1.0, 0.0, 0.0, 1.0),
									vec4(0.0, 1.0, 0.0, 1.0),
										vec4(0.0, 0.0, 1.0, 1.0));
	const vec4 red = vec4(1,0,0,1);


	//gl_Position = verts[gl_VertexID] + offset;	
	//gl_Position = transform * vec4(pos, 1.0);	
	gl_Position = position + offset;	




	//vs_out.color = color;
	//vs_out.color = red;
	vs_out.color = colors[gl_VertexID];
}*/


#version 430 core

layout (location = 0) in vec4 offset;
layout (location = 1) in vec4 color;
attribute vec3 position;
uniform mat4 transform;
uniform mat4 viewprojection;

out DATA
{
	vec4 color;
	
} vs_out;


void main(void)
{
	//drawing a triangle
	const vec4 vertices[3] = vec4[3] (vec4(0.25, -0.25, 0.5, 1.0),
								   vec4(-0.25, -0.25, 0.5, 1.0),
								   vec4(0.25, 0.25, 0.5, 1.0));


	//gl_Position = vertices[gl_VertexID] + offset;
	gl_Position =  transform * viewprojection *  vec4(position, 1.0); //With transform options
	vs_out.color = color;
}