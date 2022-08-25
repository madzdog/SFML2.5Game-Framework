#include "stateOne.h"
#include <iostream>


sf::Sprite sprite_shooter;
sf::Sprite sprite_bg2;
sf::Texture texture1;
sf::Texture texture2;
float bg2_xOffset = 0;

void StateOne::init()
{
	std::cout << " In StateOne.Init()\n";
    // load textures, fonts
    
    // load shooter
    if (!texture1.loadFromFile("assets/Biplane.png"))
    {
        std::cout << "ERROR could not load Biplane.png";
    }
    
    sprite_shooter.setTexture(texture1);
    //inital position shooter
    sprite_shooter.setPosition(sf::Vector2f(500.f, 800.f)); // absolute position

    //load background
    if (!texture2.loadFromFile("assets/bg2.png"))
    {
        std::cout << "ERROR could not load bg2.png";
    }

    sprite_bg2.setTexture(texture2);
    //inital position background
    sprite_bg2.setPosition(sf::Vector2f(5.0f, 5.0f)); // absolute position





}

void StateOne::handleInput(sf::Event* event)
{
     //if (event->type == sf::Event::Closed)
     //{
     //    _window.close();
     //    exit = true;
     //}




    // check for key input events
    switch (event->type)
    {
        case sf::Event::TextEntered:
            if (event->text.unicode < 128)
                std::cout << "ASCII character typed: " << static_cast<char>(event->text.unicode) << std::endl;
            break;

        case sf::Event::KeyPressed:

            if (event->key.code == sf::Keyboard::Escape)
            {
                std::cout << "the escape key was pressed" << std::endl;
                std::cout << "control:" << event->key.control << std::endl;
                std::cout << "alt:" << event->key.alt << std::endl;
                std::cout << "shift:" << event->key.shift << std::endl;
                std::cout << "system:" << event->key.system << std::endl;
            }
     //       else if (event->key.alt == sf::Keyboard::End)
     //       {
     //           _window.close();
     //       }
     //       break;

        // Mouse Button pressed
            break;
        case sf::Event::MouseButtonPressed:
            if (event->mouseButton.button == sf::Mouse::Right)
            {
                std::cout << "the right button was pressed\n" << std::endl;
                std::cout << "mouse x: " << event->mouseButton.x << std::endl;
                std::cout << "mouse y: " << event->mouseButton.y << std::endl;
            }
            else if (event->mouseButton.button == sf::Mouse::Left)
            {
                std::cout << "the left button was pressed\n" << std::endl;
                std::cout << "mouse x: " << event->mouseButton.x << std::endl;
                std::cout << "mouse y: " << event->mouseButton.y << std::endl;
            }
            break;
        default:              // no events this refresh
            break;
    }   // end of switch








    // 
 
}

void StateOne::update(float timeElapsed)
{
	//std::cout << " In StateOne.update()\n";   // TEST
    // Update our entities
//   //inital position shooter
//    sprite_shooter.setPosition(sf::Vector2f(500.f, 800.f)); // absolute position

    /********************************************************************
        *  Arrow keys - character movement
        *********************************************************************/
    // move the entity relatively to its current position
    // 
    // move character to the left
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        //std::cout << "Left arrow pressed - moving character to the left\n";
        sprite_shooter.move(-5.f, 0.f);
    }

    // move character to the right
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        //std::cout << "Right arrow pressed - moving character to the right\n";
        sprite_shooter.move(5.f, 0.f);
    }

    // move character forward
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        //std::cout << "Up arrow pressed - moving character forward\n";
        sprite_shooter.move(0.f, -5.f);
    }

    // move character backward
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        //std::cout << "Down arrow pressed - moving character to the back\n";
        sprite_shooter.move(0.f, 5.f);
    }

    // Spacebar Jump
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        std::cout << "Space Bar pressed - character jump- need code for this.\n";
    }
    //================================================================
    // either scroll bg to left & contol player with arrow keys 
    // - or move bg left with arrow keys & statonary player character
    // ===================================================================
    // 
    // Scroll background, if end of bg, start over. 
    // bg2.png is 4800px wide and 1200px high, window is 1600x1200.
    // if bg2_sprite.position.x < 3200  so reset when offset > 4800-1600 = 3200
    if (bg2_xOffset > (-3200 + 10))
    {
        sprite_bg2.move(-1.0f, 0.0f);
        bg2_xOffset -= 1.0f;

    }
    else
    {
        sprite_bg2.setPosition(sf::Vector2f(5.0f, 5.0f)); // absolute position
        bg2_xOffset = 0.0f;
    }
}

void StateOne::draw(sf::RenderWindow* window) 
{


    window->draw(sprite_bg2);
	//std::cout << " In StateOne.draw()\n";   //TEST
    window->draw(sprite_shooter);
}

void StateOne::endGameLogic() 
{

}
