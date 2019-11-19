#include <iostream>
#include <cmath>
#include <ctime>
#include "team_build.h"
#include "trainer.h"
#include "pokemon.h"
#include "battle.h"

// Main function for executing this program
int main()
{
	// Seed the RNG
	srand(time(NULL));

	// Initialize player 0
	// Create player 0's party
	Trainer * trainer0 = createTrainer(0);
	std::cout << trainer0->m_name << "'s party:\n";
	for (int i = 0; i < trainer0->m_party.size(); i++)
	{
		trainer0->m_party[i]->print();
	}

	// Initalize player 1
	// Create player 1's party
	Trainer * trainer1 = createTrainer(1);
	std::cout << trainer1->m_name << "'s party:\n";
	for(int i = 0; i < trainer1->m_party.size(); i++)
	{
		trainer1->m_party[i]->print();
	}

	// initialize and start the battle
	Battle * battle = new Battle();
	battle->trainer0 = trainer0;
	battle->trainer1 = trainer1;
	battle->execute();

	// Determine the winner
	if (!trainer0->m_canBattle)
	{
		std::cout << trainer0->m_name << " is out of usable Pokemon!\n";
		if (!trainer1->m_canBattle)
		{
			std::cout << trainer1->m_name << " is out of usable Pokemon!\n";
			std::cout << "The battle ends in a tie!\n";
		}
		else
		{
			std::cout << trainer1->m_name << " wins!\n";
		}
	}
	else if (!trainer1->m_canBattle)
	{
		std::cout << trainer1->m_name << " is out of usable Pokemon!\n";
		std::cout << trainer0->m_name << " wins!\n";
	}


	delete trainer0;
	delete trainer1;
	return 0;
}