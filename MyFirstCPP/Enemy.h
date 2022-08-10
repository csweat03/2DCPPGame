#pragma once

#include <SFML/Graphics.hpp>

class Enemy
{
private:
	sf::RectangleShape shape;

public:
	void spawnEnemy(sf::RenderWindow* window);
	void updateEnemy(sf::RenderWindow* window);
	sf::RectangleShape getShape();
};

