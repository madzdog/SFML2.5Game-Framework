#include "splashscreen.h"
#include "gameManager.h"
#include <iostream>

sf::Sprite sprite_splashscreen;
sf::Texture texture_splashscreen;

void Splashscreen::init()
{
	//std::cout << " In Splashscreen.Init()\n";
    // load textures, fonts

    // load shooter
    if (!texture_splashscreen.loadFromFile("assets/madzdogSplash.png"))
    {
        std::cout << "ERROR could not load madxdogSplash.png";
    }

    sprite_splashscreen.setTexture(texture_splashscreen);
    //inital position splashscreen
    sprite_splashscreen.setPosition(sf::Vector2f(0.0f, 0.0f)); // absolute position
}

void Splashscreen::handleInput(sf::Event* event)
{
    if (event->type == sf::Event::KeyPressed || event->type == sf::Event::MouseButtonPressed)
    {
        // set new state = stateOne setState(GameManager::State s)
        GameManager::setState(GameManager:: State1);
    }
}

void Splashscreen::update(float timeElapsed)
{
	//std::cout << " In Splashscreen.update()\n";
}

void Splashscreen::draw(sf::RenderWindow* window)
{
	//std::cout << " In Splashscreen.draw()\n";
    window->draw(sprite_splashscreen);
}

void Splashscreen::endGameLogic()
{

}