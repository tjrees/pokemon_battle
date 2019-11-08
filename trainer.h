#ifndef __TRAINER_H__
#define __TRAINER_H__
#include <vector>
#include <string>

class Pokemon;

class Trainer
{
public:
	Trainer(std::string trainerName_in);
	~Trainer();

	std::string m_name;
	std::vector<Pokemon*> m_party;
	int m_activePokemon;


private:

};

#endif // __TRAINER_H__