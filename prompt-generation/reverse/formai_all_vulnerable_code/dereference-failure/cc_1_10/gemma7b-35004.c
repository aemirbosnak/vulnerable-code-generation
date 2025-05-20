//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CELLS 100

typedef struct Cell {
    int x, y;
    int state;
} Cell;

void initialize_cells(Cell **cells) {
    for (int i = 0; i < MAX_CELLS; i++) {
        cells[i] = malloc(sizeof(Cell));
        cells[i]->x = i % MAX_CELLS;
        cells[i]->y = i / MAX_CELLS;
        cells[i]->state = rand() % 2;
    }
}

void update_cells(Cell **cells) {
    for (int i = 0; i < MAX_CELLS; i++) {
        int neighbors = 0;
        for (int dx = -1; dx <= 1; dx++) {
            for (int dy = -1; dy <= 1; dy++) {
                if (dx == 0 && dy == 0) continue;
                int x = cells[i]->x + dx;
                int y = cells[i]->y + dy;
                if (x >= 0 && x < MAX_CELLS && y >= 0 && y < MAX_CELLS) {
                    neighbors++;
                }
            }
        }

        cells[i]->state = (neighbors == 2) ? 1 : 0;
    }
}

int main() {
    srand(time(NULL));
    Cell **cells = malloc(MAX_CELLS * sizeof(Cell *));

    initialize_cells(cells);
    update_cells(cells);

    for (int i = 0; i < MAX_CELLS; i++) {
        printf("%d ", cells[i]->state);
    }
    printf("\n");

    free(cells);
    return 0;
}