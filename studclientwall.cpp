// Program #3 - The Wall
// Programmer: Ethan Stahl
// Class: CS2020 1001, Spring 2025
// Due Date: 10/28/25
// Purpose of Program: The purpose of this program is to
// simulate a wall climbing competition between two players.

#include "wall.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <ctime>  // Use to generate a random number.
#include<windows.h> // Used to pause a windows display.

using namespace std;

const int TOP_OF_WALL = 20;

int main()
{
	Wall player1("Player 001"), player2("Player 456");
	int player1turn, player2turn;// Use to decide if the player should climb or drop.
	bool winner = false;		// Use to terminate the loop once a player reaches.
	// The top of the wall.

	unsigned seed = time(0);	// Use top get a different set of random numbers.
	srand(seed);				// Part of the random number process.

	while (!winner)				// While there is not a winner the loop iterates.
	{
		system("CLS");			// Clears the screen (stdlib needed).

		cout << "==================== Top of the World!! =======================\n";
		player1turn = (rand() % 2);	// Randomly generates a number from 0 to 1.
		player2turn = (rand() % 2);	// 1 means the player will climb, 0 means player drops.

		if (player1turn == 0) {
			player1.drop();
		}
		else {
			player1.climb();
		}

		if (player2turn == 0) {
			player2.drop();
		}
		else {
			player2.climb();
		}

		// My test to make sure the a player does go below the ground.
		if (player1.getPosition() < 0 || player2.getPosition() < 0)
		{
			cout << "ERROR IN CODE" << endl;
			exit(1);
		}

		if (player1.getPosition() >= TOP_OF_WALL || player2.getPosition() >= TOP_OF_WALL) {
			winner = true;
		}

		// Animated wall with player labels.
		cout << "---------------------------------------------------------------\n";
		for (int k = TOP_OF_WALL; k >= 0; k--)
		{
			if (k == 0 || k == 19)
				cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			cout << setw(5) << k;

			if (player1.getPosition() == k || (k == TOP_OF_WALL && player1.getPosition() >= TOP_OF_WALL))
				cout << setw(15) << player1.getName();
			else
				cout << setw(15) << " ";

			if (player2.getPosition() == k || (k == TOP_OF_WALL && player2.getPosition() >= TOP_OF_WALL))
				cout << setw(15) << player2.getName();
			cout << endl;

		}
		cout << "---------------------------------------------------------------\n";
		Sleep(400);
	}

	// Print the results
	// Player 1 wins if they reached the top or if they both reached the top at once.
	if (player1.getPosition() >= TOP_OF_WALL) {
		cout << player1.getName() << " is the winner.\n";
		cout << "=============================================================\n";
		cout << player2.getName() << " has been eliminated.\n";
	}
	// Player 2 wins if they reach the top before player one.
	else if (player2.getPosition() >= TOP_OF_WALL) {
		cout << player2.getName() << " is the winner.\n";
		cout << "=============================================================\n";
		cout << player1.getName() << " has been eliminated.\n";
	}

	cout << "=============================================================\n";

	return 0;
}
