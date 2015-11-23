#pragma once

#include "Headers.h"

//* __CLASS__GAME__ 
/* This class is primarily to play blackjack on. It contains our player and our delear 
 * which should be all we need to interact with in this class as the dealer handles the 
 * playable deck and distributing cards to the player. This class should only need to handle 
 * the rules of game and the input provided by the player.
 */
class Game : public GameState
{
public:
	Game(GameStateManager* _gamestatemanager);

	bool Update();
	void Draw();
	void CheckEvents();

	~Game();
private:
	bool m_input_valid;
	unsigned int m_input;
	std::string m_input_str;
	int m_round;
	bool m_exit;
	Dealer* m_dealer;
	Player* m_player;
};

