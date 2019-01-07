#pragma once
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>


namespace Phoenix
{

	namespace Graphics
	{

#define MAX_KEYS	1024
#define MAX_BUTTONS	32

		class Window 
		{
		public:
			
		private:
			const char* m_Name;
			int m_Width, m_Height;
			GLFWwindow *m_Window;
			bool m_Closed;
			bool m_Keys[MAX_KEYS];
			bool m_MouseButtons[MAX_BUTTONS];
			

		public:
			int m_action;
			int getAction();
			Window(const char* name, int width, int height);
			~Window();
			void clear()const;
			void update();
			bool closed()const;
			double mx, my;
			inline int getWidth() const { return m_Width; }
			inline int getHeight() const { return m_Height; }
			
			bool isKeyPressed(unsigned int keycode)const;
			bool isMouseButtonPressed(unsigned int button)const;
			void getMousePosition(double& x, double& y)const;
			bool isFocused();

		private:
			bool init();
			friend void window_resize(GLFWwindow* window, int width, int height);
			friend void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
			friend void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
			friend void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);
			

			

		};
		
	}

}