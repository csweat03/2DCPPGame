#include "Player.h"
#include <iostream>

void Player::spawn()
{
	position = Vector(400, 400);
	shape.setSize(Vector(35, 35).cast());
	shape.setFillColor(sf::Color::Red);
}

void Player::update()
{
	moveEntity();

	position = position.transform(velocity);

	shape.setPosition(camera->getPosition().transform(position).cast());
}

void Player::render(sf::RenderWindow* window)
{
	window->draw(this->shape);
}

Vector Player::getPosition()
{
	return this->position;
}

Vector Player::getVelocity()
{
	return this->velocity;
}

void Player::setPosition(Vector position)
{
	this->position = position;
}

float Player::modifyCoord(float coord, float defSpeed)
{
	float slowing = abs(coord) > 0.15f ? coord * 0.96f : 0.f;
	return abs(slowing) > abs(defSpeed) ? slowing : defSpeed;
}

void Player::moveEntity()
{
	velocity = Vector(modifyCoord(velocity.x, defaultSpeed().x), modifyCoord(velocity.y, defaultSpeed().y));
}

Vector Player::defaultSpeed()
{
	float DEFAULT_SPEED = 0.60f;
	float STRAFE_FACTOR = 0.72f;

	bool l = hasLeftInput(), r = hasRightInput(), f = hasForwardInput(), b = hasReverseInput();

	bool hori = l||r;
	bool vert = f||b;

	float x = hori ? DEFAULT_SPEED * (vert ? STRAFE_FACTOR : 1) * (l ? -1 : r ? 1 : 0) : 0;
	float y = vert ? DEFAULT_SPEED * (hori ? STRAFE_FACTOR : 1) * (f ? -1 : b ? 1 : 0) : 0;

	return Vector(x, y);
}

bool Player::hasForwardInput()
{
	return sf::Keyboard::isKeyPressed(sf::Keyboard::W);
}

bool Player::hasReverseInput()
{
	return sf::Keyboard::isKeyPressed(sf::Keyboard::S);
}

bool Player::hasLeftInput()
{
	return sf::Keyboard::isKeyPressed(sf::Keyboard::A);
}

bool Player::hasRightInput()
{
	return sf::Keyboard::isKeyPressed(sf::Keyboard::D);
}

bool Player::hasInput()
{
	return hasForwardInput() || hasReverseInput() || hasLeftInput() || hasRightInput();
}

bool Player::isMoving()
{
	return velocity.x == velocity.y == 0;
}
