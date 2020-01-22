// GPRO-FW-Launcher.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include <stdlib.h>
#include "GPRO-FW/foo.h"
#include "GPRO-FW/game.h"

int main()
{

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
}
