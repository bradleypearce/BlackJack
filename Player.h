#pragma once

#include "Headers.h"

class Dealer;

//* __CLASS__PLAYER__ 
/* This class is contain the player's hand and to receive cards from the dealer. 
 * In order to receive cards from the dealer we need a pointer to the dealer in game
 * which is passed in on instantiation as a parameter.
 * To use dealer we need to forward declare the class Dealer. 
 */
class Player
{
public:
	Player(Card* _one, Card* _two, Dealer* _dealer);

	void TakeCard(Card* _dealtcard);
	bool Update(unsigned int _input);
	void Draw();
	unsigned int GetHandValue();

	~Player();
private: 
	unsigned int m_handvalue;
	Hand* m_hand;
	Dealer* m_dealer;
};


