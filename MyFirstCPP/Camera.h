#pragma once

#include "Vector.h"

class Camera
{
private:
	float x = 0;
	float y = 0;
	float width = 0;
	float height = 0;
public:
	void setPosition(Vector origin);
	void setSize(Vector size);
	void moveCamera(Vector magnitude);

	void render(sf::RenderWindow* window);

	Vector getPosition();
	Vector getSize();
};

