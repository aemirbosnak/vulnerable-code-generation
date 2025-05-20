//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: secure
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX_CELLS 100

typedef struct Cell {
    int x;
    int y;
    int state;
} Cell;

void initializeGame(Cell **cells) {
    for (int i = 0; i < MAX_CELLS; i++) {
        cells[i] = malloc(sizeof(Cell));
        cells[i]->x = -1;
        cells[i]->y = -1;
        cells[i]->state = 0;
    }
}

void simulateGame(Cell **cells) {
    for (int i = 0; i < MAX_CELLS; i++) {
        int neighbors = 0;
        for (int x = -1; x <= 1; x++) {
            for (int y = -1; y <= 1; y++) {
                if (cells[i]->x + x >= 0 && cells[i]->x + x < MAX_CELLS && cells[i]->y + y >= 0 && cells[i]->y + y < MAX_CELLS) {
                    if (cells[i]->state == 1 && cells[i]->x + x == cells[i]->x && cells[i]->y + y == cells[i]->y) {
                        neighbors++;
                    }
                }
            }
        }

        switch (cells[i]->state) {
            case 0:
                if (neighbors == 3) {
                    cells[i]->state = 1;
                }
                break;
            case 1:
                if (neighbors < 2 || neighbors > 3) {
                    cells[i]->state = 0;
                }
                break;
        }
    }
}

int main() {
    Cell **cells = NULL;
    initializeGame(&cells);

    // Simulate game for 10 generations
    for (int gen = 0; gen < 10; gen++) {
        simulateGame(cells);
    }

    return 0;
}