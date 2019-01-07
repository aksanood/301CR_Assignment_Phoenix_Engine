#pragma once
#include <string>
#include <vector>
#include "includes.h"

using namespace Phoenix;
using namespace Graphics;

const int TILEWIDTH = 100;
class Level {
private:

	std::vector<std::string> m_leveldata;
	int m_numberOfHumans;
	Maths::vec2 m_playerStartPosition;
	std::vector<Maths::vec2> m_EnemyStartPositions;
	Sprite* m_sprite;
	Layer* m_layer;

public:

	Level(const std::string& filename);
	~Level();

	void draw();
};