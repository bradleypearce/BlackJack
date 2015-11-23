#include "Headers.h"

/* Constructor - Requires two cards to instantiate, it prevents a hand 
 * potentially having less than two cards. We just add the two passed
 * in cards to the vector.
 */
Hand::Hand(Card* _one, Card* _two)
{
	m_hand.push_back(_one);
	m_hand.push_back(_two);
}

/* Deconstructor - We delete anything in the list of cards 
 * and delete the m_copy pointer. 
 */
Hand::~Hand()
{
	for (unsigned int i = 0; i < m_hand.size(); i++)
	{
		delete m_hand.at(i);
	}

	delete m_copy;

}

/* TakeCard - This function essentially creates of a copy
 * of the passed in card and pushes it back into the list
 * of cards in the hand. The card is not able to be transfered 
 * to the hand without a copy being created. 
 */
void Hand::TakeCard(Card* _dealtcard)
{
	m_copy = new Card(_dealtcard->GetValue(),_dealtcard->GetSuit());

	m_hand.push_back(m_copy);
}

/* Draw - Simply calls craw for every card in the list
 */
void Hand::Draw()
{
	for(unsigned int i = 0; i < m_hand.size(); i++)
	{
		m_hand.at(i)->Draw();
	}
}

/* DrawOneCard - This function is for our dealer class
 * acting as a middleman we just draw the first card in 
 * the dealers hand.
 */
void Hand::DrawOneCard()
{
	unsigned int i = 0; 

	m_hand.at(i)->Draw();
}

/* GetValue - This function returns the total value of the hand.
 * In order to get the correct values we check if they're not face 
 * cards and if not we add the value of the card. If they're face cards 
 * we assign it's designated value. At the end we check if the hand 
 * has an ace and the hand has gone over 21. If it has we assume
 * the contestant wants the ace to be a 1. We cheat this 
 * by minusing 10. 
 */
unsigned int Hand::GetValue()
{
	m_value = 0;

	for(unsigned int i = 0; i < m_hand.size();i++)
	{
		if(m_hand.at(i)->GetName() == "A")
		{
			m_value += 11;
		}
		else if(m_hand.at(i)->GetName() == "K")
		{
			m_value += 10;
		}
		else if(m_hand.at(i)->GetName() == "Q")
		{
			m_value += 10;
		}
		else if(m_hand.at(i)->GetName() == "J")
		{
			m_value += 10;
		}
		else
		{
			m_value += m_hand.at(i)->GetValue();
		}
	}

	for(unsigned int i = 0; i < m_hand.size();i++)
	{
		if(m_hand.at(i)->GetName() == "A" && m_value > 21)
		{
			m_value -= 10;
		}
	}

	return m_value;
}
