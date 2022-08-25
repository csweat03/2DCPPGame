#pragma once

/*
* This class is the main game engine.
*/

#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include "Camera.h"
#include "Player.h"
#include "Enemy.h"
#include "MilliTimer.h"
#include "EntityManager.h"
#include "Controller.h"

class Game
{
private:
	// declarations
	sf::VideoMode videoMode;
	
	sf::Vector2i mousePosition;
public:
	sf::RenderWindow* window;
	Controller* controller;
	EntityManager* entityManager;

	// constructors / destructors
	Game();
	virtual ~Game();

	// accessors
	const bool running() const;

	// methods
	void update();
	void render();
};
