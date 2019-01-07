#include "tilelayer.h"
namespace Phoenix
{
	namespace Graphics
	{
		TileLayer::TileLayer(Shader* shader)
			: Layer(new BatchRenderer2D(), shader, Maths::mat4::othographic(-16,16,-9,9,-1,1))
		{


		}

		TileLayer::~TileLayer()
		{
			
		}

		
	}
}