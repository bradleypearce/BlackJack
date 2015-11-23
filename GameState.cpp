#include "Headers.h"

/* Constructor - We assign the passed in gamestatemanager to the 
 * pointer member to gamestatemanager so versions of Gamestate can
 * make use of it's functions (transitions between states).
 */
GameState::GameState(GameStateManager* _gamestatemanager)
{
	this->m_gamestatemanager = _gamestatemanager;
}

