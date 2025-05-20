//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

#define MAX_CELLS 20

typedef struct Cell {
    int state;
    struct Cell* neighbors[4];
} Cell;

void initializeBoard(Cell** board) {
    int i, j;
    *board = (Cell*)malloc(MAX_CELLS * sizeof(Cell));
    for (i = 0; i < MAX_CELLS; i++) {
        (*board)[i].state = 0;
        for (j = 0; j < 4; j++) {
            (*board)[i].neighbors[j] = NULL;
        }
    }
}

void setCellState(Cell* cell, int state) {
    cell->state = state;
}

void updateBoard(Cell** board) {
    int i, j;
    for (i = 0; i < MAX_CELLS; i++) {
        Cell* currentCell = board[i];
        int numNeighbors = 0;
        for (j = 0; j < 4; j++) {
            if (currentCell->neighbors[j] != NULL) {
                numNeighbors++;
            }
        }
        if (currentCell->state == 1 && numNeighbors < 2) {
            setCellState(currentCell, 0);
        } else if (currentCell->state == 0 && numNeighbors == 2) {
            setCellState(currentCell, 1);
        }
    }
}

int main() {
    Cell** board;
    initializeBoard(&board);
    setCellState(board[0], 1);
    setCellState(board[5], 1);
    updateBoard(board);
    for (int i = 0; i < MAX_CELLS; i++) {
        printf("%d ", board[i]->state);
    }
    printf("\n");
    return 0;
}