#include "shader.h"


namespace Phoenix
{
	namespace Graphics
	{

		Shader::Shader(const char* vertPath, const char* fragPath)
			: m_VertPath(vertPath), m_FragPath(fragPath)
		{
			m_ShaderID = loadBasic();
		}

		Shader::Shader(const char* vertPath, const char* fragPath, const char* tessControlPath, const char* tessEvaluationPath, const char* geometryPath)
			: m_VertPath(vertPath), m_FragPath(fragPath), m_TessControlPath(tessControlPath), m_TessEvaluationPath(tessEvaluationPath), m_GeometryPath(geometryPath)
		{
			m_ShaderID = load();
		}

		Shader::~Shader()
		{
			glDeleteShader(m_ShaderID);
		}

		GLuint Shader::loadBasic()
		{
			GLuint program = glCreateProgram();

			GLuint vertex = glCreateShader(GL_VERTEX_SHADER);
			std::string vertSourceString = read_file(m_VertPath);
			const char* vertSource = vertSourceString.c_str();
			glShaderSource(vertex, 1, &vertSource, NULL);
			glCompileShader(vertex);
			GLint result;
			glGetShaderiv(vertex, GL_COMPILE_STATUS, &result);
			if (result == GL_FALSE)
			{
				GLint length;
				GLchar compilerSpew[256];
				glGetShaderiv(vertex, GL_INFO_LOG_LENGTH, &length);
				std::vector<char> error(length);
				glGetShaderInfoLog(vertex, length, &length, &error[0]);
				std::cout << "Failed to compile vertex shader" << std::endl << &error[0] << std::endl;
				glGetShaderInfoLog(vertex, sizeof(compilerSpew), 0, compilerSpew);
				std::cout << "Something wrong on the Vertex Shader " << std::endl << compilerSpew << std::endl;
				glDeleteShader(vertex);
				return 0;
			}


			GLuint fragment = glCreateShader(GL_FRAGMENT_SHADER);
			std::string fragSourceString = read_file(m_FragPath);
			const char* fragSource = fragSourceString.c_str();
			glShaderSource(fragment, 1, &fragSource, NULL);
			glCompileShader(fragment);
			GLint result1;
			glGetShaderiv(fragment, GL_COMPILE_STATUS, &result1);
			if (result1 == GL_FALSE)
			{
				GLint length;
				GLchar compilerSpew[256];
				glGetShaderiv(fragment, GL_INFO_LOG_LENGTH, &length);
				std::vector<char> error(length);
				glGetShaderInfoLog(fragment, length, &length, &error[0]);
				std::cout << "Failed to compile fragment shader" << std::endl << &error[0] << std::endl;
				glGetShaderInfoLog(fragment, sizeof(compilerSpew), 0, compilerSpew);
				std::cout << "Something wrong on the Fragment Shader " << std::endl << compilerSpew << std::endl;
				glDeleteShader(fragment);
				return 0;
			}

			glAttachShader(program, vertex);
			glAttachShader(program, fragment);

			glBindAttribLocation(program, 0, "position");

			glLinkProgram(program);
			GLint error;
			glGetProgramiv(program, GL_LINK_STATUS, &error);
			if (error == GL_FALSE)
			{
				GLchar compilerSpew[256];
				glGetProgramInfoLog(program, sizeof(compilerSpew), 0, compilerSpew);
				std::cout << "Something went wrong when linking shaders " << std::endl << compilerSpew << std::endl;
			}

			glValidateProgram(program);

			glDeleteShader(vertex);
			glDeleteShader(fragment);

			glDetachShader(program, vertex);
			glDetachShader(program, fragment);



			return program;
		}

		GLuint Shader::load()
		{
			GLuint program = glCreateProgram();

			GLuint vertex = glCreateShader(GL_VERTEX_SHADER);
			std::string vertSourceString = read_file(m_VertPath);
			const char* vertSource = vertSourceString.c_str();
			glShaderSource(vertex, 1, &vertSource, NULL);
			glCompileShader(vertex);
			GLint result;
			glGetShaderiv(vertex, GL_COMPILE_STATUS, &result);
			if (result == GL_FALSE)
			{
				GLint length;
				GLchar compilerSpew[256];
				glGetShaderiv(vertex, GL_INFO_LOG_LENGTH, &length);
				std::vector<char> error(length);
				glGetShaderInfoLog(vertex, length, &length, &error[0]);
				std::cout << "Failed to compile vertex shader" << std::endl << &error[0] << std::endl;
				glGetShaderInfoLog(vertex, sizeof(compilerSpew), 0, compilerSpew);
				std::cout << "Something wrong on the Vertex Shader " << std::endl << compilerSpew << std::endl;
				glDeleteShader(vertex);
				return 0;
			}


			GLuint tcs = glCreateShader(GL_TESS_CONTROL_SHADER);
			std::string tesscontrolSourceString = read_file(m_TessControlPath);
			const char* tessSource1 = tesscontrolSourceString.c_str();
			glShaderSource(tcs, 1, &tessSource1, NULL);
			glCompileShader(tcs);
			GLint result2;
			glGetShaderiv(tcs, GL_COMPILE_STATUS, &result2);
			if (result2 == GL_FALSE)
			{
				GLint length;
				GLchar compilerSpew[256];
				glGetShaderiv(tcs, GL_INFO_LOG_LENGTH, &length);
				std::vector<char> error(length);
				glGetShaderInfoLog(tcs, length, &length, &error[0]);
				std::cout << "Failed to compile tesselation control shader" << std::endl << &error[0] << std::endl;
				glGetShaderInfoLog(tcs, sizeof(compilerSpew), 0, compilerSpew);
				std::cout << "Something wrong on the Tessellation Control Shader " << std::endl << compilerSpew << std::endl;
				glDeleteShader(tcs);
				return 0;
			}


			GLuint tes = glCreateShader(GL_TESS_EVALUATION_SHADER);
			std::string tessevaluationSourceString = read_file(m_TessEvaluationPath);
			const char* tessSource2 = tessevaluationSourceString.c_str();
			glShaderSource(tes, 1, &tessSource2, NULL);
			glCompileShader(tes);
			GLint result3;
			glGetShaderiv(tes, GL_COMPILE_STATUS, &result3);
			if (result3 == GL_FALSE)
			{
				GLint length;
				GLchar compilerSpew[256];
				glGetShaderiv(tes, GL_INFO_LOG_LENGTH, &length);
				std::vector<char> error(length);
				glGetShaderInfoLog(tes, length, &length, &error[0]);
				std::cout << "Failed to compile tesselation evaluation shader" << std::endl << &error[0] << std::endl;
				glGetShaderInfoLog(tes, sizeof(compilerSpew), 0, compilerSpew);
				std::cout << "Something wrong on the Tessellation Evaluation Shader " << std::endl << compilerSpew << std::endl;
				glDeleteShader(tes);
				return 0;
			}


			GLuint geometry = glCreateShader(GL_GEOMETRY_SHADER);
			std::string geoSourceString = read_file(m_GeometryPath);
			const char* geoSource = geoSourceString.c_str();
			glShaderSource(geometry, 1, &geoSource, NULL);
			glCompileShader(geometry);
			GLint result4;
			glGetShaderiv(geometry, GL_COMPILE_STATUS, &result4);
			if (result4 == GL_FALSE)
			{
				GLint length;
				GLchar compilerSpew[256];
				glGetShaderiv(geometry, GL_INFO_LOG_LENGTH, &length);
				std::vector<char> error(length);
				glGetShaderInfoLog(geometry, length, &length, &error[0]);
				std::cout << "Failed to compile Geometry shader" << std::endl << &error[0] << std::endl;
				glGetShaderInfoLog(geometry, sizeof(compilerSpew), 0, compilerSpew);
				std::cout << "Something wrong on the geometry Shader " << std::endl << compilerSpew << std::endl;
				glDeleteShader(geometry);
				return 0;
			}



			GLuint fragment = glCreateShader(GL_FRAGMENT_SHADER);
			std::string fragSourceString = read_file(m_FragPath);
			const char* fragSource = fragSourceString.c_str();
			glShaderSource(fragment, 1, &fragSource, NULL);
			glCompileShader(fragment);
			GLint result1;
			glGetShaderiv(fragment, GL_COMPILE_STATUS, &result1);
			if (result1 == GL_FALSE)
			{
				GLint length;
				GLchar compilerSpew[256];
				glGetShaderiv(fragment, GL_INFO_LOG_LENGTH, &length);
				std::vector<char> error(length);
				glGetShaderInfoLog(fragment, length, &length, &error[0]);
				std::cout << "Failed to compile fragment shader" << std::endl << &error[0] << std::endl;
				glGetShaderInfoLog(fragment, sizeof(compilerSpew), 0, compilerSpew);
				std::cout << "Something wrong on the Fragment Shader " << std::endl << compilerSpew << std::endl;
				glDeleteShader(fragment);
				return 0;
			}
			
			glAttachShader(program, vertex);
			glAttachShader(program, tcs);
			glAttachShader(program, tes);
			glAttachShader(program, geometry);
			glAttachShader(program, fragment);

			glBindAttribLocation(program, 0, "position");

			glLinkProgram(program);
			GLint error;
			glGetProgramiv(program, GL_LINK_STATUS, &error);
			if (error == GL_FALSE)
			{
				GLchar compilerSpew[256];
				glGetProgramInfoLog(program, sizeof(compilerSpew), 0, compilerSpew);
				std::cout << "Something went wrong when linking shaders " << std::endl << compilerSpew << std::endl;
			}

			glValidateProgram(program);

			glDeleteShader(vertex);
			glDeleteShader(tcs);
			glDeleteShader(tes);
			glDeleteShader(geometry);
			glDeleteShader(fragment);

			//glPatchParameteri(GL_PATCH_VERTICES, 4);
			//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

			glDetachShader(program, vertex);
			glDetachShader(program, tcs);
			glDetachShader(program, tes);
			glDetachShader(program, geometry);
			glDetachShader(program, fragment);



			return program;
		}

		void Shader::update(const Maths::Transform& transform)
		{

		}

		GLuint Shader::getuniformLocation(const GLchar* name)
		{
			return glGetUniformLocation(m_ShaderID, name);
		}

		void Shader::setUniform1f(const GLchar* name, float value)
		{
			glUniform1f(getuniformLocation(name), value);
		}

		void Shader::setUniform1fv(const GLchar* name, float* value, int count)
		{
			glUniform1fv(getuniformLocation(name), count, value);
		}

		void Shader::setUniform1i(const GLchar* name, int value)
		{
			glUniform1i(getuniformLocation(name), value);
		}

		void Shader::setUniform1iv(const GLchar* name, int* value, int count)
		{
			glUniform1iv(getuniformLocation(name), count, value);
		}

		void Shader::setUniform2f(const GLchar* name, const Maths::vec2 vector)
		{
			glUniform2f(getuniformLocation(name), vector.x, vector.y);
		}

		void Shader::setUniform3f(const GLchar* name, const Maths::vec3 vector)
		{
			glUniform3f(getuniformLocation(name), vector.x, vector.y, vector.z);
		}

		void Shader::setUniform4f(const GLchar* name, const Maths::vec4 vector)
		{
			glUniform4f(getuniformLocation(name), vector.x, vector.y, vector.z, vector.w);
		}

		void Shader::setUniformMat4(const GLchar* name, const Maths::mat4& matrix)
		{
			glUniformMatrix4fv(getuniformLocation(name), 1, GL_FALSE, matrix.elements);
		}

		void Shader::enable() const
		{
			glUseProgram(m_ShaderID);
		}

		void Shader::disable() const
		{
			glUseProgram(0);
		}
	}
}