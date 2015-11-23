#include "Headers.h"

/* Deconstructor - we only need to erase anything 
 * from the list at this point */
GameStateManager::~GameStateManager() 
{
	for (unsigned int i = 0; i < m_GameStates.size(); i++)
	{
		delete m_GameStates.at(i);
	}
}

/* AddState - this will get called when we want to add
 * a new state to the states list of states in use */
void GameStateManager::AddState(GameState* _gamestate)
{
	//add it to the states list and cout a message about it
	m_GameStates.push_back(_gamestate);
}

/* ChangeState - this will get called we want to add a 
 * state and know that it will be the only one in use,
 * i.e. we clear the list before adding the new one */
void GameStateManager::ChangeState(GameState* _gamestate) 
{
	//delete any states that are in the list
	for (unsigned int i = 0; i < m_GameStates.size(); i++)
	{
		delete m_GameStates.at(i);
	}

	//clear list of states and add just the state we were passed
	m_GameStates.clear();
	AddState(_gamestate);
}

/* Update - only the last state in the list should be updated */
bool GameStateManager::Update() 
{
	if (m_GameStates.size() > 0)
	{
		return m_GameStates.back()->Update();
	}
	else
	{
		return true;
	}
}
 /* Draw - draw all states in the list */
void GameStateManager::Draw() 
{
	for (unsigned int i = 0; i < m_GameStates.size(); i++)
	{
		m_GameStates.at(i)->Draw();
	}
}
