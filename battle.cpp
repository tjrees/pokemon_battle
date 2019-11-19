// battle.cpp
// implements functions used during battle
#include <vector>
#include <cmath>
#include <iostream>
#include "battle.h"
#include "pokemon.h"
#include "item.h"
#include "ability.h"
#include "trainer.h"
#include "action.h"
#include "pokemon_enums.h"

static void moveUse(Move * movePtr, Pokemon * attacker, Pokemon * defender);

Battle::Battle() : trainer0(nullptr), trainer1(nullptr), turnCount(0) {}

void Battle::execute()
{
	if (trainer0 == nullptr || trainer1 == nullptr)
	{
		std::cout << "ERROR: There must be two trainers to start the battle!\n";
		return;
	}
	// Prompt trainers to choose their first pokemon.
	trainer0->m_activePokemon = trainer0->choosePokemon();
	trainer1->m_activePokemon = trainer1->choosePokemon();

	// Send out the Pokemon!
	std::cout << trainer0->m_name << " sent out " << trainer0->m_party[trainer0->m_activePokemon]->m_name << "!\n";
	std::cout << trainer1->m_name << " sent out " << trainer1->m_party[trainer1->m_activePokemon]->m_name << "!\n";
	// Pokemon will be switched in.
	simultaneousSwitch();
	bool beginEndOrder;
	bool actionOrder;

	while (trainer0->m_canBattle && trainer1->m_canBattle)
	{
		std::cout << "^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^\n";
		std::cout << trainer0->m_name << "\n";
		trainer0->m_party[trainer0->m_activePokemon]->battlePrint();
		std::cout << "\n";
		std::cout << "^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^\n";
		std::cout << trainer1->m_name << "\n";
		trainer1->m_party[trainer1->m_activePokemon]->battlePrint();

		// Select action, starting with trainer 0.
		Action * trainer0Action = trainer0->chooseAction();
		Action * trainer1Action = trainer1->chooseAction();

		// Run onTurnBegin functions in speed order
		int trainer0Speed = trainer0->determineSpeed();
		int trainer1Speed = trainer1->determineSpeed();
		if (trainer0Speed > trainer1Speed)
		{
			beginEndOrder = true;
		}
		else if (trainer0Speed < trainer1Speed)
		{
			beginEndOrder = false;
		}
		else
		{
			int speedTie = rand() % 2;
			if (speedTie == 0)
			{
				beginEndOrder = true;
			}
			else
			{
				beginEndOrder = false;
			}
		}
		if (beginEndOrder)
		{
			trainer0->m_party[trainer0->m_activePokemon]->onTurnBegin();
			trainer1->m_party[trainer1->m_activePokemon]->onTurnBegin();
		}
		else
		{
			trainer1->m_party[trainer1->m_activePokemon]->onTurnBegin();
			trainer0->m_party[trainer0->m_activePokemon]->onTurnBegin();
		}

		// Execute actions in order based on priority, then speed
		if (trainer0Action->m_priority > trainer1Action->m_priority)
		{
			actionOrder = true;
		}
		else if (trainer0Action->m_priority < trainer1Action->m_priority)
		{
			actionOrder = false;
		}
		else
		{
			if (trainer0Speed > trainer1Speed)
			{
				actionOrder = true;
			}
			else if (trainer0Speed < trainer1Speed)
			{
				actionOrder = false;
			}
			else
			{
				int speedTie = rand() % 2;
				if (speedTie == 0)
				{
					actionOrder = true;
				}
				else
				{
					actionOrder = false;
				}
			}
		}
		if (actionOrder)
		{
			runAction(trainer0Action, trainer0, trainer1);
			if (checkFaintedPokemon(false))
			{
				turnCount++;
				continue;
			}
			runAction(trainer1Action, trainer1, trainer0);
		}
		else
		{
			runAction(trainer1Action, trainer1, trainer0);
			if (checkFaintedPokemon(false))
			{
				turnCount++;
				continue;
			}
			runAction(trainer0Action, trainer0, trainer1);
		}
		if (checkFaintedPokemon(false))
		{
			turnCount++;
			continue;
		}

		// Run onTurnEnd functions (order does not matter).
		trainer0->m_party[trainer0->m_activePokemon]->onTurnEnd();
		trainer1->m_party[trainer1->m_activePokemon]->onTurnEnd();
		checkFaintedPokemon(true);
		turnCount++;
	}
	return;
}

// Checks if a pokemon from either side has fainted.
// If the trainer has remaining pokemon, have them switch in.
bool Battle::checkFaintedPokemon(bool endTurn)
{
	bool anyFainted = false; // if any pokemon faint, end the turn.
	while (trainer0->m_party[trainer0->m_activePokemon]->m_status == FNT ||
		trainer1->m_party[trainer1->m_activePokemon]->m_status == FNT)
	{
		anyFainted = true;
		// Both trainers switch if both pokemon have fainted.
		if (trainer0->m_party[trainer0->m_activePokemon]->m_status == FNT &&
			trainer1->m_party[trainer1->m_activePokemon]->m_status == FNT)
		{
			std::cout << trainer0->m_name << "'s " << trainer0->m_party[trainer0->m_activePokemon]->m_name << " fainted!\n";
			std::cout << trainer1->m_name << "'s " << trainer1->m_party[trainer1->m_activePokemon]->m_name << " fainted!\n";
			trainer0->checkHealth();
			trainer1->checkHealth();
			if (!trainer0->m_canBattle || !trainer1->m_canBattle)
			{
				return true;
			}
			trainer0->m_activePokemon = trainer0->choosePokemon();
			trainer1->m_activePokemon = trainer1->choosePokemon();
			simultaneousSwitch();
			if (!endTurn)
			{
				trainer0->m_party[trainer0->m_activePokemon]->onTurnEnd();
				trainer1->m_party[trainer1->m_activePokemon]->onTurnEnd();
				endTurn = true;
			}
		}
		// Trainer 0 switches if their pokemon fainted.
		else if (trainer0->m_party[trainer0->m_activePokemon]->m_status == FNT)
		{
			std::cout << trainer0->m_name << "'s " << trainer0->m_party[trainer0->m_activePokemon]->m_name << " fainted!\n";
			trainer0->checkHealth();
			if (!trainer0->m_canBattle)
			{
				return true;
			}
			trainer0->m_activePokemon = trainer0->choosePokemon();
			if (!endTurn)
			{
				trainer1->m_party[trainer1->m_activePokemon]->onTurnEnd();
				endTurn = true;
			}
		}
		// Trainer 1 switches if their pokemon fainted.
		else
		{
			std::cout << trainer1->m_name << "'s " << trainer1->m_party[trainer1->m_activePokemon]->m_name << " fainted!\n";
			trainer1->checkHealth();
			if (!trainer1->m_canBattle)
			{
				return true;
			}
			trainer1->m_activePokemon = trainer0->choosePokemon();
			if (!endTurn)
			{
				trainer0->m_party[trainer0->m_activePokemon]->onTurnEnd();
				endTurn = true;
			}
		}
	}
	return anyFainted;
}

// Calls onSwitchIn depending on Pokemon's speed stats.
// Speed stats cannot be modified after a switch in.
void Battle::simultaneousSwitch()
{
	int speed0 = trainer0->m_party[trainer0->m_activePokemon]->m_spd;
	int speed1 = trainer1->m_party[trainer1->m_activePokemon]->m_spd;
	if (speed0 > speed1)
	{
		trainer0->m_party[trainer0->m_activePokemon]->onSwitchIn();
		trainer1->m_party[trainer1->m_activePokemon]->onSwitchIn();
	}
	else if (speed0 < speed1)
	{
		trainer1->m_party[trainer1->m_activePokemon]->onSwitchIn();	
		trainer0->m_party[trainer0->m_activePokemon]->onSwitchIn();
	}
	else
	{
		int speedTie = rand() % 2;
		if (speedTie == 0)
		{
			trainer0->m_party[trainer0->m_activePokemon]->onSwitchIn();
			trainer1->m_party[trainer1->m_activePokemon]->onSwitchIn();
		}
		else
		{
			trainer1->m_party[trainer1->m_activePokemon]->onSwitchIn();	
			trainer0->m_party[trainer0->m_activePokemon]->onSwitchIn();
		}
	}
}

void Battle::runAction(Action * actionPtr, Trainer * user, Trainer * other)
{
	if (actionPtr->m_actionType == action_Switch)
	{
		SwitchPokemon * switchPtr = (SwitchPokemon *) actionPtr;
		user->m_party[user->m_activePokemon]->onSwitchOut();
		user->m_activePokemon = switchPtr->m_switchOutIdx;
		user->m_party[user->m_activePokemon]->onSwitchIn();
	}
	else if (actionPtr->m_actionType == action_Move)
	{
		Move * movePtr = (Move *) actionPtr;
		moveUse(movePtr, user->m_party[user->m_activePokemon], other->m_party[other->m_activePokemon]);
	}
	else
	{
		return;
	}
}


// This table assesses type advantages and disadvantages. The row is the attacking type,
// while the column is the defending type.
static double typeChart[19][19] = 
{//	NRM		FIR		WTR		GRS		ELE		ICE		FIG		PSN		GRD		FLY		PSY 	BUG		RCK		GST		DRG		DRK		STL		FAI 	N/A
	{1.0,	1.0,	1.0,	1.0,	1.0,	1.0,	1.0,	1.0,	1.0,	1.0,	1.0,	1.0,	0.5,	0.0,	1.0,	1.0,	0.5,	1.0, 	1.0}, // NRM
	{1.0,	0.5,	0.5,	2.0,	1.0,	2.0,	1.0,	1.0,	1.0,	1.0,	1.0,	2.0,	0.5,	1.0,	0.5,	1.0,	2.0,	1.0, 	1.0}, // FIR
	{1.0,	2.0,	0.5,	0.5,	1.0,	1.0,	1.0,	1.0,	2.0,	1.0,	1.0,	1.0,	2.0,	1.0,	0.5,	1.0,	1.0,	1.0, 	1.0}, // WTR
	{1.0,	0.5,	2.0,	0.5,	1.0,	1.0,	1.0,	0.5,	2.0,	0.5,	1.0,	0.5,	2.0,	1.0,	0.5,	1.0,	0.5,	1.0, 	1.0}, // GRS
	{1.0,	1.0,	2.0,	0.5,	0.5,	1.0,	1.0,	1.0,	0.0,	2.0,	1.0,	1.0,	1.0,	1.0,	0.5,	1.0,	1.0,	1.0, 	1.0}, // ELE
	{1.0,	0.5,	0.5,	2.0,	1.0,	0.5,	1.0,	1.0,	2.0,	2.0,	1.0,	1.0,	1.0,	1.0,	2.0,	1.0,	0.5,	1.0, 	1.0}, // ICE
	{2.0,	1.0,	1.0,	1.0,	1.0,	2.0,	1.0,	0.5,	1.0,	0.5,	0.5,	0.5,	2.0,	0.0,	1.0,	1.0,	2.0,	0.5, 	1.0}, // FIG
	{1.0,	1.0,	1.0,	2.0,	1.0,	1.0,	1.0,	0.5,	0.5,	1.0,	1.0,	1.0,	0.5,	0.5,	1.0,	2.0,	0.0,	2.0, 	1.0}, // PSN
	{1.0,	2.0,	1.0,	0.5,	2.0,	1.0,	1.0,	2.0,	1.0,	0.0,	1.0,	0.5,	2.0,	1.0,	1.0,	1.0,	2.0,	1.0, 	1.0}, // GRD
	{1.0,	1.0,	1.0,	2.0,	0.5,	1.0,	2.0,	1.0,	1.0,	1.0,	1.0,	2.0,	0.5,	1.0,	1.0,	1.0,	0.5,	1.0, 	1.0}, // FLY
	{1.0,	1.0,	1.0,	1.0,	1.0,	1.0,	2.0,	2.0,	1.0,	1.0,	0.5,	1.0,	1.0,	1.0,	1.0,	0.0,	0.5,	1.0, 	1.0}, // PSY
	{1.0,	0.5,	1.0,	2.0,	1.0,	1.0,	0.5,	0.5,	1.0,	0.5,	2.0,	1.0,	1.0,	0.5,	1.0,	2.0,	0.5,	0.5, 	1.0}, // BUG
	{1.0,	2.0,	1.0,	1.0,	1.0,	2.0,	0.5,	1.0,	0.5,	2.0,	1.0,	2.0,	1.0,	1.0,	1.0,	1.0,	0.5,	1.0, 	1.0}, // RCK
	{0.0,	1.0,	1.0,	1.0,	1.0,	1.0,	1.0,	1.0,	1.0,	1.0,	2.0,	1.0,	1.0,	2.0,	1.0,	0.5,	1.0,	1.0, 	1.0}, // GST
	{1.0,	1.0,	1.0,	1.0,	1.0,	1.0,	1.0,	1.0,	1.0,	1.0,	1.0,	1.0,	1.0,	1.0,	2.0,	1.0,	0.5,	0.0, 	1.0}, // DRG
	{1.0,	1.0,	1.0,	1.0,	1.0,	1.0,	0.5,	1.0,	1.0,	1.0,	2.0,	1.0,	1.0,	2.0,	1.0,	0.5,	1.0,	0.5, 	1.0}, // DRK
	{1.0,	0.5,	0.5,	1.0,	0.5,	2.0,	1.0,	1.0,	1.0,	1.0,	1.0,	1.0,	2.0,	1.0,	1.0,	1.0,	0.5,	2.0, 	1.0}, // STL
	{1.0,	0.5,	1.0,	1.0,	1.0,	1.0,	2.0,	0.5,	1.0,	1.0,	1.0,	1.0,	1.0,	1.0,	2.0,	2.0,	0.5,	1.0, 	1.0}, // FAI
	{1.0,	1.0,	1.0,	1.0,	1.0,	1.0,	1.0,	1.0,	1.0,	1.0,	1.0,	1.0,	1.0,	1.0,	1.0,	1.0,	1.0,	1.0,	1.0}  // N/A
};


// calculateEffectiveness
// requires - the attacking type is not NoneType
// modifies - nothing
// effects - calculates the effectiveness multiplier for an attack against a target
static double calculateEffectiveness(Type attackingType, Pokemon* target)
{
	double effectiveness = 1.0; // Default damage multiplier is 1.

	int xIdx = (int) attackingType;

	int yIdx = (int) target->m_type1;
	effectiveness *= typeChart[xIdx][yIdx];

	yIdx = (int) target->m_type2;
	effectiveness *= typeChart[xIdx][yIdx];
	return effectiveness;
}


// calculateDamage
// requires - the attacker uses a damaging move against the defender
// modifies - nothing. Damage will be applied outside of this function
// effects - calculates the amount of damage that will be done to the defender by the attacker's move
static double calculateDamage(Pokemon * attacker, Pokemon * defender, Attack * attack)
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
	double preModifiedDamage = (levelEffect * attack->m_power * (atk / def)) / 50.0 + 2.0;\
	return preModifiedDamage;
}

// Modified accuracy starts with a 3/3 fraction. Attacker accuracy buffs and 
// defender evasion debuffs add to the numerator value, while attacker accuracy 
// debuffs and evasion buffs add to the denominator value. The resulting value
// is multiplied to the attack's accuracy.
static double modifyAccuracy(int accuracy, int accuracyStage, int evasionStage)
{
	int numerator = 3;
	int denominator = 3;
	if (accuracyStage < 0)
	{
		denominator -= accuracyStage;
	}
	else 
	{
		numerator += accuracyStage;
	}
	if (evasionStage < 0)
	{
		numerator -= evasionStage;
	}
	else
	{
		denominator += evasionStage;
	}
	return double (accuracy) * (double(numerator) / double(denominator));
}


// The following are separate functions due to the presence of critical
// hits. A critical hit will reset the denominator to 2, but leave the
// numerator the same. However, these still need to be calculated in 
// the case of a defender ability or item (e.g. shell armor) that negates
// critical hits
static int modifyDamageNumerator(int attackStage, int defenseStage)
{
	int numerator = 2;
	if (attackStage > 0)
	{
		numerator += attackStage;
	}
	if (defenseStage < 0)
	{
		numerator -= defenseStage;
	}
	return numerator;
}

static int modifyDamageDenominator(int attackStage, int defenseStage)
{
	int denominator = 2;
	if (attackStage < 0)
	{
		denominator -= attackStage;
	}
	if (defenseStage > 0)
	{
		denominator += defenseStage;
	}
	return denominator;
}

// TODO: determine how to do all of this...
// TODO: split function. This is getting to be a monster
static void moveUse(Move * movePtr, Pokemon * attacker, Pokemon * defender)
{
	// Each use of a move will decrement PP, whether it fails or not.
	movePtr->m_PP--;
	std::cout << attacker->m_name << " used " << movePtr->m_name << "!\n";
	// First see if the attack is valid to use (e.g. cannot heal while at full health, cannot paralyze a sleeping pokemon)
	bool valid = movePtr->checkValidity(defender);
	// Return if the move fails
	if (!valid)
	{
		if (movePtr->m_oneTime)
		{
			delete movePtr;
		}
		std::cout << "But it failed!\n";
		return;
	}
	// Use accuracy to determine if this move hits
	bool hit = false;
	if (movePtr->m_accuracy == -1)
		hit = true;
	else 
	{
		double modifiedAccuracy = modifyAccuracy(movePtr->m_accuracy, attacker->m_accStage, defender->m_evaStage);
		double hitValue = (rand() % 100) + 1;
		if (hitValue <= modifiedAccuracy)
		{
			// Hits if the random value is <= to the accuracy.
			hit = true;
		}
	}
	// Return if the move misses
	if (!hit)
	{
		if (movePtr->m_oneTime)
		{
			delete movePtr;
		}
		std::cout << attacker->m_name << "'s attack missed!\n";
		return;
	}

	AttackResults * results = new AttackResults();
	results->attacker = attacker;
	results->defender = defender;
	results->nullified = false;
	results->additional = 1.0;
	results->unmodifiedDamage = 0.0;
	results->totalDamage = 0.0;

	// Only assess damage if the move is an attack
	if (movePtr->m_moveType == move_Attack)
	{
		Attack * attackPtr = (Attack *) movePtr;
		results->contact = true;
		results->attackType = attackPtr->m_attackType;
		results->nullified = false;
		results->additional = 1.0;
		// Calculate effectiveness. If the attack is ineffective, no primary
		// or secondary effects will occur.
		results->effectiveness = calculateEffectiveness(movePtr->m_type, defender);
		if (results->effectiveness == 0)
		{
			delete results;
			if (movePtr->m_oneTime)
			{
				delete movePtr;
			}
			return;
		}

		// Calculate STAB (same type attack bonus)
		results->stab = 1.0;
		if (movePtr->m_type == attacker->m_type1 || movePtr->m_type == attacker->m_type2)
		{
			results->stab = 1.5;
		}

		// Determine if the hit is critical or not critical
		results->critical = 1.0;
		double critValue = 100 * ((double) rand() / (double) RAND_MAX);
		if (attackPtr->m_highCritical && critValue <= 12.5)
		{
			results->critical = 2.0;
		}
		else if (!attackPtr->m_highCritical && critValue <= 6.25)
		{
			results->critical = 2.0;
		}

		// Calculate stat modificatons
		results->modifiedDamageNumerator = 2;
		results->modifiedDamageDenominator = 2;
		if (attackPtr->m_attackType == Physical)
		{
			results->modifiedDamageNumerator = modifyDamageNumerator(attacker->m_atkStage, defender->m_defStage);
			results->modifiedDamageDenominator = modifyDamageDenominator(attacker->m_atkStage, defender->m_defStage);
		}
		else
		{
			results->modifiedDamageNumerator = modifyDamageNumerator(attacker->m_spAtkStage, defender->m_spDefStage);
			results->modifiedDamageDenominator = modifyDamageDenominator(attacker->m_spAtkStage, defender->m_spDefStage);
		}

		// Calculate damage
		results->unmodifiedDamage = calculateDamage(attacker, defender, attackPtr);

		// Run results through attacker callback
		attacker->onAttack(results);

		// Run results through defender callback. This will deal damage to the defender
		defender->onAttacked(results);

		// If contact was made, run contact callback for attacker.
		if (attackPtr->m_contact)
		{
			attacker->onMakingContact(results);

			// Run contact callback for defender
			defender->onTakingContact(results);
		}

		if (results->nullified)
		{
			// If attack is nullified, return from the function.
			delete results;
			if (movePtr->m_oneTime)
			{
				delete movePtr;
			}
			return;
		}
		else
		{
			results->print();
		}
	}

	// Run primary effects
	movePtr->primaryEffects(results);

	if (movePtr->m_moveType == move_Attack && results->totalDamage != 0)
	{
		// run secondary effects
		Attack * attackPtr = (Attack *) movePtr;
		attackPtr->secondaryEffects(results);
	}

	// Clean up memory for one-time move (Struggle or a turn-2 move.)
	if (movePtr->m_oneTime)
	{
		delete movePtr;
	}
}


