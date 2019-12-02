// ability_library.cpp
#include "ability_library.h"
#include "pokemon.h"
#include "pokemon_enums.h"
#include "trainer.h"
#include <iostream>

Intimidate::Intimidate() : Ability("Intimidate", "The Pokemon intimidates opposing Pokemon upon entering battle, lowering their Attack stat.") {}
Intimidate::~Intimidate() {}
void Intimidate::onSwitchIn() 
{
	// Reduce the opponent's attack stat
	Pokemon * other = m_user->m_trainer->m_opponent->m_party[m_user->m_trainer->m_opponent->m_activePokemon];
	Stat attack = ATK;
	int numStages = -1;
	std::cout << m_user->m_name << "'s Intimidate cuts the foe's Attack stat!\n";
	other->onStatChange(&attack, &numStages, m_user);
}
void Intimidate::onSwitchOut() {}
void Intimidate::onTurnBegin() {}
void Intimidate::onTurnEnd() {}
void Intimidate::onStatusDamage(int* statusDamage) {}
void Intimidate::onAttack(AttackResults * results) {}
void Intimidate::onAttacked(AttackResults * results) {}
void Intimidate::onDamaged(AttackResults * results) {}
void Intimidate::onMakingContact(AttackResults * results) {}
void Intimidate::onTakingContact(AttackResults * results) {}
void Intimidate::onStatChange(Stat * statChanged, int * numStages, Pokemon * other) {}
void Intimidate::onStatusChange(StatusEffect * statusEffect, Pokemon * other) {}
void Intimidate::onRecoilDamage(int * recoilDamage) {}

Immunity::Immunity() : Ability("Immunity", "The immune system of the Pokemon prevents it from getting poisoned.") {}
Immunity::~Immunity() {}
void Immunity::onSwitchIn() {}
void Immunity::onSwitchOut() {}
void Immunity::onTurnBegin() {}
void Immunity::onTurnEnd() {}
void Immunity::onStatusDamage(int* statusDamage) {}
void Immunity::onAttack(AttackResults * results) {}
void Immunity::onAttacked(AttackResults * results) {}
void Immunity::onDamaged(AttackResults * results) {}
void Immunity::onMakingContact(AttackResults * results) {}
void Immunity::onTakingContact(AttackResults * results) {}
void Immunity::onStatChange(Stat * statChanged, int * numStages, Pokemon * other) {}
void Immunity::onStatusChange(StatusEffect * statusEffect, Pokemon * other) 
{
	if (*statusEffect == PSN)
	{
		*statusEffect = OK;
		std::cout << m_user->m_name << "'s Immunity prevents Poison!\n";
	}
}
void Immunity::onRecoilDamage(int * recoilDamage) {}

Sturdy::Sturdy() : Ability("Sturdy", "It cannot be knocked out in one hit.") {}
Sturdy::~Sturdy() {}
void Sturdy::onSwitchIn() {}
void Sturdy::onSwitchOut() {}
void Sturdy::onTurnBegin() {}
void Sturdy::onTurnEnd() {}
void Sturdy::onStatusDamage(int* statusDamage) {}
void Sturdy::onAttack(AttackResults * results) {}
void Sturdy::onAttacked(AttackResults * results) {}
void Sturdy::onDamaged(AttackResults * results) 
{
	if (m_user->m_hp == m_user->m_maxHp &&
		results->totalDamage > m_user->m_hp)
	{
		results->totalDamage = m_user->m_hp - 1;
		std::cout << m_user->m_name << " held on using Sturdy!\n";
	}
}
void Sturdy::onMakingContact(AttackResults * results) {}
void Sturdy::onTakingContact(AttackResults * results) {}
void Sturdy::onStatChange(Stat * statChanged, int * numStages, Pokemon * other) {}
void Sturdy::onStatusChange(StatusEffect * statusEffect, Pokemon * other) {}
void Sturdy::onRecoilDamage(int * recoilDamage) {}

Guts::Guts() : Ability("Guts", "Boosts the Attack stat if the Pokemon has a status condition.") {}
Guts::~Guts() {}
void Guts::onSwitchIn() {}
void Guts::onSwitchOut() {}
void Guts::onTurnBegin() {}
void Guts::onTurnEnd() {}
void Guts::onStatusDamage(int* statusDamage) {}
void Guts::onAttack(AttackResults * results) 
{
	if (results->movePtr->m_moveType == move_Attack)
	{
		if (((Attack*) (results->movePtr))->m_attackType == Physical)
		{
			if (results->attacker->m_status == BRN)
			{
				results->additional *= 3;
			}
			else if (results->attacker->m_status != OK)
			{
				results->additional *= 1.5;
			}
		}
	}
}
void Guts::onAttacked(AttackResults * results) {}
void Guts::onDamaged(AttackResults * results) {}
void Guts::onMakingContact(AttackResults * results) {}
void Guts::onTakingContact(AttackResults * results) {}
void Guts::onStatChange(Stat * statChanged, int * numStages, Pokemon * other) {}
void Guts::onStatusChange(StatusEffect * statusEffect, Pokemon * other) {}
void Guts::onRecoilDamage(int * recoilDamage) {}

Synchronize::Synchronize() : Ability("Synchronize", "Passes a burn, paralysis, or poison on to the foe.") {}
Synchronize::~Synchronize() {}
void Synchronize::onSwitchIn() {}
void Synchronize::onSwitchOut() {}
void Synchronize::onTurnBegin() {}
void Synchronize::onTurnEnd() {}
void Synchronize::onStatusDamage(int* statusDamage) {}
void Synchronize::onAttack(AttackResults * results) {}
void Synchronize::onAttacked(AttackResults * results) {}
void Synchronize::onDamaged(AttackResults * results) {}
void Synchronize::onMakingContact(AttackResults * results) {}
void Synchronize::onTakingContact(AttackResults * results) {}
void Synchronize::onStatChange(Stat * statChanged, int * numStages, Pokemon * other) {}
void Synchronize::onStatusChange(StatusEffect * statusEffect, Pokemon * other) 
{
	if (m_user->m_status == OK && 
		(*statusEffect == PAR || *statusEffect == BRN || *statusEffect == PSN || *statusEffect == TOX))
	{
		Pokemon * other = m_user->m_trainer->m_opponent->m_party[m_user->m_trainer->m_opponent->m_activePokemon];
		if (other->m_status == OK)
		{
			// Temporarily change to avoid a possible Synchronize cycle
			m_user->m_status = *statusEffect;
			std::cout << m_user->m_name << "'s Synchronize!\n";
			other->onStatusChange(statusEffect, m_user);
			m_user->m_status = OK;
		}
	}
}
void Synchronize::onRecoilDamage(int * recoilDamage) {}

ThickFat::ThickFat() : Ability("Thick Fat", "Boosts resistance to Fire and Ice-type moves.") {}
ThickFat::~ThickFat() {}
void ThickFat::onSwitchIn() {}
void ThickFat::onSwitchOut() {}
void ThickFat::onTurnBegin() {}
void ThickFat::onTurnEnd() {}
void ThickFat::onStatusDamage(int* statusDamage) {}
void ThickFat::onAttack(AttackResults * results) {}
void ThickFat::onAttacked(AttackResults * results) 
{
	if (results->movePtr->m_moveType == move_Attack)
	{
		Attack * attackPtr = (Attack *) results->movePtr;
		if (attackPtr->m_type == Fire ||
			attackPtr->m_type == Ice)
		{
			results->additional *= 0.5;
		}
	}
}
void ThickFat::onDamaged(AttackResults * results) {}
void ThickFat::onMakingContact(AttackResults * results) {}
void ThickFat::onTakingContact(AttackResults * results) {}
void ThickFat::onStatChange(Stat * statChanged, int * numStages, Pokemon * other) {}
void ThickFat::onStatusChange(StatusEffect * statusEffect, Pokemon * other) {}
void ThickFat::onRecoilDamage(int * recoilDamage) {}

Levitate::Levitate() : Ability("Levitate", "Gives full immunity to all Ground-type moves.") {}
Levitate::~Levitate() {}
void Levitate::onSwitchIn() {}
void Levitate::onSwitchOut() {}
void Levitate::onTurnBegin() {}
void Levitate::onTurnEnd() {}
void Levitate::onStatusDamage(int* statusDamage) {}
void Levitate::onAttack(AttackResults * results) {}
void Levitate::onAttacked(AttackResults * results) 
{
	if (results->movePtr->m_moveType == move_Attack)
	{
		Attack * attackPtr = (Attack *) results->movePtr;
		if (attackPtr->m_type == Ground)
		{
			results->additional *= 0;
			std::cout << m_user->m_name << " makes Ground-type moves miss with Levitate!\n";
		}
	}
}
void Levitate::onDamaged(AttackResults * results) {}
void Levitate::onMakingContact(AttackResults * results) {}
void Levitate::onTakingContact(AttackResults * results) {}
void Levitate::onStatChange(Stat * statChanged, int * numStages, Pokemon * other) {}
void Levitate::onStatusChange(StatusEffect * statusEffect, Pokemon * other) {}
void Levitate::onRecoilDamage(int * recoilDamage) {}

Pressure::Pressure() : Ability("Pressure", "The Pokemon increases opposing Pokemon PP usage.") {}
Pressure::~Pressure() {}
void Pressure::onSwitchIn() 
{
	std::cout << m_user->m_name << " is exerting its Pressure!\n";
}
void Pressure::onSwitchOut() {}
void Pressure::onTurnBegin() {}
void Pressure::onTurnEnd() {}
void Pressure::onStatusDamage(int* statusDamage) {}
void Pressure::onAttack(AttackResults * results) {}
void Pressure::onAttacked(AttackResults * results) 
{
	if (results->movePtr->m_PP != 0)
	{
		results->movePtr->m_PP--;
	}
}
void Pressure::onDamaged(AttackResults * results) {}
void Pressure::onMakingContact(AttackResults * results) {}
void Pressure::onTakingContact(AttackResults * results) {}
void Pressure::onStatChange(Stat * statChanged, int * numStages, Pokemon * other) {}
void Pressure::onStatusChange(StatusEffect * statusEffect, Pokemon * other) {}
void Pressure::onRecoilDamage(int * recoilDamage) {}

FlashFire::FlashFire() : Ability("Flash Fire", "Powers up the Pokemon's Fire-type moves if it is hit by one."), m_activated(false) {}
FlashFire::~FlashFire() {}
void FlashFire::onSwitchIn() {}
void FlashFire::onSwitchOut() 
{
	m_activated = false;
}
void FlashFire::onTurnBegin() {}
void FlashFire::onTurnEnd() {}
void FlashFire::onStatusDamage(int* statusDamage) {}
void FlashFire::onAttack(AttackResults * results) 
{
	if (results->movePtr->m_type == Fire && 
		results->movePtr->m_moveType == move_Attack &&
		m_activated)
	{
		results->additional *= 1.5;
	}
}
void FlashFire::onAttacked(AttackResults * results) 
{
	if (results->movePtr->m_moveType == move_Attack)
	{
		Attack * attackPtr = (Attack *) results->movePtr;
		if (attackPtr->m_type == Fire)
		{
			results->additional *= 0;
			m_activated = true;
			std::cout << m_user->m_name << "'s Flash Fire powers up its Fire-type moves!\n";
		}
	}
}
void FlashFire::onDamaged(AttackResults * results) {}
void FlashFire::onMakingContact(AttackResults * results) {}
void FlashFire::onTakingContact(AttackResults * results) {}
void FlashFire::onStatChange(Stat * statChanged, int * numStages, Pokemon * other) {}
void FlashFire::onStatusChange(StatusEffect * statusEffect, Pokemon * other) {}
void FlashFire::onRecoilDamage(int * recoilDamage) {}

Sniper::Sniper() : Ability("Sniper", "Powers up moves if they become critical hits.") {}
Sniper::~Sniper() {}
void Sniper::onSwitchIn() {}
void Sniper::onSwitchOut() {}
void Sniper::onTurnBegin() {}
void Sniper::onTurnEnd() {}
void Sniper::onStatusDamage(int* statusDamage) {}
void Sniper::onAttack(AttackResults * results) 
{
	if (results->critical > 1.0)
	{
		results->additional *= 1.5;
	}
}
void Sniper::onAttacked(AttackResults * results) {}
void Sniper::onDamaged(AttackResults * results) {}
void Sniper::onMakingContact(AttackResults * results) {}
void Sniper::onTakingContact(AttackResults * results) {}
void Sniper::onStatChange(Stat * statChanged, int * numStages, Pokemon * other) {}
void Sniper::onStatusChange(StatusEffect * statusEffect, Pokemon * other) {}
void Sniper::onRecoilDamage(int * recoilDamage) {}

PoisonHeal::PoisonHeal() : Ability("PoisonHeal", "Restores HP if the Pokemon is poisoned.") {}
PoisonHeal::~PoisonHeal() {}
void PoisonHeal::onSwitchIn() {}
void PoisonHeal::onSwitchOut() {}
void PoisonHeal::onTurnBegin() {}
void PoisonHeal::onTurnEnd() {}
void PoisonHeal::onStatusDamage(int* statusDamage) 
{
	if (m_user->m_status == PSN)
	{
		*statusDamage = 0;
		int damageHealed = m_user->m_maxHp / 8;
		if (m_user->m_hp + damageHealed > m_user->m_maxHp)
		{
			damageHealed = m_user->m_maxHp - m_user->m_hp;
		}
		std::cout << m_user->m_name << " restored its health using Poison Heal!\n";
		m_user->m_hp += damageHealed;
	}
}
void PoisonHeal::onAttack(AttackResults * results) {}
void PoisonHeal::onAttacked(AttackResults * results) {}
void PoisonHeal::onDamaged(AttackResults * results) {}
void PoisonHeal::onMakingContact(AttackResults * results) {}
void PoisonHeal::onTakingContact(AttackResults * results) {}
void PoisonHeal::onStatChange(Stat * statChanged, int * numStages, Pokemon * other) {}
void PoisonHeal::onStatusChange(StatusEffect * statusEffect, Pokemon * other) {}
void PoisonHeal::onRecoilDamage(int * recoilDamage) {}

LightningRod::LightningRod() : Ability("Flash Fire", "Draws in all Electric-type moves to boost its Special Attack stat.") {}
LightningRod::~LightningRod() {}
void LightningRod::onSwitchIn() {}
void LightningRod::onSwitchOut() {}
void LightningRod::onTurnBegin() {}
void LightningRod::onTurnEnd() {}
void LightningRod::onStatusDamage(int* statusDamage) {}
void LightningRod::onAttack(AttackResults * results) {}
void LightningRod::onAttacked(AttackResults * results) 
{
	if (results->movePtr->m_moveType == move_Attack)
	{
		Attack * attackPtr = (Attack *) results->movePtr;
		if (attackPtr->m_type == Electric)
		{
			Stat changed = SPATK;
			int numStages = 1;
			m_user->onStatChange(&changed, &numStages, results->attacker);
		}
	}
}
void LightningRod::onDamaged(AttackResults * results) {}
void LightningRod::onMakingContact(AttackResults * results) {}
void LightningRod::onTakingContact(AttackResults * results) {}
void LightningRod::onStatChange(Stat * statChanged, int * numStages, Pokemon * other) {}
void LightningRod::onStatusChange(StatusEffect * statusEffect, Pokemon * other) {}
void LightningRod::onRecoilDamage(int * recoilDamage) {}

