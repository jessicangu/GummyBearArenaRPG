#pragma once
#ifndef COMBAT_H
#define COMBAT_H

#include "GummyBear.h"
#include "Opponent.h"
#include "Actions.h"

void fight(GummyBear& player, Opponent& boss, const Actions& playerAction);

#endif // COMBAT_H
