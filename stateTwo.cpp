#include "stateTwo.h"
#include <iostream>

void StateTwo::init()
{
	std::cout << " In StateTwo.Init()\n";
}

void StateTwo::handleInput(sf::Event* event)
{

}

void StateTwo::update(float timeElapsed)
{
	std::cout << " In StateTwo.update()\n";
}

void StateTwo::draw(sf::RenderWindow* window)
{
	std::cout << " In StateTwo.draw()\n";
}

void StateTwo::endGameLogic()
{

}
