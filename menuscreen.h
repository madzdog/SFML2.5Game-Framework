#ifndef MENUSCREEN_H
#define MENUSCREEN_H

#include "gameState.h"
class Menuscreen : public GameState
{
	void init() override;
	void handleInput(sf::Event* event) override;
	void update(float timeElapsed) override;
	void draw(sf::RenderWindow* window) override;
	void endGameLogic() override;
};


#endif //MENUSCREEN_H
