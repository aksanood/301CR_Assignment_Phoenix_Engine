#pragma once
#include <GL\glew.h>
#include "vec3.h"

namespace Phoenix
{
	namespace Graphics
	{

		class Vertex
		{

		public:
			Vertex(const Maths::vec3& position)
			{
				this->m_Position= position;
			}
		private:
			Maths::vec3 m_Position;
		};



		class Mesh
		{
		public:
			Mesh(Vertex* verts, unsigned int numVerts);
			virtual ~Mesh();
			void draw();
		private:
			Mesh(const Mesh& other);
			void operator=(const Mesh& other);

			enum {POSITION_VB, NUM_BUFFERS};

			GLuint m_VertexArrayObject;
			GLuint mVertexArrayBuffers[NUM_BUFFERS];
			unsigned int m_drawCount;

		};
	}
}