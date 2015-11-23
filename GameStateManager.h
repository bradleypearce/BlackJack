#include "Headers.h"

//** __GAME_STATE_MANAGER___ 
/** GameStateManager acts as a container class for our GameStates. This class allows us to
 *  change states and automatically manages memory between states. It's here we can call 
 *  our versions of Update and draw as well. This was designed to not be specific to rendering
 *  so it can be used in console or a graphics application. We refer to our Gamestates as the list for simplicity. 
 *  A forward declaration of Gamestate is required due to compiler errors. 
 */

class GameState;

class GameStateManager
{
public:
	~GameStateManager();

	void AddState(GameState* _gamestate);
	void ChangeState(GameState* _gamestate);

	bool Update();
	void Draw();
private:
	std::vector<GameState*> m_GameStates;
};

