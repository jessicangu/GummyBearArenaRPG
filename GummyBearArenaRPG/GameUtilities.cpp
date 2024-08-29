#include "GameUtilities.h"
#include "Opponent.h"
// creating functions to display messages/menus for the user

void GameUtilities::displayMenu() { // display main menu
    std::cout << "Welcome to the Gummy Bear Universe.\n";
    std::cout << "1. Fight in the Arena\n";
    std::cout << "2. Train and Increase Your Stats\n";
    std::cout << "3. Save Game\n";
    std::cout << "4. Load Game\n";
    std::cout << "5. Exit\n";
}

void GameUtilities::displayStats(const GummyBear& bear) { // display player stats
    std::cout << "Name: " << bear.getName() << "    Level: " << bear.getLevel() << std::endl;
    std::cout << "Health: " << bear.getHealth() << std::endl;
    std::cout << "Attack: " << bear.getAttack() << std::endl;
    std::cout << "Defense: " << bear.getDefense() << std::endl;
    std::cout << "Speed: " << bear.getSpeed() << std::endl;
    std::cout << " \n";
}

void GameUtilities::displayBossStats(const Opponent& boss) { // display boss stats
    std::cout << "Name: " << boss.getName() << "    Level: " << boss.getLevel() << std::endl;
    std::cout << "Health: " << boss.getHealth() << std::endl;
    std::cout << "Attack: " << boss.getAttack() << std::endl;
    std::cout << "Defense: " << boss.getDefense() << std::endl;
    std::cout << "Speed: " << boss.getSpeed() << std::endl;
    std::cout << " \n";
}

void GameUtilities::displayTrainingMenu() { // training menu
    std::cout << "Training Menu:\n";
    std::cout << "1. Train Attack\n";
    std::cout << "2. Train Defense\n";
    std::cout << "3. Train Speed\n";
    std::cout << " \n";
}
