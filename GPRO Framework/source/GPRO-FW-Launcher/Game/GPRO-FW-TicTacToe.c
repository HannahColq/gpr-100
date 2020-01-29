
#include <stdio.h>
#include <stdbool.h>


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
	return false;
}

int launchTicTacToe()
{
	gs_tictactoe game = { 0 };

	gs_tictactoe_reset(game);

	// test
	//gs_tictactoe_setSpaceState(game, gs_tictactoe_space_x, 0, 0);
	//gs_tictactoe_getSpaceState(game, 1, 1);

	printf("Welcome to tic-tac-toe.\n(0,0) is the top left and (2,2) is in the bottom right.\n");
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
		gs_tictactoe_index xpos, ypos;
		for (xpos = 0; xpos < GS_TICTACTOE_BOARD_WIDTH; xpos++) {
			printf("%c", '|');
			for (ypos = 0; ypos < GS_TICTACTOE_BOARD_HEIGHT; ypos++) {
				printf("%c", getSpaceCharacter(game, xpos, ypos));
				printf("%c", '|');
			}
			printf("\n");
		}

		int xInput, yInput;
		printf("Enter the x coordinate: ");
		scanf("%d", &xInput);
		printf("Enter the y coordinate: ");
		scanf("%d", &yInput);

		if (turn == 'o') {
			gs_tictactoe_setSpaceState(game, gs_tictactoe_space_o, xInput, yInput);
		}
		else {
			gs_tictactoe_setSpaceState(game, gs_tictactoe_space_x, xInput, yInput);
		}
		
	}
	

	return 0;
}


//-----------------------------------------------------------------------------
