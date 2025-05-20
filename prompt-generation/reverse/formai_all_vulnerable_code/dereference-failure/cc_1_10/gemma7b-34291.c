//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: asynchronous
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX_CELLS 100

typedef struct Cell {
    int x;
    int y;
    int state;
} Cell;

void InitializeCells(Cell **cells) {
    for (int i = 0; i < MAX_CELLS; i++) {
        cells[i] = malloc(sizeof(Cell));
        cells[i]->x = i % MAX_CELLS;
        cells[i]->y = i / MAX_CELLS;
        cells[i]->state = rand() % 2;
    }
}

void SimulateLife(Cell **cells) {
    for (int i = 0; i < MAX_CELLS; i++) {
        int neighbors = 0;
        for (int dx = -1; dx <= 1; dx++) {
            for (int dy = -1; dy <= 1; dy++) {
                if (cells[i]->x + dx >= 0 && cells[i]->x + dx < MAX_CELLS && cells[i]->y + dy >= 0 && cells[i]->y + dy < MAX_CELLS) {
                    neighbors++;
                }
            }
        }

        if (cells[i]->state == 0 && neighbors >= 3) {
            cells[i]->state = 1;
        } else if (cells[i]->state == 1 && neighbors < 2) {
            cells[i]->state = 0;
        }
    }
}

int main() {
    Cell **cells = NULL;
    InitializeCells(&cells);
    SimulateLife(cells);

    for (int i = 0; i < MAX_CELLS; i++) {
        printf("%d ", cells[i]->state);
    }
    printf("\n");

    return 0;
}