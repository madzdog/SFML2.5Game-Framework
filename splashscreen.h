//#pragma once
#ifndef SPLASHSCREEN_H
#define SPLASHSCREEN_H

#include "gameState.h"
class Splashscreen : public GameState
{
	void init() override;
	void handleInput(sf::Event* event) override;
	void update(float timeElapsed) override;
	void draw(sf::RenderWindow* window) override;
	void endGameLogic() override;
};


#endif //SPLASHSCREEN_H

