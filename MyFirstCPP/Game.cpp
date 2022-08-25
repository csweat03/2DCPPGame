#include "Game.h"

Game::Game()
{
    this->window = nullptr;

    this->videoMode.width = 800;
    this->videoMode.height = 800;

    this->window = new sf::RenderWindow(this->videoMode, "MY First C++ Project", sf::Style::Titlebar | sf::Style::Close);
    this->window->setFramerateLimit(120);

    this->controller = new Controller();
    this->entityManager = new EntityManager(this->videoMode);
}

Game::~Game()
{
	delete this->window;
    delete this->entityManager;
    delete this->controller;
}

const bool Game::running() const
{
	return this->window->isOpen();
}

void Game::update()
{
    this->controller->handle(this->window);

    this->mousePosition = sf::Mouse::getPosition(*this->window);

    this->entityManager->update(window);
}

void Game::render()
{
    this->window->clear();

    this->entityManager->render(this->window);
    // End Enemy Render

    this->window->display();
}