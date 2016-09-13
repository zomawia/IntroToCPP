#pragma once

enum STATE
{
	DEFENSE,
	OFFENSE,
	FAINTED
};

class Entity
{
private:
	char name[64];
	int health, maxHealth;
	int attack, maxAttack;
	int armour, maxArmour;
	int critical;
	int threshold;

	STATE state;

	STATE offense(Entity &e);
	STATE defense();

	void takeDamage(int a_dmg, bool a_crit);

public:
	void draw() const;
	void init(const char a_name[], int a_threshold);

	void step(Entity &e);

	bool isAlive();

};
