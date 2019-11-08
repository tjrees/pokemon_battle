#ifndef __ITEM_H__
#define __ITEM_H__
#include <string>

class Pokemon;

class Item
{
public:
	std::string m_name;
	std::string m_blurb;
	Pokemon * m_holder;

	void onSwitchIn();
	void onSwitchOut();
	void onTurnBegin();
	void onTurnEnd();
	void onAttacked();
	void onAttack();
	void print();
};

#endif // __ITEM_H__