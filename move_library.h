#ifndef __MOVE_LIBRARY_H__
#define __MOVE_LIBRARY_H__

#include "action.h"
// class Action;
// class SwitchPokemon;
// class Move;
// class Status;
// class Attack;

class Struggle : public Attack
{
public:
	Struggle();
	~Struggle();
	virtual bool checkValidity(Pokemon * defender); // None
	virtual void primaryEffects(AttackResults * results); // None
	virtual void secondaryEffects(AttackResults * results); // None
};

class ThunderShock : public Attack
{
public:
	ThunderShock();
	~ThunderShock();
	virtual bool checkValidity(Pokemon * defender); // None
	virtual void primaryEffects(AttackResults * results); // None
	virtual void secondaryEffects(AttackResults * results); // 10% chance to PAR
};

class Growl : public Status
{
public:
	Growl();
	~Growl();
	virtual bool checkValidity(Pokemon * defender); // Cannot lower Atk to under -6
	virtual void primaryEffects(AttackResults * results); // Lower Atk 1 stage
};

class TailWhip : public Status
{
public:
	TailWhip();
	~TailWhip();
	virtual bool checkValidity(Pokemon * defender); // Cannot lower Def to under -6
	virtual void primaryEffects(AttackResults * results); // Lower Def 1 stage
};

class QuickAttack : public Attack
{
public:
	QuickAttack();
	~QuickAttack();
	virtual bool checkValidity(Pokemon * defender); // None
	virtual void primaryEffects(AttackResults * results); // None
	virtual void secondaryEffects(AttackResults * results); // None
};

class Scratch : public Attack
{
public:
	Scratch();
	~Scratch();
	virtual bool checkValidity(Pokemon * defender); // None
	virtual void primaryEffects(AttackResults * results); // None
	virtual void secondaryEffects(AttackResults * results); // None
};

class Ember : public Attack
{
public:
	Ember();
	~Ember();
	virtual bool checkValidity(Pokemon * defender); // None
	virtual void primaryEffects(AttackResults * results); // None
	virtual void secondaryEffects(AttackResults * results); // 10% chance to BRN
};

class MetalClaw : public Attack
{
public:
	MetalClaw();
	~MetalClaw();
	virtual bool checkValidity(Pokemon * defender); // None
	virtual void primaryEffects(AttackResults * results); // None
	virtual void secondaryEffects(AttackResults * results); // 10% chance to increase Atk 1 stage
};

#endif // __MOVE_LIBRARY_H__