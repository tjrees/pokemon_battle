// pokedex.cpp
#include "pokedex.h"

// Charmander
Charmander::Charmander(int level_in, Gender gender_in) 
: Pokemon("Charmander", level_in, gender_in, Fire, NoneType, 39, 52, 43, 60, 50, 65) {}
Charmander::~Charmander() {}

// Pikachu
Pikachu::Pikachu(int level_in, Gender gender_in) 
: Pokemon("Pikachu", level_in, gender_in, Electric, NoneType, 35, 55, 30, 50, 40, 90){}
Pikachu::~Pikachu() {}
