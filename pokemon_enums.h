#ifndef __POKEMON_ENUMS_H__
#define __POKEMON_ENUMS_H__
#include <string>

typedef enum Type
{
	Normal = 0,
	Fire = 1,
	Water = 2,
	Grass = 3,
	Electric = 4,
	Ice = 5,
	Fighting = 6,
	Poison = 7,
	Ground = 8,
	Flying = 9,
	Psychic = 10,
	Bug = 11,
	Rock = 12,
	Ghost = 13,
	Dragon = 14,
	Dark = 15,
	Steel = 16,
	Fairy = 17,
	NoneType = 18 // Used to fill the second type slot of single-typed Pokemon
} Type;

std::string typeAsString(Type input);

typedef enum ActionType
{
	action_Switch, // The trainer elects to switch the active Pokemon out of battle
	action_Move // The trainer elects to use a move from the active Pokemon
} ActionType;

typedef enum MoveType
{
	move_Status,
	move_Attack
} MoveType;

std::string moveTypeAsString(MoveType input);

typedef enum StatusEffect
{
	OK, // Default status effect
	PAR, // Paralysis. Afflicted pokemon have speed cut to 1/4, and have a 1/4 chance to be fully paralyzed each turn.
	PSN, // Poison. Afflicted pokemon lose 1/8 of their max HP at the end of each turn.
	TOX, // Toxic poison. Starting at 1/16, afflicted pokemon lose health at an exponential rate, doubling the amount of damage each turn.
	BRN, // Burn. Afflicted pokemon lose 1/8 of their max HP at the end each turn, and have their Attack stat reduced by half.
	SLP, // Sleep. Afflicted pokemon are unable to move for 1 to 3 turns. This amount is determined randomly on switch-in and reset on switch-out.
	FRZ, // Freeze. Afflicted pokemon are unable to move, and have a 20% chance to thaw each turn. Fire type attacks used by either pokemon will thaw the FRZ condition.
	FNT // Faint. The pokemon's HP is 0, and cannot battle.
} StatusEffect;

std::string statusEffectAsString(StatusEffect input);

typedef enum AttackType
{
	Physical,
	Special
} AttackType;

std::string attackTypeAsString(AttackType input);

typedef enum Gender
{
	Male,
	Female,
	None
} Gender;

std::string genderAsString(Gender input);

typedef enum Stat
{
	HP,
	ATK,
	DEF,
	SPATK,
	SPDEF,
	SPD,
	ACC,
	EVA
} Stat;

std::string statAsString(Stat input);

#endif //__POKEMON_ENUMS_H__
