/** 
 * CONSOLE BLACKJACK 
 * By Bradley Pearce
 * Games Programming
 * Bournemouth University, 2015
 * Last Updated 20/11/15
 */

//** __HEADERS.H__
/** To make the program as maintainable as possible during development, all header files are included in headers.h
 */
#include "Headers.h"

//** __MAIN__
/** For main I wanted a simple and maintainable game loop. I designed the state machine so that 
 * whether were using console, SFML, SDL or any graphics library, main wouldn't need to change very
 * much. 
 */
int main()
{
	bool running = true; 

//** __STATE_MACHINE__ 
/* * Here we instantiate the main element of our state machine, the gamestatemanager. This object helps control 
 * where the user is in the program and is far more memory efficient as states and any variables using memory 
 * are destroyed. Gamestate transitions are all handled within the GameStates methods apart from the first 
 * state added below.
 */

	GameStateManager gamestatemanager;
	gamestatemanager.ChangeState(new Menu(&gamestatemanager));

//** __GAME_LOOP__
/* Our game loop we know is going to execute atleast once, so we begin with a do while loop. As the implementation is in console 
 * and certain functions freeze the flow of the program at certain points, we execute draw first so text is drawn on the screen 
 * before the program asks for input from the user. Update returns a bool value so we assign running to the value of update. The loop 
 * condition is whether update is equal to true. If so it will go round again. The program ends when running is equal to false.
 */
	do
	{
		gamestatemanager.Draw();

		running = gamestatemanager.Update();
	}
	while(running);

	return 0;
}