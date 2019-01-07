#pragma once
#include "renderable2d.h"

namespace Phoenix 
{
	namespace Graphics
	{
		class Lable : public Renderable2D
		{
		private:
			char * m_Text;
			
		public:
			Lable(char * text, float x, float y, unsigned int color);

			void submit(Renderer2D* renderer) const override;
			


		};

	}
}