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
	std::string input;

	std::cout << "Trainer " << trainerIdx << ": What is your name?\n";
	std::getline(std::cin, input);

	int commentStart = input.find('#');
	input = input.substr(0, commentStart);

	Trainer * currentTrainer = new Trainer(input);

	if (trainerIdx == 0)
	{
		// Trainer 0's team:
		// Arcanine
		// Snorlax
		// Steelix
		// Heracross
		// Gardevoir
		// Walrein

		Pokemon * arcanine = new Arcanine(100, Male);
		Pokemon * snorlax = new Snorlax(100, Male);
		Pokemon * steelix = new Steelix(100, Male);
		Pokemon * heracross = new Heracross(100, Female);
		Pokemon * gardevoir = new Gardevoir(100, Female);
		Pokemon * walrein = new Walrein(100, Female);

		arcanine->learnMove(new FireBlast());
		arcanine->learnMove(new WildCharge());
		arcanine->learnMove(new Crunch());
		arcanine->learnMove(new ExtremeSpeed());

		snorlax->learnMove(new Curse());
		snorlax->learnMove(new BodySlam());
		snorlax->learnMove(new Earthquake());
		snorlax->learnMove(new IcePunch());

		steelix->learnMove(new IronTail());
		steelix->learnMove(new Earthquake());
		steelix->learnMove(new Toxic());
		steelix->learnMove(new Roar());

		heracross->learnMove(new CloseCombat());
		heracross->learnMove(new Megahorn());
		heracross->learnMove(new Earthquake());
		heracross->learnMove(new AerialAce());

		gardevoir->learnMove(new CalmMind());
		gardevoir->learnMove(new StoredPower());
		gardevoir->learnMove(new Moonblast());
		gardevoir->learnMove(new DoubleTeam());

		walrein->learnMove(new IceBeam());
		walrein->learnMove(new Surf());
		walrein->learnMove(new Fissure());
		walrein->learnMove(new Crunch());

		arcanine->m_trainer = currentTrainer;
		currentTrainer->m_party.push_back(arcanine);
		snorlax->m_trainer = currentTrainer;
		currentTrainer->m_party.push_back(snorlax);
		steelix->m_trainer = currentTrainer;
		currentTrainer->m_party.push_back(steelix);
		heracross->m_trainer = currentTrainer;
		currentTrainer->m_party.push_back(heracross);
		gardevoir->m_trainer = currentTrainer;
		currentTrainer->m_party.push_back(gardevoir);
		walrein->m_trainer = currentTrainer;
		currentTrainer->m_party.push_back(walrein);
	}
	else
	{
		// Trainer 1's team:
		// Gengar
		// Aerodactyl
		// Houndoom
		// Kingdra
		// Breloom
		// Manectric

		Pokemon * gengar = new Gengar(100, Male);
		Pokemon * aerodactyl = new Aerodactyl(100, Male);
		Pokemon * houndoom = new Houndoom(100, Male);
		Pokemon * kingdra = new Kingdra(100, Female);
		Pokemon * breloom = new Breloom(100, Female);
		Pokemon * manectric = new Manectric(100, Female);

		gengar->learnMove(new ShadowBall());
		gengar->learnMove(new SludgeBomb());
		gengar->learnMove(new Thunderbolt());
		gengar->learnMove(new WillOWisp());

		aerodactyl->learnMove(new StoneEdge());
		aerodactyl->learnMove(new Earthquake());
		aerodactyl->learnMove(new Roost());
		aerodactyl->learnMove(new Fly());

		houndoom->learnMove(new NastyPlot());
		houndoom->learnMove(new Flamethrower());
		houndoom->learnMove(new DarkPulse());
		houndoom->learnMove(new SolarBeam());

		kingdra->learnMove(new DracoMeteor());
		kingdra->learnMove(new Waterfall());
		kingdra->learnMove(new DragonDance());
		kingdra->learnMove(new HydroPump());

		breloom->learnMove(new SwordsDance());
		breloom->learnMove(new MachPunch());
		breloom->learnMove(new SeedBomb());
		breloom->learnMove(new DrainPunch());

		manectric->learnMove(new Thunderbolt());
		manectric->learnMove(new Flamethrower());
		manectric->learnMove(new ThunderWave());
		manectric->learnMove(new ChargeBeam());

		gengar->m_trainer = currentTrainer;
		currentTrainer->m_party.push_back(gengar);
		aerodactyl->m_trainer = currentTrainer;
		currentTrainer->m_party.push_back(aerodactyl);
		houndoom->m_trainer = currentTrainer;
		currentTrainer->m_party.push_back(houndoom);
		kingdra->m_trainer = currentTrainer;
		currentTrainer->m_party.push_back(kingdra);
		breloom->m_trainer = currentTrainer;
		currentTrainer->m_party.push_back(breloom);
		manectric->m_trainer = currentTrainer;
		currentTrainer->m_party.push_back(manectric);
	}
	return currentTrainer;
}