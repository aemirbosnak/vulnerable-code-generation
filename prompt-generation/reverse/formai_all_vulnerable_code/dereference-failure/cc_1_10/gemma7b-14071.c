//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 20

typedef struct Cell {
    int x, y;
    int state;
} Cell;

void initializeBoard(Cell **board, int size) {
    board = (Cell **)malloc(size * sizeof(Cell *));
    for (int i = 0; i < size; i++) {
        board[i] = (Cell *)malloc(size * sizeof(Cell));
        for (int j = 0; j < size; j++) {
            board[i][j].x = i;
            board[i][j].y = j;
            board[i][j].state = 0;
        }
    }
}

void printBoard(Cell **board, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", board[i][j].state);
        }
        printf("\n");
    }
}

int countAliveNeighbors(Cell **board, int x, int y) {
    int aliveNeighbors = 0;
    for (int dx = -1; dx <= 1; dx++) {
        for (int dy = -1; dy <= 1; dy++) {
            if (dx == 0 && dy == 0) continue;
            if (board[x + dx][y + dy].state == 1) {
                aliveNeighbors++;
            }
        }
    }
    return aliveNeighbors;
}

void updateBoard(Cell **board, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            int aliveNeighbors = countAliveNeighbors(board, i, j);
            if (aliveNeighbors < 2) board[i][j].state = 0;
            else if (aliveNeighbors == 2) board[i][j].state = 1;
        }
    }
}

int main() {
    int size = MAX_SIZE;
    Cell **board;
    initializeBoard(&board, size);

    // Initial state
    board[5][5].state = 1;
    board[5][6].state = 1;
    board[6][5].state = 1;
    board[6][6].state = 1;

    printBoard(board, size);

    updateBoard(board, size);

    printBoard(board, size);

    return 0;
}