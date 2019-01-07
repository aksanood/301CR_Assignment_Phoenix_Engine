#include "layer.h"

namespace Phoenix
{
	namespace Graphics
	{
		Layer::Layer(Renderer2D* renderer, Shader* shader, Maths::mat4 projectionMatrix)
			:m_Renderer(renderer),m_Shader(shader), m_ProjectionMatrix(projectionMatrix)
		{

			m_Shader->enable();
			m_Shader->setUniformMat4("pr_matrix", m_ProjectionMatrix);
			

			GLint texIds[] = 
			{
				0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 
				10,11,12,13,14,15,16,17,18,19,
				20,21,22,23,24,25,26,27,28,29,
				30,31
			
			};


			m_Shader->setUniform1iv("textures", texIds, 10);
			m_Shader->disable();
		}

		Layer::~Layer()
		{
//			delete m_Shader;
			delete m_Renderer;
			for (unsigned int i = 0; i < m_Renderables.size(); ++i)
			{
				m_Renderables.erase(m_Renderables.begin() + i);
			}
		}

		void Layer::add(Renderable2D* renderable)
		{
			m_Renderables.push_back(renderable);
		}

		void Layer::render()
		{
			
			m_Shader->enable();
			m_Renderer->begin();
			int i = 0;
			for (const Renderable2D* renderable : m_Renderables)
				renderable->submit(m_Renderer);

			m_Renderer->drawString("", Maths::vec3(0, 0, 0), 0xffffffff);
			m_Renderer->pop();
			m_Renderer->end();
			m_Renderer->flush();
			

		}
	}
}