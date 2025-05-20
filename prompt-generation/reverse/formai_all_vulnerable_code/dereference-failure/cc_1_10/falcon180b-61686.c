//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int row;
    int col;
} Coordinate;

void initializeBoard(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = '-';
        }
    }
}

void printBoard(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

void placeTile(char board[3][3], int row, int col) {
    if (row >= 0 && row < 3 && col >= 0 && col < 3) {
        board[row][col] = 'X';
    }
}

int isBoardFull(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == '-') {
                return 0;
            }
        }
    }
    return 1;
}

int checkForMatch(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == '-') {
                continue;
            }
            if (board[i][j] == board[i][j+1] && j+1 < 3) {
                return 1;
            }
            if (board[i][j] == board[i+1][j] && i+1 < 3) {
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    srand(time(NULL));
    char board[3][3];
    initializeBoard(board);
    int moves = 0;
    int matches = 0;
    int gameWon = 0;
    while (!gameWon) {
        printBoard(board);
        int row, col;
        scanf("%d %d", &row, &col);
        if (row >= 0 && row < 3 && col >= 0 && col < 3) {
            if (board[row][col] == '-') {
                placeTile(board, row, col);
                moves++;
                if (isBoardFull(board)) {
                    gameWon = 1;
                }
            } else {
                printf("Invalid move\n");
            }
        } else {
            printf("Invalid move\n");
        }
        if (checkForMatch(board)) {
            matches++;
        }
    }
    printf("You won the game in %d moves with %d matches\n", moves, matches);
    return 0;
}