// GPRO-FW-Launcher.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

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

	printf("\n\nGoodbye.\n\n");
}
