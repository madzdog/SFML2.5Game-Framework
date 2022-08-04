#pragma once
#ifndef STATE_ONE_H
#define STATE_ONE_H

#include "gameState.h"
class StateOne : public GameState
{
	void init() override;
	void handleInput(sf::Event* event) override;
	void update(float timeElapsed) override;
	void draw(sf::RenderWindow* window) override;
	void endGameLogic() override;
};


#endif

