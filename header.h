/*
 * header.h
 *
 *  Created on: Feb 13, 2024
 *      Author: adammirski
 */
/**********************************************************
* AUTHOR 		  : Adam Mirski
* STUDENT ID 	: 
* ASSIGMENT#4 : Multi-Dimentional Array
* CLASS 		  : CS1B
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


// header.h
#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <string>


using namespace std;

// Constant for the size of the Tic Tac Toe board
const int SIZE = 3;

// Global variables used to declare a global variable in another file.
extern char board[SIZE][SIZE];
extern string playerNames[2];
extern char tokens[2];

// Function prototypes - detail description in funktions.cpp file.
void printHeader(ostream& os);
void printTicTacToeHeader();
void DisplayBoard(const char boardAr[][SIZE]);
void initBoard();
bool checkWin();
void playerInput(int player);
void computerMove();
void setPlayerNames();
void setPlayerTokens();
void twoPlayerMode();
void onePlayerMode();
void menu();
void clearScreen();
bool findBestMove(int &row, int &col, char token);
bool playCorner(int &row, int &col);
bool playSide(int &row, int &col);

#endif // HEADER_H
