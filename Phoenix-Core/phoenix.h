#pragma once

#include "window.h"
#include "timer.h"

namespace  Phoenix
{
	class Phoenix
	{


	private:
		Graphics::Window* m_window;
		Timer* m_timer;
		unsigned int m_frames_per_second, m_updates_per_second;


	protected:
		Phoenix()
			:m_frames_per_second(0), m_updates_per_second(0)
		{
		}

		virtual ~Phoenix() { delete m_window; delete m_timer; }

		

		Graphics::Window* createWindow(const char *name, int width, int height)
		{
			m_window = new Graphics::Window(name, width, height);
			return m_window;
		}
		virtual void init() = 0;
		virtual void render() = 0;
		virtual void update() = 0;
		virtual void tick() { }
		const unsigned int getFPS() const { return m_frames_per_second; }
		const unsigned int getUPS() const { return m_updates_per_second; }


	public :
		void start() { init(); run(); }


	private:
		void run()
		{

			m_timer = new Timer();
			float timer = 0.0f;
			float updte_timer = 0.0f;
			float update_tick = 1.0f / 60.0f;
			unsigned int frames = 0;
			unsigned int updates = 0;
			//Game Loop
			while (!m_window->closed())
			{
				m_window->clear();

				if (m_timer->elapsed() - updte_timer > update_tick)

				{
					updates++;
					update();
					updte_timer += update_tick;
				}

				frames++;
				render();
				m_window->update();

				if (m_timer->elapsed() - timer > 1.0f)
				{
					timer += 1.0f;
					m_frames_per_second = frames;
					m_updates_per_second = updates;
					frames = 0;
					updates = 0;
					tick();

				}
			}
		}
	};
}