// main.cpp
/**********************************************************
* AUTHOR 		: Adam Mirski
* STUDENT ID 		: 
* ASSIGMENT: #4 	: Multi-Dimentional Array
* CLASS 		: CS1B
* SECTION 		: Mw: 7:30p - 10:00p
* DUE DATE 		: Feb 27, 2024
**********************************************************/

/*********************************************************
*
*   Multi-Dimentional Array, Tic Tac Toe
*
*---------------------------------------------------------
*
* This program is a simple implementation of the classic game Tic Tac Toe,
* designed to be played in a console or terminal window. It supports both
* a two-player mode, where two human players can compete against each other,
* and a one-player mode, where a human player can play against the computer.
* The game is played on a 3x3 grid, with players taking turns to place their
* tokens (either 'X' or 'O') on the grid. The goal is to be the first to get
* three of one's own tokens in a row, column, or diagonal.
*
**********************************************************/



#include "header.h"


int main() {

	printHeader(cout);
	printTicTacToeHeader();
	// Starts the game by displaying the main menu
    menu();

    return 0;
}
