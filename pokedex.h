#ifndef __POKEDEX_H__
#define __POKEDEX_H__
#include "pokemon.h"
#include "pokemon_enums.h"

// Charmander
class Charmander : public Pokemon
{
public:
	Charmander(int level_in, Gender gender_in);
	virtual ~Charmander();
};

// Pikachu
class Pikachu : public Pokemon
{
public:
	Pikachu(int level_in, Gender gender_in);
	virtual ~Pikachu();

};

// Red
// Arcanine FIRE - Intimidate
// 	Fire Blast / Wild Charge / Crunch / Extremespeed
class Arcanine : public Pokemon
{
public:
	Arcanine(int level_in, Gender gender_in);
	virtual ~Arcanine();

};

// Snorlax NRM PHY - Thick Fat
// 	Curse / Body Slam / Earthquake / Ice Punch
class Snorlax : public Pokemon
{
public:
	Snorlax(int level_in, Gender gender_in);
	virtual ~Snorlax();

};

// Steelix GRD STL PHY - Sturdy
// 	Earthquake / Iron Tail / Toxic / Roar
class Steelix : public Pokemon
{
public:
	Steelix(int level_in, Gender gender_in);
	virtual ~Steelix();

};

// Heracross BUG FIG PHY - Guts
//	Close Combat / Megahorn / Earthquake / Aerial Ace
class Heracross : public Pokemon
{
public:
	Heracross(int level_in, Gender gender_in);
	virtual ~Heracross();

};

// Gardevoir PSY FAI SPC - Synchronize
// 	Calm Mind / Stored Power / Moonblast / Double Team
class Gardevoir : public Pokemon
{
public:
	Gardevoir(int level_in, Gender gender_in);
	virtual ~Gardevoir();

};

// Walrein WTR ICE SPC - Thick Fat
//  Ice Beam / Surf / Crunch / Fissure
class Walrein : public Pokemon
{
public:
	Walrein(int level_in, Gender gender_in);
	virtual ~Walrein();

};


// Blue
// Gengar GST PSN SPC - Levitate
// 	Shadow Ball / Sludge Bomb / Thunderbolt / Will-O-Wisp
class Gengar : public Pokemon
{
public:
	Gengar(int level_in, Gender gender_in);
	virtual ~Gengar();

};

// Aerodactyl RCK FLY PHY - Pressure
//  Stone Edge / Earthquake / Roost / Fly
class Aerodactyl : public Pokemon
{
public:
	Aerodactyl(int level_in, Gender gender_in);
	virtual ~Aerodactyl();

};

// Houndoom DRK FIR SPC - Flash Fire
//  Nasty Plot / Flamethrower / Dark Pulse / Solar Beam
class Houndoom : public Pokemon
{
public:
	Houndoom(int level_in, Gender gender_in);
	virtual ~Houndoom();

};

// Kingdra WTR DRG SPC - Sniper
//  Draco Meteor / Waterfall / Dragon Dance / Hydro Pump
class Kingdra : public Pokemon
{
public:
	Kingdra(int level_in, Gender gender_in);
	virtual ~Kingdra();

};

// Breloom GRS FIG PHY - Poison Heal
//  Swords Dance / Mach Punch / Seed Bomb / Drain Punch
class Breloom : public Pokemon
{
public:
	Breloom(int level_in, Gender gender_in);
	virtual ~Breloom();

};

// Manectric ELE SPC - Lightning Rod
//  Thunderbolt / Flamethrower / Thunder Wave / Charge Beam
class Manectric : public Pokemon
{
public:
	Manectric(int level_in, Gender gender_in);
	virtual ~Manectric();

};


#endif // __POKEDEX_H__