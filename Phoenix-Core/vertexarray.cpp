#include "vertexarray.h"

namespace Phoenix
{
	namespace Graphics
	{
		
		VertexArray::VertexArray()
		{
			glGenVertexArrays(3, &m_ArrayID);
		}

		VertexArray::~VertexArray()
		{
			for (unsigned int i = 0; i < m_Buffers.size(); i++)
		
				delete m_Buffers[i];
			
			glDeleteVertexArrays(1, &m_ArrayID);
		}

		void VertexArray::addBuffers(Buffer* buffer, GLuint index)
		{
			bind();
			buffer->bind();
			glEnableVertexAttribArray(index);
			glVertexAttribPointer(index, buffer->getCoponentCount(), GL_FLOAT, GL_FALSE, 0, 0);
			buffer->unbind();
			unbind();

			m_Buffers.push_back(buffer);
		}

		void VertexArray::bind() const
		{
			glBindVertexArray(m_ArrayID);
		}

		void VertexArray::unbind() const
		{
			glBindVertexArray(0);
		}
	}
}
