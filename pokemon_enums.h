#ifndef __POKEMON_ENUMS_H__

enum Type
{
	Normal,
	Grass,
	Fire,
	Water,
	Electric,
	Fighting,
	Bug,
	Psychic,
	Ground,
	Rock,
	Flying,
	Poison,
	Ghost,
	Ice,
	Dragon,
	Steel,
	Dark,
	Fairy,
	NoneType // Used to fill the second type slot of single-typed Pokemon
};

enum ActionType
{
	Switch, // The trainer elects to switch the active Pokemon out of battle
	Move // The trainer elects to use a move from the active Pokemon
}

enum Status
{
	OK, // Default status effect
	PAR, // Paralysis. Afflicted pokemon have speed cut to 1/4, and have a 1/4 chance to be fully paralyzed each turn.
	PSN, // Poison. Afflicted pokemon lose 1/8 of their max HP at the end of each turn.
	TOX, // Toxic poison. Starting at 1/16, afflicted pokemon lose health at an exponential rate, doubling the amount of damage each turn.
	BRN, // Burn. Afflicted pokemon lose 1/8 of their max HP at the end each turn, and have their Attack stat reduced by half.
	SLP, // Sleep. Afflicted pokemon are unable to move for 1 to 3 turns. This amount is determined randomly on switch-in and reset on switch-out.
	FRZ // Freeze. Afflicted pokemon are unable to move, and have a 20% chance to thaw each turn. Fire type attacks used by either pokemon will thaw the FRZ condition.
}

enum PhysSpec
{
	Physical,
	Special
}

#endif //__POKEMON_ENUMS_H__