// trainer.cpp
#include <iostream>
#include "trainer.h"
#include "pokemon.h"
#include "action.h"
#include "move_library.h"


Trainer::Trainer(std::string trainerName_in) : m_name(trainerName_in), m_activePokemon(-1), m_canBattle(true)
{
	
}

Trainer::~Trainer()
{
	// Release dynamically allocated pokemon
	for (int i = 0; i < m_party.size(); i++)
	{
		delete m_party[i];
		m_party[i] = nullptr;
	}
}

int Trainer::choosePokemon()
{
	std::cout << m_name << ", choose a Pokemon.\n";
	int chosen = -1;
	for (int i = 0; i < m_party.size(); i++)
	{
		std::cout << "[" << i << "]\n";
		m_party[i]->print();
	}
	while (chosen == -1)
	{
		std::cin >> chosen;
		if (chosen >= 0 && chosen < m_party.size())
		{
			if (chosen == m_activePokemon)
			{
				std::cout << "Invalid index. Cannot choose active Pokemon.\n";
				chosen = -1;
			}
			else if (m_party[chosen]->m_status == FNT)
			{
				std::cout << "Invalid index. Choose a Pokemon that is not fainted.\n";
				chosen = -1;
			}
		}
		else 
		{
			std::cout << "Invalid index. Choose a Pokemon between 0 and " << m_party.size() - 1 << "\n";
			chosen = -1;
		}
	}
	std::cout << m_party[chosen]->m_name << " will be sent out.\n";
	return chosen;
}

Action * Trainer::chooseAction()
{
	std::cout << m_name << ", choose an action.\n";
	std::cout << "[0] Fight\n[1] Switch\n";
	int chosen = -1;
	while (chosen == -1)
	{
		std::cin >> chosen;
		if (chosen != 0 && chosen != 1)
		{
			std::cout << "Invalid choice!\n";
			chosen = -1;
		}
		if (chosen == 1)
		{
			int numAvailablePokemon = 0;
			for (int i = 0; i < m_party.size(); i++)
			{
				if (m_party[i]->m_status != FNT)
				{
					numAvailablePokemon++;
				}
			}
			if (numAvailablePokemon < 2)
			{
				std::cout << "No available Pokemon to switch to!\n";
				chosen = -1;
			}
		}
	}
	// Fight - prompt for the move.
	if (chosen == 0)
	{
		Pokemon * currentPokemon = m_party[m_activePokemon];
		if (!currentPokemon->ppAvailable())
		{
			return (Action *) new Struggle();
		}

		for (int i = 0; i < 4; i++)
		{
			std::cout << "[" << i << "] ";
			if (currentPokemon->m_moves[i] == nullptr)
			{
				std::cout << "---\n";
			}
			else
			{
				currentPokemon->m_moves[i]->print();
			}
		}
		chosen = -1;
		while (chosen == -1)
		{
			std::cin >> chosen;
			if (chosen < 0 || chosen >= 4)
			{
				std::cout << "Invalid index. Choose a move between 0 and 3.\n";
				chosen = -1;
			}
			else if (currentPokemon->m_moves[chosen] == nullptr)
			{
				std::cout << "No move in that slot.\n";
				chosen = -1;
			}
			else if (currentPokemon->m_moves[chosen]->m_PP == 0)
			{
				std::cout << "No PP left for this move!\n";
				chosen = -1;
			}
			else
			{
				std::cout << "\n"; // Clear screen
				return (Action *) currentPokemon->m_moves[chosen];
			}
		}
	}
	else // chosen == 1 (switch)
	{
		chosen = choosePokemon();
		return (Action *) new SwitchPokemon(m_activePokemon, chosen);
	}
	//  Shouldn't get here
	return nullptr;
}

int Trainer::determineSpeed()
{
	if (m_activePokemon == -1)
	{
		return -1;
	}
	return m_party[m_activePokemon]->determineSpeed();
}

void Trainer::checkHealth()
{
	m_canBattle = false;
	for(int i = 0; i < m_party.size(); i++)
	{
		if (m_party[i]->m_status != FNT)
		{
			m_canBattle = true;
			return;
		}
	}
}
