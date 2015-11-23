#pragma once

#include "Headers.h"

//* CLASS__CARD__
/* The card class is some simple behaviour to manage the value of each of our cards
 * along with any graphics and identifiers for our cards. Handling graphics for each  
 * individual card makes our Game class just worry about the logic of the game. We use
 * an enum to specify the suit of the card as well to make the code more readable.
 */

class Card
{
public:
	Card(unsigned int _value,unsigned int _suit);

	void Draw();
	unsigned int GetValue();
	unsigned int GetSuit();
	std::string GetName();

	~Card();

private: 
	std::string name; 
	unsigned int value;
	unsigned int suit_ident;

	typedef enum suit
	{
		DIAMONDS,

		HEARTS,

		CLUBS,

		SPADES
	};

	suit m_suit;
	std::string m_suitname;

};

