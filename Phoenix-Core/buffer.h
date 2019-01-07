#pragma once
#include <GL\glew.h>

namespace Phoenix
{
	namespace Graphics
	{
		class Buffer
		{
		private:
			GLuint m_BufferID;
			GLuint m_componentCount;

		public:
			Buffer(GLfloat* data, GLsizei count, GLuint componentCount);
			~Buffer();
			void bind() const;
			void unbind() const;

			inline GLuint getCoponentCount() const { return m_componentCount; }
		};

	}
}
