#include "phoenix.h"
#include "includes.h"
#include "methods.h"

using namespace std;
using namespace Phoenix;
using namespace Graphics;
using namespace Maths;

class GameLevel : public Phoenix
{
private:
	//Fps and Ups count
	unsigned int fps;
	unsigned int ups;

	//creates a pointer to a window
	Window* window;

	//Orthographic matrix
	mat4 ortho = Maths::mat4::othographic(-16.0f, 16.0f, -9.0f, 9.0f, -1.0f, 1.0f);

	//Timer variables
	Timer time;
	float previousetime = 0;
	float currenttime = time.curretTime();

	//Player variables
	Sprite* player;
	Layer* layer;

	//Enemies and Friends variables
	TileLayer* m_groundLayer; 
	Block* m_enemies;
	Block* m_friends;


	//Physics
	Maths::vec3 GRAVITY = Maths::vec3(0, -0.1f, 0);
	Maths::vec3 VELOCITY = Maths::vec3(0.0f, 0.0f, 0);
	float Bounce = 3.0f;
	float speedX = 1.0f;
	float speedY = 0.5f;

public:
	GameLevel(){}
	~GameLevel()
	{
		delete layer;

	}

	void init() override
	{
		window = createWindow("BENCHMARK", 960, 540);			//Initialize Winow
		Shader* s = new Shader("benchmark.vs", "benchmark.fs");	//Initialize Shader
		Shader& shader = *s;									//Initialize Shader

		layer = new Layer(new BatchRenderer2D(), &shader, ortho);	//Initialize player renderer
		m_groundLayer = new TileLayer(&shader);

		Texture* textures[] =				//Load Textures
		{									//Load Textures
			new Texture("test.png"),		//Load Textures
			new Texture("test1.png"),		//Load Textures
			new Texture("test2.png"),		//Load Textures
			new Texture("bunny.png")		//Load Textures
		};

		for (int x = -18; x < 15; x +=2)
		{																												//Initialize the ground
			for (int y = -9; y < -6; y++)																				//Initialize the ground
			{																											//Initialize the ground
				m_groundLayer->add(new Sprite(x, y, 0, 1.9, 0.9f, Maths::vec4(rand() % 100000 / 1000.0f, 0, 0.2, 1)));	//Initialize the ground
			}																											//Initialize the ground
		}																												//Initialize the ground

		player = new Sprite(0, 1, 0, 1, 1, vec4(1,0,0,0.5));						//Initialize the player
		layer->add(player);														

		m_enemies = new Block(vec3(0 , 0, 0), vec2(10, 1), vec4(0, 1, 0, 1.0));		//Initialize enemies
		m_enemies->init();
		m_enemies->addblock(vec3(0, 0, 0), vec2(-10, 1), vec4(1, 1, 0, 1.0));
		m_friends = new Block(vec3(4, 0, 0), vec2(10, 1), vec4(0, 0, 1, 1.0));		//Initialize players
		m_friends->init();		
	}

	void tick() override
	{
		//Prints FPS and UPS count derived from phoenix.h
		fps = getFPS();
		ups == getUPS();
		std::cout << "FPS : " << fps << endl;
		std::cout << "UPS : " << ups << endl;
	}

	void render() override
	{
		layer->render();		//render all renderables
		m_enemies->draw();		//render all renderables
		m_friends->draw();		//render all renderables
		m_groundLayer->render();
		
	}

	void update() override
	{
		previousetime = currenttime;
		currenttime = time.curretTime();
		float dt = currenttime - previousetime;
		if (dt > 0.15f) { dt = 0.15f; }
		double x, y;
		window->getMousePosition(x, y);

		vec3 playerOrigin = vec3(player->position.x + player->getSize().x / 2,
							player->position.y + player->getSize().y / 2, 0);
		bool collision = m_enemies->checkCollision(playerOrigin);
		bool collision2 = m_friends->checkCollision(playerOrigin);

		//Limits
		if (player->position.x > 16) { player->position.x = 14.0f; }
		if (player->position.x < -16) { player->position.x = -16.0f; }
		if (player->position.y < -5.9f) { player->position.y = -6.1f; GRAVITY = vec3();}

		if (window->isKeyPressed(GLFW_KEY_D))
		{
			player->position.x = player->position.x + dt * speedX;
			//m_enemies->update(vec3(1,0,0));
		}
		if (window->isKeyPressed(GLFW_KEY_A))
		{
			player->position.x = player->position.x - dt * speedX;
			//m_enemies->update(vec3(-1, 0, 0));
			
		}
		if (window->isKeyPressed(GLFW_KEY_R))
		{
			player->position = Maths::vec3(0, 0, 0);
		}
		if (window->isKeyPressed(GLFW_KEY_SPACE)) 
		{
			
		}
		if (window->isKeyPressed(GLFW_KEY_W))
		{
			player->position = player->position + Maths::vec3(0, dt * Bounce, 0);

		}
		if (window->isKeyPressed(GLFW_KEY_Q))
		{
			m_enemies->die();
		}
		
		if (collision || collision2)
		{
			cout << "weeeeeeeeeeeeeee";
			//GRAVITY = vec3();
			//player->position = player->position - (dt * VELOCITY);
			collision = collision2 = false;
		}

	
		player->position = player->position + (dt * VELOCITY);
		VELOCITY = VELOCITY + dt * GRAVITY;
		


	}
	void keyRelease()
	{
		if (window->getAction() == 0)
		{
			
		}
	}

	void keyPress() {
		
	}
};


