#ifndef __ABILITY_H__
#define __ABILITY_H__
// Definition of the Ability class. Each Pokemon has an ability
// that affects their actions throughout the battle.
#include <string>
#include "pokemon_enums.h"

class Pokemon;
struct AttackResults;

class Ability
{
public:
	std::string m_name;
	std::string m_blurb;
	Pokemon * m_user;

	Ability(std::string name_in, std::string blurb_in);
	~Ability();

	// Functions that run during different sections of the battle
	virtual void onSwitchIn() = 0;
	virtual void onSwitchOut() = 0;
	virtual void onTurnBegin() = 0;
	virtual void onTurnEnd() = 0;
	virtual void onStatusDamage(int * statusDamage) = 0;
	virtual void onAttack(AttackResults * results) = 0;
	virtual void onAttacked(AttackResults * results) = 0;
	virtual void onDamaged(AttackResults * results) = 0;
	virtual void onMakingContact(AttackResults * results) = 0;
	virtual void onTakingContact(AttackResults * results) = 0;
	virtual void onStatChange(Stat * statChanged, int * numStages, Pokemon * other) = 0;
	virtual void onStatusChange(StatusEffect * statusEffect, Pokemon * other) = 0;
	virtual void onRecoilDamage(int * recoilDamage) = 0;

	// Print for debugging and command line output
	void print();
};

#endif  // __ABILITY_H__