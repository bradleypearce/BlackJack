#include "Player.h"

/* Constructor - The player shouldn't be initialised until they have cards to play with
 * which is appropriate for the scale of the application. We add the cards to the hand and 
 * assign the value of hand to our handvalue variable and assign our local pointer to dealer 
 * to our passed in dealer.
 * 
 * NOTE: Regrettably, i would have liked to expand the logic of the dealer class by changing the player's 
 * reliance on the dealer being initialised. This however would've required going over some of the fundamental 
 * concepts in the design and therefore more time so ensure overall quality of the implementation.  
 */
Player::Player(Card* _one, Card* _two, Dealer* _dealer)
{
	m_hand = new Hand(_one, _two);

	m_handvalue = m_hand->GetValue();

	m_dealer = _dealer;
}

/* Deconstructor - We delete our m_hand here, delete m_dealer causes errors 
 */
Player::~Player()
{
	delete m_hand;
	delete m_dealer;
}

/* Take Card - This function essential acts as a middleman between the hand and the card passed to the player
 * this means we can encapsulate our hands to our 'players' as it were and making interfacing in Game simpler. 
 * The m_hand function simply adds a card to the list in m_hand. 
 */
void Player::TakeCard(Card* _dealtcard)
{
	m_hand->TakeCard(_dealtcard);
}

/* Draw - Just calls the hand's draw function
 */
void Player::Draw()
{
	m_hand->Draw();
}

/* GetHandValue - Returns the value of the player's hand
 */
unsigned int Player::GetHandValue()
{
	return m_hand->GetValue();
}

/* Update - To tidy game up slightly, i've embedded the hit logic in the player class
 * this is last minute modification to the design which still works the same, it just
 * encapsulates more logic in the player class to keep it maintainable.
 */
bool Player::Update(unsigned int _input)
{
	bool input_valid = false;

	while(!input_valid)
	{
		switch(_input)
		{
		case 1:
			this->TakeCard(m_dealer->GiveCard());
			std::cout << "New card given\n" << std::endl;
			input_valid = true;
			break;

		case 2:
			std::cout << "No card given\n" << std::endl;
			input_valid = true;
			break;
		default:
			std::cout << "Not an available option, try again" << std::endl;
			std::cin >> _input;
			break;
		}
	}

	return true;
}