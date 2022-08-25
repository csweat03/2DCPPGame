#include "Camera.h"

void Camera::setPosition(Vector origin)
{
	// Unpack Vector and assign to x,y
	x = origin.x;
	y = origin.y;
}

void Camera::setSize(Vector size)
{
	// Unpack vector and assign to width,height
	width = size.x;
	height = size.y;
}

void Camera::moveCamera(Vector magnitude)
{
	// Unpack vector and manipulate x,y
	setPosition(Vector(x + magnitude.x, y + magnitude.y));
}

void Camera::render(sf::RenderWindow* window)
{
	sf::RectangleShape cameraRect = sf::RectangleShape(getSize().cast());

	cameraRect.setFillColor(sf::Color(255, 255, 255, 50));
	cameraRect.setPosition(getPosition().cast());

	window->draw(cameraRect);
}

Vector Camera::getPosition()
{
	return Vector(x, y);
}

Vector Camera::getSize()
{
	return Vector(width, height);
}