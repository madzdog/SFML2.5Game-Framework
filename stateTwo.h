#pragma once
#ifndef STATE_TWO_H
#define STATE_TWO_H

#include "gameState.h"
class StateTwo : public GameState
{
	void init() override;
	void handleInput(sf::Event* event) override;
	void update(float timeElapsed) override;
	void draw(sf::RenderWindow* window) override;
	void endGameLogic() override;
};


#endif