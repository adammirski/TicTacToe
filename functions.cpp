/*
 * functions.cpp
 *
 *  Created on: Feb 13, 2024
 *      Author: adammirski
 */
// function.cpp
/**********************************************************
* AUTHOR 		: Adam Mirski
* STUDENT ID 	: 584507
* ASSIGMENT: #4 : Multi-Dimentional Array
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

// Initialize global variables
char board[SIZE][SIZE];
string playerNames[2];
char tokens[2] = {'X', 'O'};

// Function to display the Tic Tac Toe board
void DisplayBoard(const char boardAr[][SIZE]) {
    int i, j;
    cout << setw(10) << "1" << setw(8) << "2" << setw(9) << "3\n";
    for (i = 0; i < SIZE; i++) {
        cout << setw(7) << "[" << i + 1 << "][1] | " << "[" << i + 1;
        cout << "][2] | " << "[" << i + 1 << "][3]" << endl;
        cout << setw(14) << "|" << setw(9) << "|" << endl;
        for (j = 0; j < SIZE; j++) {
            switch(j) {
                case 0: cout << i + 1 << setw(9) << boardAr[i][j] << setw(4) << "|";
                        break;
                case 1: cout << setw(4) << boardAr[i][j] << setw(5) << "|";
                        break;
                case 2: cout << setw(4) << boardAr[i][j] << endl;
                        break;
                default: cout << "ERROR!\n\n";
            }
        }
        cout << setw(14) << "|" << setw(10) << "|\n";
        if (i != 2) {
            cout << setw(32) << "--------------------------\n";
        }
    }
    cout << endl << endl;
}

// Function to clear the console screen for macOS
/*void clearScreen() {
    system("clear");
}
*/

// Function to initialize the board with spaces
void initBoard() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = ' ';
        }
    }
}

// Function to check if there is a winning condition
bool checkWin() {
    // Check rows and columns
    for (int i = 0; i < SIZE; i++) {
        if ((board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') ||
            (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')) {
            return true;
        }
    }

    // Check diagonals
    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') ||
        (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')) {
        return true;
    }

    return false; // No win found
}

// Function for player input and move
void playerInput(int player) {
    int row, col;
    bool validMove = false;
    do {
        cout << playerNames[player] << "'s turn (" << tokens[player] << "). Enter row and column numbers (1-3): ";
        cin >> row >> col;
        if (row >= 1 && row <= SIZE && col >= 1 && col <= SIZE && board[row - 1][col - 1] == ' ') {
            board[row - 1][col - 1] = tokens[player];
            validMove = true;
        } else {
            cout << "Invalid move, try again.\n";
            cin.clear();
            cin.ignore(10000, '\n');
        }
    } while (!validMove);
}

// Function for computer's move

void computerMove() {
    int row, col;

    // Check for a winning move
    if (findBestMove(row, col, tokens[1])) {
        board[row][col] = tokens[1];
        return;
    }

    // Block opponent's winning move
    if (findBestMove(row, col, tokens[0])) {
        board[row][col] = tokens[1];
        return;
    }

    // Play center if available
    if (board[1][1] == ' ') {
        board[1][1] = tokens[1];
        return;
    }

    // Play an opposite corner or any corner
    if (playCorner(row, col)) {
        board[row][col] = tokens[1];
        return;
    }

    // Play an empty side
    if (playSide(row, col)) {
        board[row][col] = tokens[1];
        return;
    }

    // If no other move is found, resort to random placement (as a fallback)
    do {
        row = rand() % SIZE;
        col = rand() % SIZE;
    } while (board[row][col] != ' ');
    board[row][col] = tokens[1];
}

bool findBestMove(int &row, int &col, char token) {
    // Check rows, columns, and diagonals for a potential winning move or to block opponent's win
    // This function should implement the logic to find the best move by checking the current state of the board
    // and deciding whether placing 'token' in a certain position will lead to a win or block the opponent's win.
    // If such a move is found, set 'row' and 'col' to that position and return true; otherwise, return false.

    return false;
}

bool playCorner(int &row, int &col) {
    // This function should implement the logic to play an opposite corner or any available corner.
    // Set 'row' and 'col' to the chosen corner and return true; if no corner move is possible, return false.

    return false;
}

bool playSide(int &row, int &col) {
    // This function should implement the logic to play an empty side.
    // Set 'row' and 'col' to the chosen side position and return true; if no side move is possible, return false.

    return false;
}



// Function to set player names
void setPlayerNames() {
    cout << "\nEnter name for Player 1: ";
    cin >> playerNames[0];
    cout << "Enter name for Player 2 or Computer: ";
    cin >> playerNames[1];
}

// Function to allow players to choose their tokens
void setPlayerTokens() {
    char tokenChoice;
    cout << "Player 1, choose your token (X/O): ";
    cin >> tokenChoice;
    tokenChoice = toupper(tokenChoice);

    while (tokenChoice != 'X' && tokenChoice != 'O') {
        cout << "Invalid choice. Please choose 'X' or 'O': ";
        cin >> tokenChoice;
        tokenChoice = toupper(tokenChoice);
    }

    tokens[0] = tokenChoice;
    tokens[1] = (tokenChoice == 'X') ? 'O' : 'X'; // Automatically assign the other token to Player 2
    cout << "Player 1 is '" << tokens[0] << "' and Player 2/Computer is '" << tokens[1] << "'\n";
}

// Function for two-player mode
void twoPlayerMode() {
    initBoard();
    int turn = 0;
    while (turn < SIZE * SIZE && !checkWin()) {
        //clearScreen();
        DisplayBoard(board);
        playerInput(turn % 2);
        if (checkWin()) {
            //clearScreen();
            DisplayBoard(board);
            cout << playerNames[turn % 2] << " wins!" << endl;
            return;
        }
        turn++;
    }
    if (turn == SIZE * SIZE) {
        cout << "It's a draw!" << endl;
    }
}

// Function for one-player mode against the computer
void onePlayerMode() {
    initBoard();
    int turn = 0, player = 0;
    cout << "Do you want to be Player 1 or Player 2? (1/2): ";
    cin >> player;
    player--; // Adjust for 0-indexed array
    while (turn < SIZE * SIZE && !checkWin()) {
        //clearScreen();
        DisplayBoard(board);
        if (turn % 2 == player) {
            playerInput(player);
        } else {
            computerMove();
        }
        if (checkWin()) {
           // clearScreen();
            DisplayBoard(board);
            cout << (turn % 2 == player ? playerNames[player] : "Computer") << " wins!" << endl;
            return;
        }
        turn++;
    }
    if (turn == SIZE * SIZE) {
        cout << "It's a draw!" << endl;
    }
}

// Main menu function
void menu() {
    int choice = 0;
    do {
        cout << "\n1. Exit\n2. Set Player Names\n3. Set Player Tokens\n4. Play in Two Player Mode\n5. Play in One Player Mode\n\nEnter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                return;
            case 2:
                setPlayerNames();
                break;
            case 3:
                setPlayerTokens();
                break;
            case 4:
                twoPlayerMode();
                break;
            case 5:
                onePlayerMode();
                break;
            default:
                cout << "Invalid choice, please try again.\n";
        }
    } while (choice != 1);
}

void printHeader(ostream& os) {

		const char PROGRAMMER[30] = "Adam Mirski";
	    const char CLASS[5] = "CS1B";
	    const char SECTION[25] = "MW: 7:30p - 10:00p";
	    const int LAB_NUM = 2;
	    const char LAB_NAME[50] = "Multi-Dimentional Array";


	    os << left;
	    os << "**************************************************";
	    os << "\n* PROGRAMMED BY : " << PROGRAMMER;
	    os << "\n* " << setw(14) << "CLASS" << ": " << CLASS;
	    os << "\n* " << setw(14) << "SECTION" << ": " << SECTION;
	    os << "\n* " << "ASSIGMENT#" << setw(4) << LAB_NUM << ": " << LAB_NAME;
	    os << "\n**************************************************\n\n";
	    os << right;

}
void printTicTacToeHeader() {
    cout <<
        " _____ _     _____         _____          \n"
        "|_   _(_)   |_   _|_ _  __|_   _|__   ___ \n"
        "  | | | |_____| |/ _` |/ __|| |/ _ \\ / _ \\ \n"
        "  | | | |_____| | (_| | (__ | | (_) |  __/\n"
        "  |_| |_|     |_|\__, _|\\___||_|\\___/ \\___|\n"
        "                                           \n";
}


