//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: safe
#include <stdio.h>
#include <stdlib.h>

#define MAX_CELLS 100

typedef struct Cell {
    int x, y;
    int state;
} Cell;

void initializeGame(Cell **cells) {
    for (int x = 0; x < MAX_CELLS; x++) {
        for (int y = 0; y < MAX_CELLS; y++) {
            cells[x][y].x = x;
            cells[x][y].y = y;
            cells[x][y].state = 0;
        }
    }
}

void calculateNextState(Cell **cells) {
    for (int x = 0; x < MAX_CELLS; x++) {
        for (int y = 0; y < MAX_CELLS; y++) {
            int numNeighbors = 0;
            for (int dx = -1; dx <= 1; dx++) {
                for (int dy = -1; dy <= 1; dy++) {
                    if (dx == 0 && dy == 0) continue;
                    if (cells[x + dx][y + dy].state == 1) numNeighbors++;
                }
            }
            switch (numNeighbors) {
                case 2:
                    cells[x][y].state = 1;
                    break;
                case 3:
                    cells[x][y].state = 1;
                    break;
                default:
                    cells[x][y].state = 0;
                    break;
            }
        }
    }
}

int main() {
    Cell **cells = (Cell **)malloc(MAX_CELLS * sizeof(Cell *));
    initializeGame(cells);

    for (int t = 0; t < 10; t++) {
        calculateNextState(cells);
    }

    for (int x = 0; x < MAX_CELLS; x++) {
        for (int y = 0; y < MAX_CELLS; y++) {
            printf("%d ", cells[x][y].state);
        }
        printf("\n");
    }

    free(cells);
    return 0;
}