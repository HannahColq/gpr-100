
#include <stdio.h>
#include <stdbool.h>

//-----------------------------------------------------------------------------
// DECLARATIONS

#define GS_BATTLESHIP_PLAYERS				2
#define GS_BATTLESHIP_BOARD_WIDTH			10
#define GS_BATTLESHIP_BOARD_HEIGHT			10

enum gs_battleship_space_state
{
	// invalid space state
	gs_battleship_space_invalid = -1,

	// states visible to both players
	gs_battleship_space_open,			// space is open and unguessed
	gs_battleship_space_miss,			// space was guessed and missed
	gs_battleship_space_hit,			// space was guessed and hit
	gs_battleship_space_enemy_hit,      // space was guessed and hit by the enemy

	// states hidden from opponent player
	gs_battleship_space_patrol2,		// 2-unit patrol boat
	gs_battleship_space_submarine3,		// 3-unit submarine
	gs_battleship_space_destroyer3,		// 3-unit destroyer
	gs_battleship_space_battleship4,	// 4-unit battleship
	gs_battleship_space_carrier5,		// 5-unit carrier
};
#ifndef __cplusplus
typedef		enum gs_battleship_space_state	gs_battleship_space_state;
#endif	// !__cplusplus

// battleship game state
typedef		unsigned char					gs_battleship_index;
typedef		gs_battleship_space_state		gs_battleship[GS_BATTLESHIP_PLAYERS][GS_BATTLESHIP_BOARD_WIDTH][GS_BATTLESHIP_BOARD_HEIGHT];


#define	GS_VALIDATE_COORDINATE(x,y,z,w,h,d)		(x < w && y < h && z < d)
#define GS_BATTLESHIP_VALID(p,x,y)				GS_VALIDATE_COORDINATE(x,y,p,GS_BATTLESHIP_BOARD_WIDTH,GS_BATTLESHIP_BOARD_HEIGHT,GS_BATTLESHIP_PLAYERS)


inline gs_battleship_space_state gs_checkers_getSpaceState(gs_battleship const game, gs_battleship_index const player, gs_battleship_index const xpos, gs_battleship_index const ypos)
{
	if (GS_BATTLESHIP_VALID(player, xpos, ypos))
		return (game[player][xpos][ypos]);
	return gs_battleship_space_invalid;
}

inline gs_battleship_space_state gs_checkers_setSpaceState(gs_battleship game, gs_battleship_space_state const state, gs_battleship_index const player, gs_battleship_index const xpos, gs_battleship_index const ypos)
{
	if (GS_BATTLESHIP_VALID(player, xpos, ypos))
		return (game[player][xpos][ypos] = state);
	return gs_battleship_space_invalid;
}

inline gs_battleship_index gs_battleship_reset(gs_battleship game)
{
	gs_battleship_index player, xpos, ypos, total;
	for (player = 0; player < GS_BATTLESHIP_PLAYERS; ++player)
		for (xpos = 0; xpos < GS_BATTLESHIP_BOARD_WIDTH; ++xpos)
			for (ypos = 0; ypos < GS_BATTLESHIP_BOARD_HEIGHT; ++ypos)
				game[player][xpos][ypos] = gs_battleship_space_open;
	total = (player * xpos * ypos);
	return total;
}


//-----------------------------------------------------------------------------
// DEFINITIONS

char getSpaceState(gs_battleship game, int player, int x, int y) {
	switch (gs_checkers_getSpaceState(game, player, x, y)) {
	case gs_battleship_space_open:
		return ' ';
	case gs_battleship_space_miss:
		return 'o';
	case gs_battleship_space_hit:
		return 'x';
	case gs_battleship_space_enemy_hit:
		return '/';
	case gs_battleship_space_patrol2:
		return 'p';
	case gs_battleship_space_submarine3:
		return 's';
	case gs_battleship_space_destroyer3:
		return 'd';
	case gs_battleship_space_battleship4:
		return 'b';
	case gs_battleship_space_carrier5:
		return 'c';
	}
}

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

void drawGameBoard(gs_battleship game, int player)
{
	// draw game board
	printf("\nPlayer %d's turn:\n\n", player+1);
	// draw top labels
	for (int i = 0; i < GS_BATTLESHIP_BOARD_WIDTH; i++) {
		printf(" %d", i);
	}
	printf("\n");
	gs_battleship_index xpos, ypos;
	for (xpos = 0; xpos < GS_BATTLESHIP_BOARD_WIDTH; xpos++) {
		printf("%c", '|');
		for (ypos = 0; ypos < GS_BATTLESHIP_BOARD_HEIGHT; ypos++) {
			printf("%c", getSpaceState(game, player, xpos, ypos));
			printf("%c", '|');
		}
		printf(" %d\n", xpos);
	}
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

		drawGameBoard(game, player);

		printf("Place your patrol boat.\n");
		for (int i = 1; i <= 2; i++)
		{
			int xInput, yInput;
			printf("Enter the horizontal row for spot %d: ", i);
			scanf("%d", &xInput);
			printf("Enter the vertical column for spot %d: ", i);
			scanf("%d", &yInput);
			gs_checkers_setSpaceState(game, gs_battleship_space_patrol2, player, xInput, yInput);
		}

		drawGameBoard(game, player);

		printf("Place your submarine.\n");
		for (int i = 1; i <= 3; i++)
		{
			int xInput, yInput;
			printf("Enter the horizontal row for spot %d: ", i);
			scanf("%d", &xInput);
			printf("Enter the vertical column for spot %d: ", i);
			scanf("%d", &yInput);
			gs_checkers_setSpaceState(game, gs_battleship_space_submarine3, player, xInput, yInput);
		}

		drawGameBoard(game, player);

		printf("Place your destroyer.\n");
		for (int i = 1; i <= 3; i++)
		{
			int xInput, yInput;
			printf("Enter the horizontal row for spot %d: ", i);
			scanf("%d", &xInput);
			printf("Enter the vertical column for spot %d: ", i);
			scanf("%d", &yInput);
			gs_checkers_setSpaceState(game, gs_battleship_space_destroyer3, player, xInput, yInput);
		}

		drawGameBoard(game, player);

		printf("Place your battleship.\n");
		for (int i = 1; i <= 4; i++)
		{
			int xInput, yInput;
			printf("Enter the horizontal row for spot %d: ", i);
			scanf("%d", &xInput);
			printf("Enter the vertical column for spot %d: ", i);
			scanf("%d", &yInput);
			gs_checkers_setSpaceState(game, gs_battleship_space_battleship4, player, xInput, yInput);
		}

		drawGameBoard(game, player);

		printf("Place your carrier.\n");
		for (int i = 1; i <= 5; i++)
		{
			int xInput, yInput;
			printf("Enter the horizontal row for spot %d: ", i);
			scanf("%d", &xInput);
			printf("Enter the vertical column for spot %d: ", i);
			scanf("%d", &yInput);
			gs_checkers_setSpaceState(game, gs_battleship_space_carrier5, player, xInput, yInput);
		}
	}

	player = 1;

	while (!checkWinState(game)) {
		if (player == 0) {
			player = 1;
		}
		else {
			player = 0;
		}

		drawGameBoard(game, player);

		int xInput, yInput;
		printf("Enter the horizontal row: ");
		scanf("%d", &xInput);
		printf("Enter the vertical column: ");
		scanf("%d", &yInput);

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
