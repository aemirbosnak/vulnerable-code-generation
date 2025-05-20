//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: protected
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 20

typedef struct Cell {
    int x, y;
    int state;
} Cell;

void initializeBoard(Cell **board) {
    int i, j;
    for (i = 0; i < MAX_SIZE; i++) {
        for (j = 0; j < MAX_SIZE; j++) {
            board[i][j].x = i;
            board[i][j].y = j;
            board[i][j].state = 0;
        }
    }
}

void printBoard(Cell **board) {
    int i, j;
    for (i = 0; i < MAX_SIZE; i++) {
        for (j = 0; j < MAX_SIZE; j++) {
            printf("%d ", board[i][j].state);
        }
        printf("\n");
    }
}

void updateBoard(Cell **board) {
    int i, j, neighbors;
    for (i = 0; i < MAX_SIZE; i++) {
        for (j = 0; j < MAX_SIZE; j++) {
            neighbors = 0;
            if (board[i - 1][j].state == 1) neighbors++;
            if (board[i + 1][j].state == 1) neighbors++;
            if (board[i][j - 1].state == 1) neighbors++;
            if (board[i][j + 1].state == 1) neighbors++;

            if (board[i][j].state == 1 && neighbors < 2) board[i][j].state = 0;
            if (board[i][j].state == 0 && neighbors == 3) board[i][j].state = 1;
        }
    }
}

int main() {
    Cell **board = (Cell **)malloc(MAX_SIZE * MAX_SIZE * sizeof(Cell));
    initializeBoard(board);

    board[5][5].state = 1;
    board[5][6].state = 1;
    board[6][5].state = 1;
    board[6][6].state = 1;

    printBoard(board);

    updateBoard(board);

    printBoard(board);

    free(board);
    return 0;
}