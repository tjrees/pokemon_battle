#ifndef __POKEMON_H__
#include "pokemon_enums.h"
#include <string>

class Pokemon
{
public:

	Pokemon(int name_in, int hp_in, int atk_in, int def_in, int spAtk_in, int spDef_in, int spd_in);
	~Pokemon();

	std::string m_name;
	Type m_type;
	int m_level;

	// Base stats
	int m_baseHp;
	int m_baseAtk;
	int m_baseDef;
	int m_baseSpAtk;
	int m_baseSpDef;
	int m_Spd;

	// True stats
	int m_maxHp;
	int m_hp;
	int m_atk;
	int m_def;
	int m_spAtk;
	int m_spDef;
	int m_spd;

	// Stat stages
	int m_atkStage = 0;
	int m_defStage = 0;
	int m_spAtkStage = 0;
	int m_spDefStage = 0;
	int m_spdStage = 0;
	int m_accStage = 0;
	int m_evaStage = 0;

	void switchIn();
	void switchOut();

	int calcHp();
	int calcStat();

private:

};

#endif // __POKEMON_H__