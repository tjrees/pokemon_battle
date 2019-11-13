// action.cpp
// Implementation of Action class
#include "action.h"
#include "pokemon_enums.h"
#include <iostream>
#include <cstdlib>

// The most generic level implemented in this file. Action only contains the action type
// (switch or attack) and the priority.
Action::Action(ActionType actionType_in, int priority_in)
: m_actionType(actionType_in), m_priority(priority_in) {}
Action::~Action() {}

// One level below Action. The listed parameters fill SwitchPokemon-specific values. The
// action_Switch enum value and priority of 6 are used to call the Action constructor
SwitchPokemon::SwitchPokemon(int out, int in) 
: Action(action_Switch, 6), m_switchOutIdx(out), m_switchInIdx(in) {}

SwitchPokemon::~SwitchPokemon() {}

// One level below Action. The listed parameters fill Move-specifc values. The action_Move
// enum value and priority are used to call the Action construcotr
Move::Move(std::string name_in, Type type_in, MoveType moveType_in, int maxPP_in, int PP_in, 
	int accuracy_in, bool oneTime_in, int priority_in)
	: Action(action_Move, priority_in), m_name(name_in), m_type(type_in), m_moveType(moveType_in), 
	m_maxPP(maxPP_in), m_PP(PP_in), m_accuracy(accuracy_in), m_oneTime(oneTime_in) {}
Move::~Move() {}

// Most specific level implemented in this file. There are no members specific to the Status
// class, so the parameters are used to call the Move constructor
Status::Status(std::string name_in, Type type_in, int maxPP_in, int PP_in, int accuracy_in, 
	bool oneTime_in, int priority_in)
	: Move(name_in, type_in, move_Status, maxPP_in, PP_in, accuracy_in, oneTime_in, priority_in) {}
Status::~Status() {}

// Most specific level implemented in this file. The listed parameters fill Attack-specific
// values and the rest are used to call the Move constructor
Attack::Attack(std::string name_in, Type type_in, int maxPP_in, int PP_in, int accuracy_in, 
	AttackType attackType_in, int power_in, bool contact_in, bool oneTime_in, int priority_in)
	: Move(name_in, type_in, move_Attack, maxPP_in, PP_in, accuracy_in, oneTime_in, priority_in), 
	m_attackType(attackType_in), m_power(power_in), m_contact(contact_in) {}
Attack::~Attack() {}

// Print fuction for a move. Prints the name, type, pp, and accuracy. Prints power
// if the move is an attack.
void Move::print()
{
	std::cout << m_name << " | ";
	std::cout << "Type: " << typeAsString(m_type) << " | ";
	std::cout << "PP: " << m_PP << "/" << m_maxPP << " | ";
	std::cout << "Power: ";
	if (m_moveType == move_Attack)
	{
		Attack * attackPtr = (Attack *) this;
		std::cout << attackPtr->m_power << " | ";
	}
	else {
		std::cout << "--- | ";
	}
	std::cout << "Accuracy: ";
	if (m_accuracy != -1)
	{
		std::cout << m_accuracy << "\n";
	}
	else
	{
		std::cout << "---\n";
	}
}

void AttackResults::print()
{
	if (critical > 1.0)
	{
		std::cout << "Critical hit!\n";
	}
	if (effectiveness == 0.0)
	{
		std::cout << "The move had no effect!\n";
	}
	else if (effectiveness < 1.0)
	{
		std::cout << "It's not very effective...\n";
	}
	else if (effectiveness > 1.0)
	{
		std::cout << "It's super effective!\n";
	}

}
