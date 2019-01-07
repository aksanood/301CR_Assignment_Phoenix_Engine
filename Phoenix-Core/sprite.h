#pragma once

#include "renderable2d.h"

namespace Phoenix
{
	namespace Graphics
	{
		class Sprite : public Renderable2D
		{
		private:
			

		public:
			Maths::vec3& position;
			Sprite(float x, float y, float z, float width, float height, unsigned int color);
			Sprite(float x, float y, float z, float width, float height, Maths::vec4& color);
			Sprite(float x, float y, float z, float width, float height, Texture* texture);
			Sprite();
			virtual ~Sprite(){}


			
		};
	}
}
