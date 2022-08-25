#include "Math.h"

float Math::get_magnitude(Vector vector)
{
    float x2 = vector.x * vector.x;
    float y2 = vector.y * vector.y;

    float z = sqrt(x2 + y2);

    return 0.0f;
}

float Math::get_direction(Vector vector)
{
    return 0.0f;
}

Vector Math::get_vector(float magnitude, float direction)
{
    return Vector(0,0);
}
