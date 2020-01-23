/*
#include "GPRO-FW/foo.h"
#include "GPRO-FW/game.h"
#include <stdio.h>

void gameStart()
{
	printf("Guess my favorite color. \nEnter your guess or enter 0 to stop playing");
	game();
}

int game()
{
	char userInput[30];

	do
	{
		fgets(userInput, 30, stdin);

		if (userInput == "Purple" || userInput == "purple")
		{
			printf("You're correct! It is ", userInput, "!");
			return 0;
		}
		else
		{
			printf("I'm sorry but ", userInput, " is not correct. \nEnter a new guess or enter 0 to stop playing");
		}
	} while (userInput != "0");
}
*/