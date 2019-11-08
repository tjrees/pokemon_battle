// action.cpp
#include "action.h"
#include <iostream>

void Move::print()
{
	std::cout << m_name << "\n" << typeAsString(m_type) << "\n";
	std::cout << "Power: ";
	if (m_moveType == move_Attack)
	{
		std::cout << ((Attack*) this)->m_power << "\n";
	}
	else {
		std::cout << "---\n";
	}
	std::cout << "Accuracy: ";
	if (m_accuracy != -1)
	{
		std::cout << m_accuracy << "\n";
	}
	else
	{
		std::cout << "---\n";
	}
}