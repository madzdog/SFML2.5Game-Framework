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
GameState* GameManager::_currentState;


void GameManager::start() 
{
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
     
    _currentState = _stateOne;


    gameLoop();

 
    _window.close();
}

void GameManager::gameLoop()
{

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
            // HandleInputs in current state
            _currentState->handleInput(&event);
        }
            
        

        // Update our entities in the currentState
        _currentState->update(timeElapsed);


        // Draw our new entities in the currentState
        _currentState->draw(&_window);
         

        // display the updated frame in the window
        _window.display();

    }
 
        //check game over flag run endGameLogic
    
}

static void setState(GameManager::State s)
{
    //_state - s;
}


static GameState* getState()
{
//    return _state;
}




