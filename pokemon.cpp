#include "pokemon.h"
#include <cmath>

// Constructor for the Pokemon class. Initializes base stats, calculates true stats, and fills health.
Pokemon::Pokemon(int name_in, int level_in, int hp_in, int atk_in, int def_in, int spAtk_in, int spDef_in, int spd_in)
{
	this->m_baseHp = hp_in;
	this->m_baseAtk = atk_in;
	this->m_baseDef = def_in;
	this->m_baseSpAtk = spAtk_in;
	this->m_baseSpDef = spDef_in;
	this->m_spd = spd_in;

	this->m_maxHp = this->calcHp();
	this->m_hp = this->m_maxHp;
	this->m_atk = this->calcStat(this->m_baseAtk);
	this->m_atk = this->calcStat(this->m_baseDef);
	this->m_atk = this->calcStat(this->m_baseSpAtk);
	this->m_atk = this->calcStat(this->m_baseSpDef);
	this->m_atk = this->calcStat(this->m_spd);
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
void Pokemon::calcHp()
{
	// TODO: Calculate with IVs, EVs
	return std::floor(
				(double(m_baseHp) + 31.0) * 2.0 + 
				std::floor(
					std::ceil(
						std::sqrt(85.0) / 4.0
					)
				) * m_level
			) + m_level + 10;

}

void Pokemon::calcStat(int base)
{
	// TODO: Calculate with IVs, EVs
	return std::floor(
				(double(base) + 31.0) * 2.0 + 
				std::floor(
					std::ceil(
						std::sqrt(85.0) / 4.0
					)
				) * m_level
			) + 5;

}
