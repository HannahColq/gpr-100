
#include <stdio.h>
#include <stdbool.h>
#include <GPRO-FW/common.h>


//-----------------------------------------------------------------------------
// DECLARATIONS

#define GS_TICTACTOE_PLAYERS					2
#define GS_TICTACTOE_BOARD_WIDTH				3
#define GS_TICTACTOE_BOARD_HEIGHT				3

enum gs_tictactoe_space_state
{
	// invalid space state
	gs_tictactoe_space_invalid = -1,

	// states visible to both players
	gs_tictactoe_space_open,	// space is open
	gs_tictactoe_space_o,		// space is taken by O player
	gs_tictactoe_space_x,		// space is taken by X player
};
#ifndef __cplusplus
typedef		enum gs_tictactoe_space_state		gs_tictactoe_space_state;
#endif	// !__cplusplus

// tic-tac-toe game state
typedef		unsigned char						gs_tictactoe_index;
typedef		gs_tictactoe_space_state			gs_tictactoe[GS_TICTACTOE_BOARD_WIDTH][GS_TICTACTOE_BOARD_HEIGHT];


#define	GS_VALIDATE_COORDINATE(x,y,w,h)			(x < w && y < h)
#define GS_TICTACTOE_VALID(x,y)					GS_VALIDATE_COORDINATE(x,y,GS_TICTACTOE_BOARD_WIDTH,GS_TICTACTOE_BOARD_HEIGHT)


inline gs_tictactoe_space_state gs_tictactoe_getSpaceState(gs_tictactoe const game, gs_tictactoe_index const xpos, gs_tictactoe_index const ypos)
{
	if (GS_TICTACTOE_VALID(xpos, ypos))
		return (game[xpos][ypos]);
	return gs_tictactoe_space_invalid;
}

inline gs_tictactoe_space_state gs_tictactoe_setSpaceState(gs_tictactoe game, gs_tictactoe_space_state const state, gs_tictactoe_index const xpos, gs_tictactoe_index const ypos)
{
	if (GS_TICTACTOE_VALID(xpos, ypos))
		return (game[xpos][ypos] = state);
	return gs_tictactoe_space_invalid;
}

inline gs_tictactoe_index gs_tictactoe_reset(gs_tictactoe game)
{
	gs_tictactoe_index xpos, ypos, total;
	for (xpos = 0; xpos < GS_TICTACTOE_BOARD_WIDTH; ++xpos)
		for (ypos = 0; ypos < GS_TICTACTOE_BOARD_HEIGHT; ++ypos)
			game[xpos][ypos] = gs_tictactoe_space_open;
	total = (xpos * ypos);
	return total;
}


//-----------------------------------------------------------------------------
// DEFINITIONS

char getSpaceCharacter(gs_tictactoe game, int x, int y) {
	switch (gs_tictactoe_getSpaceState(game, x, y)) {
	case gs_tictactoe_space_open:
		return ' ';
	case gs_tictactoe_space_o:
		return 'o';
	case gs_tictactoe_space_x:
		return 'x';
	}
}

bool checkWin(gs_tictactoe game) {

	// check rows and columns
	for (int i = 0; i < GS_TICTACTOE_BOARD_HEIGHT; i++) {
		if (game[i][0] == game[i][1] && game[i][1] == game[i][2] && game[i][0] != gs_tictactoe_space_open) {
			return true;
		}
	}
	for (int i = 0; i < GS_TICTACTOE_BOARD_WIDTH; i++) {
		if (game[0][i] == game[1][i] && game[1][i] == game[2][i] && game[0][i] != gs_tictactoe_space_open) {
			return true;
		}
	}
	// check diagonals
	if (game[0][0] == game[1][1] && game[1][1] == game[2][2] && game[0][0] != gs_tictactoe_space_open) {
		return true;
	}
	if (game[0][2] == game[1][1] && game[1][1] == game[2][0] && game[0][2] != gs_tictactoe_space_open) {
		return true;
	}


	return false;
}

int launchTicTacToe()
{
	gs_tictactoe game = { 0 };

	gs_tictactoe_reset(game);

	// test
	//gs_tictactoe_setSpaceState(game, gs_tictactoe_space_x, 0, 0);
	//gs_tictactoe_getSpaceState(game, 1, 1);

	printf("\nWelcome to tic-tac-toe.\nChoose from rows and columns 0, 1, or 2.\n");
	char turn = 'o';

	while (!checkWin(game)) {
		if (turn == 'o') {
			turn = 'x';
		}
		else {
			turn = 'o';
		}

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
				printf("%c", getSpaceCharacter(game, xpos, ypos));
				printf("%c", '|');
			}
			printf(" %d\n", xpos);
		}

		int xInput = getXInput();
		int yInput = getYInput();

		if (turn == 'o') {
			gs_tictactoe_setSpaceState(game, gs_tictactoe_space_o, xInput, yInput);
		}
		else {
			gs_tictactoe_setSpaceState(game, gs_tictactoe_space_x, xInput, yInput);
		}
		
	}
	
	printf("\n\n%c wins!\n\n", turn);

	return 0;
}


//-----------------------------------------------------------------------------
