#include "GPRO-FW/game.h"
#include <stdio.h>

int minigame() {

	int num = (rand() % 100) + 1;
	int guesses = 0;

	int input;
	do {
		printf("\nGuess a number from 1 to 100: ");
		scanf_s("%d", &input);
		guesses++;
		if (input > num) {
			printf("Too high!\n");
		}
		else if (input < num && input != 0) {
			printf("Too low!\n");
		}
		else if (input == num) {
			printf("Correct!\n");
			printf("Guesses: %d\n", guesses);
		}
	} while (input != num && input != 0);

	return input;

}