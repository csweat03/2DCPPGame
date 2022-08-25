#pragma once

#include "Vector.h"

class Math
{
	float get_magnitude(Vector vector);
	float get_direction(Vector vector);

	Vector get_vector(float magnitude, float direction);

};

