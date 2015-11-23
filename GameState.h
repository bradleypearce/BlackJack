#pragma once

#include "Headers.h"

/** CLASS__GAME_STATE__
/* For more complex behaviour, a simple state machine like a switch statement won't do. 
 * Memory is taken by objects that aren't even in use and the code becomes harder to 
 * maintain. To avoid this, we create a base class GameState which will have 3 virtual 
 * functions: Update, Draw and CheckEvents. These function, because they are virtual,an 
 * inherited object of GameState can be called and a version of that function will be executed.
 * This comes in handy for our main loop where our Gamestatemanager calls our virtual functions. 
 * We need to forward declare Gamestatemanager here so our gamestates can make use of its 
 * functions like transitioning between states. 
 */
class GameStateManager;

class GameState
{
public:
	GameState(GameStateManager* _gamestatemanager);
	virtual ~GameState() {};

	virtual bool Update() = 0;
	virtual void Draw() = 0;
	virtual void CheckEvents() = 0;
protected: 
	GameStateManager* m_gamestatemanager;
};

