#include "pokemon.h"
#include "action.h"
#include "ability.h"
#include "item.h"
#include <cmath>
#include <iostream>

// Constructor for the Pokemon class. Initializes base stats, calculates true stats, and fills health.
Pokemon::Pokemon(std::string name_in, int level_in, Gender gender_in, Type type1_in, Type type2_in,
	int hp_in, int atk_in, int def_in, int spAtk_in, int spDef_in, int spd_in) : 
	m_name(name_in), m_level(level_in), m_gender(gender_in),
	m_type1(type1_in), m_type2(type2_in), m_baseHp(hp_in), m_baseAtk(atk_in), 
	m_baseDef(def_in), m_baseSpAtk(spAtk_in), m_baseSpDef(spDef_in), m_baseSpd(spd_in)
{
	this->m_maxHp = this->calcHp();
	this->m_hp = this->m_maxHp;
	this->m_atk = this->calcStat(this->m_baseAtk);
	this->m_def = this->calcStat(this->m_baseDef);
	this->m_spAtk = this->calcStat(this->m_baseSpAtk);
	this->m_spDef = this->calcStat(this->m_baseSpDef);
	this->m_spd = this->calcStat(this->m_baseSpd);

	// TODO: Reconsider how to initalize moves
	for (int i = 0; i < 4; i++)
	{
		this->m_moves.push_back(nullptr);
	}
}

// Destructor for the Pokemon class. Cleans up attached objects (ability, item)
Pokemon::~Pokemon()
{
	if (m_heldItem != nullptr)
	{
		delete m_heldItem;
		m_heldItem = nullptr;
	}
	if (m_ability != nullptr)
	{
		delete m_ability;
		m_ability = nullptr;
	}
}

// Switch in method
void Pokemon::switchIn()
{

}

// Switch out method. Resets stat stages
void Pokemon::switchOut()
{
	m_atkStage = 0;
	m_defStage = 0;
	m_spAtkStage = 0;
	m_spDefStage = 0;
	m_spdStage = 0;
	m_accStage = 0;
	m_evaStage = 0;
}

// Calculates the pokemon's HP stat
int Pokemon::calcHp()
{
	// TODO: Calculate with IVs, EVs
	double numerator = (2.0 * double(m_baseHp) + 31.0 + std::floor(85.0 / 4.0)) * double(m_level);
	int mainValue = std::floor(numerator / 100.0);
	return (mainValue + m_level + 10);

}

int Pokemon::calcStat(int base)
{
	// TODO: Calculate with IVs, EVs
	double numerator = (2.0 * double(base) + 31.0 + std::floor(85.0 / 4.0)) * double(m_level);
	int mainValue = std::floor(numerator / 100.0);
	return (mainValue + 5);

}

bool Pokemon::learnMove(Move * learnedMove)
{
	for (int i = 0; i < 4; i++)
	{
		if (m_moves[i] == nullptr)
		{
			m_moves[i] = learnedMove;
			return true;
		}
	}
	return false;
}

bool Pokemon::forgetMove(int idx)
{
	if (m_moves[idx] == nullptr)
	{
		return false;
	}
	int totalMoves = 0;
	for (int i = 0; i < 4; i++)
	{
		if (m_moves[i] != nullptr)
		{
			totalMoves++;
		}
	}
	if (totalMoves <= 1)
	{
		return false;
	}
	delete m_moves[idx];
	m_moves[idx] = nullptr;
	return true;
}

void Pokemon::print()
{
	std::cout << "- - - - - - - - - - - - - - - - - - - -\n";
	std::cout << m_name << "\n";

	std::cout << genderAsString(m_gender) << " Lv " << m_level << "\n";

	std::cout << typeAsString(m_type1);
	if (m_type2 != NoneType)
	{
		std::cout << " / " << typeAsString(m_type2);
	}
	std::cout << "\n";

	if (m_ability != nullptr)
	{
		std::cout << "Ability: " << m_ability->m_name << "\n";
	}
	if (m_heldItem != nullptr)
	{
		std::cout << "Item: " << m_heldItem->m_name << "\n";
	}
	std::cout << "\n";

	std::cout << "Stats:\n";
	std::cout << "HP: " << m_hp << "/" << m_maxHp << " | ";
	std::cout << "Attack: " << m_atk << " | ";
	std::cout << "Defense: " << m_def << " | ";
	std::cout << "Special Attack: " << m_spAtk << " | ";
	std::cout << "Special Defense: " << m_spDef << " | ";
	std::cout << "Speed: " << m_spd << "\n";
	std::cout << "\n";

	std::cout << "Moves:\n";
	for(int i = 0; i < 4; i++)
	{
		if (m_moves[i] == nullptr)
		{
			std::cout << "---\n\n";
		}
		else
		{
			m_moves[i]->print();
			std::cout << "\n";
		}
	}
	std::cout << "- - - - - - - - - - - - - - - - - - - -\n";
}
