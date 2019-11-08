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

#endif // __POKEDEX_H__