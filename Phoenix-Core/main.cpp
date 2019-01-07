#include "Benchmark.h"
#include "includes.h"
#define BATCH_RENDERER 1
#define TEST1 0
#define BENCHMARK 0
#if 0
#if BATCH_RENDERER
int main() 
{
	using namespace Phoenix;
	using namespace Graphics;
	using namespace Maths;

	/*std::string file = read_file("main.cpp");
	std::cout << file << std::endl;
	system("PAUSE");
	return 0;
	*/

	Window window("Phoenix-Engine", 960, 540);
	//glClearColor(0.0f, 1.0f, 1.0f, 1.0f);

	Shader* s = new Shader("basic.vs", "basic.fs");
	Shader* s1 = new Shader("benchmark.vs", "benchmark.fs");

	Shader& shader = *s;
	Shader& shader1 = *s1;

	int spritecount = 0;

	TileLayer layer(&shader);

	//Corners representd by squares...
	TileLayer square(&shader1);
	Sprite ss(-16, -9, 0, 1.0f, 1.0f, Maths::vec4(1, 0, 0, 0.5));
	Sprite ss1(15, -9, 0, 1.0f, 1.0f, Maths::vec4(0, 1, 0, 0.5));
	Sprite ss2(15, 8, 0, 1.0f, 1.0f, Maths::vec4(0, 0, 1, 0.5));
	Sprite ss3(-16, 8, 0, 1.0f, 1.0f, Maths::vec4(1, 1, 1, 0.5));
	//
	square.add(new Sprite(ss));
	square.add(new Sprite(ss1));
	square.add(new Sprite(ss2));
	square.add(new Sprite(ss3));


	Texture* textures[] =
	{
		new Texture("test.png"),
		new Texture("test1.png"),
		new Texture("test2.png")

	};
	


	for (float y = -9.0f; y < 9.0f; y ++)	//60K Sprites +=0.1f
	{
		for (float x = -16.0f; x < 16.0f; x ++)	//60K Sprites +=0.1f
		{
			if (rand() % 4 == 0)
			layer.add(new Sprite(x, y, 0, 0.9f, 0.9f, Maths::vec4(rand() % 1000 / 1000.0f, 0, 0, 1))); //60K Sprites 0.09f
			else
			layer.add(new Sprite(x, y, 0, 0.9f, 0.9f, textures[rand() % 3])); //60K Sprites 0.09f

			//layer.add(new Sprite(x, y, 0.09f, 0.09f, textures[1])); //60K Sprites 0.09f
			//layer.add(new Sprite(-16, -9, 0.9f, 0.9f, textures[1])); //Bottem left -16, -9

			spritecount++;
		}
	}


	GLint texIDs[] = {0,1,2,3,4,5,6,7,8,9};

	shader.enable();
	shader.setUniform1iv("textures", texIDs, 10);
	shader.disable();
	//shader.setUniformMat4("pr_matrix", Maths::mat4::othographic(-16.0f, 16.0f, -9.0f, 9.0f, -1.0f, 1.0f));

	Timer time;
	float timer = 0;
	unsigned int frames = 0;

	float t = 0.0f;
	while (!window.closed())
	{
		t += 0.05f;
		//std::cout << window.getWidth() << " ," << window.getHeight() <<std::endl;
		window.clear();
		double x, y;
		window.getMousePosition(x, y);
		
		shader.setUniform2f("light_pos", vec2((float)(x * 32.0f / window.getWidth() - 16.0f), (float)(9.0f - y * 18.0f / window.getHeight())));
		layer.render();

		const std::vector<Renderable2D*>& rs = layer.getRenderables();
		for (int i = 0; i < rs.size(); i++)
		{
			float c = sin(t) / 2 + 0.5;
			rs[i]->setColor(Maths::vec4(0, 0, c, 1));
			rs[i]->setSize(0.5, 0.5);
		}

		square.render();
		window.update();
		frames++;
		if (time.elapsed() - timer > 1.0f)
		{
			timer += 1.0f;
			printf("Sprites : %d\n", spritecount);
			printf("%d FPS\n", frames);
			frames = 0;
		}
	}

	for (int i = 0; i < 3; i++)
		delete textures[i];
	return 0;
}



#else if TEST_1
	
int main()
{
#define WIDTH 960
#define HEIGHT 560
	using namespace Phoenix;
	using namespace Graphics;
	using namespace Maths;

	Window window("Phoenix-Engine", WIDTH, HEIGHT);
	

	Shader* benchmarkShader = new Shader("benchmark.vs", "benchmark.fs");
	GLint texIDs[] = { 0,1,2,3,4,5,6,7,8,9 };
	benchmarkShader->enable();
	benchmarkShader->setUniform1iv("textures", texIDs, 10);
	

	Timer time;
	float timer = 0;
	unsigned int frames = 0;
	float counter = 0.0f;
	while (!window.closed())
	{
		window.clear();
		double x, y;
		window.getMousePosition(x, y);

		const GLfloat bgColor[] = { 0.0f, 0.4f, 0.0f, 1.0f };
		glClearBufferfv(GL_COLOR, 0, bgColor);
		
		
		

		window.update();
		counter += 0.0001f;
		frames++;
		if (time.elapsed() - timer > 1.0f)
		{
			timer += 1.0f;
			printf("%d FPS\n", frames);
			frames = 0;
		}
	}
	return 0;

}

#endif
#endif

/*

#else if TEST_1
int main()
{

	#define WIDTH 960
	#define HEIGHT 560
	using namespace Phoenix;
	using namespace Graphics;
	using namespace Maths;

	Window window("Phoenix-Engine", WIDTH, HEIGHT);
	Shader* s = new Shader("test.vs", "test.fs", "testTessellationControlShader.tcs", "testTessellationEvaluationlShader.tes", "testGeometry.gs");
	Shader& shader = *s;
	
	Shader* s1 = new Shader("test.vs", "test.fs");
	Shader& shader1 = *s1;

	Shader* benchmarkShader = new Shader("benchmark.vs", "benchmark.fs");
	
	GLint texIDs[] = { 0,1,2,3,4,5,6,7,8,9 };

	benchmarkShader->enable();
	benchmarkShader->setUniform1iv("textures", texIDs, 10);

	Timer time;
	float timer = 0;
	unsigned int frames = 0;
	Benchmark::Benchmark b(benchmarkShader);
	Vertex verticies[] = { Vertex(vec3(-0.5f, -0.5f, 0)),
							Vertex(vec3(0.0f, 0.5f, 0)),
							Vertex(vec3(0.5f, -0.5f, 0)) };

	Mesh triangle(verticies, sizeof(verticies) / sizeof(verticies[0]));
	Transform transform;
	Camera camera(vec3(0, 0, -5), 70.0f, (float)WIDTH/ (float)HEIGHT, 0.01f, 1000.0f);
	float counter = 0.0f;
	while (!window.closed())
	{
		window.clear();
		double x, y;
		window.getMousePosition(x, y);

		const GLfloat bgColor [] = {  0.0f, 0.4f, 0.0f, 1.0f };
		glClearBufferfv(GL_COLOR, 0, bgColor);
		GLfloat offset[] = { (float)sin(time.elapsed()) * 0.5f, (float)cos(time.elapsed()) * 0.6f, 0.0f, 0.0f };
		GLfloat color[] = { 0.3f, (float)sin(time.elapsed()) * 0.5f, (float)cos(time.elapsed()) * 0.5f, 1.0f, 1.0f };
		//glVertexAttrib4fv(3, attrib);
		//triangle.draw();

		//shader.enable();// = glUseProgram();
		//glVertexAttrib4fv(4, color);
		//glVertexAttrib4fv(0, offset);
		//glVertexAttrib4fv(1, color);
		//glPatchParameteri(GL_PATCH_VERTICES, 3);
		//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		//glPointSize(5.0);
		//glDrawArrays(GL_PATCHES, 0, 3);
		//shader.disable();

		//transform.getPosition().x = sinf(counter);
		//transform.getRotation().x = counter * 50;
		//transform.setRotation(Maths::vec3(0, 0 , counter * 100));
		//transform.setScale(Maths::vec3(counter, counter, 0));
		//transform.setPosition(vec3(counter,counter,2));

		//shader1.enable();
		//shader1.setUniformMat4("transform", transform.getTransform());
		//shader1.setUniformMat4("viewprojection", camera.getViewProjection());
		//triangle.draw();
		//shader1.disable();

		benchmarkShader->enable();
		b.run();
		benchmarkShader->disable();

		window.update();
		counter += 0.0001f;
		frames++;
		if (time.elapsed() - timer > 1.0f)
		{
			timer += 1.0f;
			printf("%d FPS\n", frames);
			frames = 0;
		}
	}
	return 0;
}

#endif

*/