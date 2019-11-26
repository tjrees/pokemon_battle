// move_library.cpp
#include "move_library.h"
#include "pokemon_enums.h"
#include "pokemon.h"
#include <cmath>

// Struggle
Struggle::Struggle()
: Attack("Struggle", NoneType, 1, 1, 100, Physical, 40, true, true, 0) {}
Struggle::~Struggle() {}

void Struggle::primaryEffects(AttackResults * results) {}
void Struggle::secondaryEffects(AttackResults * results) {}

// ThunderShock
ThunderShock::ThunderShock()
: Attack("ThunderShock", Electric, 30, 30, 100, Special, 40, false, false, 0) {}

ThunderShock::~ThunderShock() {}

void ThunderShock::primaryEffects(AttackResults * results) {}
void ThunderShock::secondaryEffects(AttackResults * results)
{
	if (results->defender->m_status == OK &&
		results->defender->m_type != Electric &&
		results->defender->m_type != Ground)
	{
		// 10% chance of causing paralysis
		double chanceValue = (rand() % 100) + 1;
		if (chanceValue <= 10)
		{
			StatusEffect paralysis = PAR;
			results->defender->onStatusChange(&paralysis, results->attacker);
		}
	}
}

// Growl
Growl::Growl()
: Status("Growl", Normal, 40, 40, 100, false, 0) {}

Growl::~Growl() {}

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

void QuickAttack::primaryEffects(AttackResults * results) {}
void QuickAttack::secondaryEffects(AttackResults * results) {}

// Scratch
Scratch::Scratch()
: Attack("Scratch", Normal, 35, 35, 100, Physical, 40, true, false, 0) {}

Scratch::~Scratch() {}

void Scratch::primaryEffects(AttackResults * results) {}
void Scratch::secondaryEffects(AttackResults * results) {}

// Ember
Ember::Ember()
: Attack("Ember", Fire, 25, 25, 100, Special, 40, false, false, 0) {}

Ember::~Ember() {}

void Ember::primaryEffects(AttackResults * results) {}
void Ember::secondaryEffects(AttackResults * results)
{
	if (results->defender->m_status == OK)
	{
		// 10% chance of causing burn
		double chanceValue = (rand() % 100) + 1;
		if (chanceValue <= 10)
		{
			StatusEffect burn = BRN;
			results->defender->onStatusChange(&burn, results->attacker);
		}
	}
}

// MetalClaw
MetalClaw::MetalClaw()
: Attack("Metal Claw", Steel, 35, 35, 95, Physical, 50, true, false, 0) {}

MetalClaw::~MetalClaw() {}

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

// FireBlast
FireBlast::FireBlast()
: Attack("Fire Blast", Fire, 5, 5, 85, Special, 110, false, false, 0) {}

FireBlast::~FireBlast() {}

void FireBlast::primaryEffects(AttackResults * results) {}
void FireBlast::secondaryEffects(AttackResults * results)
{
	if (results->defender->m_status == OK)
	{
	// 30% chance of causing burn
		double chanceValue = (rand() % 100) + 1;
		if (chanceValue <= 10)
		{
			StatusEffect burn = BRN;
			results->defender->onStatusChange(&burn, results->attacker);
		}
	}
}

// Wild Charge
WildCharge::WildCharge()
: Attack("Wild Charge", Electric, 15, 15, 100, Physical, 90, true, false, 0) {}

WildCharge::~WildCharge() {}

void WildCharge::primaryEffects(AttackResults * results) 
{
	int recoilDamage = results->totalDamage / 4.0;
	onRecoilDamage(&recoilDamage);
}
void WildCharge::secondaryEffects(AttackResults * results){}

// Crunch
Crunch::Crunch()
: Attack("Crunch", Dark, 15, 15, 100, Physical, 80, true, false, 0) {}

Crunch::~Crunch() {}
void Crunch::primaryEffects(AttackResults * results) {}
void Crunch::secondaryEffects(AttackResults * results)
{
	double chanceValue = (rand() % 100) + 1;
	if (chanceValue <= 20)
	{
		Stat defense = DEF;
		int numStages = -1;
		results->defender->onStatChange(&defense, &numStages, results->attacker);
	}
}

// ExtremeSpeed
ExtremeSpeed::ExtremeSpeed()
: Attack("Extreme Speed", Normal, 5, 5, 100, Physical, 80, true, false, 2) {}

ExtremeSpeed::~ExtremeSpeed() {}
void ExtremeSpeed::primaryEffects(AttackResults * results) {}
void ExtremeSpeed::secondaryEffects(AttackResults * results) {}

// Curse
Curse::Curse()
: Status("Curse", Ghost, 10, 10, -1, false, 0) {}

Curse::~Curse() {} 
void Curse::primaryEffects(AttackResults * results) 
{
	Stat changed = SPD;
	int numStages = -1;
	results->attacker->onStatChange(&changed, &numStages, results->attacker);
	changed = ATK;
	int numStages = 1;
	results->attacker->onStatChange(&changed, &numStages, results->attacker);
	changed = DEF;
	int numStages = 1;
	results->attacker->onStatChange(&changed, &numStages, results->attacker);
}

// BodySlam
BodySlam::BodySlam()
: Attack("Body Slam", Normal, 15, 15, 100, Physical, 85, true, false, 0) {}

BodySlam::~BodySlam() {}

void BodySlam::primaryEffects(AttackResults * results) {}
void BodySlam::secondaryEffects(AttackResults * results)
{
	if (results->defender->m_status == OK)
	{
		// 30% chance of causing paralysis
		double chanceValue = (rand() % 100) + 1;
		if (chanceValue <= 30)
		{
			StatusEffect paralysis = PAR;
			results->defender->onStatusChange(&paralysis, results->attacker);
		}
	}
}

// Earthquake
Earthquake::Earthquake()
: Attack("Earthquake", Ground, 10, 10, 100, Physical, 100, false, false, 0) {}

Earthquake::~Earthquake() {}
void Earthquake::primaryEffects(AttackResults * results) {}
void Earthquake::secondaryEffects(AttackResults * results) {}

// IcePunch
IcePunch::IcePunch()
: Attack("Ice Punch", Ice, 15, 15, 100, Physical, 75, true, false, 0) {}

IcePunch::~IcePunch() {}

void IcePunch::primaryEffects(AttackResults * results) {}
void IcePunch::secondaryEffects(AttackResults * results)
{
	if (results->defender->m_status == OK)
	{
		double chanceValue = (rand() % 100) + 1;
		if (chanceValue <= 10)
		{
			StatusEffect freeze = FRZ;
			results->defender->onStatusChange(&freeze, results->attacker);
		}
	}
}

// IronTail
IronTail::IronTail()
: Attack("Iron Tail", Steel, 15, 15, 75, Physical, 100, true, false, 0) {}

IronTail::~IronTail() {}

void IronTail::primaryEffects(AttackResults * results) {}
void IronTail::secondaryEffects(AttackResults * results)
{
	double chanceValue = (rand() % 100) + 1;
	if (chanceValue <= 30)
	{
		Stat defense = DEF;
		int numStages = -1;
		results->defender->onStatChange(&defense, &numStages, results->attacker);
	}
}

// Toxic
Toxic::Toxic()
: Status("Toxic", Poison, 10, 10, 90, false, 0) {}

Toxic::~Toxic() {} 
void Toxic::primaryEffects(AttackResults * results) 
{
	if (results->defender->m_type == Steel || results->defender->m_type == Poison)
	{
		std::cout << results->defender->m_name << " is immune to posion!\n";
		return;
	}
	if (results->defender_m_status == OK)
	{
		StatusEffect toxic = TOX;
		results->defender->onStatusChange(&toxic, results->attacker);
	}
	else
	{
		std::cout << "... but it failed!\n";
	}
}

// CloseCombat
CloseCombat::CloseCombat()
: Attack("Close Combat", Fighting, 5, 5, 100, Physical, 120, true, false, 0) {}

CloseCombat::~CloseCombat() {}

void CloseCombat::primaryEffects(AttackResults * results) 
{
	Stat changed = DEF;
	int numStages = -1;
	results->defender->onStatChange(&changed, &numStages, results->attacker);
	changed = SPDEF;
	int numStages = -1;
	results->defender->onStatChange(&changed, &numStages, results->attacker);
}
void CloseCombat::secondaryEffects(AttackResults * results) {}

// Megahorn
Megahorn::Megahorn()
: Attack("Megahorn", Bug, 5, 5, 85, Physical, 120, true, false, 0) {}

Megahorn::~Megahorn() {}

void Megahorn::primaryEffects(AttackResults * results) {}
void Megahorn::secondaryEffects(AttackResults * results) {}

// AerialAce
AerialAce::AerialAce()
: Attack("Aerial Ace", Flying, 20, 20, -1, Physical, 60, true, false, 0) {}

AerialAce::~AerialAce() {}

void AerialAce::primaryEffects(AttackResults * results) {}
void AerialAce::secondaryEffects(AttackResults * results) {}

// CalmMind
CalmMind::CalmMind()
: Status("Calm Mind", Psychic, 20, 20, -1, false, 0) {}

CalmMind::~CalmMind() {} 
void CalmMind::primaryEffects(AttackResults * results) 
{
	Stat changed = SPATK;
	int numStages = 1;
	results->attacker->onStatChange(&changed, &numStages, results->attacker);
	changed = SPDEF;
	int numStages = 1;
	results->attacker->onStatChange(&changed, &numStages, results->attacker);
}

// StoredPower
StoredPower::StoredPower()
: Attack("Stored Power", Psychic, 10, 10, 100, Special, 20, false, false, 0) {}

StoredPower::~StoredPower() {}

void StoredPower::primaryEffects(AttackResults * results) {}
void StoredPower::secondaryEffects(AttackResults * results) {}

// Moonblast
Moonblast::Moonblast()
: Attack("Moonblast", Fairy, 15, 15, 100, Special, 95, false, false, 0) {}

Moonblast::~Moonblast() {}

void Moonblast::primaryEffects(AttackResults * results) {}
void Moonblast::secondaryEffects(AttackResults * results)
{
	double chanceValue = (rand() % 100) + 1;
	if (chanceValue <= 30)
	{
		Stat spAtk = SPATK;
		int numStages = -1;
		results->defender->onStatChange(&spAtk, &numStages, results->attacker);
	}
}

// DoubleTeam
DoubleTeam::DoubleTeam()
: Status("Double Team", Normal, 15, 15, -1, false, 0) {}

DoubleTeam::~DoubleTeam() {} 
void DoubleTeam::primaryEffects(AttackResults * results) 
{
	Stat changed = EVA;
	int numStages = 1;
	results->attacker->onStatChange(&changed, &numStages, results->attacker);
}

// IceBeam
IceBeam::IceBeam()
: Attack("Ice Beam", Ice, 10, 10, 100, Special, 90, false, false, 0) {}

IceBeam::~IceBeam() {}

void IceBeam::primaryEffects(AttackResults * results) {}
void IceBeam::secondaryEffects(AttackResults * results)
{
	if (results->defender->m_status == OK)
	{
		double chanceValue = (rand() % 100) + 1;
		if (chanceValue <= 10)
		{
			StatusEffect freeze = FRZ;
			results->defender->onStatusChange(&freeze, results->attacker);
		}
	}
}

// Surf
Surf::Surf()
: Attack("Surf", Water, 15, 15, 100, Special, 90, false, false, 0) {}

Surf::~Surf() {}

void Surf::primaryEffects(AttackResults * results) {}
void Surf::secondaryEffects(AttackResults * results) {}

// Fissure
Fissure::Fissure()
: Attack("Fissure", Ground, 5, 5, 30, Physical, 5, false, false, 0) {}

Fissure::~Fissure() {}
void Fissure::primaryEffects(AttackResults * results) {}
void Fissure::secondaryEffects(AttackResults * results) {}

// ShadowBall
ShadowBall::ShadowBall()
: Attack("Shadow Ball", Ghost, 15, 15, 100, Special, 80, false, false, 0) {}

ShadowBall::~ShadowBall() {}

void ShadowBall::primaryEffects(AttackResults * results) {}
void ShadowBall::secondaryEffects(AttackResults * results)
{
	double chanceValue = (rand() % 100) + 1;
	if (chanceValue <= 20)
	{
		Stat spDef = SPDEF;
		int numStages = -1;
		results->defender->onStatChange(&spDef, &numStages, results->attacker);
	}
}

// SludgeBomb
SludgeBomb::SludgeBomb()
: Attack("Sludge Bomb", Poison, 10, 10, 100, Special, 90, false, false, 0) {}

SludgeBomb::~SludgeBomb() {}

void SludgeBomb::primaryEffects(AttackResults * results) {}
void SludgeBomb::secondaryEffects(AttackResults * results)
{
	if (results->defender->m_status == OK && 
		results->defender->m_type != Poison &&
		results->defender->m_type != Steel)
	{
		double chanceValue = (rand() % 100) + 1;
		if (chanceValue <= 30)
		{
			StatusEffect poison = PSN;
			results->defender->onStatusChange(&poison, results->attacker);
		}
	}
}

// Thunderbolt
Thunderbolt::Thunderbolt()
: Attack("Thunderbolt", Electric, 15, 15, 100, Special, 90, false, false, 0) {}

Thunderbolt::~Thunderbolt() {}

void Thunderbolt::primaryEffects(AttackResults * results) {}
void Thunderbolt::secondaryEffects(AttackResults * results)
{
	if (results->defender->m_status == OK &&
		results->defender->m_type != Electric &&
		results->defender->m_type != Ground)
	{
		// 10% chance of causing paralysis
		double chanceValue = (rand() % 100) + 1;
		if (chanceValue <= 10)
		{
			StatusEffect paralysis = PAR;
			results->defender->onStatusChange(&paralysis, results->attacker);
		}
	}
}

// WillOWisp
WillOWisp::WillOWisp()
: Status("Will-O-Wisp", Fire, 15, 15, 85, false, 0) {}

WillOWisp::~WillOWisp() {} 
void WillOWisp::primaryEffects(AttackResults * results) 
{
	if (results->defender->m_type == Fire)
	{
		std::cout << results->defender->m_name << " is immune to burn!\n";
		return;
	}
	if (results->defender_m_status == OK)
	{
		StatusEffect burn = BRN;
		results->defender->onStatusChange(&burn, results->attacker);
	}
	else
	{
		std::cout << "... but it failed!\n";
	}
}



