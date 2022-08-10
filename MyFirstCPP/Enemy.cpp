#include "Enemy.h"

void Enemy::spawnEnemy(sf::RenderWindow* window)
{
	shape.setPosition(sf::Vector2f(static_cast<float>(rand() % (window->getSize().x - 50)), 0.f));
	shape.setSize(sf::Vector2f(25.f, 25.f));
	shape.setFillColor(sf::Color::Cyan);
}

void Enemy::updateEnemy(sf::RenderWindow* window)
{
	shape.move(0.f, 0.9f);

	if (shape.getPosition().y > window->getSize().y)
	{
		shape.setPosition(static_cast<float>(rand() % (window->getSize().x - 50)), 0);
	}
}

sf::RectangleShape Enemy::getShape()
{
	return shape;
}
