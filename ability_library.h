#ifndef __ABILITY_LIBRARY_H__
#define __ABILITY_LIBRARY_H__
#include "ability.h"

class Intimidate : public Ability
{
public:
	Intimidate();
	~Intimidate();
	// Functions that run during different sections of the battle
	virtual void onSwitchIn();
	virtual void onSwitchOut();
	virtual void onTurnBegin();
	virtual void onTurnEnd();
	virtual void onStatusDamage(int * statusDamage);
	virtual void onAttack(AttackResults * results);
	virtual void onAttacked(AttackResults * results);
	virtual void onDamaged(AttackResults * results);
	virtual void onMakingContact(AttackResults * results);
	virtual void onTakingContact(AttackResults * results);
	virtual void onStatChange(Stat * statChanged, int * numStages, Pokemon * other);
	virtual void onStatusChange(StatusEffect * statusEffect, Pokemon * other);
	virtual void onRecoilDamage(int * recoilDamage);
};

class Immunity : public Ability
{
public:
	Immunity();
	~Immunity();
	// Functions that run during different sections of the battle
	virtual void onSwitchIn();
	virtual void onSwitchOut();
	virtual void onTurnBegin();
	virtual void onTurnEnd();
	virtual void onStatusDamage(int * statusDamage);
	virtual void onAttack(AttackResults * results);
	virtual void onAttacked(AttackResults * results);
	virtual void onDamaged(AttackResults * results);
	virtual void onMakingContact(AttackResults * results);
	virtual void onTakingContact(AttackResults * results);
	virtual void onStatChange(Stat * statChanged, int * numStages, Pokemon * other);
	virtual void onStatusChange(StatusEffect * statusEffect, Pokemon * other);
	virtual void onRecoilDamage(int * recoilDamage);
};

class Sturdy : public Ability
{
public:
	Sturdy();
	~Sturdy();
	// Functions that run during different sections of the battle
	virtual void onSwitchIn();
	virtual void onSwitchOut();
	virtual void onTurnBegin();
	virtual void onTurnEnd();
	virtual void onStatusDamage(int * statusDamage);
	virtual void onAttack(AttackResults * results);
	virtual void onAttacked(AttackResults * results);
	virtual void onDamaged(AttackResults * results);
	virtual void onMakingContact(AttackResults * results);
	virtual void onTakingContact(AttackResults * results);
	virtual void onStatChange(Stat * statChanged, int * numStages, Pokemon * other);
	virtual void onStatusChange(StatusEffect * statusEffect, Pokemon * other);
	virtual void onRecoilDamage(int * recoilDamage);
};

class Guts : public Ability
{
public:
	Guts();
	~Guts();
	// Functions that run during different sections of the battle
	virtual void onSwitchIn();
	virtual void onSwitchOut();
	virtual void onTurnBegin();
	virtual void onTurnEnd();
	virtual void onStatusDamage(int * statusDamage);
	virtual void onAttack(AttackResults * results);
	virtual void onAttacked(AttackResults * results);
	virtual void onDamaged(AttackResults * results);
	virtual void onMakingContact(AttackResults * results);
	virtual void onTakingContact(AttackResults * results);
	virtual void onStatChange(Stat * statChanged, int * numStages, Pokemon * other);
	virtual void onStatusChange(StatusEffect * statusEffect, Pokemon * other);
	virtual void onRecoilDamage(int * recoilDamage);
};

class Synchronize : public Ability
{
public:
	Synchronize();
	~Synchronize();
	// Functions that run during different sections of the battle
	virtual void onSwitchIn();
	virtual void onSwitchOut();
	virtual void onTurnBegin();
	virtual void onTurnEnd();
	virtual void onStatusDamage(int * statusDamage);
	virtual void onAttack(AttackResults * results);
	virtual void onAttacked(AttackResults * results);
	virtual void onDamaged(AttackResults * results);
	virtual void onMakingContact(AttackResults * results);
	virtual void onTakingContact(AttackResults * results);
	virtual void onStatChange(Stat * statChanged, int * numStages, Pokemon * other);
	virtual void onStatusChange(StatusEffect * statusEffect, Pokemon * other);
	virtual void onRecoilDamage(int * recoilDamage);
};

class ThickFat : public Ability
{
public:
	ThickFat();
	~ThickFat();
	// Functions that run during different sections of the battle
	virtual void onSwitchIn();
	virtual void onSwitchOut();
	virtual void onTurnBegin();
	virtual void onTurnEnd();
	virtual void onStatusDamage(int * statusDamage);
	virtual void onAttack(AttackResults * results);
	virtual void onAttacked(AttackResults * results);
	virtual void onDamaged(AttackResults * results);
	virtual void onMakingContact(AttackResults * results);
	virtual void onTakingContact(AttackResults * results);
	virtual void onStatChange(Stat * statChanged, int * numStages, Pokemon * other);
	virtual void onStatusChange(StatusEffect * statusEffect, Pokemon * other);
	virtual void onRecoilDamage(int * recoilDamage);
};

class Levitate : public Ability
{
public:
	Levitate();
	~Levitate();
	// Functions that run during different sections of the battle
	virtual void onSwitchIn();
	virtual void onSwitchOut();
	virtual void onTurnBegin();
	virtual void onTurnEnd();
	virtual void onStatusDamage(int * statusDamage);
	virtual void onAttack(AttackResults * results);
	virtual void onAttacked(AttackResults * results);
	virtual void onDamaged(AttackResults * results);
	virtual void onMakingContact(AttackResults * results);
	virtual void onTakingContact(AttackResults * results);
	virtual void onStatChange(Stat * statChanged, int * numStages, Pokemon * other);
	virtual void onStatusChange(StatusEffect * statusEffect, Pokemon * other);
	virtual void onRecoilDamage(int * recoilDamage);
};

class Pressure : public Ability
{
public:
	Pressure();
	~Pressure();
	// Functions that run during different sections of the battle
	virtual void onSwitchIn();
	virtual void onSwitchOut();
	virtual void onTurnBegin();
	virtual void onTurnEnd();
	virtual void onStatusDamage(int * statusDamage);
	virtual void onAttack(AttackResults * results);
	virtual void onAttacked(AttackResults * results);
	virtual void onDamaged(AttackResults * results);
	virtual void onMakingContact(AttackResults * results);
	virtual void onTakingContact(AttackResults * results);
	virtual void onStatChange(Stat * statChanged, int * numStages, Pokemon * other);
	virtual void onStatusChange(StatusEffect * statusEffect, Pokemon * other);
	virtual void onRecoilDamage(int * recoilDamage);
};

class FlashFire : public Ability
{
public:
	FlashFire();
	~FlashFire();
	// Functions that run during different sections of the battle
	virtual void onSwitchIn();
	virtual void onSwitchOut();
	virtual void onTurnBegin();
	virtual void onTurnEnd();
	virtual void onStatusDamage(int * statusDamage);
	virtual void onAttack(AttackResults * results);
	virtual void onAttacked(AttackResults * results);
	virtual void onDamaged(AttackResults * results);
	virtual void onMakingContact(AttackResults * results);
	virtual void onTakingContact(AttackResults * results);
	virtual void onStatChange(Stat * statChanged, int * numStages, Pokemon * other);
	virtual void onStatusChange(StatusEffect * statusEffect, Pokemon * other);
	virtual void onRecoilDamage(int * recoilDamage);
private:
	bool m_activated;
};

class Sniper : public Ability
{
public:
	Sniper();
	~Sniper();
	// Functions that run during different sections of the battle
	virtual void onSwitchIn();
	virtual void onSwitchOut();
	virtual void onTurnBegin();
	virtual void onTurnEnd();
	virtual void onStatusDamage(int * statusDamage);
	virtual void onAttack(AttackResults * results);
	virtual void onAttacked(AttackResults * results);
	virtual void onDamaged(AttackResults * results);
	virtual void onMakingContact(AttackResults * results);
	virtual void onTakingContact(AttackResults * results);
	virtual void onStatChange(Stat * statChanged, int * numStages, Pokemon * other);
	virtual void onStatusChange(StatusEffect * statusEffect, Pokemon * other);
	virtual void onRecoilDamage(int * recoilDamage);
};

class PoisonHeal : public Ability
{
public:
	PoisonHeal();
	~PoisonHeal();
	// Functions that run during different sections of the battle
	virtual void onSwitchIn();
	virtual void onSwitchOut();
	virtual void onTurnBegin();
	virtual void onTurnEnd();
	virtual void onStatusDamage(int * statusDamage);
	virtual void onAttack(AttackResults * results);
	virtual void onAttacked(AttackResults * results);
	virtual void onDamaged(AttackResults * results);
	virtual void onMakingContact(AttackResults * results);
	virtual void onTakingContact(AttackResults * results);
	virtual void onStatChange(Stat * statChanged, int * numStages, Pokemon * other);
	virtual void onStatusChange(StatusEffect * statusEffect, Pokemon * other);
	virtual void onRecoilDamage(int * recoilDamage);
};

class LightningRod : public Ability
{
public:
	LightningRod();
	~LightningRod();
	// Functions that run during different sections of the battle
	virtual void onSwitchIn();
	virtual void onSwitchOut();
	virtual void onTurnBegin();
	virtual void onTurnEnd();
	virtual void onStatusDamage(int * statusDamage);
	virtual void onAttack(AttackResults * results);
	virtual void onAttacked(AttackResults * results);
	virtual void onDamaged(AttackResults * results);
	virtual void onMakingContact(AttackResults * results);
	virtual void onTakingContact(AttackResults * results);
	virtual void onStatChange(Stat * statChanged, int * numStages, Pokemon * other);
	virtual void onStatusChange(StatusEffect * statusEffect, Pokemon * other);
	virtual void onRecoilDamage(int * recoilDamage);
};


#endif // __ABILITY_LIBRARY_H__