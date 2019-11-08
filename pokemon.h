#ifndef __POKEMON_H__
#define __POKEMON_H__
#include "pokemon_enums.h"
#include "action.h"
#include <string>
#include <vector>

class Ability;
class Item;
class Move;

class Pokemon
{
public:

	Pokemon(int name_in, int level_in, int hp_in, int atk_in, int def_in, int spAtk_in, int spDef_in, int spd_in);
	~Pokemon();

	std::string m_name;
	int m_level;
	Gender m_gender;
	Type m_type1;
	Type m_type2;

	Ability * m_ability;
	Item * m_heldItem;

	StatusEffect m_status;

	// Base stats
	int m_baseHp;
	int m_baseAtk;
	int m_baseDef;
	int m_baseSpAtk;
	int m_baseSpDef;
	int m_baseSpd;

	// True stats
	int m_maxHp;
	int m_hp;
	int m_atk;
	int m_def;
	int m_spAtk;
	int m_spDef;
	int m_spd;

	// Stat stages
	int m_atkStage;
	int m_defStage;
	int m_spAtkStage;
	int m_spDefStage;
	int m_spdStage;
	int m_accStage;
	int m_evaStage;

	// Moves
	std::vector<Move *> m_moves;

	void switchIn();
	void switchOut();

	int calcHp();
	int calcStat(int base);

	bool learnMove(Move * learnedMove);
	bool forgetMove(int idx);

	void print();

private:

};

#endif // __POKEMON_H__