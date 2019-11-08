#ifndef __ACTION_H__
#define __ACTION_H__
#include <string>
#include "pokemon_enums.h"

class Action
{
public:
	ActionType m_actionType;
	int priority; // Determines move order. Higher priority moves go first, with Pokemon speed as the tie breaker.

};


class Move : public Action
{
public:
	std::string m_name;
	Type m_type;
	MoveType m_moveType;
	int m_accuracy;

	void print();

};

class Status : public Move
{
public:


};

class Attack : public Move
{
public:
	AttackType m_attackType; // Tells if the move is physical or special
	int m_power;

};

#endif // __ACTION_H__