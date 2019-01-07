#pragma once
#include <windows.h>
namespace Phoenix
{
	class Timer
	{
	private:
		LARGE_INTEGER m_Start;
		double m_Frequancy;

	public:

		Timer()
		{
			LARGE_INTEGER frequancy;
			QueryPerformanceFrequency(&frequancy);
			m_Frequancy = 1.0 / frequancy.QuadPart;
			QueryPerformanceCounter(&m_Start);

		}

		void reset()
		{
			QueryPerformanceCounter(&m_Start);
		}

		float elapsed()
		{
			LARGE_INTEGER current;
			QueryPerformanceCounter(&current);
			unsigned _int64 cycles = current.QuadPart - m_Start.QuadPart;
			return (float)(cycles * m_Frequancy);
		}

		float curretTime()
		{
			LARGE_INTEGER current;
			QueryPerformanceCounter(&current);
			unsigned _int64 cycles = current.QuadPart - m_Start.QuadPart;
			return (float)cycles;
		}
	};
}