#pragma once
#include <iostream>

namespace Phoenix
{
	namespace Maths
	{
		struct vec3
		{
			float x, y, z;

			vec3();
			vec3(const float& x, const float& y, const float& z);


			vec3& add(const vec3& other);
			vec3& substract(const vec3& other);
			vec3& multiply(const vec3& other);
			vec3& multiply(float other);
			vec3& divide(const vec3& other);
			vec3& negative();


			friend vec3 operator+(vec3 left, const vec3& right);
			friend vec3 operator-(vec3 left, const vec3& right);
			friend vec3 operator*(vec3 left, const vec3& right);
			friend vec3 operator/(vec3 left, const vec3& right);

			vec3& operator+=(const vec3& other);
			vec3& operator-=(const vec3& other);
			vec3& operator*=(const vec3& other);
			vec3& operator/=(const vec3& other);

			bool operator==(const vec3& other);
			bool operator!=(const vec3& other);

			vec3 Cross(const vec3& other) const;
			float Dot(const vec3& other) const;

			float Magnitude() const;
			vec3 Normalize() const;
			float Distance(const vec3& other) const;

			friend std::ostream& operator << (std::ostream& stream, const vec3& vector);
		};

	}
}