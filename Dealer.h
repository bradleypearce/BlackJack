#pragma once

#include "Headers.h"

class Deck;

class Player;

//* __CLASS__DEALER__ 
/* This class is to act as a contestant for the player in the Game state and to also be
 * the interface for the deck in our game. The dealer was designed to 'deal' so to speak. 
 * Above we need to forward declare deck and player due to compiler errors when developing. 
 */
class Dealer
{
public:
	Dealer();

	void ShuffleDeck();
	void HitSelf();
	bool Update();
	void Draw();
	void DrawOneCard();
	Card* GiveCard();
	void Dealtoself();
	void CheckHand();
	unsigned int GetHandValue();

	~Dealer();
private:
	unsigned int m_handvalue;
	Deck* m_deck;
	Hand* m_hand;
	Card* m_dealtcard;
};

