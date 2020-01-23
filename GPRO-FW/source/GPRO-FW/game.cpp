#include "GPRO-FW/game.h"
//#include "GPRO-FW/foo.h"
#include <iostream>
#include <string>

using namespace std;

void gameStart()
{
	cout << "Guess my favorite color." << endl << "Enter your guess or enter 0 to stop playing: " << endl;
	game();
}

int game()
{
	string userInput;

	do
	{
		cin >> userInput;

		if (userInput == "Purple" || userInput == "purple")
		{
			cout << "You're correct! It is " << userInput << "!";
			return 0;
		}
		else
		{
			cout << "I'm sorry but " << userInput << " is not correct." << endl;
			cout << "Enter a new guess or enter 0 to stop playing: " << endl;
		}
	} while (userInput != "0");
}