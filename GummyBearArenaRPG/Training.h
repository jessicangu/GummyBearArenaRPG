#pragma once
#ifndef TRAINING_H
#define TRAINING_H

#include "GummyBear.h"

class Training {
public:
    static void trainAttack(GummyBear& bear);
    static void trainDefense(GummyBear& bear);
    static void trainSpeed(GummyBear& bear);
};

#endif // TRAINING_H
