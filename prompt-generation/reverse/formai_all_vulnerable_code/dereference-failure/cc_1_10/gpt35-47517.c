//FormAI DATASET v1.0 Category: Table Game ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 3
#define COLS 3
#define PLAYER_X 'X'
#define PLAYER_O 'O'

void printBoard(char board[][COLS]);
void playGame(char board[][COLS], char currentPlayer);
void initBoard(char board[][COLS]);
char checkWin(char board[][COLS]);

int main() {
    char board[ROWS][COLS];
    initBoard(board);
    char currentPlayer = PLAYER_X;
    int moves = 0;
    while(moves < 9) {
        printBoard(board);
        playGame(board, currentPlayer);
        char winner = checkWin(board);
        if(winner != ' ') {
            printf("Player %c Wins!!\n", winner);
            break;
        }
        if(currentPlayer == PLAYER_X) {
            currentPlayer = PLAYER_O;
        } else {
            currentPlayer = PLAYER_X;
        }
        moves++;
    }
    if(moves == 9) {
        printf("It's a Draw!\n");
    }
    return 0;
}

void initBoard(char board[][COLS]) {
    for(int row = 0; row < ROWS; row++) {
        for(int col = 0; col < COLS; col++) {
            board[row][col] = '-';
        }
    }
}

void printBoard(char board[][COLS]) {
    printf("\n");
    for(int row = 0; row < ROWS; row++) {
        for(int col = 0; col < COLS; col++) {
            printf("%c ", board[row][col]);
        }
        printf("\n");
    }
}

void playGame(char board[][COLS], char currentPlayer) {
    int row, col;
    printf("Player %c's Turn:\n", currentPlayer);
    printf("Enter Row (0 - 2): ");
    scanf("%d", &row);
    printf("Enter Column (0 - 2): ");
    scanf("%d", &col);
    if(board[row][col] != '-') {
        printf("Invalid move! Please try again.\n");
        playGame(board, currentPlayer);
    } else {
        board[row][col] = currentPlayer;
    }
}

char checkWin(char board[][COLS]) {
    // Check Rows
    for(int row = 0; row < ROWS; row++) {
        if(board[row][0] != '-' && board[row][0] == board[row][1] && board[row][1] == board[row][2]){
            return board[row][0];
        }
    }
    // Check Columns
    for(int col = 0; col < COLS; col++) {
        if(board[0][col] != '-' && board[0][col] == board[1][col] && board[1][col] == board[2][col]){
            return board[0][col];
        }
    }
    // Check Diagonals
    if(board[0][0] != '-' && board[0][0] == board[1][1] && board[1][1] == board[2][2]){
        return board[0][0];
    }
    if(board[0][2] != '-' && board[0][2] == board[1][1] && board[1][1] == board[2][0]){
        return board[0][2];
    }
    return ' ';
}