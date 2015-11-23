#pragma once

#include "Headers.h"

//* __CLASS__DECK__ 
/* This class is a container class for cards, this will acts as our Deck of cards and will 
 * provide for our hands. This also shuffles the cards so they are not in numerical or any
 * particular order so it will feel authentic when playing. 
 */
class Deck
{
public:
	Deck();

	void Draw();
	void Shuffle();
	Card GetTopCard();

	~Deck();
private:
	std::vector<Card*> m_deck;
	std::vector<Card*> m_tempdeck;
};

