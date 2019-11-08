#ifndef __ACTION_H__
#define __ACTION_H__
#include <string>
#include "pokemon_enums.h"

class Action
{
public:
	Action(ActionType actionType_in, int priority_in);
	virtual ~Action() = 0;
	ActionType m_actionType;
	int m_priority; // Determines move order. Higher priority moves go first, with Pokemon speed as the tie breaker.
	virtual void use() = 0;

};

class SwitchPokemon : public Action
{
public:
	SwitchPokemon(int out, int in);
	virtual ~SwitchPokemon();
	int m_switchOutIdx;
	int m_switchInIdx;
	virtual void use();
};


class Move : public Action
{
public:
	Move(std::string name_in, Type type_in, MoveType moveType_in, int maxPP_in, int PP_in, int accuracy_in, int priority_in);
	virtual ~Move() = 0;
	std::string m_name;
	Type m_type;
	MoveType m_moveType;
	int m_maxPP;
	int m_PP;
	int m_accuracy;

	void print();
	virtual void use() = 0;

};

class Status : public Move
{
public:
	Status(std::string name_in, Type type_in, int maxPP_in, int PP_in, int accuracy_in, int priority_in);
	virtual ~Status() = 0;
	virtual void use() = 0;


};

class Attack : public Move
{
public:
	Attack(std::string name_in, Type type_in, int maxPP_in, int PP_in, int accuracy_in, AttackType attackType_in, 
		bool contact_in, int power_in, int priority_in);
	virtual ~Attack() = 0;
	AttackType m_attackType; // Tells if the move is physical or special
	bool m_contact;
	int m_power;

	virtual void use() = 0;

};

#endif // __ACTION_H__