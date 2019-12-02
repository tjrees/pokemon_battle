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
	virtual void modifyDamage(AttackResults * results);
	virtual void primaryEffects(AttackResults * results); // None
	virtual void secondaryEffects(AttackResults * results); // None
};

class ThunderShock : public Attack
{
public:
	ThunderShock();
	~ThunderShock();
	virtual void modifyDamage(AttackResults * results);
	virtual void primaryEffects(AttackResults * results); // None
	virtual void secondaryEffects(AttackResults * results); // 10% chance to PAR
};

class Growl : public Status
{
public:
	Growl();
	~Growl();
	virtual void primaryEffects(AttackResults * results); // Lower Atk 1 stage
};

class TailWhip : public Status
{
public:
	TailWhip();
	~TailWhip();
	virtual void primaryEffects(AttackResults * results); // Lower Def 1 stage
};

class QuickAttack : public Attack
{
public:
	QuickAttack();
	~QuickAttack();
	virtual void modifyDamage(AttackResults * results);
	virtual void primaryEffects(AttackResults * results); // None
	virtual void secondaryEffects(AttackResults * results); // None
};

class Scratch : public Attack
{
public:
	Scratch();
	~Scratch();
	virtual void modifyDamage(AttackResults * results);
	virtual void primaryEffects(AttackResults * results); // None
	virtual void secondaryEffects(AttackResults * results); // None
};

class Ember : public Attack
{
public:
	Ember();
	~Ember();
	virtual void modifyDamage(AttackResults * results);
	virtual void primaryEffects(AttackResults * results); // None
	virtual void secondaryEffects(AttackResults * results); // 10% chance to BRN
};

class MetalClaw : public Attack
{
public:
	MetalClaw();
	~MetalClaw();
	virtual void modifyDamage(AttackResults * results);
	virtual void primaryEffects(AttackResults * results); // None
	virtual void secondaryEffects(AttackResults * results); // 10% chance to increase Atk 1 stage
};

class FireBlast : public Attack
{
public:
	FireBlast();
	~FireBlast();
	virtual void modifyDamage(AttackResults * results);
	virtual void primaryEffects(AttackResults * results); // None
	virtual void secondaryEffects(AttackResults * results); // 10% chance to burn
};

class WildCharge : public Attack
{
public:
	WildCharge();
	~WildCharge();
	virtual void modifyDamage(AttackResults * results);
	virtual void primaryEffects(AttackResults * results); // 1/4 recoil damage
	virtual void secondaryEffects(AttackResults * results); // None
};

class Crunch : public Attack
{
public:
	Crunch();
	~Crunch();
	virtual void modifyDamage(AttackResults * results);
	virtual void primaryEffects(AttackResults * results); // None
	virtual void secondaryEffects(AttackResults * results); // 20% chance to lower Defense 1 stage
};

class ExtremeSpeed : public Attack
{
public:
	ExtremeSpeed();
	~ExtremeSpeed();
	virtual void modifyDamage(AttackResults * results);
	virtual void primaryEffects(AttackResults * results); // None
	virtual void secondaryEffects(AttackResults * results); // None
};

class Curse : public Status
{
public:
	Curse();
	~Curse();
	virtual void primaryEffects(AttackResults * results); // Lower Speed 1 stage, increase Attack and Defense 1 stage
};

class BodySlam : public Attack
{
public:
	BodySlam();
	~BodySlam();
	virtual void modifyDamage(AttackResults * results);
	virtual void primaryEffects(AttackResults * results); // None
	virtual void secondaryEffects(AttackResults * results); // 30% chance to paralyze
};

class Earthquake : public Attack
{
public:
	Earthquake();
	~Earthquake();
	virtual void modifyDamage(AttackResults * results);
	virtual void primaryEffects(AttackResults * results); // None
	virtual void secondaryEffects(AttackResults * results); // None
};

class IcePunch : public Attack
{
public:
	IcePunch();
	~IcePunch();
	virtual void modifyDamage(AttackResults * results);
	virtual void primaryEffects(AttackResults * results); // None
	virtual void secondaryEffects(AttackResults * results); // 10% chance to freeze
};

class IronTail : public Attack
{
public:
	IronTail();
	~IronTail();
	virtual void modifyDamage(AttackResults * results);
	virtual void primaryEffects(AttackResults * results); // None
	virtual void secondaryEffects(AttackResults * results); // 30% chance to lower defense 1 stage
};

class Toxic : public Status
{
public:
	Toxic();
	~Toxic();
	virtual void primaryEffects(AttackResults * results); // Inflicts bad poision (TOX) status
};

class Roar : public Status
{
public:
	Roar();
	~Roar();
	virtual void primaryEffects(AttackResults * results); // Forces out opposing pokemon, switches for a random pokemon in party
};

class CloseCombat : public Attack
{
public:
	CloseCombat();
	~CloseCombat();
	virtual void modifyDamage(AttackResults * results);
	virtual void primaryEffects(AttackResults * results); // Drops Defense and Special Defense 1 stage
	virtual void secondaryEffects(AttackResults * results); // None
};

class Megahorn : public Attack
{
public:
	Megahorn();
	~Megahorn();
	virtual void modifyDamage(AttackResults * results);
	virtual void primaryEffects(AttackResults * results); // None
	virtual void secondaryEffects(AttackResults * results); // None
};

class AerialAce : public Attack
{
public:
	AerialAce();
	~AerialAce();
	virtual void modifyDamage(AttackResults * results);
	virtual void primaryEffects(AttackResults * results); // None
	virtual void secondaryEffects(AttackResults * results); // None
};

class CalmMind : public Status
{
public:
	CalmMind();
	~CalmMind();
	virtual void primaryEffects(AttackResults * results); // Increases Special Attack and Special Defense 1 stage
};

class StoredPower : public Attack
{
public:
	StoredPower();
	~StoredPower();
	virtual void modifyDamage(AttackResults * results);
	virtual void primaryEffects(AttackResults * results); // None
	virtual void secondaryEffects(AttackResults * results); // None
};

class Moonblast : public Attack
{
public:
	Moonblast();
	~Moonblast();
	virtual void modifyDamage(AttackResults * results);
	virtual void primaryEffects(AttackResults * results); // None
	virtual void secondaryEffects(AttackResults * results); // 30% chance to lower Special Attack 1 stage
};

class DoubleTeam : public Status
{
public:
	DoubleTeam();
	~DoubleTeam();
	virtual void primaryEffects(AttackResults * results); // Increases evasion 1 stage
};

class IceBeam : public Attack
{
public:
	IceBeam();
	~IceBeam();
	virtual void modifyDamage(AttackResults * results);
	virtual void primaryEffects(AttackResults * results); // None
	virtual void secondaryEffects(AttackResults * results); // 10% chance to freeze
};

class Surf : public Attack
{
public:
	Surf();
	~Surf();
	virtual void modifyDamage(AttackResults * results);
	virtual void primaryEffects(AttackResults * results); // None
	virtual void secondaryEffects(AttackResults * results); // None
};

class Fissure : public Attack
{
public:
	Fissure();
	~Fissure();
	virtual void modifyDamage(AttackResults * results);
	virtual void primaryEffects(AttackResults * results); // OHKO
	virtual void secondaryEffects(AttackResults * results); // None
};

class ShadowBall : public Attack
{
public:
	ShadowBall();
	~ShadowBall();
	virtual void modifyDamage(AttackResults * results);
	virtual void primaryEffects(AttackResults * results); // None
	virtual void secondaryEffects(AttackResults * results); // 20% chance to lower special defense 1 stage
};

class SludgeBomb : public Attack
{
public:
	SludgeBomb();
	~SludgeBomb();
	virtual void modifyDamage(AttackResults * results);
	virtual void primaryEffects(AttackResults * results); // None
	virtual void secondaryEffects(AttackResults * results); // 30% chance to poison
};

class Thunderbolt : public Attack
{
public:
	Thunderbolt();
	~Thunderbolt();
	virtual void modifyDamage(AttackResults * results);
	virtual void primaryEffects(AttackResults * results); // None
	virtual void secondaryEffects(AttackResults * results); // 10% chance to paralyze
};

class WillOWisp : public Status
{
public:
	WillOWisp();
	~WillOWisp();
	virtual void primaryEffects(AttackResults * results); // Burns target
};

class StoneEdge : public Attack
{
public:
	StoneEdge();
	~StoneEdge();
	virtual void modifyDamage(AttackResults * results);
	virtual void primaryEffects(AttackResults * results); // None
	virtual void secondaryEffects(AttackResults * results); // None
};

class Roost : public Status
{
public:
	Roost();
	~Roost();
	virtual void primaryEffects(AttackResults * results); // Restores half of max HP
};

class Fly : public Attack
{
public:
	Fly();
	~Fly();
	virtual void modifyDamage(AttackResults * results);
	virtual void primaryEffects(AttackResults * results); // None
	virtual void secondaryEffects(AttackResults * results); // None
};

class NastyPlot : public Status
{
public:
	NastyPlot();
	~NastyPlot();
	virtual void primaryEffects(AttackResults * results); // Increases Special Attack 2 stages
};

class Flamethrower : public Attack
{
public:
	Flamethrower();
	~Flamethrower();
	virtual void modifyDamage(AttackResults * results);
	virtual void primaryEffects(AttackResults * results); // None
	virtual void secondaryEffects(AttackResults * results); // 10% chance to burn
};

class DarkPulse : public Attack
{
public:
	DarkPulse();
	~DarkPulse();
	virtual void modifyDamage(AttackResults * results);
	virtual void primaryEffects(AttackResults * results); // None
	virtual void secondaryEffects(AttackResults * results); // 30% chance to flinch
};

class SolarBeam : public Attack
{
public:
	SolarBeam();
	~SolarBeam();
	virtual void modifyDamage(AttackResults * results);
	virtual void primaryEffects(AttackResults * results); // None
	virtual void secondaryEffects(AttackResults * results); // None
};

class SolarBeam_turn2 : public Attack
{
public:
	SolarBeam_turn2();
	~SolarBeam_turn2();
	virtual void modifyDamage(AttackResults * results);
	virtual void primaryEffects(AttackResults * results); // None
	virtual void secondaryEffects(AttackResults * results); // None
};

class DracoMeteor : public Attack
{
public:
	DracoMeteor();
	~DracoMeteor();
	virtual void modifyDamage(AttackResults * results);
	virtual void primaryEffects(AttackResults * results); // Drop Special Attack by 2 stages
	virtual void secondaryEffects(AttackResults * results); // None
};

class Waterfall : public Attack
{
public:
	Waterfall();
	~Waterfall();
	virtual void modifyDamage(AttackResults * results);
	virtual void primaryEffects(AttackResults * results); // None
	virtual void secondaryEffects(AttackResults * results); // 30% chance to flinch
};

class DragonDance : public Status
{
public:
	DragonDance();
	~DragonDance();
	virtual void primaryEffects(AttackResults * results); // Increases Speed and Attack by 1 stage
};

class HydroPump : public Attack
{
public:
	HydroPump();
	~HydroPump();
	virtual void modifyDamage(AttackResults * results);
	virtual void primaryEffects(AttackResults * results); // None
	virtual void secondaryEffects(AttackResults * results); // None
};

class SwordsDance : public Status
{
public:
	SwordsDance();
	~SwordsDance();
	virtual void primaryEffects(AttackResults * results); // Increases Attack 2 stages
};

class MachPunch : public Attack
{
public:
	MachPunch();
	~MachPunch();
	virtual void modifyDamage(AttackResults * results);
	virtual void primaryEffects(AttackResults * results); // None
	virtual void secondaryEffects(AttackResults * results); // None
};

class SeedBomb : public Attack
{
public:
	SeedBomb();
	~SeedBomb();
	virtual void modifyDamage(AttackResults * results);
	virtual void primaryEffects(AttackResults * results); // None
	virtual void secondaryEffects(AttackResults * results); // None
};

class DrainPunch : public Attack
{
public:
	DrainPunch();
	~DrainPunch();
	virtual void modifyDamage(AttackResults * results);
	virtual void primaryEffects(AttackResults * results); // Restores 1/2 of the damage dealt
	virtual void secondaryEffects(AttackResults * results); // None
};

class ThunderWave : public Status
{
public:
	ThunderWave();
	~ThunderWave();
	virtual void primaryEffects(AttackResults * results); // Paralyzes target
};

class ChargeBeam : public Attack
{
public:
	ChargeBeam();
	~ChargeBeam();
	virtual void modifyDamage(AttackResults * results);
	virtual void primaryEffects(AttackResults * results); // None
	virtual void secondaryEffects(AttackResults * results); // 70% chance to increase Special Attack 1 stage
};

#endif // __MOVE_LIBRARY_H__