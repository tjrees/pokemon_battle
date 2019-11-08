// battle.cpp
// implements functions used during battle
#include <vector>
#include <cmath>
#include "pokemon.h"
#include "item.h"
#include "ability.h"
#include "trainer.h"
#include "action.h"
#include "pokemon_enums.h"

// battle
// requires - two trainers with valid teams and at least 1 non-fainted Pokemon each.
// modifies - parties of the trainers.
// effects - runs a batttle between the two trainers. Returns a pointer to the winner.
Trainer* battle(Trainer* trainer1, Trainer* trainer2)
{
	return trainer1;
}


static double typeChart[18][18] = 
{//	NRM		FIR		WTR		GRS		ELE		ICE		FIG		PSN		GRD		FLY		PSY 	BUG		RCK		GST		DRG		DRK		STL		FAI
	{1.0,	1.0,	1.0,	1.0,	1.0,	1.0,	1.0,	1.0,	1.0,	1.0,	1.0,	1.0,	0.5,	0.0,	1.0,	1.0,	0.5,	1.0}, // NRM
	{1.0,	0.5,	0.5,	2.0,	1.0,	2.0,	1.0,	1.0,	1.0,	1.0,	1.0,	2.0,	0.5,	1.0,	0.5,	1.0,	2.0,	1.0}, // FIR
	{1.0,	2.0,	0.5,	0.5,	1.0,	1.0,	1.0,	1.0,	2.0,	1.0,	1.0,	1.0,	2.0,	1.0,	0.5,	1.0,	1.0,	1.0}, // WTR
	{1.0,	0.5,	2.0,	0.5,	1.0,	1.0,	1.0,	0.5,	2.0,	0.5,	1.0,	0.5,	2.0,	1.0,	0.5,	1.0,	0.5,	1.0}, // GRS
	{1.0,	1.0,	2.0,	0.5,	0.5,	1.0,	1.0,	1.0,	0.0,	2.0,	1.0,	1.0,	1.0,	1.0,	0.5,	1.0,	1.0,	1.0}, // ELE
	{1.0,	0.5,	0.5,	2.0,	1.0,	0.5,	1.0,	1.0,	2.0,	2.0,	1.0,	1.0,	1.0,	1.0,	2.0,	1.0,	0.5,	1.0}, // ICE
	{2.0,	1.0,	1.0,	1.0,	1.0,	2.0,	1.0,	0.5,	1.0,	0.5,	0.5,	0.5,	2.0,	0.0,	1.0,	1.0,	2.0,	0.5}, // FIG
	{1.0,	1.0,	1.0,	2.0,	1.0,	1.0,	1.0,	0.5,	0.5,	1.0,	1.0,	1.0,	0.5,	0.5,	1.0,	2.0,	0.0,	2.0}, // PSN
	{1.0,	2.0,	1.0,	0.5,	2.0,	1.0,	1.0,	2.0,	1.0,	0.0,	1.0,	0.5,	2.0,	1.0,	1.0,	1.0,	2.0,	1.0}, // GRD
	{1.0,	1.0,	1.0,	2.0,	0.5,	1.0,	2.0,	1.0,	1.0,	1.0,	1.0,	2.0,	0.5,	1.0,	1.0,	1.0,	0.5,	1.0}, // FLY
	{1.0,	1.0,	1.0,	1.0,	1.0,	1.0,	2.0,	2.0,	1.0,	1.0,	0.5,	1.0,	1.0,	1.0,	1.0,	0.0,	0.5,	1.0}, // PSY
	{1.0,	0.5,	1.0,	2.0,	1.0,	1.0,	0.5,	0.5,	1.0,	0.5,	2.0,	1.0,	1.0,	0.5,	1.0,	2.0,	0.5,	0.5}, // BUG
	{1.0,	2.0,	1.0,	1.0,	1.0,	2.0,	0.5,	1.0,	0.5,	2.0,	1.0,	2.0,	1.0,	1.0,	1.0,	1.0,	0.5,	1.0}, // RCK
	{0.0,	1.0,	1.0,	1.0,	1.0,	1.0,	1.0,	1.0,	1.0,	1.0,	2.0,	1.0,	1.0,	2.0,	1.0,	0.5,	1.0,	1.0}, // GST
	{1.0,	1.0,	1.0,	1.0,	1.0,	1.0,	1.0,	1.0,	1.0,	1.0,	1.0,	1.0,	1.0,	1.0,	2.0,	1.0,	0.5,	0.0}, // DRG
	{1.0,	1.0,	1.0,	1.0,	1.0,	1.0,	0.5,	1.0,	1.0,	1.0,	2.0,	1.0,	1.0,	2.0,	1.0,	0.5,	1.0,	0.5}, // DRK
	{1.0,	0.5,	0.5,	1.0,	0.5,	2.0,	1.0,	1.0,	1.0,	1.0,	1.0,	1.0,	2.0,	1.0,	1.0,	1.0,	0.5,	2.0}, // STL
	{1.0,	0.5,	1.0,	1.0,	1.0,	1.0,	2.0,	0.5,	1.0,	1.0,	1.0,	1.0,	1.0,	1.0,	2.0,	2.0,	0.5,	1.0}  // FAI
};
// calculateEffectiveness
// requires - the attacking type is not NoneType
// modifies - nothing
// effects - calculates the effectiveness multiplier for an attack against a target
static double calculateEffectiveness(Type attackingType, Pokemon* target)
{
	double effectiveness = 1.0; // Default damage multiplier is 1.

	int xIdx = (int) attackingType;
	if (target->m_type1 != NoneType)
	{
		int yIdx = (int) target->m_type1;
		effectiveness *= typeChart[xIdx][yIdx];
	}
	if (target->m_type2 != NoneType)
	{
		int yIdx = (int) target->m_type2;
		effectiveness *= typeChart[xIdx][yIdx];
	}
	return effectiveness;
}

double calculateModifier(Pokemon * attacker, Pokemon * defender, Attack * attack)
{
	return 1.0;
}


// calculateDamage
// requires - the attacker uses a damaging move against the defender
// modifies - nothing. Damage will be applied outside of this function
// effects - calculates the amount of damage that will be done to the defender by the attacker's move
int calculateDamage(Pokemon * attacker, Pokemon * defender, Attack * attack)
{
	double atk, def;
	if (attack->m_attackType == Physical)
	{
		atk = (double) attacker->m_atk;
		def = (double) defender->m_def;
	}
	else
	{
		atk = (double) attacker->m_spAtk;
		def = (double) defender->m_def;
	}
	double levelEffect = (2.0 * (double) attacker->m_level) / 5.0 + 2.0;
	double preModifiedDamage = (levelEffect * attack->m_power * atk) / 50 + 2.0;
	double modifier = calculateModifier(attacker, defender, attack);
	return (int) (modifier * preModifiedDamage);
}


