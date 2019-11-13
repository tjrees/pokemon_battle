#include <iostream>
#include "team_build.h"
#include "trainer.h"
#include "pokemon.h"
#include "battle.h"

// Main function for executing this program
int main()
{
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

	Battle * battle = new Battle();
	battle->trainer0 = trainer0;
	battle->trainer1 = trainer1;
	battle->execute();

	// Enter battle
	// Announce winner
	delete trainer0;
	delete trainer1;
	return 0;
}