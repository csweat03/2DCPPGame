#pragma once

#include <SFML/Graphics.hpp>

class Vector
{
public:
	float x, y;

	Vector(sf::Vector2f vector) {
		this->x = vector.x;
		this->y = vector.y;
	}

	Vector(float x, float y) {
		this->x = x;
		this->y = y;
	}

	Vector transform(Vector vector);
	Vector transform(float x, float y);
	Vector multiply(Vector vector);
	Vector multiply(float x, float y);

	sf::Vector2f cast();
};

