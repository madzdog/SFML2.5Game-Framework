#include "menuscreen.h"
#include "gameManager.h"
#include <iostream>

// define Sprites and Textures
//sf::Sprite 
//sf::Texture 

void Menuscreen::init()
{
    std::cout << " In Menuscreen.Init()\n";   //TEST
    // load textures, fonts
    // load texture files
    // set texture for sprites

    //set inital position of sprites
    
}

void Menuscreen::handleInput(sf::Event* event)
{
     std::cout << " In Menuscreen Init()\n";   // TEST
    // handle inputs, keystrokes, mouse button etc.
     if (event->type == sf::Event::KeyPressed || event->type == sf::Event::MouseButtonPressed)
     {
         // set new state = stateOne setState(GameManager::State s)
         GameManager::setState(GameManager:: State1);
        
     }


}

void Menuscreen::update(float timeElapsed)
{
    std::cout << " In Menuscreen.update()\n";  //TEST
}

void Menuscreen::draw(sf::RenderWindow* window)
{
    std::cout << " In Menuscreen.draw()\n";
    
}

void Menuscreen::endGameLogic()
{

}