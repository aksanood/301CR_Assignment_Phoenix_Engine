#pragma once
#include "layer.h"
#include "batchrenderer2d.h"
#include "camera3D.h"

namespace Phoenix
{
	namespace Graphics
	{
		class TileLayer : public Layer
		{

		public:
			TileLayer(Shader* shader);
			~TileLayer();
		
		};
	}
}
