#include "Level.h"
#include <fstream>
#include <iostream>

Level::Level(const std::string& filename)
{
	std::fstream file;
	file.open(filename);

	if (file.fail())
	{
		std::cout << "faild to load the level text file" << std::endl;
	}

	std::string temp;
	file >> temp >> m_numberOfHumans;
	while (std::getline(file, temp))
	{
		m_leveldata.push_back(temp);
	}

	for (int y = 0; y < m_leveldata.size(); y++)
	{
		for (int x = 0; x < m_leveldata[y].size(); x++)
		{
			char tile = m_leveldata[x][y];
			Maths::vec3 position(x * TILEWIDTH, y * TILEWIDTH, 0);
			Maths::vec2 size(TILEWIDTH, TILEWIDTH);
			int color1 = 100;
			int color2 = 100;


			//process tiles
			switch (tile) 
			{
			case 'R' :
				//m_sprite = new Sprite(position.x, position.y, position.z,size.x, size.y,color1);
				m_layer->add(new Sprite(position.x, position.y, position.z, size.x, size.y, color1));
				break;
			case 'S':
				//m_sprite = new Sprite(position.x, position.y, position.z, size.x, size.y, color2);
				m_layer->add(new Sprite(position.x, position.y, position.z, size.x, size.y, color1));
				break;
			case '@' : 
				m_playerStartPosition.x = x * TILEWIDTH;
				m_playerStartPosition.y = y * TILEWIDTH;
				break;
			case 'Z':
				m_EnemyStartPositions.emplace_back(x * TILEWIDTH, y * TILEWIDTH);
				break;
			default :
				std::cout << "unexpected symbol found"<< tile <<std::endl;
				break;

			}
		}
	}
}

Level::~Level()
{
	delete m_sprite;
}

void Level::draw()
{
	m_layer->render();
}