#ifndef __ABILITY_H__
#define __ABILITY_H__
// Definition of the Ability class. Each Pokemon has an ability
// that affects their actions throughout the battle.
#include <string>

class Pokemon;

class Ability
{
public:
	std::string m_name;
	std::string m_blurb;
	Pokemon * m_user;

	// Functions that run during different sections of the battle
	virtual void onSwitchIn() = 0;
	virtual void onSwitchOut() = 0;
	virtual void onTurnBegin() = 0;
	virtual void onTurnEnd() = 0;
	virtual void onAttack(AttackResults * results) = 0;
	virtual void onAttacked(AttackResults * results) = 0;
	virtual void onMakingContact(AttackResults * results) = 0;
	virtual void onTakingContact(AttackResults * results) = 0;
	virtual void onStatChange(AttackResults * results) = 0;

	// Print for debugging and command line output
	void print();
};

#endif  // __ABILITY_H__