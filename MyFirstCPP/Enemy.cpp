#include "Enemy.h"

void Enemy::spawn() {
	setPosition(Vector(static_cast<float>(rand() % (static_cast<int>(window->getSize().x) - 50)), 0));
	shape.setSize(Vector(25, 25).cast());
	shape.setFillColor(sf::Color::Cyan);
};

void Enemy::update()
{
	Entity::update();
	// Move down
	moveEntity(Vector(0.0f, 0.5f));

	// Respawn enemy at top at same location
	if (shape.getPosition().y > window->getSize().y)
	{
		setPosition(sf::Vector2f(shape.getPosition().x - window->getPosition().x, 0));
	}
}

void Enemy::render()
{
	Entity::render();
}
