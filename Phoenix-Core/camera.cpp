#include "camera.h"

namespace Phoenix
{
	namespace Graphics
	{
		Camera::Camera(const Maths::mat4& projectionMatrix)
			: m_ProjectionMatrix(projectionMatrix)
		{
			m_ViewMatrix = Maths::mat4::identity();
			m_Position = Maths::vec3();
			m_Rotation = Maths::vec3();
			m_needUpdate = true;
			cameraMatrix = Maths::mat4::identity();
			m_scale = 5;
			m_width = 500;
			m_height = 500;
			orthoMatrix = Maths::mat4::identity();

		}
		void Camera::init(int width, int height)
		{
			m_width = width;
			m_height = height;
			orthoMatrix = Maths::mat4::othographic(0.0f, (float)m_width, 0.0f, (float)m_height, -1.0f, 1.0f);
		}
		void Camera::Update()
		{
			if (m_needUpdate)
			{
				Maths::vec3 translate(-m_Position.x + (float)(m_width / 2), -m_Position.y + (float)(m_height / 2), 0.0f);
				cameraMatrix = orthoMatrix.translation(translate);
				Maths::vec3 scalevector(m_scale, m_scale, 0.0f);
				cameraMatrix = cameraMatrix.scale(scalevector);
				m_needUpdate = false;
				std::cout << "Update Cam" << std::endl;
			}
		}
	}
}