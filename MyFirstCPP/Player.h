#pragma once

#include <SFML/Graphics/RectangleShape.hpp>
#include "Camera.h"
#include "Vector.h"

class Player
{
private:
	Vector position = Vector(0, 0);
	Vector velocity = Vector(0, 0);

	float modifyCoord(float coord, float defSpeed);
public:
	Camera* camera;
	sf::RectangleShape shape = sf::RectangleShape();

	void spawn();
	void update();
	void render(sf::RenderWindow* window);

	Vector getPosition();
	Vector getVelocity();

	void setPosition(Vector position);
	void moveEntity();
	Vector defaultSpeed();
	bool hasForwardInput();
	bool hasReverseInput();
	bool hasLeftInput();
	bool hasRightInput();
	bool hasInput();
	bool isMoving();
};

