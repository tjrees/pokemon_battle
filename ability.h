#ifndef __ABILITY_H__
#define __ABILITY_H__
#include <string>

class Pokemon;

class Ability
{
public:
	std::string m_name;
	std::string m_blurb;
	Pokemon * m_user;

	void onSwitchIn();
	void onSwitchOut();
	void onTurnBegin();
	void onTurnEnd();
	void onAttacked();
	void onAttack();
	void print();
};

#endif  // __ABILITY_H__