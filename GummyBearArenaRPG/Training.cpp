#include "Training.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

void Training::trainAttack(GummyBear& bear) {
    std::srand(std::time(nullptr));  // Seed the random number generator
    int increase = std::rand() % 5 + 1;  // Random increase between 1 and 5 for attack
    bear.setAttack(bear.getAttack() + increase);
    std::cout << "Attack trained by sparring practice! Attack increased by " << increase << ".\n";
}

void Training::trainDefense(GummyBear& bear) {
    std::srand(std::time(nullptr));  // Seed the random number generator
    int increase = std::rand() % 5 + 1;  // Random increase between 1 and 5 for defense
    bear.setDefense(bear.getDefense() + increase);
    std::cout << "Defense trained by blocking practice! Defense increased by " << increase << ".\n";
}

void Training::trainSpeed(GummyBear& bear) {
    std::srand(std::time(nullptr));  // Seed the random number generator
    int increase = std::rand() % 5 + 1;  // Random increase between 1 and 5 for speed
    bear.setSpeed(bear.getSpeed() + increase);
    std::cout << "Speed trained by running practice! Speed increased by " << increase << ".\n";
}
