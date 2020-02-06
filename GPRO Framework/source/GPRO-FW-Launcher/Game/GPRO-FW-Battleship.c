
#include <stdio.h>
#include <GPRO-FW/common.h>

gs_tictactoe blankGame = { 0 };

// DEFINITIONS

bool checkWinState(gs_battleship game) {
	for (int player = 0; player < GS_BATTLESHIP_PLAYERS; player++) {
		for (int i = 0; i < GS_BATTLESHIP_BOARD_HEIGHT; i++) {
			for (int j = 0; j < GS_BATTLESHIP_BOARD_WIDTH; j++) {
					if (gs_checkers_getSpaceState(game, player, i, j) == gs_battleship_space_patrol2 || gs_checkers_getSpaceState(game, player, i, j) == gs_battleship_space_submarine3 || gs_checkers_getSpaceState(game, player, i, j) == gs_battleship_space_destroyer3 || gs_checkers_getSpaceState(game, player, i, j) == gs_battleship_space_battleship4 || gs_checkers_getSpaceState(game, player, i, j) == gs_battleship_space_carrier5) {
					return false;
					}
			}
		}
	}

	return true;
}

int launchBattleship()
{
	gs_battleship game = { 0 };

	gs_battleship_reset(game);

	printf("\nWelcome to Battleship.\nChoose from rows and columns 0 through 9.\n");

	int player;

	for (int i = 0; i < GS_BATTLESHIP_PLAYERS; i++)
	{
		player = i;

		drawGameBoard(blankGame, game, 'a', player);

		printf("Place your patrol boat.\n");
		for (int i = 1; i <= 2; i++)
		{
			int xInput = getXInput();
			int yInput = getYInput();
			gs_checkers_setSpaceState(game, gs_battleship_space_patrol2, player, xInput, yInput);
		}

		drawGameBoard(blankGame, game, 'a', player);

		printf("Place your submarine.\n");
		for (int i = 1; i <= 3; i++)
		{
			int xInput = getXInput();
			int yInput = getYInput();
			gs_checkers_setSpaceState(game, gs_battleship_space_submarine3, player, xInput, yInput);
		}

		drawGameBoard(blankGame, game, 'a', player);

		printf("Place your destroyer.\n");
		for (int i = 1; i <= 3; i++)
		{
			int xInput = getXInput();
			int yInput = getYInput();
			gs_checkers_setSpaceState(game, gs_battleship_space_destroyer3, player, xInput, yInput);
		}

		drawGameBoard(blankGame, game, 'a', player);

		printf("Place your battleship.\n");
		for (int i = 1; i <= 4; i++)
		{
			int xInput = getXInput();
			int yInput = getYInput();
			gs_checkers_setSpaceState(game, gs_battleship_space_battleship4, player, xInput, yInput);
		}

		drawGameBoard(blankGame, game, 'a', player);

		printf("Place your carrier.\n");
		for (int i = 1; i <= 5; i++)
		{
			int xInput = getXInput();
			int yInput = getYInput();
			gs_checkers_setSpaceState(game, gs_battleship_space_carrier5, player, xInput, yInput);
		}
	}

	player = 1;

	while (!checkWinState(game)) {
		player = swapTurn('a', player);

		drawGameBoard(blankGame, game, 'a', player);

		int xInput = getXInput();
		int yInput = getYInput();

		if (player == 0) {
			if (gs_checkers_getSpaceState(game, 1, xInput, yInput) == gs_battleship_space_open || gs_checkers_getSpaceState(game, 1, xInput, yInput) == gs_battleship_space_enemy_hit) {
				if (gs_checkers_getSpaceState(game, 0, xInput, yInput) == gs_battleship_space_open) {
					gs_checkers_setSpaceState(game, gs_battleship_space_miss, 0, xInput, yInput);
				}
				printf("Miss!");
			}
			if (gs_checkers_getSpaceState(game, 1, xInput, yInput) == gs_battleship_space_patrol2 || gs_checkers_getSpaceState(game, 1, xInput, yInput) == gs_battleship_space_submarine3 || gs_checkers_getSpaceState(game, 1, xInput, yInput) == gs_battleship_space_destroyer3 || gs_checkers_getSpaceState(game, 1, xInput, yInput) == gs_battleship_space_battleship4 || gs_checkers_getSpaceState(game, 1, xInput, yInput) == gs_battleship_space_carrier5) {
				if (gs_checkers_getSpaceState(game, 0, xInput, yInput) == gs_battleship_space_open) {
					gs_checkers_setSpaceState(game, gs_battleship_space_hit, 0, xInput, yInput);
				}
				gs_checkers_setSpaceState(game, gs_battleship_space_enemy_hit, 1, xInput, yInput);
				printf("Hit!");
			}
		}

		else {
			if (gs_checkers_getSpaceState(game, 0, xInput, yInput) == gs_battleship_space_open || gs_checkers_getSpaceState(game, 0, xInput, yInput) == gs_battleship_space_enemy_hit) {
				if (gs_checkers_getSpaceState(game, 1, xInput, yInput) == gs_battleship_space_open) {
					gs_checkers_setSpaceState(game, gs_battleship_space_miss, 1, xInput, yInput);
				}
				printf("Miss!");
			}
			if (gs_checkers_getSpaceState(game, 0, xInput, yInput) == gs_battleship_space_patrol2 || gs_checkers_getSpaceState(game, 0, xInput, yInput) == gs_battleship_space_submarine3 || gs_checkers_getSpaceState(game, 0, xInput, yInput) == gs_battleship_space_destroyer3 || gs_checkers_getSpaceState(game, 0, xInput, yInput) == gs_battleship_space_battleship4 || gs_checkers_getSpaceState(game, 0, xInput, yInput) == gs_battleship_space_carrier5) {
				if (gs_checkers_getSpaceState(game, 1, xInput, yInput) == gs_battleship_space_open) {
					gs_checkers_setSpaceState(game, gs_battleship_space_hit, 1, xInput, yInput);
				}
				gs_checkers_setSpaceState(game, gs_battleship_space_enemy_hit, 0, xInput, yInput);
				printf("Hit!");
			}
		}
	}

		printf("\n\n%c wins!\n\n", player + 1);

		return 0;
}


//-----------------------------------------------------------------------------
