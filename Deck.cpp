#include "Headers.h"

/* Constructor - We use two for loops to instantiate all the 
 * possible cards that can be in the deck. We start by using i 
 * as the suit identifier and j in the nested for loop for the 
 * card's identifier. This results in a full deck 1 - 13 for each suit. 
 */
Deck::Deck()
{
	for(unsigned int i = 0; i < 4; i++)
	{
		for(unsigned int j = 1; j < 14; j++)
		{
			m_deck.push_back(new Card(j,i));
		}
	}
}

/* Deconstructor - We use a simple for loop to delete 
 * all the objects in our vectors when destroyed. 
 */
Deck::~Deck()
{
	for (unsigned int i = 0; i < m_deck.size(); i++)
	{
		delete m_deck.at(i);
	}

	for (unsigned int i = 0; i < m_deck.size(); i++)
	{
		delete m_tempdeck.at(i);
	}
}

/* Draw - We loop through all the cards in the deck and draw them
 * this isn't used in the game I added this for debugging purposes 
 */
void Deck::Draw()
{
	for(unsigned int i = 0; i < m_deck.size();i++)
	{
		m_deck.at(i)->Draw();
	}
}

/* Shuffle - This method of shuffling is as close to random as possible. 
 * We start by seeding rand and then use a for loop to instantiate i and 
 * then every loop we do, it randomises i to a value between 0 and the size
 * of deck. We then add the card we randomly selected from deck to a temporary 
 * deck. We can't use i as the condition of our loop as it changes every loop. 
 * We use counter to keep track of how many cards we've done. Then to get the cards 
 * back in the original deck, we do the same but vice versa. This results in a random 
 * deck order every game played. 
 */
void Deck::Shuffle()
{
	std::srand(time(NULL));

	unsigned int counter = 0;

	for(unsigned int i = 0; counter < m_deck.size();counter++)
	{
		i = std::rand() % m_deck.size();
		
		m_tempdeck.push_back(m_deck.at(i));
	}

	m_deck.clear();

	counter = 0;

	for(unsigned int i = 0; counter < m_tempdeck.size(); counter++)
	{
		i = std::rand() % m_tempdeck.size();
		m_deck.push_back(m_tempdeck.at(i));
	}

	m_tempdeck.clear();

}

/* GetTopCard - Returns creates a copy of the first card 
 * in the deck, delete that card and then returns the copy. 
 * This mitigates any chance a copy of a card is created. 
 */
Card Deck::GetTopCard()
{
	Card topcard = (*m_deck.back());

	m_deck.pop_back();

	return topcard;
}
