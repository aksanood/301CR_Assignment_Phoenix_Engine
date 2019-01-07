#include "mesh.h"

namespace Phoenix
{
	namespace Graphics
	{
		class Triangle {

		private:
			Vertex verticies[] = { Vertex(vec3(-0.5f, -0.5f, 0)),
				Vertex(vec3(0, 0.5f, 0)),
				Vertex(vec3(0.5f, -0.5f, 0)) };
			//Mesh *triangle = new Mesh(verticies, sizeof(verticies) / sizeof(verticies[0]));
		public:

		};
	}
}
