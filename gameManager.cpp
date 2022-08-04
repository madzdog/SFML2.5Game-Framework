//gameManager.cpp

#include "gameManager.h"
#include "gameState.h"
#include "stateOne.h"
#include "stateTwo.h"


sf::RenderWindow GameManager::_window;
sf::Clock GameManager::_clock;
GameManager::State GameManager::_state = Uninitialized;
GameState* GameManager::_stateOne;
GameState* GameManager::_stateTwo;
//GameState* GameManager::_currentState;


void GameManager::start() {
    if (_state != Uninitialized) return;

    // create main window
    _window.create(sf::VideoMode(GameManager::SCREEN_WIDTH, GameManager::SCREEN_HEIGHT, 32), "MadZDog Games");
    _window.setFramerateLimit(60);

    // create new scene classes based on Scene class and call their init()
    // Scene class has definitations for: init(), handleInput(), update(), and draw() 
    // for each scene.  Specific scene classes are based on the parent class Scene in gameState.h & gameState.cpp/
    _stateOne = new StateOne();   // have to include stateOne.h
    _stateOne->init();

    _stateTwo = new StateTwo();
    _stateTwo->init();
        
    gameLoop();

 
    _window.close();
}

void GameManager::gameLoop()
{

    //

    // load textures, fonts
    sf::Texture texture1;
    if (!texture1.loadFromFile("assets/shooter.bmp"))
    {
        std::cout << "ERROR could not load shooter.bmp";
    }
    sf::Sprite sprite_shooter;
    sprite_shooter.setTexture(texture1);



    bool exit = false;

    while (!exit)
    {
        // restart clock
        float timeElapsed = _clock.restart().asSeconds();

        _window.clear(sf::Color(255, 255, 255));

        // Handle input
        sf::Event event;
        while (_window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                _window.close();
                exit = true;
            }
        }

        // Update our entities
          //position shooter
        sprite_shooter.setPosition(sf::Vector2f(500.f, 400.f)); // absolute position
               
        _stateOne->update(timeElapsed);





        // Draw our new entities
        _window.draw(sprite_shooter);
        _stateOne->draw(&_window);


        // display the updated frame in the window
        _window.display();

    }
 
        //check game over flag
    
}




