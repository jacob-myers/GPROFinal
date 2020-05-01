//Contributors: Jacob Myers, Justin Marko
//File Purpose: Declarations for tic-tac-toe functions and information

#pragma once

#include <stdio.h>
#include <iostream>
#include "GPROFinal/input.h"
using namespace std;

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

// tic-tac-toe game state
typedef		unsigned char						gs_tictactoe_index;
typedef		gs_tictactoe_space_state			gs_tictactoe[GS_TICTACTOE_BOARD_WIDTH][GS_TICTACTOE_BOARD_HEIGHT];  //3x3 Array

//Gets the state of a position in a tic tac toe board
//Given: gamestate, x-position, y-position
//Returns: state of a position (X, O, or null)
inline gs_tictactoe_space_state gs_tictactoe_getSpaceState(gs_tictactoe const game, gs_tictactoe_index const xpos, gs_tictactoe_index const ypos);

//Sets the state of a position in a tic tac toe board
//Given: gamestate, x-position, y-position
//Returns: state of a position (X, O, or null)
inline gs_tictactoe_space_state gs_tictactoe_setSpaceState(gs_tictactoe game, gs_tictactoe_space_state const state, gs_tictactoe_index const xpos, gs_tictactoe_index const ypos);

//Resets a tic tac toe board that it's given
//Given: gamestate
inline gs_tictactoe_index gs_tictactoe_reset(gs_tictactoe game);

//Checks if any player has won on a given board and returns that person
//Given: gamestate
//Returns: A player's character (X or O) if one of them won
gs_tictactoe_space_state gs_tictactoe_getWon(gs_tictactoe game);

//Gets input from the user to place Xs and Os
//Given: player, gamestate
void input(gs_tictactoe_space_state player, gs_tictactoe& game);

//Displays the board
//Given: gamestate
void display(gs_tictactoe& game);

//Launches a game instance. Called in main
int launchTicTacToe();