#include <iostream>
#include <windows.h>
#include <string>

#include "GameUtilities.h"
#include "Actions.h"
#include "Opponent.h"
#include "FileIO.h"
#include "Combat.h"
#include "Training.h"
#include "GummyBear.h"

// creating a heads-up display to show player their stats
void HUD(const GummyBear& player)
{
	Sleep(500);
	system("cls");
	std::cout << "Name: " << player.getName() << "	Health: " << player.getHealth()
		<< "\nLevel: " << player.getLevel() << "\nAttack: " << player.getAttack()
		<< "\nDefense: " << player.getDefense() << "\nSpeed: " << player.getSpeed() << std::endl;
};

int main()
{
	std::string name;
	std::cout << "Enter Player Name: ";
	getline(std::cin, name); // player input

	int maxHealth = 100;
	GummyBear player(name, 1, 100, 8, 5, 8, maxHealth); // initialize default stats for the user.
	Opponent* defeatedBy = nullptr; // creating pointer to keep track of what bosses they player has or has not defeated
	Actions actions;

	int choice; // more initializations
	bool running = false;
	int currentBoss = 0;

	Opponent opponents[] = {
		Opponent("Sloth", 1, 50, 8, 3, 5, 50),
		Opponent("Lust", 2, 70, 12, 6, 7, 70),
		Opponent("Greed", 3, 90, 15, 8, 8, 90),
		Opponent("Gluttony", 4, 110, 18, 10, 9, 110),
		Opponent("Pride", 5, 130, 20, 12, 10, 130),
		Opponent("Envy", 6, 150, 22, 14, 11, 150),
		Opponent("Wrath", 7, 170, 25, 16, 12, 170)
	};

	// creating character loading fun
	std::cout << "Creating Character.\n";
	Sleep(300);
	system("cls");

	std::cout << "Creating Character..\n";
	Sleep(300);
	system("cls");

	std::cout << "Creating Character...\n";
	Sleep(300);
	system("cls");

	// display stats
	HUD(player);

	std::cout << "\nYou are placed in a universe where gummy bears roam. Most gummy bears welcome you with open arms.\n"
		<< "However, some aren't so friendly. Train to strengthen your stats. Then, go to the arena and fight evil bears until you drop!\n\n";

	// while this game is running, player chooses between fighting, training, saving, loading, or exiting
	while (!running) {
		std::cout << "Choose an option. \n1. Fight in the Arena! \n2. Train \n3. Save Game\n4. Load Game\n5. Exit\n\n";
		std::cin >> choice;

		switch (choice) {
			std::cout << "Choose an option. \n1. Fight in the Arena! \n2. Train \n3. Save Game\n4. Load Game\n5. Exit\n\n";
			std::cin >> choice;

		case 1: {
			for (int i = currentBoss; i < 7; ++i) { // start from the current opponent
				// reset opponent's health before each battle
				opponents[i].setHealth(opponents[i].getMaxHealth());

				std::cout << "\n===== Fighting against " << opponents[i].getName() << " =====\n\n";
				Actions actions(1, "Default", player.getAttack());
				fight(player, opponents[i], actions);
				HUD(player);
				if (player.getHealth() <= 0) {
					std::cout << "Your bear was defeated by " << opponents[i].getName() << "!\n";
					defeatedBy = &opponents[i];
					player.recover();
					break;
				}
				else if (opponents[i].getHealth() <= 0) {
					std::cout << "Congratulations! You defeated " << opponents[i].getName() << "!\n";
					opponents[i].recover();
				}
				else {
					std::cout << "Congratulations! Your bear won against " << opponents[i].getName() << "!\n";
				}
				currentBoss++; // Move to the next opponent
			}
			if (defeatedBy != nullptr) { // if a boss beats the player, the boss resets their health before the next battle with the user
				defeatedBy->recover();
				defeatedBy = nullptr;
			}
			break;
		}

		case 2: { // 
			GameUtilities::displayTrainingMenu(); // training menu for the player to choose from
			std::cout << "Enter your choice: ";
			std::cin >> choice;
			std::cin.ignore(); // clear the input
			switch (choice) {
			case 1: // training attack
				Training::trainAttack(player);
				break;
			case 2: // training defense
				Training::trainDefense(player);
				break;
			case 3: // training speed
				Training::trainSpeed(player);
				break;
			default:
				std::cout << "Invalid choice!\n";
				break;
			}
			break;
		}

		case 3: { // saving game
			saveGame(name + ".txt", player, currentBoss);
			std::cout << "Game saved!\n";
			break;
		}

		case 4: { // loading saved game with player name
			loadGame(name + ".txt", player, currentBoss);
			std::cout << "Game loaded!\n";
			HUD(player);
			break;
		}

		case 5: { // exit game
			std::cout << "Exiting the game...\n";
			running = true;
			break;
		}

		default: { // invalid choice
			std::cout << "Invalid choice!\n";
			break;
		}
		}
		if (currentBoss == 7) { // after the player has defeated the bosses, they win!
			std::cout << "Congratulations! You have defeated all the Seven Deadly Bears. You win the game!\n";
			running = true; // end the game loop
		}
	}
	system("pause"); // end
}