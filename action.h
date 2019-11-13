#ifndef __ACTION_H__
#define __ACTION_H__
// Definition of the Action class. This class and its derived
// classes have the Trainer or Pokemon "do" things in battle.
#include <string>
#include <vector>
#include "pokemon_enums.h"

class Pokemon;
struct AttackResults;

// Most generic class. Only contains the action type (Switch, Move)
// and priority.
class Action
{
public:
	Action(ActionType actionType_in, int priority_in);
	virtual ~Action() = 0;
	ActionType m_actionType;
	int m_priority; // Determines move order. Higher priority moves go first, with Pokemon speed as the tie breaker.

};

// This class defines a switch from one Pokemon to another.
class SwitchPokemon : public Action
{
public:
	SwitchPokemon(int out, int in);
	virtual ~SwitchPokemon();
	int m_switchOutIdx;
	int m_switchInIdx;
};

// This class defines a move used by a Pokemon. It can be
// either an attacking move or a status move.
class Move : public Action
{
public:
	Move(std::string name_in, Type type_in, MoveType moveType_in, int maxPP_in, int PP_in, int accuracy_in, bool oneTime_in, int priority_in);
	virtual ~Move() = 0;
	std::string m_name;
	Type m_type;
	MoveType m_moveType;
	int m_maxPP;
	int m_PP;
	int m_accuracy;
	bool m_oneTime; // If this move is a one time move, it will be deleted after use.

	void print();
	virtual bool checkValidity(Pokemon * defender) = 0;
	virtual void primaryEffects(AttackResults * results) = 0;

};

// This class defines a status move used by a Pokemon.
// These moves do not directly inflict damage.
class Status : public Move
{
public:
	Status(std::string name_in, Type type_in, int maxPP_in, int PP_in, int accuracy_in, bool oneTime_in, int priority_in);
	virtual ~Status() = 0;
	virtual bool checkValidity(Pokemon * defender) = 0;
	virtual void primaryEffects(AttackResults * results) = 0;


};

// This class defines an attacking move used by a Pokemon.
// These moves directly do damage and may make contact with the opponent.
class Attack : public Move
{
public:
	Attack(std::string name_in, Type type_in, int maxPP_in, int PP_in, int accuracy_in, AttackType attackType_in, 
		int power_in, bool contact_in, bool oneTime_in, int priority_in);
	virtual ~Attack() = 0;
	AttackType m_attackType; // Tells if the move is physical or special
	int m_power; // Base power of the attack, determines how much damage it will do
	bool m_contact; // Tells if the attack makes contact with the opponent
	bool m_highCritical; // Tells if the attack has a high critical hit ratio

	virtual bool checkValidity(Pokemon * defender) = 0;
	virtual void primaryEffects(AttackResults * results) = 0;
	virtual void secondaryEffects(AttackResults * results) = 0; // Only attacks have secondary effects
};

struct AttackResults
{
	double effectiveness; // Some items and abilities boost the power of super effective moves (e.g. Expert Belt)
	double stab; // Some items and abilities boost the power of STAB moves (e.g. Adaptability)
	double critical; // Some items and abilities boost the power of critical hit moves, or nullify their effects (e.g. Sniper, Shell Armor)
	double unmodifiedDamage; // Set to 0 when an attack is nullified (e.g. Flare Blitz has no recoil if used on a Pokemon with Flash Fire)
	double additional; // For any additional boost in damage (e.g. Plates, Aerilate)
	int modifiedDamageNumerator; // Cleared for certain abilities and items (e.g. Unaware)
	int modifiedDamageDenominator; // Cleared for critical hits and certain abilities and items (e.g. Unaware)
	int totalDamage;
	bool nullified; // Set by the attacked pokemon if the ability or item nullifies the attack (e.g. Sap Sipper, Water Absorb)

	Pokemon * attacker;
	Pokemon * defender;

	void print();
};

#endif // __ACTION_H__