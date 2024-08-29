#pragma once
#ifndef GUMMYBEAR_H
#define GUMMYBEAR_H

#include <string>
// gummybear class for player

class GummyBear
{
protected:
	int maxHealth;
	int level;
	int health;
	int attack;
	int defense;
	int speed;
	std::string name;
	int id;
	static int nextID;
	bool defending;

public:
	GummyBear(std::string name, int level, int health, int attack, int defense, int speed, int maxHealth);
	~GummyBear() {}


	int getID() const;
	std::string getName() const;
	int getLevel() const;
	int getHealth() const;
	int getAttack() const;
	int getDefense() const;
	int getSpeed() const;
	int getMaxHealth() const;

	void setName(std::string newName);
	void setLevel(int newLevel);
	void setHealth(int newHealth);
	void setAttack(int newAttack);
	void setDefense(int newDefense);
	void setSpeed(int newSpeed);
	virtual void takeDamage(int damage);
	void setDefend(bool state);
	bool isDefending() const;
	void recover();
};

#endif
