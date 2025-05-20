//Falcon2-11B DATASET v1.0 Category: Checkers Game ; Style: protected
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<limits.h>

// Checkerboard definition
const int board[8][8] = {
    {2,2,2,2,2,2,2,2},
    {2,2,2,2,2,2,2,2},
    {2,2,2,2,2,2,2,2},
    {2,2,2,2,2,2,2,2},
    {2,2,2,2,2,2,2,2},
    {2,2,2,2,2,2,2,2},
    {2,2,2,2,2,2,2,2},
    {2,2,2,2,2,2,2,2}
};

// Function to print board
void printBoard(int board[8][8]) {
    for(int i=0; i<8; i++) {
        for(int j=0; j<8; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

// Function to check if the player has won
int checkWinner(int board[8][8], int player) {
    int row_count = 0, col_count = 0, diagonal_count = 0;
    for(int i=0; i<8; i++) {
        for(int j=0; j<8; j++) {
            if(board[i][j] == player) {
                if(i == j) {
                    diagonal_count++;
                }
                if(i + j == 7) {
                    col_count++;
                }
                if(i - j == 7) {
                    row_count++;
                }
            }
        }
    }
    if(row_count == 8 || col_count == 8 || diagonal_count == 8) {
        return player;
    }
    else {
        return 0;
    }
}

// Function to make a move
void move(int board[8][8], int row, int col, int player) {
    if(board[row][col]!= 0) {
        printf("Invalid move!\n");
        return;
    }
    board[row][col] = player;
    int winner = checkWinner(board, player);
    if(winner!= 0) {
        printf("%d has won the game!\n", winner);
    }
}

// Main function
int main() {
    srand(time(NULL));
    int board[8][8] = {0};
    char choice;
    int player = 1;
    printf("Welcome to Checkers! \n");
    while(1) {
        printBoard(board);
        printf("Player %d's turn. Please choose a position to move (row, column): ", player);
        scanf("%c", &choice);
        int row = choice - '0';
        int col = choice - '1';
        move(board, row, col, player);
        player = 3 - player;
    }
    return 0;
}