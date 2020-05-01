//Contributors: Jacob Myers, Justin Marko
//File Purpose: Definitions for tic-tac-toe functions

#include "GPROFinal/tic-tac-toe-source.h"
using namespace std;

#ifndef __cplusplus
typedef		enum gs_tictactoe_space_state		gs_tictactoe_space_state;
#endif	// !__cplusplus


#define	GS_VALIDATE_COORDINATE(x,y,w,h)			(x < w && y < h)
#define GS_TICTACTOE_VALID(x,y)					GS_VALIDATE_COORDINATE(x,y,GS_TICTACTOE_BOARD_WIDTH,GS_TICTACTOE_BOARD_HEIGHT)

//-----------------------------------------------------------------------------
// DEFINITIONS

//Gets the state of a position in a tic tac toe board
inline gs_tictactoe_space_state gs_tictactoe_getSpaceState(gs_tictactoe const game, gs_tictactoe_index const xpos, gs_tictactoe_index const ypos)
{
	if (GS_TICTACTOE_VALID(xpos, ypos))
		return (game[xpos][ypos]);
	return gs_tictactoe_space_invalid;
}

//Sets the state of a position in a tic tac toe board
inline gs_tictactoe_space_state gs_tictactoe_setSpaceState(gs_tictactoe game, gs_tictactoe_space_state const state, gs_tictactoe_index const xpos, gs_tictactoe_index const ypos)
{
	if (GS_TICTACTOE_VALID(xpos, ypos))
		return (game[xpos][ypos] = state);
	return gs_tictactoe_space_invalid;
}

//Resets a tic tac toe board that it's given
inline gs_tictactoe_index gs_tictactoe_reset(gs_tictactoe game)
{
	gs_tictactoe_index xpos, ypos, total;
	for (xpos = 0; xpos < GS_TICTACTOE_BOARD_WIDTH; ++xpos)
		for (ypos = 0; ypos < GS_TICTACTOE_BOARD_HEIGHT; ++ypos)
			game[xpos][ypos] = gs_tictactoe_space_open;
	total = (xpos * ypos);
	return total;
}

//Checks if any player has won on a given board and returns that person
gs_tictactoe_space_state gs_tictactoe_getWon(gs_tictactoe game)
{
	for (int i = 0; i < 3; i++) // Check row
	{
		if (gs_tictactoe_getSpaceState(game, i, 0) == gs_tictactoe_getSpaceState(game, i, 1) && gs_tictactoe_getSpaceState(game, i, 0) == gs_tictactoe_getSpaceState(game, i, 2))
		{
			if (gs_tictactoe_getSpaceState(game, i, 0) == gs_tictactoe_space_o)
			{
				return gs_tictactoe_space_o;
			}

			else if (gs_tictactoe_getSpaceState(game, i, 0) == gs_tictactoe_space_x)
			{
				return gs_tictactoe_space_x;
			}
		}
	}

	for (int i = 0; i < 3; i++) // Check col
	{
		if (gs_tictactoe_getSpaceState(game, 0, i) == gs_tictactoe_getSpaceState(game, 1, i) && gs_tictactoe_getSpaceState(game, 0, i) == gs_tictactoe_getSpaceState(game, 2, i))
		{
			if (gs_tictactoe_getSpaceState(game, 0, i) == gs_tictactoe_space_o)
			{
				return gs_tictactoe_space_o;
			}

			else if (gs_tictactoe_getSpaceState(game, 0, i) == gs_tictactoe_space_x)
			{
				return gs_tictactoe_space_x;
			}
		}
	}

	if (gs_tictactoe_getSpaceState(game, 0, 0) == gs_tictactoe_getSpaceState(game, 1, 1) && gs_tictactoe_getSpaceState(game, 0, 0) == gs_tictactoe_getSpaceState(game, 2, 2)) // Check diag 1
	{
		if (gs_tictactoe_getSpaceState(game, 0, 0) == gs_tictactoe_space_o)
		{
			return gs_tictactoe_space_o;
		}

		else if (gs_tictactoe_getSpaceState(game, 0, 0) == gs_tictactoe_space_x)
		{
			return gs_tictactoe_space_x;
		}
	}

	if (gs_tictactoe_getSpaceState(game, 0, 2) == gs_tictactoe_getSpaceState(game, 1, 1) && gs_tictactoe_getSpaceState(game, 0, 2) == gs_tictactoe_getSpaceState(game, 2, 0)) // Check diag 2
	{
		if (gs_tictactoe_getSpaceState(game, 0, 2) == gs_tictactoe_space_o)
		{
			return gs_tictactoe_space_o;
		}

		else if (gs_tictactoe_getSpaceState(game, 0, 2) == gs_tictactoe_space_x)
		{
			return gs_tictactoe_space_x;
		}
	}

	return gs_tictactoe_space_invalid;
}

//Gets input from the user to place Xs and Os
void input(gs_tictactoe_space_state player, gs_tictactoe& game)
{
	bool doneInput = false;
	while (!doneInput)
	{
		int ROW = 0, COL = 0;
		if (player == gs_tictactoe_space_o)
		{
			ROW = getIntFromUser("Enter row to place an O: ");
			COL = getIntFromUser("Enter col to place an O: ");
		}
		else if (player == gs_tictactoe_space_x)
		{
			ROW = getIntFromUser("Enter row to place an X: ");
			COL = getIntFromUser("Enter col to place an X: ");
		}
		if (gs_tictactoe_getSpaceState(game, COL - 1, ROW - 1) != gs_tictactoe_space_o && gs_tictactoe_getSpaceState(game, COL - 1, ROW - 1) != gs_tictactoe_space_x)
		{
			if (gs_tictactoe_setSpaceState(game, player, COL - 1, ROW - 1) == player)
			{
				doneInput = true;
			}
		}
	}
}

//Displays the board
void display(gs_tictactoe& game)
{
	for (int row = 0; row < GS_TICTACTOE_BOARD_HEIGHT; row++)
	{
		for (int col = 0; col < GS_TICTACTOE_BOARD_WIDTH; col++)
		{
			if (gs_tictactoe_getSpaceState(game, col, row) == gs_tictactoe_space_x)
			{
				cout << "X ";
			}
			else if (gs_tictactoe_getSpaceState(game, col, row) == gs_tictactoe_space_o)
			{
				cout << "O ";
			}
			else
			{
				cout << "- ";
			}
		}
		cout << endl;
	}
}

//Launches a game instance. Called in main
int launchTicTacToe()
{
	gs_tictactoe game;

	bool done = false;
	gs_tictactoe_space_state player = gs_tictactoe_space_x;

	while (!done)
	{
		input(player, game);
		display(game);

		if (gs_tictactoe_getWon(game) != gs_tictactoe_space_invalid)
		{
			done = true;
			if (gs_tictactoe_getWon(game) == gs_tictactoe_space_x)
			{
				cout << "Player X Wins!";
			}
			else
			{
				cout << "Player O Wins!";
			}
		}

		if (player == gs_tictactoe_space_x)
			player = gs_tictactoe_space_o;
		else
			player = gs_tictactoe_space_x;
	}

	return 0;
}

//-----------------------------------------------------------------------------
