#ifndef __BATTLE_H__
#define __BATTLE_H__
#include <queue>

class Pokemon;
class Trainer;
class Action;

class Battle
{
public:
	Battle();
	~Battle();

	Trainer * trainer0;
	Trainer * trainer1;

	int turnCount;

	void execute();
	void simultaneousSwitch();
	void beginTurn();
	void endTurn();
	void selectActions();
	void runAction(Action * actionPtr, Trainer * user, Trainer * other);
	bool checkFaintedPokemon(bool endTurn);
};

#endif // __BATTLE_H__