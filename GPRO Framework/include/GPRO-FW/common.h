#pragma once

#include <stdbool.h>


// tic tac toe declarations --------------------------------------------------------------------------------------------------------

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


// battleship declarations --------------------------------------------------------------------------------------------------------

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


// added common functions


int getXInput();
int getYInput();

void drawGameBoard(gs_tictactoe tGame, gs_battleship bGame, char turn, int player);
char getSpaceState(gs_tictactoe tGame, gs_battleship bGame, int player, int x, int y);
int swapTurn(char turn, int player);