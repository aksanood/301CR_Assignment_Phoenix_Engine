#include "includes.h"
using namespace Phoenix;
using namespace Graphics;
using namespace Maths;

//int main()
//{
//	
//	Window window("Phoenix-Engine", 960, 540);
//	Shader* s = new Shader("basic.vs", "basic.fs");
//	Shader& shader = *s;
//	int spritecount = 0;
//	TileLayer layer(&shader);
//	Camera* camera;
//
//	//Corners representd by squares...
//	TileLayer square(&shader);
//	Sprite ss(-16, -9, 0, 1.0f, 1.0f, Maths::vec4(1, 0, 0, 0.5));
//	Sprite ss1(15, -9, 0, 1.0f, 1.0f, Maths::vec4(0, 1, 0, 0.5));
//	Sprite ss2(15, 8, 0, 1.0f, 1.0f, Maths::vec4(0, 0, 1, 0.5));
//	Sprite ss3(-16, 8, 0, 1.0f, 1.0f, Maths::vec4(1, 1, 1, 0.5));
//	//add sprites to the square layer
//	square.add(new Sprite(ss));
//	square.add(new Sprite(ss1));
//	square.add(new Sprite(ss2));
//	square.add(new Sprite(ss3));
//	//load textures
//	Texture* textures[] =
//	{
//		new Texture("test.png"),
//		new Texture("test1.png"),
//		new Texture("test2.png")
//
//	};
//	for (float y = -9.0f; y < 9.0f; y++)
//	{
//		for (float x = -16.0f; x < 16.0f; x++)
//		{
//			if (rand() % 4 == 0)
//				layer.add(new Sprite(x, y, 0, 0.9f, 0.9f, Maths::vec4(rand() % 1000 / 1000.0f, 0, 0, 1)));
//			else
//				layer.add(new Sprite(x, y, 0, 0.9f, 0.9f, textures[rand() % 3])); 
//			spritecount++;
//		}
//	}
//
//	//Texture ID for sending textures to the shader
//	GLint texIDs[] = { 0,1,2,3,4,5,6,7,8,9 };
//	shader.enable();
//	shader.setUniform1iv("textures", texIDs, 10);
//	shader.disable();
//	//shader.setUniformMat4("pr_matrix", Maths::mat4::othographic(-16.0f, 16.0f, -9.0f, 9.0f, -1.0f, 1.0f));
//	Timer time;
//	float timer = 0;
//	unsigned int frames = 0;
//
//	float t = 0.0f;
//	while (!window.closed())
//	{
//		t += 0.05f;
//		//std::cout << window.getWidth() << " ," << window.getHeight() <<std::endl;
//		window.clear();
//		double x, y;
//		window.getMousePosition(x, y);
//
//		shader.setUniform2f("light_pos", vec2((float)(x * 32.0f / window.getWidth() - 16.0f), (float)(9.0f - y * 18.0f / window.getHeight())));
//
//		const std::vector<Renderable2D*>& rs = layer.getRenderables();
//		for (int i = 0; i < rs.size(); i++)
//		{
//			float c = sin(t) / 2 + 0.5;
//			rs[i]->setColor(Maths::vec4(0, 0, c, 1));
//			rs[i]->setSize(0.5, 0.5);
//		}
//
//		const std::vector<Renderable2D*>& bs = square.getRenderables();
//		for (int i = 0; i < bs.size(); i++)
//		{
//			float c = sin(t) / 2 + 0.5;
//			bs[i]->setColor(Maths::vec4(c - 0.2, c - 0.5, c-0.3, 1));
//			//bs[i]->setSize(0.5, 0.5);
//
//			if (x > 500) {
//				
//					std::cout << "onnnnnnnnnnn" << std::endl;
//			}
//		}
//	
//		layer.render();
//		square.render();
//		window.update();
//		frames++;
//		if (time.elapsed() - timer > 1.0f)
//		{
//			timer += 1.0f;
//			printf("Sprites : %d\n", spritecount);
//			printf("%d FPS\n", frames);
//			frames = 0;
//		}
//	}
//
//	for (int i = 0; i < 3; i++)
//		delete textures[i];
//	return 0;
//}