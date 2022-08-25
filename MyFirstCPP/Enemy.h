#pragma once

#include "Entity.h"
#include <SFML/Graphics.hpp>

class Enemy: public Entity
{
public:
	void spawn() override;
	void update() override;
	void render() override;
};

