#include "FileIO.h"
#include "GummyBear.h"
#include "Opponent.h"
#include <fstream>
#include <iostream>

void saveGame(const std::string& fileName, const GummyBear& playerBear, int currentOpponentIndex) {
    // write player data and opponentindex to file
    std::ofstream file(fileName);
    if (file.is_open()) {
        file << playerBear.getName() << "\n";
        file << playerBear.getLevel() << "\n";
        file << playerBear.getHealth() << "\n";
        file << playerBear.getAttack() << "\n";
        file << playerBear.getDefense() << "\n";
        file << playerBear.getSpeed() << "\n";
        file << playerBear.getMaxHealth() << "\n"; // save max health
        file << currentOpponentIndex << "\n"; // save current opponent index
        file.close();
    }
    else {
        std::cout << "Error: Unable to open file for saving.\n";
    }
}

void loadGame(const std::string& fileName, GummyBear& playerBear, int& currentOpponentIndex) { // load
    std::ifstream file(fileName);
    if (file.is_open()) {
        std::string name;
        int level, health, attack, defense, speed, maxHealth, index;
        file >> name >> level >> health >> attack >> defense >> speed >> maxHealth >> index; // read max health and current opponent index
        playerBear = GummyBear(name, level, health, attack, defense, speed, maxHealth);
        currentOpponentIndex = index;
        file.close();
    }
    else {
        std::cout << "Error: Unable to open file for loading.\n";
    }
}
