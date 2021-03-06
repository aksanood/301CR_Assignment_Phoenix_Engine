#pragma once
#include "renderer2d.h"
#include "renderable2d.h"
#include "camera3D.h"

namespace Phoenix
{
	namespace Graphics
	{
		class Layer
		{
		protected:
			Renderer2D* m_Renderer;
			std::vector<Renderable2D*> m_Renderables;
			Shader* m_Shader;
			Maths::mat4 m_ProjectionMatrix;
			Camera2D* m_Camera;


		public:
			Layer(Renderer2D* renderer, Shader* shader, Maths::mat4 projectionMatrix);

			virtual ~Layer();
			virtual void add(Renderable2D* renderable);
			virtual void render();

			inline const std::vector<Renderable2D*>& getRenderables() const { return m_Renderables; }


		};
	}
}
