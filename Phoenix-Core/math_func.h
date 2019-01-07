#pragma once
#define _USE_MATH_DEFINES
#include <stdlib.h>
#include <math.h>
#include <ctime>

namespace Phoenix
{
	namespace Maths
	{
		inline float toRadians(float degrees)
		{
			return degrees * ((float)M_PI / 180.0f);
		}

		inline int randomint(int from, int to)
		{
			return rand() % (to - from) + from;
		}

		inline float randomfloat(float a, float b)
		{
			float random = ((float)rand()) / (float)RAND_MAX;
			float diff = b - a;
			float r = random * diff;
			return a + r;
		}
	}
}