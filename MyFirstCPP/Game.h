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

#include "Enemy.h"
#include "MilliTimer.h"

class Game
{
private:
	// declarations
	sf::RenderWindow *window;
	sf::VideoMode videoMode;
	sf::Event ev;

	sf::Vector2i mousePosition;

	std::vector<Enemy> enemies;

	MilliTimer timer;

	// methods
	void initVariables();
	void initWindow();

public:
	// constructors / destructors
	Game();
	virtual ~Game();

	// accessors
	const bool running() const;


	// methods
	void pollEvents();
	void updateMousePosition();

	void updateEnemies();
	void update();

	void renderEnemies();
	void render();
};
