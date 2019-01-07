#pragma once
#include "maths.h"


namespace Phoenix
{
	namespace Maths
	{
		struct mat4
		{
			union
			{
				float elements[4 * 4];
				vec4 columns[4];
			};

			mat4();
			mat4(float diagonal);

			static mat4 identity();

			mat4& multiply(const mat4& other);
			friend mat4 operator*(mat4 left, const mat4& right);
			mat4& operator*=(const mat4& other);

			vec3 multiply(const vec3& other) const;
			friend vec3 operator*(const mat4& left, const vec3& right);

			vec4 multiply(const vec4& other) const;
			friend vec4 operator*(const mat4& left, const vec4& right);

			mat4& invert();

			static mat4 othographic(float left, float right, float bottom, float top, float near, float far);
			static mat4 perspective(float fov, float aspectratio, float near, float far);
			static mat4 lookat(const vec3& eye, const vec3& center, const vec3& up);

			static mat4 translation(const mat4 result, const vec3& translation);
			static mat4 translation(const vec3& translation);

			static mat4 rotate(float angle, const vec3& axis);
			static mat4 scale(const vec3& scale);

			friend std::ostream& operator << (std::ostream& stream, const mat4& matrix);
		};
	}
}