// GPRO-FW-Launcher.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include <stdlib.h>
#include "GPRO-FW/foo.h"
#include "GPRO-FW/game.h"

int launchTicTacToe();
int launchBattleship();

int main()
{
	int input;
	do {
		printf("\nWelcome to our mini games!\n\n0: exit the program\n1: launch tic-tac-toe\n2: launch battleship\n");
		scanf("%d", &input);
		if (input < 0 || input > 2) {
			printf("%d is not a valid option.\n", input);
		}
		else {
			if (input == 1) {
				launchTicTacToe();
			}
			else if (input == 2) {
				launchBattleship();
			}
		}
	} while (input != 0);


	// from foo.h and foo.c
	int test = foo(80);
	printf("%d\n", test);


	// from game.h and game.c

	time_t t;
	srand((unsigned)time(&t));

	printf("\nEnter 0 to exit the program.\n");

	int result;
	do {
		result = minigame();
	} while (result != 0);

	printf("Exiting the program.\n");
	printf("\n\nGoodbye.\n\n");
}
