#include "Entity.h"

void Entity::spawn()
{

}

void Entity::update()
{

}

void Entity::render()
{
	window->draw(this->shape);
}

Vector Entity::getPosition()
{
	return Vector(shape.getPosition());
}

void Entity::setPosition(Vector position)
{
	shape.setPosition(position.cast());
}

void Entity::moveEntity(Vector offset)
{
	shape.setPosition(getPosition().transform(offset).cast());
}
