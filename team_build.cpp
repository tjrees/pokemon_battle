// team_build.cpp
// Prompts users to create their trainers and parties.
#include <iostream>
#include <string>
#include "trainer.h"
#include "pokemon.h"

Trainer * createTrainer(int trainerIdx)
{
	std::string trainerName;

	std::cout << "Trainer " << trainerIdx << ": What is your name?\n";

	std::cin >> trainerName;

	Trainer * currentTrainer = new Trainer(trainerName);

	//TODO: Prompt to build team
	if (trainerIdx == 1)
	{
		// Pikachu
	}
	else
	{
		// Charmander
	}
	return nullptr;
}