#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class Controller
{
protected:
    sf::Event ev;
public:
    void handle(sf::RenderWindow* window) 
    {
        while (window->pollEvent(this->ev)) 
        {
            handleWindow(window, ev);
        }
    }
private:
    bool pressed(sf::Keyboard::Key key) {
        return sf::Keyboard::isKeyPressed(key);
    }

	void handleWindow(sf::RenderWindow* window, sf::Event event) 
    {
        if (pressed(sf::Keyboard::Escape) || event.type == sf::Event::Closed) {
            window->close();
        }
    }
};

