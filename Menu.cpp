#include "Headers.h"

/* Constructor - Just initialise our bool variables to true. 
 */
Menu::Menu(GameStateManager *_gamestatemanager) : GameState(_gamestatemanager)
{
	m_running = true;
	m_option_valid = false;
}

/* CheckEvents - We call this to check the details of an event, such as 
 * if what input was entered. We use a switch statement to decide what to 
 * do next as it's a simpler way of seperating out specific behaviour.
 * Case 1 simply transitions to our Game class, Case 2 will explain how the game works
 * and Case 3 is a controlled exit to our program by checking the answer given when asked to enter
 * a option. Input checking checks if the answer given is a single character answer and if it's valid
 * to stop errors at run time.
 */
void Menu::CheckEvents()
{
	switch(m_input)
	{
	case 1: 
		system("cls"); 
		m_gamestatemanager->ChangeState(new Game(m_gamestatemanager));
		break;

	case 2: 
		system("cls");
		std::cout << "\t\t HOW TO PLAY BLACKJACK" << std::endl 
			<< std::endl << " - You start with two cards.\n\n"  
			<< " - Your hand cannot exceed 21.\n\n" 
			<< " - There are 2 rounds in BlackJack, you may request a card each round -\n or you can stick with your cards.\n\n"
			<< " - Aces are worth 11 unless your hand goes over 21, it is then worth 1.\n\n"
			<< " - Kings, Queens and Jacks are worth 10 each.\n\n"
			<< " - Other numbered cards are worth they're named value.\n\n"
			<< " - The player with the highest cards wins (unless it's over 21)!\n\n" 
			<< "Refreshing screen on keypress\n\n" << std::endl;

		std::cin.get();
		std::cin.get();
		system("cls");
			
		break;

	case 3: 
		system("cls");

		std::cout << "Are you sure you want to exit the program? Y/N" << std::endl;
		std::cin >> m_option; 

		if(std::strlen(m_option) < 2) 
		{
			if(strcmp(m_option,"Y") == 0 || std::strcmp(m_option,"y") == 0 
				|| std::strcmp(m_option,"N") == 0 || std::strcmp(m_option,"n") == 0 
				|| std::strcmp(m_option,"n") == 0)
			{
				if(std::strcmp(m_option,"y") == 0 || std::strcmp(m_option,"Y") == 0)
				{
					m_running = false;
				}
				else if(std::strcmp(m_option,"n") == 0 || std::strcmp(m_option,"N") == 0)
				{
					std::cout << std::endl << "Refreshing on enter key press";
					std::cin.get();
					std::cin.get();
					system("cls");
				}
			}
			else
			{
				std::cout << m_option << " is not an available option, please try again" << std::endl;
				std::cout << std::endl << "Refreshing on enter key press";
				std::cin.get();
				std::cin.get();
				system("cls");
			}
		}
		else
		{
			std::cout << m_option << " is not a single character answer, please try again" << std::endl;
			std::cout << std::endl << "Refreshing on enter key press";
			std::cin.get();
			std::cin.get();
			system("cls");
		}
		break;

	default: 
		std::cout << m_input << "is not an available option, please try again" << std::endl;
		std::cin.get();
		std::cin.get();
		system("cls");
	}
}

/* Update - This simply asks the user to enter a number before going into check events. 
 * Check Events will not be called if input is not a digit. It returns the value of exit 
 * which will decide if the program should terminate or not. In Check Events, we assign running 
 * to false if we want to close the program.
 */
bool Menu::Update()
{
	std::cin >> m_input_str;

	if(m_input_str == "1")
	{
		m_input = 1;
	}
	else if(m_input_str == "2")
	{
		m_input = 2;
	}
	else if(m_input_str == "3")
	{
		m_input = 3;
	}
	else
	{
		m_input = 4;
	}

	if(m_input == 1 || m_input == 2 || m_input == 3)
	{
		CheckEvents();
	}
	else
	{
		system("cls");
		std::cout << m_input_str << " is not an available option, please try again\n Refreshing on keypress" << std::endl;
		std::cin.get();
		std::cin.get();
		system("cls");
	}

	return m_running;
}

/* Draw - This simply outputs the below text to the screen.   
 */
void Menu::Draw()
{
	std::cout << std::endl << "WELCOME TO BLACKJACK!" << std::endl << std::endl
						   << "Please select from one of the following options:" << std::endl << std::endl 
						   << "1: New Game" << std::endl << std::endl
						   << "2: How To Play" << std::endl << std::endl
						   << "3: Exit Game" << std::endl << std::endl;
}
