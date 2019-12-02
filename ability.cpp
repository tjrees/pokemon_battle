// ability.cpp
#include "ability.h"
#include <iostream>

Ability::Ability(std::string name_in, std::string blurb_in) 
: m_name(name_in), m_blurb(blurb_in) {}

Ability::~Ability() {}

void Ability::print()
{
	std::cout << m_name << "\n";
	std::cout << m_blurb << "\n";
}