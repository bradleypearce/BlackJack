#pragma once

#include "Headers.h"

//* CLASS__MENU__ 
/* This class is designed to be primarily the exit to our program. The program control flow shouldn't allow 
 * for the player to exit the game whilst playing the main game. Therefore, we use a Menu state to contain the exit 
 * and also be an entrance to the main game. This means that we can separate logic easier and a controlled exit is 
 * far more achievable.
 */

class Menu : public GameState
{
public:
	Menu(GameStateManager* _gamestatemanager);
	
	bool Update();
	void Draw();
	void CheckEvents();
private: 
	int m_input;
	std::string m_input_str;
	bool m_running;
	char m_option[100];
	bool m_option_valid;
};

