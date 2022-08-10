#include "Game.h"

void Game::initVariables()
{
	this->window = nullptr;
}

void Game::initWindow()
{
	this->videoMode.height = 700;
	this->videoMode.width = 1000;

	this->window = new sf::RenderWindow(this->videoMode, "MY First C++ Project", sf::Style::Titlebar | sf::Style::Close);

    this->window->setFramerateLimit(120);
}

Game::Game()
{
	this->initVariables();
	this->initWindow();
}

Game::~Game()
{
	delete this->window;
}

const bool Game::running() const
{
	return this->window->isOpen();
}

void Game::pollEvents()
{
    while (this->window->pollEvent(this->ev))
    {
        switch (this->ev.type)
        {
        case sf::Event::Closed:
            this->window->close();
            break;
        case sf::Event::KeyPressed:
            if (this->ev.key.code == sf::Keyboard::Escape)
                this->window->close();
            break;
        }
    }
}

void Game::updateMousePosition()
{
    this->mousePosition = sf::Mouse::getPosition(*this->window);
}

void Game::updateEnemies()
{
    if (this->enemies.size() <= 20)
    {
        if (this->timer.hasTimeElapsed(500))
        {
            Enemy enemy = Enemy();

            enemy.spawnEnemy(window);

            this->enemies.push_back(enemy);
            this->timer.resetTimer();
        }
    }

    for (auto &e : this->enemies)
    {
        e.updateEnemy(window);
    }
}

void Game::update()
{
    this->pollEvents();

    this->updateMousePosition();

    this->updateEnemies();
}

void Game::renderEnemies()
{
    for (Enemy enemy : this->enemies)
    {
        this->window->draw(enemy.getShape());
    }
}

void Game::render()
{
    this->window->clear();

    // do render stuff
    this->renderEnemies();

    this->window->display();
}