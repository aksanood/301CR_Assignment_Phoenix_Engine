#include "mesh.h"

namespace Phoenix
{
	namespace Graphics
	{
		Mesh::Mesh(Vertex* verts, unsigned int numVerts)
			:m_drawCount(numVerts)
		{
			
			glGenVertexArrays(1, &m_VertexArrayObject);
			glBindVertexArray(m_VertexArrayObject);

			glGenBuffers(NUM_BUFFERS, mVertexArrayBuffers);
			glBindBuffer(GL_ARRAY_BUFFER, mVertexArrayBuffers[POSITION_VB]);
			glBufferData(GL_ARRAY_BUFFER, numVerts * sizeof(verts[0]), verts, GL_DYNAMIC_DRAW);

			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

			glBindVertexArray(0);
		}

		Mesh::~Mesh()
		{

		}

		void Mesh::draw()
		{
			glBindVertexArray(m_VertexArrayObject);
			glDrawArrays(GL_TRIANGLES, 0, m_drawCount);
			glBindVertexArray(0);

		}
	}
}