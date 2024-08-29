#ifndef FILEIO_H
#define FILEIO_H

#include "GummyBear.h"

void saveGame(const std::string& fileName, const GummyBear& playerBear, int currentOpponentIndex);
void loadGame(const std::string& fileName, GummyBear& playerBear, int& currentOpponentIndex);

#endif
