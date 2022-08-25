#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include "Vector.h"

class Entity
{
public:
	sf::RenderWindow* window;
	sf::RectangleShape shape = sf::RectangleShape();

	virtual void spawn();
	virtual void update();
	virtual void render();

	virtual Vector getPosition();

	virtual void setPosition(Vector position);
	virtual void moveEntity(Vector offset);
};

