#ifndef __ACTION_H__
#include "pokemon_enums.h"

class Action
{
public:
	ActionType m_actionType;
	int priority; // Determines move order. Higher priority moves go first, with Pokemon speed as the tie breaker.

	virtual void 
};


class Move : public Action
{
public:
	Type m_type;
	int m_accuracy;

};

class Status : public Move
{
public:


};

class Attack : public Move
{
public:
	PhysSpec m_physSpec; // Tells if the move is physical or special
	int power;

};

#endif // __ACTION_H__