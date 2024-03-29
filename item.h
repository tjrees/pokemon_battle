#ifndef __ITEM_H__
#define __ITEM_H__
// Defines the class for held items.
#include <string>
#include "pokemon_enums.h"

class Pokemon;
struct AttackResults;

class Item
{
public:
	std::string m_name;
	std::string m_blurb;
	Pokemon * m_holder;

	virtual void onSwitchIn() = 0;
	virtual void onSwitchOut() = 0;
	virtual void onTurnBegin() = 0;
	virtual void onTurnEnd() = 0;
	virtual void onAttack(AttackResults * results) = 0;
	virtual void onAttacked(AttackResults * results) = 0;
	virtual void onMakingContact(AttackResults * results) = 0;
	virtual void onTakingContact(AttackResults * results) = 0;
	virtual void onStatChange(Stat * statChanged, int *numStages, Pokemon * other) = 0;
	virtual void onStatusChange(StatusEffect * statusEffect, Pokemon * other) = 0;
	virtual void onRecoilDamage(int * recoilDamage);
	void print(AttackResults * results);
};

#endif // __ITEM_H__