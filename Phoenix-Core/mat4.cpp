#include "mat4.h"


namespace Phoenix
{
	namespace Maths
	{
		mat4::mat4()
		{
			for (int i = 0; i < 4 * 4; i++)
				elements[i] = 0.0f;
		}

		mat4::mat4(float diagonal)
		{
			for (int i = 0; i < 4 * 4; i++)
				elements[i] = 0.0f;

			elements[0 + 0 * 4] = diagonal;
			elements[1 + 1 * 4] = diagonal;
			elements[2 + 2 * 4] = diagonal;
			elements[3 + 3 * 4] = diagonal;
		}

		mat4 mat4::identity()
		{
			return mat4(1.0f);
		}

		mat4& mat4::multiply(const mat4& other)
		{
			float data[16];
			for (int row = 0; row < 4; row++)
			{
				for (int col = 0; col < 4; col++)
				{
					float sum = 0.0f;
					for (int e = 0; e < 4; e++)
					{
						sum += elements[e + row * 4] * other.elements[col + e * 4];
					}
					data[col + row * 4] = sum;
				}

			}
			memcpy(elements, data, 4 * 4 * sizeof(float));
			return *this;
		}

		vec3 mat4::multiply(const vec3& other) const
		{
			return vec3(

				columns[0].x * other.x + columns[1].x * other.y + columns[2].x * other.z + columns[3].x,
				columns[0].y * other.x + columns[1].y * other.y + columns[2].y * other.z + columns[3].y,
				columns[0].z * other.x + columns[1].z * other.y + columns[2].z * other.z + columns[3].z
				

				);
		}

		vec4 mat4::multiply(const vec4& other) const
		{
			return vec4(
					
				columns[0].x * other.x + columns[1].x * other.y + columns[2].x * other.z + columns[3].x * other.w, 
				columns[0].y * other.x + columns[1].y * other.y + columns[2].y * other.z + columns[3].y * other.w,
				columns[0].z * other.x + columns[1].z * other.y + columns[2].z * other.z + columns[3].z * other.w,
				columns[0].w * other.x + columns[1].w * other.y + columns[2].w * other.z + columns[3].w * other.w

				);
		}

		mat4 operator*(mat4 left, const mat4& right)
		{
			return left.multiply(right);
		}

		mat4& mat4::operator*=(const mat4& other)
		{
			return multiply(other);
		}

		vec3 operator*(const mat4& left, const vec3& right)
		{
			return left.multiply(right);
		}

		vec4 operator*(const mat4& left, const vec4& right)
		{
			return left.multiply(right);
		}


		mat4& mat4::invert()
		{

			float temp[16];

			temp[0] = elements[5] * elements[10] * elements[15] -
				elements[5] * elements[11] * elements[14] -
				elements[9] * elements[6] * elements[15] +
				elements[9] * elements[7] * elements[14] +
				elements[13] * elements[6] * elements[11] -
				elements[13] * elements[7] * elements[10];

			temp[4] = -elements[4] * elements[10] * elements[15] +
				elements[4] * elements[11] * elements[14] +
				elements[8] * elements[6] * elements[15] -
				elements[8] * elements[7] * elements[14] -
				elements[12] * elements[6] * elements[11] +
				elements[12] * elements[7] * elements[10];

			temp[8] = elements[4] * elements[9] * elements[15] -
				elements[4] * elements[11] * elements[13] -
				elements[8] * elements[5] * elements[15] +
				elements[8] * elements[7] * elements[13] +
				elements[12] * elements[5] * elements[11] -
				elements[12] * elements[7] * elements[9];

			temp[12] = -elements[4] * elements[9] * elements[14] +
				elements[4] * elements[10] * elements[13] +
				elements[8] * elements[5] * elements[14] -
				elements[8] * elements[6] * elements[13] -
				elements[12] * elements[5] * elements[10] +
				elements[12] * elements[6] * elements[9];

			temp[1] = -elements[1] * elements[10] * elements[15] +
				elements[1] * elements[11] * elements[14] +
				elements[9] * elements[2] * elements[15] -
				elements[9] * elements[3] * elements[14] -
				elements[13] * elements[2] * elements[11] +
				elements[13] * elements[3] * elements[10];

			temp[5] = elements[0] * elements[10] * elements[15] -
				elements[0] * elements[11] * elements[14] -
				elements[8] * elements[2] * elements[15] +
				elements[8] * elements[3] * elements[14] +
				elements[12] * elements[2] * elements[11] -
				elements[12] * elements[3] * elements[10];

			temp[9] = -elements[0] * elements[9] * elements[15] +
				elements[0] * elements[11] * elements[13] +
				elements[8] * elements[1] * elements[15] -
				elements[8] * elements[3] * elements[13] -
				elements[12] * elements[1] * elements[11] +
				elements[12] * elements[3] * elements[9];

			temp[13] = elements[0] * elements[9] * elements[14] -
				elements[0] * elements[10] * elements[13] -
				elements[8] * elements[1] * elements[14] +
				elements[8] * elements[2] * elements[13] +
				elements[12] * elements[1] * elements[10] -
				elements[12] * elements[2] * elements[9];

			temp[2] = elements[1] * elements[6] * elements[15] -
				elements[1] * elements[7] * elements[14] -
				elements[5] * elements[2] * elements[15] +
				elements[5] * elements[3] * elements[14] +
				elements[13] * elements[2] * elements[7] -
				elements[13] * elements[3] * elements[6];

			temp[6] = -elements[0] * elements[6] * elements[15] +
				elements[0] * elements[7] * elements[14] +
				elements[4] * elements[2] * elements[15] -
				elements[4] * elements[3] * elements[14] -
				elements[12] * elements[2] * elements[7] +
				elements[12] * elements[3] * elements[6];

			temp[10] = elements[0] * elements[5] * elements[15] -
				elements[0] * elements[7] * elements[13] -
				elements[4] * elements[1] * elements[15] +
				elements[4] * elements[3] * elements[13] +
				elements[12] * elements[1] * elements[7] -
				elements[12] * elements[3] * elements[5];

			temp[14] = -elements[0] * elements[5] * elements[14] +
				elements[0] * elements[6] * elements[13] +
				elements[4] * elements[1] * elements[14] -
				elements[4] * elements[2] * elements[13] -
				elements[12] * elements[1] * elements[6] +
				elements[12] * elements[2] * elements[5];

			temp[3] = -elements[1] * elements[6] * elements[11] +
				elements[1] * elements[7] * elements[10] +
				elements[5] * elements[2] * elements[11] -
				elements[5] * elements[3] * elements[10] -
				elements[9] * elements[2] * elements[7] +
				elements[9] * elements[3] * elements[6];

			temp[7] = elements[0] * elements[6] * elements[11] -
				elements[0] * elements[7] * elements[10] -
				elements[4] * elements[2] * elements[11] +
				elements[4] * elements[3] * elements[10] +
				elements[8] * elements[2] * elements[7] -
				elements[8] * elements[3] * elements[6];

			temp[11] = -elements[0] * elements[5] * elements[11] +
				elements[0] * elements[7] * elements[9] +
				elements[4] * elements[1] * elements[11] -
				elements[4] * elements[3] * elements[9] -
				elements[8] * elements[1] * elements[7] +
				elements[8] * elements[3] * elements[5];

			temp[15] = elements[0] * elements[5] * elements[10] -
				elements[0] * elements[6] * elements[9] -
				elements[4] * elements[1] * elements[10] +
				elements[4] * elements[2] * elements[9] +
				elements[8] * elements[1] * elements[6] -
				elements[8] * elements[2] * elements[5];

			float determinant = elements[0] * temp[0] + elements[1] * temp[4] + elements[2] * temp[8] + elements[3] * temp[12];
			determinant = 1.0f / determinant;

			for (int i = 0; i < 4 * 4; i++)
				elements[i] = temp[i] * determinant;

			return *this;

		}


		mat4 mat4::othographic(float left, float right, float bottom, float top, float near, float far)
		{
			mat4 result(1.0f);

			//result.elements[0] = 2.0f / (right - left); //0
			//result.elements[3] = -(right + left) / (right - left); // 3
			//result.elements[5] = 2.0f / (top - bottom); //5
			//result.elements[7] = -(top + bottom) / (top - bottom); //7
			//result.elements[10] = -2.0f / (far - near); //10
			//result.elements[11] = -(far + near) / (far - near); //11

			result.elements[0] = 2 / (right - left);
			result.elements[1] = 0;
			result.elements[2] = 0;
			result.elements[3] = 0;

			result.elements[4] = 0;
			result.elements[5] = 2 / (top - bottom);
			result.elements[6] = 0;
			result.elements[7] = 0;

			result.elements[8] = 0;
			result.elements[9] = 0;
			result.elements[10] = -2 / (far - near);
			result.elements[11] = 0;

			result.elements[12] = -(right + left) / (right - left);
			result.elements[13] = -(top + bottom) / (top - bottom);
			result.elements[14] = -(far + near) / (far - near);
			result.elements[15] = 1;

			return result;

		}

		mat4 mat4::perspective(float fov, float aspectratio, float near, float far)
		{
			mat4 result(1.0f);
			float q = 1.0f / tan(toRadians(0.5f * fov));
			float a = q / aspectratio;

			float b = (near + far) / (near - far);
			float c = (2.0f * near * far) / (near - far);

			result.elements[0 + 0 * 4] = a;
			result.elements[1 + 1 * 4] = q;
			result.elements[2 + 2 * 4] = b;
			result.elements[2 + 3 * 4] = -1.0f;
			result.elements[3 + 2 * 4] = c;

			return result;
		}

		mat4 mat4::lookat(const vec3& eye, const vec3& center,const vec3& up)
		{
			mat4 result = identity();
			vec3 f = (center - eye).Normalize();
			vec3 s = f.Cross(up.Normalize());
			vec3 u = s.Cross(f);
			result.elements[0 + 0 * 4] = s.x;
			result.elements[0 + 1 * 4] = s.y;
			result.elements[0 + 2 * 4] = s.z;

			result.elements[1 + 0 * 4] = u.x;
			result.elements[1 + 1 * 4] = u.y;
			result.elements[1 + 2 * 4] = u.z;

			result.elements[2 + 0 * 4] = -f.x;
			result.elements[2 + 1 * 4] = -f.y;
			result.elements[2 + 2 * 4] = -f.z;

			return result * translation(vec3(-eye.x, -eye.y, -eye.z));
		}
		mat4 mat4::translation(const vec3& translation)
		{
			mat4 result(1.0f);
			result.elements[0 + 3 * 4] = translation.x;
			result.elements[1 + 3 * 4] = translation.y;
			result.elements[2 + 3 * 4] = translation.z;

			//result.elements[3 + 0 * 4] = translation.x;
			//result.elements[3 + 1 * 4] = translation.y;
			//result.elements[3 + 2 * 4] = translation.z;


			return result;
		}

		mat4 mat4::translation(const mat4 result, const vec3& translation)
		{
			mat4 result1 = result;
			//result.elements[0 + 3 * 4] = translation.x;
			//result.elements[1 + 3 * 4] = translation.y;
			//result.elements[2 + 3 * 4] = translation.z;

			result1.elements[3 + 0 * 4] = translation.x;
			result1.elements[3 + 1 * 4] = translation.y;
			result1.elements[3 + 2 * 4] = translation.z;

			return result1;
		}

		mat4 mat4::rotate(float angle, const vec3& axis)
		{
			mat4 result(1.0f);

			float r = toRadians(angle);
			float c = cos(r);
			float s = sin(r);
			float omc = 1.0f - c;

			float x = axis.x;
			float y = axis.y;
			float z = axis.z;

			//result.elements[0 + 0 * 4] = x * omc + c;
			//result.elements[1 + 0 * 4] = y * x * omc + z * s;
			//result.elements[2 + 0 * 4] = x * z * omc - y * s;
			//
			//result.elements[0 + 1 * 4] = x * y * omc -z * s;
			//result.elements[1 + 1 * 4] = y * omc + c;
			//result.elements[2 + 1 * 4] = y * z * omc + x * s;
			//
			//result.elements[0 + 2 * 4] = x * z * omc + y * s;
			//result.elements[1 + 2 * 4] = y * z * omc - x * s;
			//result.elements[2 + 2 * 4] = z * omc + c;

			result.elements[0 + 0 * 4] = x * omc + c;
			result.elements[0 + 1 * 4] = y * x * omc + z * s;
			result.elements[0 + 2 * 4] = x * z * omc - y * s;

			result.elements[1 + 0 * 4] = x * y * omc - z * s;
			result.elements[1 + 1 * 4] = y * omc + c;
			result.elements[1 + 2 * 4] = y * z * omc + x * s;

			result.elements[2 + 0 * 4] = x * z * omc + y * s;
			result.elements[2 + 1 * 4] = y * z * omc - x * s;
			result.elements[2 + 2 * 4] = z * omc + c;

			return result;
		}


		mat4 mat4::scale(const vec3& scale)
		{
			mat4 result(1.0f);
			result.elements[0 + 0 * 4] = scale.x;
			result.elements[1 + 1 * 4] = scale.y;
			result.elements[2 + 2 * 4] = scale.z;

			return result;

		}

		std::ostream& operator << (std::ostream& stream, const mat4& matrix)
		{
			for (int i = 0; i < sizeof(matrix.elements); i++) {
				stream << "mat4: (" << ", " << matrix.elements[i] << ")";
			}
				return stream;
			
		}


	}
}