#pragma once
#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

#include <SFML/Graphics.hpp>
#include "gameState.h"
//#include "stateOne.h"
//#include "stateTwo.h"
#include <iostream>


class GameManager
{
public:
	const static int SCREEN_WIDTH = 1600;
	const static int SCREEN_HEIGHT = 1200;
	static void start();
	static void gameLoop();
	enum State {Uninitialized, State1, State2,ExitGame};
	static void setState(State s);
	static GameState *getState();

private:
	static State _state;
	static GameState* _currentState;
	static GameState * _stateOne;
	static GameState * _stateTwo;
	static sf::RenderWindow _window;
	static sf::Clock _clock;
};

#endif