
#include <SDL.h>
#include <SDL_ttf.h>
#include "phoenix.h"
#include "includes.h"
#include "methods.h"


using namespace std;
using namespace Phoenix;
using namespace Graphics;
using namespace Maths;

#define SCREEN_WIDTH 960
#define SCREEN_HEIGHT 540

class SSGame : public Phoenix
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
	//Game objects
	Sprite* player;
	Sprite* bullet;
	Sprite* enemy;
	vector<Sprite*> enemies;
	vector<Sprite*> bullets;
	Layer* layer;
	Layer* m_groundLayer;
	Layer* enemy_layer;
	Layer* bullet_layer;
	vec3 playercenter;
	int shootTimer = 0;
	int enemySpwanTimer = 0;
	//Physics
	Maths::vec3 GRAVITY = Maths::vec3(0, -0.1f, 0);
	Maths::vec3 VELOCITY = Maths::vec3(0.0f, 0.0f, 0);
	float Bounce = 3.0f;
	float speedX = 1.0f;
	float speedY = 0.5f;
	float counter = 0.0f;
	//Random Numbers
	

public:
	SSGame() {}
	~SSGame()
	{
		delete layer;
		delete m_groundLayer;
		delete enemy_layer;
		delete bullet_layer;
		delete player;
		delete bullet;
		delete enemy;
		

		for (size_t i = 0; i < enemies.size(); ++i)
		{
			enemies.erase(enemies.begin() + i);
		}
		for (size_t i = 0; i < bullets.size(); ++i)
		{
			bullets.erase(bullets.begin() + i);
		}
	
	}

	void init() override
	{
		window = createWindow("BENCHMARK", SCREEN_WIDTH, SCREEN_HEIGHT);			// Initialize Winow
		Shader* s = new Shader("benchmark.vs", "benchmark.fs");						// Initialize Shader
		Shader& shader = *s;														// Initialize Shader
		Texture* textures[] =				//Load Textures
		{									//Load Textures
			new Texture("test.png"),		//Load Textures
			new Texture("test1.png"),		//Load Textures
			new Texture("test2.png"),		//Load Textures
			new Texture("bunny.png")		//Load Textures
		};
		Texture* playerTexture = new Texture("test1.png");

		layer = new Layer(new BatchRenderer2D(), &shader, ortho);	//Initialize player renderer
		m_groundLayer = new TileLayer(&shader);
		enemy_layer = new TileLayer(&shader);
		bullet_layer = new TileLayer(&shader);
		

		player = new Sprite(0, 0, 0, 1, 1, playerTexture);	//Initialize the player
		layer->add(player);
	
		enemy = new Sprite(0, 0, 0, 1, 1, vec4(1, 0, 0, 1));
		
		playercenter = player->position;
		bullet = new Sprite(playercenter.x, playercenter.y, 0, 0.3, 0.3, vec4(0, 0, 1, 1));
		

		

		for (int x = -18; x < 15; x += 2)
		{																												//Initialize the ground
			for (int y = -9; y < -6; y++)																				//Initialize the ground
			{																											//Initialize the ground
				m_groundLayer->add(new Sprite(x, y, 0, 1.9, 0.9f, Maths::vec4(rand() % 100000 / 1000.0f, 0, 0.2, 1)));	//Initialize the ground
			}																											//Initialize the ground
		}
		

		

	}

	void tick() override
	{
		//Prints FPS and UPS count derived from phoenix.h
		fps = getFPS();
		ups == getUPS();
		std::cout << "FPS : " << fps << endl;
		//std::cout << "UPS : " << ups << endl;
	}

	void render() override
	{
		layer->render();		//render all renderables
		m_groundLayer->render();
		enemy_layer->render();
		bullet_layer->render();

	}

	void update() override
	{

		window->isFocused();
		previousetime = currenttime;
		currenttime = time.curretTime();
		float dt = currenttime - previousetime;
		if (dt > 0.15f) { dt = 0.15f; }
		

		//Limits
		if (player->position.x > 16) { player->position.x = 14.0f; }
		if (player->position.x < -16) { player->position.x = -16.0f; }
		if (player->position.y < -5.4f) { player->position.y = -6.1f; GRAVITY = vec3(0,0,0);}
		
		playercenter = vec3(player->getPosition());

		//Bullets update
		if (shootTimer < 5){shootTimer++;}
		if (window->isMouseButtonPressed(GLFW_MOUSE_BUTTON_LEFT) && shootTimer >= 5) 
		{
			bullet->position.x = playercenter.x + 0.5f;
			bullet->position.y = playercenter.y + 0.5f;
			bullets.push_back(bullet);
			shootTimer = 0;
		}

		for (size_t i = 0; i < bullets.size(); ++i)
		{
			bullets[i]->setVelocity(vec3(0.0f, 5.0f * dt, 0.0f));
			if (bullets[i]->getPosition().y > 10)
			{
				bullets.erase(bullets.begin() + i);
				//bullets[i]->
			}
		}

		

		//Enemies update

		for (size_t i = 0; i < enemies.size(); i++)
		{
			if (enemies[i]->isColliding(player->getPosition(), player->getSize())) {
				player->setSize(2,2);
			}
		}

		if(enemySpwanTimer < 30){enemySpwanTimer++;}
		if (enemySpwanTimer >= 30) {

			enemy->setPosititon(vec3(randomint(-16, 15), 9, 0));
			enemies.push_back(enemy);
			enemySpwanTimer = 0;
		}

		for (size_t i = 0; i < enemies.size(); i++)
		{
			//enemies[i]->setVelocity(vec3(0.0, -1.0f * dt, 0.0f));
			enemies[i]->setGravity(0.5f * dt);
			if (enemies[i]->position.y < -6)
			{
				enemies.erase(enemies.begin() + i);

			}
			
		}
		

		//Colision with enemies
		for (size_t i = 0; i < bullets.size(); ++i)
		{
			for (size_t j = 0; j < enemies.size(); ++j)
			{
				if (bullets[i]->isColliding(enemies[j]->getPosition(), enemies[j]->getSize()))
				{
					cout << "collision with " << enemies[i] << " TRUE" << endl;
					bullets.erase(bullets.begin() + i);
					enemies.erase(enemies.begin() + j);
					break;
					
				}
			}
		}

		

		for (size_t i = 0; i < bullets.size(); i++)
		{
			bullet_layer->add(bullets[i]);
		}
		for (size_t i = 0; i < enemies.size(); i++)
		{
			enemy_layer->add(enemies[i]);
		}


		// Input Handle
		if (window->isFocused())
		{
			if (window->isKeyPressed(GLFW_KEY_W))
			{
				//player->setVelocity(vec3(0.0f, 1.0f, 0.0f));
			}
			if (window->isKeyPressed(GLFW_KEY_S))
			{
				player->setVelocity(vec3(0.0f, -1.0f, 0.0f));
			}
			if (window->isKeyPressed(GLFW_KEY_A))
			{
				player->position.x = player->position.x - dt * speedX;
			}
			if (window->isKeyPressed(GLFW_KEY_D))
			{
				player->position.x = player->position.x + dt * speedX;
				//player->setVelocity(vec3(speedX * dt, 0.0f, 0.0f));
			}
			if (window->isKeyPressed(GLFW_KEY_R))
			{
				player->position = Maths::vec3(0, 0, 0);
			}
			if (window->isKeyPressed(GLFW_KEY_SPACE))

			{
				cout << VELOCITY.y << endl;
				if (player->position.y < -6.0)
				{
					player->position = player->position + Maths::vec3(0, dt * Bounce, 0);
				}
			}
			
			player->position = player->position + (dt * VELOCITY);
			VELOCITY = VELOCITY + dt * GRAVITY;
			
		}


	}

};