#include "phoenix.h"
#include "includes.h"
#include <string>

using namespace std;
using namespace Phoenix;
using namespace Graphics;


class Benchmark : public Phoenix
{
private:

	Window* window;
	Layer* layer;
	Sprite* sprite;
	bool add = false;
	int startcount = 0;
	

public :

	unsigned int fps;
	unsigned int ups;

	Benchmark()
	{
		
	}

	~Benchmark()
	{
		delete layer;
	}

	void init() override
	{
		window = createWindow("BENCHMARK", 960, 540);
		layer = new Layer(new BatchRenderer2D(), new Shader("basic.vs", "basic.fs"), Maths::mat4::othographic(-16.0f, 16.0f, -9.0f, 9.0f, -1.0f, 1.0f));
		Texture* textures[] =
		{
			new Texture("test.png"),
			new Texture("test1.png"),
			new Texture("test2.png"),
			new Texture("bunny.png")

		};

		//sprite = new Sprite(0, 0, 0, 0.9f, 0.9f, textures[3]);
		//layer->add(sprite);

		for (float y = -9.0f; y < 9.0f; y++)	//60K Sprites +=0.1f
		{
			for (float x = -16.0f; x < 16.0f; x++)	//60K Sprites +=0.1f
			{
				
				
					//sprite = new Sprite(x, y, 0.9f, 0.9f, textures[1]);
					sprite = new Sprite(x, y,0.0f, 0.9f, 0.9f, Maths::vec4(rand() % 1000 / 1000.0f, 0, 0, rand() % 1000 / 1000.0f));
					layer->add(sprite); //60K Sprites 0.09f
					//layer.add(new Sprite(x, y, 0.09f, 0.09f, textures[1])); //60K Sprites 0.09f
					//layer.add(new Sprite(-16, -9, 0.9f, 0.9f, textures[1])); //Bottem left -16, -9
			}
		}
		
		
		
		
	}

	void tick() override
	{
		fps = getFPS();
		ups == getUPS();
		std::cout << "FPS : " << fps << endl;
		std::cout << "UPS : " << ups << endl;
		cout << startcount << endl;

	}

	void render() override
	{
		addSprites();
		layer->render();
		
	}

	void update() override
	{
			//float speed = 0.5f;
			Maths::vec3 speedX(0.5f, 0, 0);
			Maths::vec3 speedY(0, 0.5f, 0);
			Maths::vec3 GRAVITY(0, -0.1f, 0);
			//sprite->position += GRAVITY;

				if (window->isKeyPressed(GLFW_KEY_W))
					sprite->position += speedY;
				if (window->isKeyPressed(GLFW_KEY_S))
					sprite->position -= speedY;
				if (window->isKeyPressed(GLFW_KEY_D))
					sprite->position += speedX;
				if (window->isKeyPressed(GLFW_KEY_A))
					sprite->position -= speedX;
				if (window->isKeyPressed(GLFW_KEY_R))
					sprite->position = Maths::vec3(0, 0, 0);
				if (window->isKeyPressed(GLFW_KEY_Z))
				{
					add = true;
				}

				std::cout<<sprite->position << endl;
	}

	void addSprites()
	{
		if (add)
		{
		for (int i = 0; i < 1000; i++)
		{
			sprite = new Sprite(Maths::randomint(-10, 10), Maths::randomint(-10, 10), 0, 0.9f, 0.9f, Maths::vec4(Maths::randomfloat(0.0f, 1.0f), Maths::randomfloat(0.0f, 1.0f), Maths::randomfloat(0, 1), 1));
			layer->add(sprite);
			startcount++;

		}
			//cout << startcount << endl;
			add = false;
		}
	}


	
};

//int main()
//{
//
//	Benchmark quality_Test;
//	quality_Test.start();
//	return 0;
//}
