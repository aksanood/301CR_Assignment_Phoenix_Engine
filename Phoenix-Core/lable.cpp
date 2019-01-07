#include "lable.h"

namespace Phoenix
{
	namespace Graphics
	{

		Lable::Lable(char * text, float x, float y, unsigned int color)
			: Renderable2D(),  m_Text(text)
		{
			m_Position = Maths::vec3(x, y, 0.0f);
			m_Color = color;
		}


		void Lable::submit(Renderer2D* renderer) const
		{
			renderer->drawString(m_Text, m_Position, m_Color);

		}
	}
}
