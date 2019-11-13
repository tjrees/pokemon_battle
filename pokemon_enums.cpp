// pokemon_enums.cpp
#include "pokemon_enums.h"

std::string typeAsString(Type input)
{
	switch (input)
	{
		case Normal:
			return "Normal";
		case Fire:
			return "Fire";
		case Water:
			return "Water";
		case Grass:
			return "Grass";
		case Electric:
			return "Electric";
		case Fighting:
			return "Fighting";
		case Poison:
			return "Poison";
		case Ground:
			return "Ground";
		case Flying:
			return "Flying";
		case Psychic:
			return "Psychic";
		case Bug:
			return "Bug";
		case Rock:
			return "Rock";
		case Ghost:
			return "Ghost";
		case Dragon:
			return "Dragon";
		case Dark:
			return "Dark";
		case Steel:
			return "Steel";
		case Fairy:
			return "Fairy";
		default: // NoneType
			return "";
	}
}


std::string moveTypeAsString(MoveType input)
{
	if (input == move_Status)
	{
		return "Status";
	}
	else 
	{
		return "Attack";
	}
}

std::string statusEffectAsString(StatusEffect input)
{
	switch (input)
	{
		case PAR:
			return "PAR";
		case PSN:
			return "PSN";
		case TOX:
			return "TOX";
		case BRN:
			return "BRN";
		case SLP:
			return "SLP";
		case FRZ:
			return "FRZ";
		case FNT:
			return "FNT";
		default:
			return "OK";
	}
}

std::string attackTypeAsString(AttackType input)
{
	if (input == Physical)
	{
		return "Physical";
	}
	else
	{
		return "Special";
	}
}


std::string genderAsString(Gender input)
{
	if (input == Male)
	{
		return "Male";
	}
	else
	{
		return "Female";
	}
}

std::string statAsString(Stat input)
{
	switch (input)
	{
		case HP:
			return "HP";
		case ATK:
			return "Attack";
		case DEF:
			return "Defense";
		case SPATK:
			return "Special Attack";
		case SPDEF:
			return "Special Defense";
		case SPD:
			return "Speed";
		case ACC:
			return "Accuracy";
		default: // EVA
			return "Evasiveness";
	}
}

