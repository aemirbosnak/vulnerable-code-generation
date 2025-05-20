//Falcon-180B DATASET v1.0 Category: Checkers Game ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 8

// Function to initialize the board
void initBoard(char board[SIZE][SIZE]) {
    int i, j;
    for(i = 0; i < SIZE; i++) {
        for(j = 0; j < SIZE; j++) {
            board[i][j] = '.';
        }
    }
}

// Function to print the board
void printBoard(char board[SIZE][SIZE]) {
    int i, j;
    for(i = 0; i < SIZE; i++) {
        for(j = 0; j < SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

// Function to check if a move is valid
int isValidMove(char board[SIZE][SIZE], int row, int col, int dir) {
    int newRow, newCol;
    if(dir == 1) {
        newRow = row - 1;
        newCol = col;
    }
    else if(dir == -1) {
        newRow = row + 1;
        newCol = col;
    }
    else if(dir == 2) {
        newRow = row;
        newCol = col - 1;
    }
    else if(dir == -2) {
        newRow = row;
        newCol = col + 1;
    }
    else {
        return 0;
    }
    if(newRow < 0 || newRow >= SIZE || newCol < 0 || newCol >= SIZE) {
        return 0;
    }
    if(board[newRow][newCol]!= '.' && board[newRow][newCol]!= '*') {
        return 0;
    }
    return 1;
}

// Function to check if a player has won
int checkWin(char board[SIZE][SIZE], int player) {
    int i, j;
    // Check rows
    for(i = 0; i < SIZE; i++) {
        if(board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return 1;
        }
        if(board[i][6] == player && board[i][5] == player && board[i][4] == player) {
            return 1;
        }
    }
    // Check columns
    for(j = 0; j < SIZE; j++) {
        if(board[0][j] == player && board[1][j] == player && board[2][j] == player) {
            return 1;
        }
        if(board[6][j] == player && board[5][j] == player && board[4][j] == player) {
            return 1;
        }
    }
    // Check diagonals
    if(board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return 1;
    }
    if(board[0][6] == player && board[1][5] == player && board[2][4] == player) {
        return 1;
    }
    return 0;
}

// Function to play the game
void playGame(char board[SIZE][SIZE]) {
    int player = 1;
    int row = 0;
    int col = 0;
    int dir = 1;
    while(1) {
        printBoard(board);
        printf("Player %d's turn\n", player);
        printf("Enter row and column: ");
        scanf("%d%d", &row, &col);
        if(isValidMove(board, row, col, dir)) {
            board[row][col] = (player == 1)? 'X' : 'O';
            if(checkWin(board, player)) {
                printf("Player %d wins!\n", player);
                break;
            }
            player = (player == 1)? 2 : 1;
            dir = -dir;
        }
        else {
            printf("Invalid move\n");
        }
    }
}

// Main function
int main() {
    srand(time(NULL));
    char board[SIZE][SIZE];
    initBoard(board);
    playGame(board);
    return 0;
}