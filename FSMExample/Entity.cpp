#include "Entity.h"
#include <cstdio>
#include <cstdlib>

void Entity::draw() const
{
	switch (state)
	{
	case DEFENSE: printf("%s %d is defending!\n", name, health); break;
	case OFFENSE: printf("%s %d is attacking!\n", name, health); break;
	case FAINTED: printf("%s %d is failure!\n", name, health); break;

	}
}

void Entity::init(const char a_name[], int a_threshold)
{
	sprintf_s(name, "%s", a_name);
	health = maxHealth = rand() % 120 + 120;	// 120 - 240
	attack = maxAttack = rand() % 20 + 20;		// 20  - 40
	armour = maxArmour = rand() % 60 + 60;		// 60 - 120

	critical = rand() % 4 + 1;					// 1 - 5

	threshold = rand() % health; // 0 - 240

	state = OFFENSE;
}

void Entity::step(Entity & e)
{

	switch (state)
	{
	case DEFENSE: defense(); break;
	case OFFENSE: offense(e); break;
	case FAINTED:;
	}
}

STATE Entity::offense(Entity & e)
{
	bool crit = rand() % critical == 0;
	int dmg = rand() % attack + attack;

	e.takeDamage(dmg, crit);

	// transition
	if (health > threshold || attack < 0)
		return DEFENSE;
	else if (health < 0)
		return FAINTED;
	else 
		return OFFENSE;
}

STATE Entity::defense()
{
	health += 5 + rand() % 30;
	attack += 5 + rand() % 5;
	armour += 5 + rand() % 5;

	if (health > maxHealth) health = maxHealth;
	if (attack > maxAttack) attack = maxAttack;
	if (armour > maxArmour) armour = maxArmour;

	// transition
	if (health > threshold)
		return OFFENSE;
	else if (health < 0)
		return FAINTED;
	else 
		return DEFENSE;
}

void Entity::takeDamage(int a_dmg, bool a_crit)
{
	int red = (a_dmg * 2) / 3;

	if (armour > red && !a_crit)
	{
		armour -= red;
		a_dmg -= red;
	}
	
	if (a_crit)
	{
		attack -= rand() % 10 + 5;
	}

	health -= a_dmg;
}

bool Entity::isAlive()
{
	return health > 0;
}
