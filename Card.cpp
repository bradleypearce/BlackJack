#include "Headers.h"

/* Constructor - Here we specify the value and suit of the card 
 * we use a switch statement to handle the suit and then name 
 * the card based on it's value. Unfortunately, trial and error
 * found that hardcoding all the values was the best way. 
 *
 * TO DO LIST: Can a loop name the card to tidy this function up?
 */
Card::Card(unsigned int _value,unsigned int _suit)
{
	this->value = _value;

	if(value > 13)
	{
		value = 13;
	}

	suit_ident = _suit;
	
	switch(_suit)
	{
		case 0: 
			m_suit = DIAMONDS;
			break;

		case 1: 
			m_suit = HEARTS;
			break;

		case 2: 
			m_suit = CLUBS;
			break;

		case 3:
			m_suit = SPADES;
			break;
	}

	if(value == 1)
	{
		name = 'A';
	}
	if(value == 2)
	{
		name = '2';
	}
	if(value == 3)
	{
		name = '3';
	}
	if(value == 4)
	{
		name = '4';
	}
	if(value == 5)
	{
		name = '5';
	}
	if(value == 6)
	{
		name = '6';
	}
	if(value == 7)
	{
		name = '7';
	}
	if(value == 8)
	{
		name = '8';
	}
	if(value == 9)
	{
		name = '9';
	}
	if(value == 10)
	{
		name = "10";
	}
	if(value == 11)
	{
		name = 'J';
	}
	if(value == 12)
	{
		name = 'Q';
	}
	if(value == 13)
	{
		name = 'K';
	}
	
	switch(m_suit)
	{
	case DIAMONDS:
		m_suitname = "DIAMONDS";
		break;
	case HEARTS: 
		m_suitname = "HEARTS"; 
		break;
	case CLUBS:
		m_suitname = "CLUBS";
		break;
	case SPADES: 
		m_suitname = "SPADES";
		break;
	}
}

/* Deconstructor - no objects to destroy 
 */
Card::~Card()
{
}

/* Draw - Each card is given a template 'graphic' and we place in
 * the cards value and suit name. This helps the player visualise the 
 * game easier. 
 */
void Card::Draw()
{
	std::cout << std::endl 
		<< "=============================" << std::endl
		<< "|| "<<name<<"			   ||" << std::endl
		<< "||                         ||" << std::endl
		<< "||	                   ||" << std::endl
		<< "||        "<<m_suitname.c_str()<<"           ||"<< std::endl
		<< "||                         ||" << std::endl
		<< "||                         ||" << std::endl
		<< "||		      "<< name <<"    ||" << std::endl
		<< "=============================" << std::endl;
}

/* GetValue - Returns value of card. 
 */
unsigned int Card::GetValue()
{
	return value;
}

/* GetSuit - Returns the number identifier for suit.
 */
unsigned int Card::GetSuit()
{
	return suit_ident;
}

/* GetName - Returns the card identifier for name such as K, Q, J ect. 
 */
std::string Card::GetName()
{
	return name;
}
