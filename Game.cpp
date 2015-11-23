#include "Headers.h"

/* Constructor - On game start, we create a new dealer and then shuffle the deck
 * the deck is initialised in order so without shuffling the game wouldn't be fair.
 * We then deal the cards out to the player and the dealer, set the current round as 1 
 * and initialise our exit variable as false.
 */
Game::Game(GameStateManager* _gamestatemanager) : GameState(_gamestatemanager)
{
	m_dealer = new Dealer();

	m_dealer->ShuffleDeck();

	m_dealer->Dealtoself();

	m_player = new Player(m_dealer->GiveCard(),m_dealer->GiveCard(), m_dealer);

	m_round = 1;

	

	m_exit = false;
}

/* Deconstructor - Have tried to delete dealer and player but kept 
 * getting memory allocation issues. 
 */
Game::~Game()
{
	
}

/* Update - This function checks what state the game is in but using a switch statement.
 * we use the round variable to signify what round it is and choose behaviour based off that value.
 * In round 1 of blackjack, the player is able to hit, this is also true in round 2. In round 3 however, 
 * the cards are revealed and the game must then decide who won. We check if the player won by checking if their
 * hand went over 21 and if the players hand is more than the dealers or if the dealer's hand went over 21. If the values
 * are anything else then the player loses. We also decide if the player has lost before the third round by checking the dealer's 
 * hand and player's. If either the dealer or player has gone bust or if the dealer has 21 then we skip straight to round 3 and decide 
 * who won. 
 * 
 * Known Errors: 1: - m_input is by design an int value. If whats entered is anything other than a number the program will close due to an assertion error. 
 *				    - I tried to solve this by changing m_input to a char however this resulted in the program entering an endless loop as the switch statement
 *				    - in player.update wouldn't operate correctly. To solve in a neat and appropriate way would require changing much of the design which i am
 *					- currently unwilling to do. This error is also present in the Menu class. 
 */
bool Game::Update()
{
	switch(m_round)
	{
	case 1: 
		std::cout << std::endl << "Hit?\n" << std::endl
			<< "1. Yes	2.No" << std::endl;
		
		std::cin >> m_input_str;

		if(m_input_str == "1")
		{
			m_input = 1;
		}
		else if(m_input_str == "2")
		{
			m_input = 2;
		}
		else
		{
			m_input = 3;
		}
		
		if(m_input == 1 || m_input == 2)
		{
			CheckEvents();
			m_dealer->Update();
		}
		else
		{
			system("cls");
			std::cout << m_input_str << " is not an available option, please try again" << std::endl;
		}
		break;

	case 2: 
		std::cout << std::endl << "Hit?\n" << std::endl
			<< "1. Yes	2.No" << std::endl;
		
		std::cin >> m_input_str;

		if(m_input_str == "1")
		{
			m_input = 1;
		}
		else if(m_input_str == "2")
		{
			m_input = 2;
		}
		else
		{
			m_input = 3;
		}
		
		if(m_input == 1 || m_input == 2)
		{
			CheckEvents();
			m_dealer->Update();
		}
		else
		{
			system("cls");
			std::cout << m_input << "is not an available option, please try again" << std::endl;
		}
		break;

	case 3:
		if(m_player->GetHandValue() > m_dealer->GetHandValue() && m_player->GetHandValue() < 22 && m_dealer->GetHandValue() < 22 || m_dealer->GetHandValue() > 21 && m_player->GetHandValue() < 22)
		{
			std::cout << "You:" << m_player->GetHandValue() << " > " << "Dealer:" << m_dealer->GetHandValue() << std::endl;
			std::cout << "Congratulations! You Won!" << std::endl;
		}
		else
		{
			std::cout << "You:" << m_player->GetHandValue() << " < " << "Dealer:" << m_dealer->GetHandValue() << std::endl;
			std::cout << "Sorry, you lost" << std::endl;
		}

		m_exit = true;
		break;

	default:
		std::cerr << "A horrible error has occurred";
		break;
	}

	if(m_player->GetHandValue() > 21 || m_dealer->GetHandValue() > 21 || m_round == 3 || m_dealer->GetHandValue() == 21)
	{
		m_round = 3;
	}
	else
	{
		if(m_input == 1 || m_input == 2)
		{
			m_round++;
		}
	}

	std::cout << std::endl << "Refreshing screen on keypress" << std::endl;
	std::cin.get();
	std::cin.get();
	system("cls");

	if(m_exit)
	{
		m_gamestatemanager->ChangeState(new Menu(m_gamestatemanager));
	}

	return true;
}

/* CheckEvents - Here we just check if the input was a number and if it was we call player.update 
 * and the switch statemachine in there handles any logic specific to this input. 
 */
void Game::CheckEvents()
{
	if(isdigit(m_input)==0)
	{
		m_player->Update(m_input);
	}
	else
	{
		std::cout << "Not an available option, try again" << std::endl;
		std::cin >> m_input_str;
	}
}

/* Draw - Here we draw what we can see of the dealers hand depending on what round it is and of course the player's hand. 
 * In order to see the correct value and correct amount of cards in the hand we need to refresh draw by exiting the loop
 * and coming back to draw after a card has been taken. This happens above in check events and update.
 */
void Game::Draw()
{
	system("CLS");
	std::cout 
		<< "===================================================" << std::endl
		<< "                      BLACKJACK                    " << std::endl
		<< "===================================================" << std::endl << std::endl;
	std::cout << "Round:" << m_round << std::endl;
	std::cout << "DEALERS HAND:\n" << std::endl;
	switch(m_round)
	{
	case 1: 
		std::cout << "Dealer's Hand is hidden\n" << std::endl;
		break;
	case 2:	
		m_dealer->DrawOneCard();
		break;
	case 3:
		m_dealer->Draw();
		std::cout << m_dealer->GetHandValue() << std::endl;
		break;
	}
	std::cout << "Your HAND:\n" << m_player->GetHandValue() << std::endl;
	m_player->Draw();
}