#include "GummyBear.h"
#include <algorithm>

// initialize static member variable
int GummyBear::nextID = 1;

// constructor definition
GummyBear::GummyBear(std::string name, int level, int health, int attack, int defense, int speed, int maxHealth)
    : name(name), level(level), health(health), attack(attack), defense(defense), speed(speed), maxHealth(maxHealth), defending(false) {  // Initialize defending to false
    id = nextID++;  // assign an ID and increment the next available ID
}

// getter functions
int GummyBear::getID() const {
    return id;
}

std::string GummyBear::getName() const {
    return name;
}

int GummyBear::getLevel() const {
    return level;
}

int GummyBear::getHealth() const {
    return health;
}

int GummyBear::getAttack() const {
    return attack;
}

int GummyBear::getDefense() const {
    return defense;
}

int GummyBear::getSpeed() const {
    return speed;
}

int GummyBear::getMaxHealth() const {
    return maxHealth;
}

// setter functions
void GummyBear::setName(std::string newName) {
    name = newName;
}

void GummyBear::setLevel(int newLevel) {
    level = newLevel;
}

void GummyBear::setHealth(int newHealth) {
    health = newHealth;
}

void GummyBear::setAttack(int newAttack) {
    attack = newAttack;
}

void GummyBear::setDefense(int newDefense) {
    defense = newDefense;
}

void GummyBear::setSpeed(int newSpeed) {
    speed = newSpeed;
}

void GummyBear::setDefend(bool state) {
    defending = state;
}

bool GummyBear::isDefending() const {
    return defending;
}

void GummyBear::takeDamage(int damage) {
    if (defending) {
        damage = std::max(0, damage - (defense / 2));  // reduce damage by half of defense if defending
    }
    health -= damage;
    if (health <= 0) {
        health = 0;
    }
}

void GummyBear::recover() {
    if (health <= 0) {  // Check if the GummyBear was defeated
        health = maxHealth;  // Reset health to maximum
    }
}
