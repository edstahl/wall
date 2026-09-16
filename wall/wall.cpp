// Program #3 - The Wall
// Programmer: Ethan Stahl
// Class: CS2020 1001, Spring 2025
// Due Date: 10/28/25
// Purpose of Program: The purpose of this program is to
// simulate a wall climbing competition between two players.

#include "wall.h"
#include <cstdlib>

using namespace std;

// Wall caps/boundaries
const int MAX_HEIGHT = 20;
const int MIN_HEIGHT = 0;

// Constructor
Wall::Wall(string climberName) : name(climberName), position(0) {
    // The member initializer list handles the required initializations.
}

// Name accessor function.
string Wall::getName() {
    return name;
}

// Position accessor function.
int Wall::getPosition() {
    return position;
}

// Climb: Generates a random climb amount (1-3) and adds it to the position.
void Wall::climb() {
    // Generate a random climb amount.
    int climbAmount = (rand() % 3) + 1;

    // Calculate position
    int newPosition = position + climbAmount;

    // Cap the climb amount to the peak.
    if (newPosition > MAX_HEIGHT) {
        position = MAX_HEIGHT;
    }
    else {
        position = newPosition;
    }
}

// Drop: Generates a random drop amount (1-3) and subtracts it from the position.
void Wall::drop() {
    // Generate a random drop amount: (rand() % 3) gives 0, 1, or 2. Adding 1 gives 1, 2, or 3.
    int dropAmount = (rand() % 3) + 1;

    // Calculate position
    int newPosition = position - dropAmount;

    // Cap the climb amount to the floor.
    if (newPosition < MIN_HEIGHT) {
        position = MIN_HEIGHT;
    }
    else {
        position = newPosition;
    }
}