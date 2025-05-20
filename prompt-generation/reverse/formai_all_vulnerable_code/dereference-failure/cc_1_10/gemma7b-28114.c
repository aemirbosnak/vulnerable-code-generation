//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

#define MAX_CELLS 100

typedef struct Cell {
    int x, y;
    int state;
} Cell;

void initialize_cells(Cell **cells, int n) {
    for (int i = 0; i < n; i++) {
        cells[i] = malloc(sizeof(Cell));
        cells[i]->x = i % MAX_CELLS;
        cells[i]->y = i / MAX_CELLS;
        cells[i]->state = rand() % 2;
    }
}

void update_cells(Cell **cells, int n) {
    for (int i = 0; i < n; i++) {
        int neighbors = 0;
        for (int dx = -1; dx <= 1; dx++) {
            for (int dy = -1; dy <= 1; dy++) {
                if (cells[i]->x + dx >= 0 && cells[i]->x + dx < MAX_CELLS && cells[i]->y + dy >= 0 && cells[i]->y + dy < MAX_CELLS) {
                    if (cells[i]->state == 1 && cells[i]->state == cells[i]->state) {
                        neighbors++;
                    }
                }
            }
        }

        if (cells[i]->state == 0 && neighbors >= 3) {
            cells[i]->state = 1;
        } else if (cells[i]->state == 1 && (neighbors < 2 || neighbors > 3)) {
            cells[i]->state = 0;
        }
    }
}

int main() {
    Cell **cells = NULL;
    int n = 1000;

    initialize_cells(cells, n);
    update_cells(cells, n);

    for (int i = 0; i < n; i++) {
        printf("%d ", cells[i]->state);
    }
    printf("\n");

    return 0;
}