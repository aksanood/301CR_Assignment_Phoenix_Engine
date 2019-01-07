#include "layer.h"
#include "sprite.h"
#include "lua\lua.hpp"

using namespace Phoenix;
using namespace Graphics;
using namespace Maths;

class Block{
	
private:
public:
	Layer* m_layer;
	Sprite* m_block;
	vec3 m_position;
	vec2 m_size;
	vec4 m_color;
	float tilesize = 1.0f;
	
	Block(){}
	Block(vec3 position, vec2 size, vec4 color) {
		m_position = position;
		m_size = size;
		m_color = color;
		m_layer = new Layer(new BatchRenderer2D(), new Shader("basic.vs", "basic.fs"), Maths::mat4::othographic(-16.0f, 16.0f, -9.0f, 9.0f, -1.0f, 1.0f));
	}
	~Block() { delete m_layer; delete m_block; }

	void init() {
		m_block = new Sprite(m_position.x, m_position.y, m_position.z, m_size.x, m_size.y, m_color);
		m_layer->add(m_block);
	}
	void draw() { m_layer->render();}

	void update(vec3 translate)
	{
		const std::vector<Renderable2D*>& rs = m_layer->getRenderables();
		for (int i = 0; i < rs.size(); i++)
		{
			rs[i]->setVelocity(translate);
		}

	}
	void addblock(vec3 position, vec2 size, vec4 color)
	{
		m_layer->add(new Sprite(position.x, position.y, position.z, size.x, size.y, color));
	}
	bool checkCollision(vec3 playerpos)
	{
		
		const std::vector<Renderable2D*>& rs = m_layer->getRenderables();
		for (int i = 0; i < rs.size(); i++)
		{
			if (playerpos.x + 0.5 >= rs[i]->getPosition().x && playerpos.x + 0.5 <= rs[i]->getPosition().x + rs[i]->getSize().x)
			{
				if (playerpos.y + 0.5 >= rs[i]->getPosition().y && playerpos.y + 0.5 <= rs[i]->getPosition().y + 0.5+ rs[i]->getSize().y)
				{
					rs[i]->setSize(m_size.x / 2, m_size.y / 2);
					rs[i]->setColor(vec4(1, 0, 0, 0.5));
					return true;
				}
			}
			rs[i]->setSize(m_size.x, m_size.y);
			rs[i]->setColor(vec4(0, 1, 0, 0.5));
			return false;
		}
	}

	void die()
	{
		
	}
};



	


