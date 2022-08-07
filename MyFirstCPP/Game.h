#pragma once

/*
* This class is the main game engine.
*/

#include <list>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class Game
{
private:
	// declarations
	sf::RenderWindow *window;
	sf::VideoMode videoMode;
	sf::Event ev;

	std::list<sf::RectangleShape> enemies;

	// methods
	void initVariables();
	void initWindow();
	void initEntities();

public:
	// constructors / destructors
	Game();
	virtual ~Game();

	// accessors
	const bool running() const;


	// methods
	void pollEvents();
	void update();
	void render();
};
