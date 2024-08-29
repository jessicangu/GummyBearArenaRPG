#include "Opponent.h"
#include <iostream>

void Opponent::takeDamage(int damage) {
    GummyBear::takeDamage(damage);  // Call to base class method
    if (this->getHealth() <= 0) {
        std::cout << this->getName() << " has been defeated!\n";
    }
}
