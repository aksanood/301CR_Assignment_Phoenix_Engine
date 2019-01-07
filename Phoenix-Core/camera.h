#pragma once
#include "mat4.h"
#include "vec4.h"


namespace Phoenix
{
	namespace Graphics
	{
		class  Camera
		{
		protected:
			Maths::mat4 m_ProjectionMatrix, m_ViewMatrix;
			Maths::vec3 m_Position, m_Rotation, m_FocalPoint;
		public:
			Camera(){}
			Camera(const Maths::mat4& projectionMatrix);
			bool m_needUpdate;
			Maths::mat4 cameraMatrix;
			float m_scale;
			int m_width, m_height;
			Maths::mat4 orthoMatrix;
			void Focus() { }
			void Update();
			void init(int width, int height);

			inline const Maths::vec3& GetPosition() const { return m_Position; }
			inline void SetPosition(const Maths::vec3& position) { m_Position = position; m_needUpdate= true;}

			inline const Maths::vec3& GetRotation() const { return m_Rotation; }
			inline void SetRotation(const Maths::vec3& rotation) { m_Rotation = rotation; }

			inline const Maths::mat4& GetProjectionMatrix() const { return m_ProjectionMatrix; }
			inline void SetProjectionMatrix(const Maths::mat4& projectionMatrix) { m_ProjectionMatrix = projectionMatrix; }

			inline void Translate(const Maths::vec3& translation) { m_Position += translation; }
			inline void Rotate(const Maths::vec3& rotation) { m_Rotation += rotation; }

			inline void Translate(float x, float y, float z) { m_Position += Maths::vec3(x, y, z); }
			inline void Rotate(float x, float y, float z) { m_Rotation += Maths::vec3(x, y, z); }

			inline const Maths::vec3& GetFocalPoint() const { return m_FocalPoint; }

			inline const Maths::mat4& GetViewMatrix() { return m_ViewMatrix; }

		};
	}
}