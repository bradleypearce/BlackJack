#include "Headers.h"

/* Constructor - Here we assign our associated objects and variables
 */
Dealer::Dealer()
{
	m_deck = new Deck;
	m_hand = new Hand(NULL,NULL);
	m_handvalue = 0;
}

/* Deconstructor - Deletes the deck, hand and dealtcard. 
 */
Dealer::~Dealer()
{
	delete m_deck;
	delete m_hand;
	delete m_dealtcard;
}

/* ShuffleDeck - This simply calls the shuffle function from deck, 
 * this allows us to shuffle the deck anytime in Game
 */
void Dealer::ShuffleDeck()
{
	m_deck->Shuffle();
}

/* HitSelf - This simply takes the top card from the deck
 */
void Dealer::HitSelf()
{
	m_hand->TakeCard(&m_deck->GetTopCard());
}

/* Draw - This calls the hand's draw function
 */
void Dealer::Draw()
{
	m_hand->Draw();
}

/* GiveCard - This returns a copy of the top card 
 * from the deck. To be used to pass cards to the 
 * player. 
 */
Card* Dealer::GiveCard()
{
	m_dealtcard = &m_deck->GetTopCard();

	Card* copy = new Card(m_dealtcard->GetValue(), m_dealtcard->GetSuit());

	return copy;
}

/* Dealtoself - Initialises the dealers hand
 */
void Dealer::Dealtoself()
{
	m_hand = new Hand(GiveCard(),GiveCard());
}

/* CheckHand - The dealer will check if the hand
 * is less thank 17, if it is then the dealer takes 
 * a card from the deck through hitself. 
 */
void Dealer::CheckHand()
{
	m_handvalue = m_hand->GetValue();

	if(m_handvalue < 17)
	{
		HitSelf();
	}
}

/* GetHandValue - returns the value of the dealer's hand
 */
unsigned int Dealer::GetHandValue()
{
	return m_hand->GetValue();
}

/* DrawOneCard - Draws one card from the dealer's hand through 
 * the hand's drawone card function
 */
void Dealer::DrawOneCard()
{
	m_hand->DrawOneCard();
}

/* Update - This calls Checkhand so interfacing in main is easier
 */
bool Dealer::Update()
{
	CheckHand();

	return true;
}

