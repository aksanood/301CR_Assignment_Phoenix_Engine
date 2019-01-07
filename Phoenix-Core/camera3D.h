#pragma once
#include "camera.h"

namespace Phoenix
{
	namespace Graphics
	{
	
		class Camera2D
		{
			private:
				Maths::vec2 m_position;
				Maths::mat4 cameraMatrix;
				float m_scale;
				bool m_needUpdate;
				int m_width, m_height;
				Maths::mat4 orthoMatrix;
			public:
				Camera2D();
				~Camera2D();
				void init(int width, int height);
				Maths::vec2 getPosition(){return m_position;}
				float getScale() { return m_scale; }
				inline void setMatrix(Maths::mat4 matrix)
				{
					cameraMatrix = matrix;
				}
				inline void setPosition(Maths::vec2& newPosition) 
				{
					m_position = newPosition; 
					m_needUpdate= true;
				}
				inline void setScale(float newScale)
				{
					m_scale = newScale; 
					m_needUpdate = true;
				}

				void update();
				Maths::mat4 getCameraMatrix() { return cameraMatrix; }

		};
	
	
		
	}
}