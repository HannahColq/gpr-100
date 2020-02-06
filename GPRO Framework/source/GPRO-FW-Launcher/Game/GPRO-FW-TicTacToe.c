
#include <stdio.h>
#include <GPRO-FW/common.h>


//-----------------------------------------------------------------------------
gs_battleship blankBattleshipGame = { 0 };

// DEFINITIONS

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
		turn = swapTurn(turn, -2);

		drawGameBoard(game, blankBattleshipGame, turn, -1);

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
