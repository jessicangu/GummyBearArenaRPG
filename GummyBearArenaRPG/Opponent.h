#ifndef OPPONENT_H
#define OPPONENT_H

#include "GummyBear.h"

class Opponent : public GummyBear {
public:
    Opponent(const std::string& name, int level, int health, int attack, int defense, int speed, int maxHealth)
        : GummyBear(name, level, health, attack, defense, speed, maxHealth) {}

    int getMaxHealth() const {
        return maxHealth;
    }

    void takeDamage(int damage) override;
};

#endif // OPPONENT_H
