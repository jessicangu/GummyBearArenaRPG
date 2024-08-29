#ifndef GAMEUTILITIES_H
#define GAMEUTILITIES_H

#include <iostream>
#include <vector>
#include "GummyBear.h"
#include "Opponent.h"

class GameUtilities {
public:
    static void displayMenu();
    static void displayStats(const GummyBear& bear);
    static void displayBossStats(const Opponent& boss);
    static void displayTrainingMenu();
};

#endif