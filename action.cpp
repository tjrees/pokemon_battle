// action.cpp
#include "action.h"
#include "pokemon_enums.h"
#include <iostream>


Action::Action(ActionType actionType_in, int priority_in)
: m_actionType(actionType_in), m_priority(priority_in) {}
Action::~Action() {}


SwitchPokemon::SwitchPokemon(int out, int in) 
: Action(action_Switch, 6), m_switchOutIdx(out), m_switchInIdx(in) {}

SwitchPokemon::~SwitchPokemon() {}
void SwitchPokemon::use()
{

}


Move::Move(std::string name_in, Type type_in, MoveType moveType_in, int maxPP_in, int PP_in, 
	int accuracy_in, int priority_in)
	: Action(action_Move, priority_in), m_name(name_in), m_type(type_in), m_moveType(moveType_in), 
	m_maxPP(maxPP_in), m_PP(PP_in), m_accuracy(accuracy_in) {}
Move::~Move() {}


Status::Status(std::string name_in, Type type_in, int maxPP_in, int PP_in, int accuracy_in, 
	int priority_in)
	: Move(name_in, type_in, move_Status, maxPP_in, PP_in, accuracy_in, priority_in) {}
Status::~Status() {}


Attack::Attack(std::string name_in, Type type_in, int maxPP_in, int PP_in, int accuracy_in, 
	AttackType attackType_in, bool contact_in, int power_in, int priority_in)
	: Move(name_in, type_in, move_Attack, maxPP_in, PP_in, accuracy_in, priority_in), 
	m_attackType(attackType_in), m_contact(contact_in), m_power(power_in) {}
Attack::~Attack() {}

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
