#include "sprite.h"

namespace Phoenix
{
	namespace Graphics
	{
		Sprite::Sprite(float x, float y, float z, float width, float height, unsigned int color)
			:Renderable2D(Maths::vec3(x, y, z), Maths::vec2(width, height), color), position(m_Position)
		{
			
		}

		Sprite::Sprite(float x, float y, float z, float width, float height, Maths::vec4& color)
			: Renderable2D(Maths::vec3(x, y, z), Maths::vec2(width, height), 0xffffffff), position(m_Position)
		{
			setColor(color);
		}

		Sprite::Sprite(float x, float y, float z, float width, float height, Texture* texture)
			: Renderable2D(Maths::vec3(x, y, z), Maths::vec2(width, height), 0xffffffff), position(m_Position)
		{
			m_Texture = texture;
		}
	}
}