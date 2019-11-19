// move_library.cpp
#include "move_library.h"
#include "pokemon_enums.h"
#include "pokemon.h"
#include <cmath>

// Struggle
Struggle::Struggle()
: Attack("Struggle", NoneType, 1, 1, 100, Physical, 40, true, true, 0) {}
Struggle::~Struggle() {}

bool Struggle::checkValidity(Pokemon * defender) {return true;}
void Struggle::primaryEffects(AttackResults * results) {}
void Struggle::secondaryEffects(AttackResults * results) {}

// ThunderShock
ThunderShock::ThunderShock()
: Attack("ThunderShock", Electric, 30, 30, 100, Special, 40, false, false, 0) {}

ThunderShock::~ThunderShock() {}

bool ThunderShock::checkValidity(Pokemon * defender) {return true;}
void ThunderShock::primaryEffects(AttackResults * results) {}
void ThunderShock::secondaryEffects(AttackResults * results)
{
	// 10% chance of causing paralysis
	double chanceValue = (rand() % 100) + 1;
	if (chanceValue <= 10)
	{
		StatusEffect paralysis = PAR;
		results->defender->onStatusChange(&paralysis, results->attacker);
	}
}

// Growl
Growl::Growl()
: Status("Growl", Normal, 40, 40, 100, false, 0) {}

Growl::~Growl() {}

bool Growl::checkValidity(Pokemon * defender) {return true;}
void Growl::primaryEffects(AttackResults * results) 
{
	Stat attack = ATK;
	int numStages = -1;
	results->defender->onStatChange(&attack, &numStages, results->attacker);
}

// TailWhip
TailWhip::TailWhip()
: Status("Tail Whip", Normal, 30, 30, 100, false, 0) {}

TailWhip::~TailWhip() {}

bool TailWhip::checkValidity(Pokemon * defender) {return true;}
void TailWhip::primaryEffects(AttackResults * results) 
{
	Stat defense = DEF;
	int numStages = -1;
	results->defender->onStatChange(&defense, &numStages, results->attacker);
}

// QuickAttack
QuickAttack::QuickAttack()
: Attack("Quick Attack", Normal, 30, 30, 100, Physical, 40, true, false, 1) {}

QuickAttack::~QuickAttack() {}

bool QuickAttack::checkValidity(Pokemon * defender) {return true;}
void QuickAttack::primaryEffects(AttackResults * results) {}
void QuickAttack::secondaryEffects(AttackResults * results) {}

// Scratch
Scratch::Scratch()
: Attack("Scratch", Normal, 35, 35, 100, Physical, 40, true, false, 0) {}

Scratch::~Scratch() {}

bool Scratch::checkValidity(Pokemon * defender) {return true;}
void Scratch::primaryEffects(AttackResults * results) {}
void Scratch::secondaryEffects(AttackResults * results) {}

// Ember
Ember::Ember()
: Attack("Ember", Fire, 25, 25, 100, Special, 40, false, false, 0) {}

Ember::~Ember() {}

bool Ember::checkValidity(Pokemon * defender) {return true;}
void Ember::primaryEffects(AttackResults * results) {}
void Ember::secondaryEffects(AttackResults * results)
{
	// 10% chance of causing burn
	double chanceValue = (rand() % 100) + 1;
	if (chanceValue <= 10)
	{
		StatusEffect burn = BRN;
		results->defender->onStatusChange(&burn, results->attacker);
	}
}

// MetalClaw
MetalClaw::MetalClaw()
: Attack("Metal Claw", Steel, 35, 35, 95, Physical, 50, true, false, 0) {}

MetalClaw::~MetalClaw() {}

bool MetalClaw::checkValidity(Pokemon * defender) {return true;}
void MetalClaw::primaryEffects(AttackResults * results) {}
void MetalClaw::secondaryEffects(AttackResults * results)
{
	// 10% chance of increasing attack one stage
	double chanceValue = (rand() % 100) + 1;
	if (chanceValue <= 10)
	{
		Stat attack = ATK;
		int numStages = 1;
		results->attacker->onStatChange(&attack, &numStages, results->attacker);
	}
}
