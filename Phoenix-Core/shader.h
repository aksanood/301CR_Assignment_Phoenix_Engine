#pragma once
#include <iostream>
#include <vector>
#include <GL\glew.h>
#include "fileutils.h"
#include "maths.h"
#include "camera.h"




namespace Phoenix
{

	namespace Graphics
	{
		class Shader 
		{
		private: 
			GLuint m_ShaderID;
			const char *m_VertPath, *m_FragPath, *m_TessControlPath, *m_TessEvaluationPath, *m_GeometryPath;
		public:
			Shader(const char* vertPath, const char* fragPath);
			Shader(const char* vertPath, const char* fragPath, const char* tessControlPath, const char* tessEvaluationPath, const char* geometryPath);

			~Shader();

			void update(const Maths::Transform& transform);

			void setUniform1f(const GLchar* name, float value);
			void setUniform1fv(const GLchar* name, float* value, int count);

			void setUniform1i(const GLchar* name, int value);
			void setUniform1iv(const GLchar* name, int* value, int count);

			void setUniform2f(const GLchar* name, const Maths::vec2 vector);
			void setUniform3f(const GLchar* name, const Maths::vec3 vector);
			void setUniform4f(const GLchar* name, const Maths::vec4 vector);
			void setUniformMat4(const GLchar* name, const Maths::mat4& matrix);

			void enable() const;
			void disable() const;
			

			GLuint getuniformLocation(const GLchar* name);
		private:
			GLuint loadBasic();
			GLuint load();

		};
	}

}
