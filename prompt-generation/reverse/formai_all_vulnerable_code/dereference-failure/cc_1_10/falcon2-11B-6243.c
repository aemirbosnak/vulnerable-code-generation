//Falcon2-11B DATASET v1.0 Category: Checkers Game ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int row;
    int col;
    int player;
    int score;
} Player;

void printBoard(Player* board, int numRows, int numCols) {
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            printf("%d ", board[i].row == j? board[i].player : '.');
        }
        printf("\n");
    }
    printf("\n");
}

Player* newBoard(int numRows, int numCols) {
    Player* board = malloc(numRows * numCols * sizeof(Player));
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            board[i * numCols + j].row = j;
            board[i * numCols + j].col = j;
            board[i * numCols + j].player = 0;
            board[i * numCols + j].score = 0;
        }
    }
    return board;
}

void initializeBoard(Player* board, int numRows, int numCols) {
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            if (i % 2 == 0 && j % 2 == 0) {
                board[i * numCols + j].player = 1;
            } else {
                board[i * numCols + j].player = 2;
            }
        }
    }
}

int main() {
    int numRows = 8, numCols = 8;
    Player* board = newBoard(numRows, numCols);
    initializeBoard(board, numRows, numCols);
    printBoard(board, numRows, numCols);
    free(board);
    return 0;
}