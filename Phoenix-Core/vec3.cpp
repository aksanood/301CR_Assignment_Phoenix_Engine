#include "vec3.h"

namespace Phoenix
{
	namespace Maths
	{
		vec3::vec3()
		{
			x = 0.0f;
			y = 0.0f;
			z = 0.0f;
		}

		vec3::vec3(const float& x, const float& y, const float& z)
		{
			this->x = x;
			this->y = y;
			this->z = z;
		}

		vec3& vec3::add(const vec3& other)
		{
			x += other.x;
			y += other.y;
			z += other.z;

			return *this;
		}

		vec3& vec3::substract(const vec3& other)
		{
			x -= other.x;
			y -= other.y;
			z -= other.z;

			return *this;
		}

		vec3& vec3::multiply(const vec3& other)
		{
			x *= other.x;
			y *= other.y;
			z *= other.z;

			return *this;
		}

		vec3& vec3::multiply(float other)
		{
			x *= other;
			y *= other;
			z *= other;

			return *this;
		}

		vec3& vec3::divide(const vec3& other)
		{
			x /= other.x;
			y /= other.y;
			z /= other.z;

			return *this;
		}

		vec3& vec3::negative()
		{

			return vec3(-x, -y, -z);
		}

		vec3 operator+(vec3 left, const vec3& right)
		{
			return left.add(right);
		}

		vec3 operator-(vec3 left, const vec3& right) 
		{
			return left.substract(right);
		}

		vec3 operator*(vec3 left, const vec3& right)
		{
			return left.multiply(right);
		}

		vec3 operator/(vec3 left, const vec3& right)
		{
			return left.divide(right);
		}

		vec3& vec3::operator+=(const vec3& other)
		{
			return add(other);
		}

		vec3& vec3::operator-=(const vec3& other)
		{
			return substract(other);
		}

		vec3& vec3::operator*=(const vec3& other)
		{
			return multiply(other);
		}

		vec3& vec3::operator/=(const vec3& other)
		{
			return divide(other);
		}

		bool vec3::operator==(const vec3& other)
		{
			return x == other.x && y == other.y && z == other.z;
		}

		bool vec3::operator!=(const vec3& other)
		{
			return !(*this == other);
		}

		vec3 vec3::Cross(const vec3& other) const
		{
			return vec3(y * other.z - z * other.y, z * other.x - x * other.z, x * other.y - y * other.x);
		}

		float vec3::Dot(const vec3& other) const
		{
			return x * other.x + y * other.y + z * other.z;
		}


		float vec3::Magnitude() const
		{
			return sqrt(x * x + y * y + z * z);
		}

		vec3 vec3::Normalize() const
		{
			float length = Magnitude();
			return vec3(x / length, y / length, z / length);
		}

		float vec3::Distance(const vec3& other) const
		{
			float a = x - other.x;
			float b = y - other.y;
			float c = z - other.z;
			return sqrt(a * a + b * b + c * c);
		}

		std::ostream& operator << (std::ostream& stream, const vec3& vector)
		{
			stream << "vec3: (" << vector.x << ", " << vector.y <<", " << vector.z << ")";
			return stream;
		}
	}
}