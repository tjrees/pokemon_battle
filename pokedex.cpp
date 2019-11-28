// pokedex.cpp
#include "pokedex.h"

// Charmander
Charmander::Charmander(int level_in, Gender gender_in) 
: Pokemon("Charmander", level_in, gender_in, Fire, NoneType, nullptr, 39, 52, 43, 60, 50, 65) {}
Charmander::~Charmander() {}

// Pikachu
Pikachu::Pikachu(int level_in, Gender gender_in) 
: Pokemon("Pikachu", level_in, gender_in, Electric, NoneType, nullptr, 35, 55, 30, 50, 40, 90){}
Pikachu::~Pikachu() {}

// Arcanine
Arcanine::Arcanine(int level_in, Gender gender_in) 
: Pokemon("Arcanine", level_in, gender_in, Fire, NoneType, nullptr, 90, 110, 80, 100, 80, 95){}
Arcanine::~Arcanine() {}

// Snorlax
Snorlax::Snorlax(int level_in, Gender gender_in) 
: Pokemon("Snorlax", level_in, gender_in, Normal, NoneType, nullptr, 160, 110, 65, 65, 110, 30){}
Snorlax::~Snorlax() {}

// Steelix
Steelix::Steelix(int level_in, Gender gender_in) 
: Pokemon("Steelix", level_in, gender_in, Steel, Ground, nullptr, 75, 85, 200, 55, 65, 30){}
Steelix::~Steelix() {}

// Heracross
Heracross::Heracross(int level_in, Gender gender_in) 
: Pokemon("Heracross", level_in, gender_in, Bug, Fighting, nullptr, 80, 125, 75, 40, 95, 85){}
Heracross::~Heracross() {}

// Gardevoir
Gardevoir::Gardevoir(int level_in, Gender gender_in) 
: Pokemon("Gardevoir", level_in, gender_in, Psychic, Fairy, nullptr, 68, 65, 65, 125, 115, 80){}
Gardevoir::~Gardevoir() {}

// Walrein
Walrein::Walrein(int level_in, Gender gender_in) 
: Pokemon("Walrein", level_in, gender_in, Ice, Water, nullptr, 110, 80, 90, 95, 90, 65){}
Walrein::~Walrein() {}

// Gengar
Gengar::Gengar(int level_in, Gender gender_in) 
: Pokemon("Gengar", level_in, gender_in, Ghost, Poison, nullptr, 60, 65, 60, 130, 75, 110){}
Gengar::~Gengar() {}

// Aerodactyl
Aerodactyl::Aerodactyl(int level_in, Gender gender_in) 
: Pokemon("Aerodactyl", level_in, gender_in, Rock, Flying, nullptr, 80, 105, 65, 60, 75, 130){}
Aerodactyl::~Aerodactyl() {}

// Houndoom
Houndoom::Houndoom(int level_in, Gender gender_in) 
: Pokemon("Houndoom", level_in, gender_in, Dark, Fire, nullptr, 75, 90, 50, 110, 80, 95){}
Houndoom::~Houndoom() {}

// Kingdra
Kingdra::Kingdra(int level_in, Gender gender_in) 
: Pokemon("Kingdra", level_in, gender_in, Water, Dragon, nullptr, 75, 95, 95, 95, 95, 85){}
Kingdra::~Kingdra() {}

// Breloom
Breloom::Breloom(int level_in, Gender gender_in) 
: Pokemon("Breloom", level_in, gender_in, Grass, Fighting, nullptr, 60, 130, 80, 60, 60, 70){}
Breloom::~Breloom() {}

// Manectric
Manectric::Manectric(int level_in, Gender gender_in) 
: Pokemon("Manectric", level_in, gender_in, Electric, NoneType, nullptr, 70, 75, 60, 105, 60, 105){}
Manectric::~Manectric() {}
