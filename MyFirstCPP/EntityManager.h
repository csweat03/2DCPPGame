#pragma once
#include "Game.h"
#include "Player.h"
#include "Enemy.h"
#include "Entity.h"

class EntityManager
{
protected:
	Camera* camera;
	Player* player;
	std::vector<Enemy*> enemies;
	std::vector<Entity*> entities;
	MilliTimer timer;
public:
	EntityManager(sf::VideoMode videoMode) {
		this->camera = new Camera();
		this->player = new Player();

		this->camera->setPosition(Vector(50, 50));
		this->camera->setSize(Vector(videoMode.width - 100.f, videoMode.height - 100.f));

		this->player->camera = camera;
		this->player->spawn();
	}

	~EntityManager() {
		delete this->camera;
		delete this->player;

		for (auto& enemy : this->enemies)
			delete enemy;

		for (auto& entity : this->entities)
			delete entity;
	}

	void update(sf::RenderWindow* window) {
		this->player->update();

		addEnemies(window);
		addEntities(window);

		for (auto& enemy : this->enemies)
			enemy->update();
		
		for (auto& entity : this->entities)
			entity->update();
	}

	void render(sf::RenderWindow* window) {
		this->camera->render(window);

		this->player->render(window);

		for (Enemy* enemy : this->enemies)
			enemy->render();
		for (Entity* entity : this->entities)
			entity->render();
	}
	///// Getters (and Setters...) /////
	Camera* getCamera() {
		return camera;
	}
	Player* getPlayer() {
		return player;
	}
	std::vector<Enemy*> getEnemyVector() {
		return enemies;
	}
	std::vector<Entity*> getEntityVector() {
		return entities;
	}
	MilliTimer getGameTimer1() {
		return timer;
	}
private:
	void addEnemies(sf::RenderWindow* window) {
		if (this->enemies.size() <= 20 && timer.hasTimeElapsed(500))
		{
			Enemy* enemy = new Enemy();

			enemy->window = window;

			enemy->spawn();

			this->enemies.push_back(enemy);
			timer.resetTimer();
		}
	}
	void addEntities(sf::RenderWindow* window) {

	}
};

