#ifndef __MOVE_LIBRARY_H__
#define __MOVE_LIBRARY_H__

#include "action.h"
// class Action;
// class SwitchPokemon;
// class Move;
// class Status;
// class Attack;

class ThunderShock : public Attack
{
public:
	ThunderShock();
	~ThunderShock();
	virtual void use();
};

class Growl : public Status
{
public:
	Growl();
	~Growl();
	virtual void use();
};

class TailWhip : public Status
{
public:
	TailWhip();
	~TailWhip();
	virtual void use();
};

class QuickAttack : public Attack
{
public:
	QuickAttack();
	~QuickAttack();
	virtual void use();
};

class Scratch : public Attack
{
public:
	Scratch();
	~Scratch();
	virtual void use();
};

class Ember : public Attack
{
public:
	Ember();
	~Ember();
	virtual void use();
};

class MetalClaw : public Attack
{
public:
	MetalClaw();
	~MetalClaw();
	virtual void use();
};

#endif // __MOVE_LIBRARY_H__