// trainer.cpp
#include "trainer.h"
#include "pokemon.h"

Trainer::Trainer(std::string trainerName_in) : m_name(trainerName_in), m_activePokemon(-1)
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