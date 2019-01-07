#include "camera3D.h"

namespace Phoenix
{
	namespace Graphics
	{

		Camera2D::Camera2D(): m_position(0.0f,0.0f),
			cameraMatrix(1.0f),
			orthoMatrix(1.0f),
			m_scale(1.0f),
			m_needUpdate(true),
			m_width(500),
			m_height(500)
		{

		}

		Camera2D::~Camera2D()
		{

		}
		void Camera2D::init(int width, int height)
		{
			m_width = width;
			m_height = height;
			orthoMatrix = Maths::mat4::othographic(0.0f, (float)m_width, 0.0f, (float)m_height, -1.0f, 1.0f);
		}

		void Camera2D::update()
		{
			if (m_needUpdate)
			{
				Maths::vec3 translate(-m_position.x + (float)(m_width/2), -m_position.y + (float)(m_height/2), 0.0f);
				cameraMatrix = orthoMatrix.translation(translate);
				Maths::vec3 scalevector(m_scale, m_scale, 0.0f);
				cameraMatrix = cameraMatrix.scale(scalevector);
				m_needUpdate = false;
			}
		}
	}
}
