// Program #3 - The Wall
// Programmer: Ethan Stahl
// Class: CS2020 1001, Spring 2025
// Due Date: 10/28/25
// Purpose of Program: The purpose of this program is to
// simulate a wall climbing competition between two players.

#ifndef WALL_H
#define WALL_H

#include <string>
using namespace std;

// Wall: A class representing a wall climber.
class Wall {

    // Define the variables
    private:
        string name;
        int position;

    public:
        // Wall class constructor
        Wall(string climberName);

        // Accessor functions.
        string getName();
        int getPosition();

        // Mutator functions
        void climb();
        void drop();
};

#endif
