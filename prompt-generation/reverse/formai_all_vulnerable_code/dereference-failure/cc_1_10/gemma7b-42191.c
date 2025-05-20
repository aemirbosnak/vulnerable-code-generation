//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 20

typedef struct Cell {
    int x;
    int y;
    int state;
} Cell;

void initializeBoard(Cell **board, int size) {
    *board = malloc(size * sizeof(Cell));
    for (int i = 0; i < size; i++) {
        board[i] = malloc(size * sizeof(Cell));
        for (int j = 0; j < size; j++) {
            board[i][j].x = i;
            board[i][j].y = j;
            board[i][j].state = 0;
        }
    }
}

void displayBoard(Cell **board, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", board[i][j].state);
        }
        printf("\n");
    }
}

int getNeighbors(Cell **board, int x, int y) {
    int neighbors = 0;
    for (int dx = -1; dx <= 1; dx++) {
        for (int dy = -1; dy <= 1; dy++) {
            if (board[x + dx][y + dy].state != 0) {
                neighbors++;
            }
        }
    }
    return neighbors;
}

void updateBoard(Cell **board, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            int neighbors = getNeighbors(board, i, j);
            if (neighbors == 3) {
                board[i][j].state = 1;
            } else if (neighbors == 2) {
                board[i][j].state = 0;
            }
        }
    }
}

int main() {
    Cell **board;
    initializeBoard(&board, MAX_SIZE);

    // Play the game
    for (int round = 0; round < 10; round++) {
        displayBoard(board, MAX_SIZE);
        updateBoard(board, MAX_SIZE);
    }

    displayBoard(board, MAX_SIZE);

    return 0;
}