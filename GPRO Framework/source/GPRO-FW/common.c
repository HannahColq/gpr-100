#include "GPRO-FW/common.h"
#include <stdio.h>
#include <stdbool.h>

int getXInput() {
	int xInput;
	printf("Enter the horizontal row: ");
	scanf_s("%d", &xInput);
	return xInput;
}
int getYInput() {
	int yInput;
	printf("Enter the vertical column: ");
	scanf_s("%d", &yInput);
	return yInput;
}

void drawGameBoard(gs_tictactoe tGame, gs_battleship bGame, char turn, int player)
{

	if (turn == 'a') {
		// draw game board
		printf("\nPlayer %d's turn:\n\n", player + 1);
		// draw top labels
		for (int i = 0; i < GS_BATTLESHIP_BOARD_WIDTH; i++) {
			printf(" %d", i);
		}
		printf("\n");
		gs_battleship_index xpos, ypos;
		for (xpos = 0; xpos < GS_BATTLESHIP_BOARD_WIDTH; xpos++) {
			printf("%c", '|');
			for (ypos = 0; ypos < GS_BATTLESHIP_BOARD_HEIGHT; ypos++) {
				printf("%c", getSpaceState(tGame, bGame, player, xpos, ypos));
				printf("%c", '|');
			}
			printf(" %d\n", xpos);
		}
	}

	else if (player == -1) {
		// draw game board
		printf("\n%c's turn:\n\n", turn);
		// draw top labels
		for (int i = 0; i < GS_TICTACTOE_BOARD_WIDTH; i++) {
			printf(" %d", i);
		}
		printf("\n");
		gs_tictactoe_index xpos, ypos;
		for (xpos = 0; xpos < GS_TICTACTOE_BOARD_WIDTH; xpos++) {
			printf("%c", '|');
			for (ypos = 0; ypos < GS_TICTACTOE_BOARD_HEIGHT; ypos++) {
				printf("%c", getSpaceState(tGame, bGame, -2, xpos, ypos));
				printf("%c", '|');
			}
			printf(" %d\n", xpos);
		}
	}
}

char getSpaceState(gs_tictactoe tGame, gs_battleship bGame, int player, int x, int y) {
	if (player != -2) {
		switch (gs_checkers_getSpaceState(bGame, player, x, y)) {
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
	else {
		switch (gs_tictactoe_getSpaceState(tGame, x, y)) {
		case gs_tictactoe_space_open:
			return ' ';
		case gs_tictactoe_space_o:
			return 'o';
		case gs_tictactoe_space_x:
			return 'x';
		}
	}
}

int swapTurn(char turn, int player) {
	if (player != -2) {
		if (player == 0) {
			return 1;
		}
		else {
			return 0;
		}
	}
	else {
		if (turn == 'o') {
			return 'x';
		}
		else {
			return 'o';
		}
	}
}