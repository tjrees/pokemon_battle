#include "pokemon.h"
#include "action.h"
#include "ability.h"
#include "item.h"
#include <cmath>
#include <iostream>

// Constructor for the Pokemon class. Initializes base stats, calculates true stats, and fills health.
Pokemon::Pokemon(std::string name_in, int level_in, Gender gender_in, Type type1_in, Type type2_in,
	Ability * ability_in, int hp_in, int atk_in, int def_in, int spAtk_in, int spDef_in, int spd_in) : 
	m_name(name_in), m_level(level_in), m_gender(gender_in),
	m_type1(type1_in), m_type2(type2_in), m_ability(ability_in), m_heldItem(nullptr), m_status(OK),
	m_baseHp(hp_in), m_baseAtk(atk_in), m_baseDef(def_in), m_baseSpAtk(spAtk_in), 
	m_baseSpDef(spDef_in), m_baseSpd(spd_in), m_atkStage(0), m_defStage(0), m_spAtkStage(0), 
	m_spDefStage(0), m_spdStage(0), m_accStage(0), m_evaStage(0), m_trainer(nullptr), m_turnsIn(0),
	m_sleepCounter(0)
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

void Pokemon::onSwitchIn()
{
	m_turnsIn = 0;
	if (m_ability != nullptr)
	{
		m_ability->onSwitchIn();
	}
	if (m_heldItem != nullptr)
	{
		m_heldItem->onSwitchIn();
	}
}

void Pokemon::onSwitchOut()
{
	m_atkStage = 0;
	m_defStage = 0;
	m_spAtkStage = 0;
	m_spDefStage = 0;
	m_spdStage = 0;
	m_accStage = 0;
	m_evaStage = 0;

	if (m_ability != nullptr)
	{
		m_ability->onSwitchOut();
	}
	if (m_heldItem != nullptr)
	{
		m_heldItem->onSwitchOut();
	}
}

void Pokemon::onTurnBegin()
{
	if (m_ability != nullptr)
	{
		m_ability->onTurnBegin();
	}
	if (m_heldItem != nullptr)
	{
		m_heldItem->onTurnBegin();
	}
}

void Pokemon::onTurnEnd()
{
	m_turnsIn++;
	if (m_ability != nullptr)
	{
		m_ability->onTurnEnd();
	}
	if (m_heldItem != nullptr)
	{
		m_heldItem->onTurnEnd();
	}

	if (m_status == SLP)
	{
		m_sleepCounter++;
	}

	int statusDamage = 0;
	if (m_status == BRN || m_status == PSN)
	{
		statusDamage = m_maxHp / 8;
	}
	else if (m_status == TOX)
	{
		double toxDenominator = 16.0;
		toxDenominator /= pow(2, m_turnsIn - 1);
		statusDamage = m_maxHp / toxDenominator;
	}
	if (statusDamage != 0)
	{
		if (statusDamage >= m_hp)
		{
			statusDamage = m_hp;
			m_hp = 0;
		}
		else
		{
			m_hp -= statusDamage;
		}
		std::cout << m_name << " was hurt by ";
		if (m_status == BRN)
		{
			std::cout << "its burn! (";
		}
		else if (m_status == PSN || m_status == TOX)
		{
			std::cout << "poison! (";
		}
		std::cout << (((double) statusDamage) / ((double) m_maxHp) * 100.0) << "%%)\n";
		if (m_hp == 0)
		{
			m_status = FNT;
		}
	}
}

void Pokemon::onAttack(AttackResults * results)
{
	// A burn status halves the afflicted pokemon's attack
	if (m_status == BRN && results->movePtr->attackType == Physical)
	{
		results->additional *= 0.5;
	}
	if (m_ability != nullptr)
	{
		m_ability->onAttack(results);
	}
	if (m_heldItem != nullptr)
	{
		m_heldItem->onAttack(results);
	}
}

void Pokemon::onAttacked(AttackResults * results)
{
	if (m_ability != nullptr)
	{
		m_ability->onAttacked(results);
	}
	if (m_heldItem != nullptr)
	{
		m_heldItem->onAttacked(results);
	}

	// Damaging fire-type attacks will freeze a frozen pokemon
	if (m_status == FRZ && results->movePtr->m_type == Fire && results->movePtr->m_moveType == move_Attack)
	{
		StatusEffect okStatus = OK;
		onStatusChange(okStatus, results->attacker);
	}

	// Calculate the total damage dealt by the attack
	if (results->critical > 1)
	{
		results->modifiedDamageDenominator = 2;
	}
	if (results->totalDamage == 0)
	{
		if (results->nullified)
		{
			results->totalDamage = 0;
		}
		else
		{
			results->totalDamage = 
				std::round((results->effectiveness * results->stab * results->critical * 
				results->additional * results->unmodifiedDamage * 
				results->modifiedDamageNumerator) / 
				results->modifiedDamageDenominator);;
		}
	}	
	// Apply the damage from the attack
	if (results->totalDamage >= m_hp)
	{
		results->totalDamage = m_hp;
		m_hp = 0;
		m_status = FNT;
	}
	else
	{
		m_hp -= results->totalDamage;
	}
	std::cout << m_name << " lost " << (((double) results->totalDamage) / ((double) m_maxHp) * 100.0) << " percent of its health!\n";
}

void Pokemon::onMakingContact(AttackResults * results)
{
	if (m_ability != nullptr)
	{
		m_ability->onMakingContact(results);
	}
	if (m_heldItem != nullptr)
	{
		m_heldItem->onMakingContact(results);
	}
}

void Pokemon::onTakingContact(AttackResults * results)
{
	if (m_ability != nullptr)
	{
		m_ability->onTakingContact(results);
	}
	if (m_heldItem != nullptr)
	{
		m_heldItem->onTakingContact(results);
	}
}

void Pokemon::onStatChange(Stat * statChanged, int * numStages, Pokemon * other)
{
	if (m_ability != nullptr)
	{
		m_ability->onStatChange(statChanged, numStages, other);
	}
	if (m_heldItem != nullptr)
	{
		m_heldItem->onStatChange(statChanged, numStages, other);
	}
	if (*numStages == 0)
	{
		return;
	}
	int * statPtr = nullptr;
	switch (*statChanged)
	{
		case ATK:
		{
			statPtr = &m_atkStage;
			break;
		}
		case DEF:
		{
			statPtr = &m_defStage;
			break;
		}
		case SPATK:
		{
			statPtr = &m_spAtkStage;
			break;
		}
		case SPDEF:
		{
			statPtr = &m_spDefStage;
			break;
		}
		case SPD:
		{
			statPtr = &m_spdStage;
			break;
		}
		case ACC:
		{
			statPtr = &m_accStage;
			break;
		}
		case EVA:
		{
			statPtr = &m_evaStage;
			break;
		}
		default:
		{
			statPtr = nullptr;
		}
	}
	if (*numStages > 0)
	{
		if (*statPtr == 6)
		{
			std::cout << m_name << "'s " << statAsString(*statChanged) << " won't go higher!\n";
			*numStages = 0;
		}
		else if (*statPtr + *numStages > 6)
		{
			*numStages = 6 - *statPtr;
		}
	}
	else if (*numStages < 0)
	{
		if (*statPtr == -6)
		{
			std::cout << m_name << "'s " << statAsString(*statChanged) << " won't go lower!\n";
			*numStages = 0;
		}
		else if (*statPtr + *numStages < -6)
		{
			*numStages = -6 - *statPtr;
		}
	}
	// apply the stat change
	*statPtr += *numStages;

	if (*numStages == 0)
	{
		return;
	}
	if (*numStages == 1)
	{
		std::cout << m_name << "'s " << statAsString(*statChanged) << " rose!\n";
	}
	else if (*numStages == 2)
	{
		std::cout << m_name << "'s " << statAsString(*statChanged) << " sharply rose!\n";
	}
	else if (*numStages >= 3)
	{
		std::cout << m_name << "'s " << statAsString(*statChanged) << " drastically rose!\n";
	}
	else if (*numStages == -1)
	{
		std::cout << m_name << "'s " << statAsString(*statChanged) << " fell!\n";
	}
	else if (*numStages == -2)
	{
		std::cout << m_name << "'s " << statAsString(*statChanged) << " harshly fell!\n";
	}
	else if (*numStages <= -3)
	{
		std::cout << m_name << "'s " << statAsString(*statChanged) << " severely fell!\n";
	}
}

void Pokemon::onStatusChange(StatusEffect * statusEffect, Pokemon * other)
{
	// Status effects do not stack
	if (m_status != OK && *statusEffect != OK)
	{
		return;
	}
	if (m_ability != nullptr)
	{
		m_ability->onStatusChange(statusEffect, other);
	}
	if (m_heldItem != nullptr)
	{
		m_heldItem->onStatusChange(statusEffect, other);
	}
	if (m_status == *statusEffect) // Return if the status effect is nullified
	{
		return;
	}
	switch (*statusEffect)
	{
		case PAR:
		{
			std::cout << m_name << " was paralyzed!\n";
			break;
		}
		case PSN:
		{
			std::cout << m_name << " was poisoned!\n";
			break;
		}
		case TOX:
		{
			std::cout << m_name << " was badly poisoned\n";
			break;
		}
		case BRN:
		{
			std::cout << m_name << " was burned!\n";
			break;
		}
		case SLP:
		{
			std::cout << m_name << " went to sleep!\n";
			break;
		}
		case FRZ:
		{
			std::cout << m_name << " was frozen solid!\n";
			break;
		}
		default:
		{
			switch(m_status)
			{
				case PAR:
				{
					std::cout << m_name << " was cured of its paralysis!\n";
					break;
				}
				case PSN:
				{
					std::cout << m_name << " was cured of its poison!\n";
					break;
				}
				case TOX:
				{
					std::cout << m_name << " was cured of its poison!\n";
					break;
				}
				case BRN:
				{
					std::cout << m_name << " was cured of its burn!\n";
					break;
				}
				case SLP:
				{
					std::cout << m_name << " woke up!\n";
					break;
				}
				case FRZ:
				{
					std::cout << m_name << " thawed out!\n";
					break;
				}
				default: {}
			}
		}
	}
	m_status = *statusEffect;
}

void Pokemon::onRecoilDamage(int * recoilDamage)
{
	if (m_ability != nullptr)
	{
		m_ability->onRecoilDamage(recoilDamage);
	}
	if (m_heldItem != nullptr)
	{
		m_heldItem->onRecoilDamage(recoilDamage);
	}
	if (recoilDamage > m_hp)
	{
		recoilDamage = m_hp;
		m_status = FNT;
	}
	m_hp -= recoilDamage;
	std::cout << m_name << " is damaged by recoil!\n";
}

bool Pokemon::ppAvailable()
{
	for (int i = 0; i < 4; i++)
	{
		if (m_moves[i] != nullptr)
		{
			if (m_moves[i]->m_PP > 0)
			{
				return true;
			}
		}
	}
	return false;
}

int Pokemon::determineSpeed()
{
	int speedNumerator = 2;
	int speedDenominator = 2;
	if (m_spdStage > 0)
	{
		speedNumerator += m_spdStage;
	}
	else
	{
		speedDenominator -= m_spdStage;
	}
	double speed =  ((double) m_spd * (double) speedNumerator) / (double) speedDenominator;
	if (m_status == PAR)
	{
		speed /= 4.0;
	}
	return speed;
}

// Determines if the pokemon can move this turn.
bool Pokemon::canMove(Move * moveUsed)
{
	if (m_status == OK)
	{
		return true;
	}
	// Check random chance status effects
	double moveValue = (rand() % 100) + 1;
	if (m_status == PAR)
	{
		if (moveValue <= 75)
		{
			return true;
		}
		else
		{
			std::cout << m_name << " is fully paralyzed. It can't move!\n";
		}
	}
	else if (m_status == SLP)
	{
		if (m_sleepCounter == 0)
		{
			std::cout << m_name << " is fast asleep.\n";
			return false;
		}
		else if (m_sleepCounter == 1)
		{
			if (moveValue < 33.3333)
			{
				StatusEffect okStatus = OK;
				onStatusChange(&okStatus, nullptr);
				m_sleepCounter = 0;
				return true;
			}
			else
			{
				std::cout << m_name << " is fast asleep.\n";
				return false;
			}
		}
		else if (m_sleepCounter == 2)
		{
			if (moveValue < 50)
			{
				StatusEffect okStatus = OK;
				onStatusChange(&okStatus, nullptr);
				m_sleepCounter = 0;
				return true;
			}
			else
			{
				std::cout << m_name << " is fast asleep.\n";
				return false;
			}
		}
		else
		{
			StatusEffect okStatus = OK;
			onStatusChange(&okStatus, nullptr);
			m_sleepCounter = 0;
			return true;
		}
	}
	else if (m_status == FRZ)
	{
		if (moveUsed->m_type == Fire && moveUsed->m_moveType == move_Attack)
		{
			StatusEffect okStatus = OK;
			onStatusChange(&okStatus, nullptr);
			return true;
		}
		else if (moveValue <= 20)
		{
			StatusEffect okStatus = OK;
			onStatusChange(&okStatus, nullptr);
			return true;
		}
		else
		{
			std::cout << m_name << " is frozen solid!\n";
			return false;
		}
	}
	return true;
}


void Pokemon::print()
{
	std::cout << "- - - - - - - - - - - - - - - - - - - -\n";
	std::cout << m_name << " | " << statusEffectAsString(m_status) << "\n";

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
			std::cout << "---\n";
		}
		else
		{
			m_moves[i]->print();
		}
	}
	std::cout << "- - - - - - - - - - - - - - - - - - - -\n";
}

// Alternate print statement that does not show your opponent your exact health or 
void Pokemon::battlePrint()
{
	std::cout << "^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^\n";
	std::cout << m_name << " | " << genderAsString(m_gender) << " | Lv " << m_level << " | " << statusEffectAsString(m_status) << "\n";
	double percentHP = (double) m_hp / (double) m_maxHp;
	std::cout << "HP: " << percentHP * 100.0 << "%%\n";
	std::cout << "^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^\n";
}
