#include "Combat.h"
#include "Actions.h"
#include "GameUtilities.h"
#include <iostream>

void fight(GummyBear& player, Opponent& boss, const Actions& playerAction) {
    bool playerTurn = true;
    while (player.getHealth() > 0 && boss.getHealth() > 0) {
        if (playerTurn) {
            GameUtilities::displayStats(player);
            GameUtilities::displayBossStats(boss);

            std::cout << "\nChoose your action:\n";
            std::cout << "1. Attack\n";
            std::cout << "2. Defend\n";
            int choice;
            std::cin >> choice;

            if (choice == 1) { // If the player chooses to attack
                int damage = playerAction.getDamage(); // Get damage from the action
                std::cout << "\nYou attack the opponent for " << damage << " damage!\n";
                boss.takeDamage(damage);
            }
            else if (choice == 2) { // If the player chooses to defend
                std::cout << "\nYou defend. Damage will be reduced on the next attack!\n";
                player.setDefend(true); // Set defending status
            }
        }
        else { // Opponent's turn
            int damage = std::max(0, boss.getAttack() - (player.isDefending() ? player.getDefense() / 2 : player.getDefense()));
            std::cout << "\nThe evil bear attacks you for " << damage << " damage!\n";
            player.takeDamage(damage);
            player.setDefend(false); // Reset defending status
        }

        playerTurn = !playerTurn;
    }
}
