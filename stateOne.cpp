#include "stateOne.h"
#include <iostream>


sf::Sprite sprite_shooter;
sf::Texture texture1;


void StateOne::init()
{
	std::cout << " In StateOne.Init()\n";
    // load textures, fonts
    
    if (!texture1.loadFromFile("assets/shooter.bmp"))
    {
        std::cout << "ERROR could not load shooter.bmp";
    }
    
    sprite_shooter.setTexture(texture1);



}

void StateOne::handleInput(sf::Event* event)
{

}

void StateOne::update(float timeElapsed)
{
	//std::cout << " In StateOne.update()\n";   // TEST
    // Update our entities
   //position shooter
    sprite_shooter.setPosition(sf::Vector2f(500.f, 800.f)); // absolute position

}

void StateOne::draw(sf::RenderWindow* window) 
{
	//std::cout << " In StateOne.draw()\n";   //TEST
    window->draw(sprite_shooter);

}

void StateOne::endGameLogic() 
{

}
