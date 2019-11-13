// team_build.cpp
// Prompts users to create their trainers and parties.
#include <iostream>
#include <string>
#include "team_build.h"
#include "trainer.h"
#include "pokedex.h"
#include "pokemon_enums.h"
#include "move_library.h"

Trainer * createTrainer(int trainerIdx)
{
	std::string trainerName;

	std::cout << "Trainer " << trainerIdx << ": What is your name?\n";
	std::cin >> trainerName;

	Trainer * currentTrainer = new Trainer(trainerName);

	//TODO: Prompt to build team
	if (trainerIdx == 0)
	{
		// Charmander
		Pokemon * charmander = new Charmander(15, Male);
		Move * growl = new Growl();
		Move * scratch = new Scratch();
		Move * ember = new Ember();
		Move * metalClaw = new MetalClaw();
		bool result = charmander->learnMove(growl);
		result = charmander->learnMove(scratch);
		result = charmander->learnMove(ember);
		result = charmander->learnMove(metalClaw);
		charmander->m_trainer = currentTrainer;
		currentTrainer->m_party.push_back(charmander);
	}
	else
	{
		// Pikachu
		Pokemon * pikachu = new Pikachu(15, Female);
		Move * growl = new Growl();
		Move * thunderShock = new ThunderShock();
		Move * tailWhip = new TailWhip();
		Move * quickAttack = new QuickAttack();
		pikachu->learnMove(growl);
		pikachu->learnMove(thunderShock);
		pikachu->learnMove(tailWhip);
		pikachu->learnMove(quickAttack);
		pikachu->m_trainer = currentTrainer;
		currentTrainer->m_party.push_back(pikachu);
	}
	return currentTrainer;
}