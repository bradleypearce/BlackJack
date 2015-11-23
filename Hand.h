#pragma once

#include "Headers.h"

//* __CLASS__HAND__ 
/* This class is a container of cards that acts as the hand for the contestants in the Game.
 * It needs two cards to be initialised as that's the minimum number of cards a Hand can have.
 * This class is reletively simple but is enormously useful for containing cards in our game. 
 */
class Hand
{
public:
	Hand(Card* _one, Card* _two);

	void TakeCard(Card* _dealtcard);
	unsigned int GetValue();
	void DrawOneCard();

	void Draw();

	~Hand();
private:
	unsigned int m_value;
	Card* m_copy;
	std::vector<Card*> m_hand;
};

