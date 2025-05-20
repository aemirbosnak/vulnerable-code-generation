//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

#define MAX_CELLS 10

typedef struct Cell {
    int x;
    int y;
    int state;
} Cell;

void initializeBoard(Cell **board) {
    for (int i = 0; i < MAX_CELLS; i++) {
        board[i] = malloc(sizeof(Cell));
        board[i]->x = i % MAX_CELLS;
        board[i]->y = i / MAX_CELLS;
        board[i]->state = 0;
    }
}

void printBoard(Cell **board) {
    for (int i = 0; i < MAX_CELLS; i++) {
        printf("%d ", board[i]->state);
    }
    printf("\n");
}

void calculateNextState(Cell **board) {
    for (int i = 0; i < MAX_CELLS; i++) {
        int neighbors = 0;
        for (int dx = -1; dx <= 1; dx++) {
            for (int dy = -1; dy <= 1; dy++) {
                if (dx == 0 && dy == 0) continue;
                int x = board[i]->x + dx;
                int y = board[i]->y + dy;
                if (x >= 0 && x < MAX_CELLS && y >= 0 && y < MAX_CELLS) {
                    neighbors++;
                }
            }
        }
        board[i]->state = (neighbors == 3) ? 1 : 0;
    }
}

int main() {
    Cell **board = NULL;
    initializeBoard(&board);

    // Simulate game of life
    for (int t = 0; t < 10; t++) {
        printBoard(board);
        calculateNextState(board);
    }

    return 0;
}