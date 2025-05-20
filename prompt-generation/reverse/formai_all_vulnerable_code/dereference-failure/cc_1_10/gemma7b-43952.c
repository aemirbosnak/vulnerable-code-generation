//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CELLS 100

typedef struct Cell {
    int x;
    int y;
    int state;
} Cell;

void initializeGame(Cell **cells, int numCells);
void updateCells(Cell **cells, int numCells);
void printCells(Cell **cells, int numCells);

int main() {
    srand(time(NULL));

    Cell **cells = (Cell **)malloc(MAX_CELLS * sizeof(Cell));
    initializeGame(cells, MAX_CELLS);

    for (int i = 0; i < 10; i++) {
        updateCells(cells, MAX_CELLS);
        printCells(cells, MAX_CELLS);
    }

    free(cells);

    return 0;
}

void initializeGame(Cell **cells, int numCells) {
    for (int i = 0; i < numCells; i++) {
        cells[i] = (Cell *)malloc(sizeof(Cell));
        cells[i]->x = rand() % numCells;
        cells[i]->y = rand() % numCells;
        cells[i]->state = rand() % 2;
    }
}

void updateCells(Cell **cells, int numCells) {
    for (int i = 0; i < numCells; i++) {
        int neighbors = 0;
        for (int x = -1; x <= 1; x++) {
            for (int y = -1; y <= 1; y++) {
                if (cells[i]->x + x >= 0 && cells[i]->x + x < numCells && cells[i]->y + y >= 0 && cells[i]->y + y < numCells) {
                    if (cells[i]->state == 1) {
                        neighbors++;
                    }
                }
            }
        }

        if (neighbors < 2) {
            cells[i]->state = 0;
        } else if (neighbors > 3) {
            cells[i]->state = 0;
        }
    }
}

void printCells(Cell **cells, int numCells) {
    for (int i = 0; i < numCells; i++) {
        printf("(%d, %d): %d ", cells[i]->x, cells[i]->y, cells[i]->state);
    }

    printf("\n");
}