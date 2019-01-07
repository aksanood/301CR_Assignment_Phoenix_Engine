#pragma once
#include "mat4.h"


namespace Phoenix
{
	namespace Maths
	{
		class Transform
		{
		private:
			vec3 m_Position;
			vec3 m_Rotation;
			vec3 m_Scale;

		public:
			
			Transform(const vec3& position = vec3(), const vec3& rotation = vec3(), const vec3& scale = vec3(1.0f, 1.0f, 1.0f))
				: m_Position(position), m_Rotation(rotation), m_Scale(scale)
			{}

			
			//inline mat4 getTransform() const
			//{
			//	mat4 positionMatrix = mat4::translation(m_Position);
			//	mat4 rotationMatrixX = mat4::rotate(m_Rotation.x, vec3(1, 0, 0));
			//	mat4 rotationMatrixY = mat4::rotate(m_Rotation.y, vec3(0, 1, 0));
			//	mat4 rotationMatrixZ = mat4::rotate(m_Rotation.z, vec3(0, 0, 1));
			//	mat4 scaleMatrix = mat4::scale(m_Scale);
			//
			//	mat4 rotationMatrix = rotationMatrixZ * rotationMatrixY * rotationMatrixX;
			//	return positionMatrix * rotationMatrix * scaleMatrix;
			//}

		    

			inline vec3&  getPosition() { return m_Position;}
			inline vec3&  getRotation() { return m_Rotation; }
			inline vec3&  getScale() { return m_Scale; }

			inline void  setPosition(vec3& pos) { m_Position = pos; }
			inline void  setRotation(vec3& rot) { m_Rotation = rot; }
			inline void  setScale(vec3& scale)  { m_Scale = scale; }



		};
	}
}
