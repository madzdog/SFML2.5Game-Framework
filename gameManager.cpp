//gameManager.cpp

#include "gameManager.h"
#include "gameState.h"
#include "splashscreen.h"
#include "menuscreen.h"
#include "stateOne.h"
#include "stateTwo.h"


sf::RenderWindow GameManager::_window;
sf::Clock GameManager::_clock;


GameManager::State GameManager::_state = Uninitialized;
GameState* GameManager::_splashscreen;
GameState* GameManager::_menuscreen;
GameState* GameManager::_stateOne;
GameState* GameManager::_stateTwo;
GameState* GameManager::_currentState;


void GameManager::start() 
{
    if (_state != Uninitialized) return;

    // create main window
    _window.create(sf::VideoMode(GameManager::SCREEN_WIDTH, GameManager::SCREEN_HEIGHT, 32), "MadZDog Games");
    _window.setFramerateLimit(60);

    // create new scene. i.e state, classes based on state class and call their init()
    // State class has definitations for: init(), handleInput(), update(), and draw() 
    // for each scene.  Specific state classes are based on the parent class State/
    _splashscreen = new Splashscreen();   // have to include splashscreen.h
    _splashscreen->init();

    _menuscreen = new Menuscreen();  // add menuscreen.h
    _menuscreen->init();
    
    _stateOne = new StateOne();   // have to include stateOne.h
    _stateOne->init();

    _stateTwo = new StateTwo();
    _stateTwo->init();
     
    //Start the program on the splashscreen
    _state = SplashScreen;
    //_state = State1;

    gameLoop();

// need to put in delete of objectInstances here 
    delete _splashscreen;
    delete _menuscreen;
    delete _stateOne;
    delete _stateTwo;


    _window.close();
}

void GameManager::gameLoop()
{

    // bool exit = false;

    while (_state != ExitGame)
    {
        // restart clock
        float timeElapsed = _clock.restart().asSeconds();

        _window.clear(sf::Color(255, 255, 255));

        // change the game states here ==========
        // I need to learn how Map class works to replace this 
        //switch with a Key:Value class !
        switch (_state)
        {
        case GameManager::Uninitialized:
            _currentState = _stateTwo;  
            break;
        case GameManager::SplashScreen:
            _currentState = _splashscreen;
            break;
        case GameManager::MenuScreen:
            _currentState = _menuscreen;
            break;
        case GameManager::State1:
            _currentState = _stateOne;
            break;
        case GameManager::State2:
            _currentState = _stateTwo;
            break;
        case GameManager::ExitGame: 
            break;
        default:
            break;
        }


        // Handle input
        sf::Event event;
       while (_window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                _window.close();
            //    exit = true;
                _state = ExitGame;  //get out of gameloop
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
 
        //here - check game over flag run endGameLogic
    
}

void GameManager::setState(GameManager::State s)
{
    _state = s;

}


static GameState* getState()
{
//    return _state;
}




