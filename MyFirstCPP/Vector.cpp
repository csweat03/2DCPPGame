#include "Vector.h"

Vector Vector::transform(Vector vector)
{
	return Vector(this->x + vector.x, this->y + vector.y);
}

Vector Vector::transform(float x, float y)
{
	return Vector(this->x + x, this->y + y);
}

Vector Vector::multiply(Vector vector)
{
	return Vector(this->x + vector.x, this->y + vector.y);
}

Vector Vector::multiply(float x, float y)
{
	return Vector(this->x * x, this->y * y);
}

sf::Vector2f Vector::cast()
{
	return sf::Vector2f(x, y);
}
