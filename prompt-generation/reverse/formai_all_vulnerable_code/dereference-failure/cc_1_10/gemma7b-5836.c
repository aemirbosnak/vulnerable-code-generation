//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: careful
#include <stdio.h>
#include <stdlib.h>

#define MAX_CELLS 10

typedef struct Cell {
    int alive;
    struct Cell* neighbors;
} Cell;

void initialize_game(Cell** cells) {
    for (int i = 0; i < MAX_CELLS; i++) {
        cells[i] = malloc(sizeof(Cell));
        cells[i]->alive = 0;
        cells[i]->neighbors = NULL;
    }
}

void simulate_game(Cell** cells) {
    for (int i = 0; i < MAX_CELLS; i++) {
        int num_alive_neighbors = 0;
        Cell* neighbor = cells[i]->neighbors;
        while (neighbor) {
            if (neighbor->alive) {
                num_alive_neighbors++;
            }
            neighbor = neighbor->neighbors;
        }

        if (cells[i]->alive && num_alive_neighbors < 2) {
            cells[i]->alive = 0;
        } else if (!cells[i]->alive && num_alive_neighbors == 3) {
            cells[i]->alive = 1;
        }
    }
}

int main() {
    Cell** cells = NULL;
    initialize_game(&cells);

    // Simulate game for 10 rounds
    for (int round = 0; round < 10; round++) {
        simulate_game(cells);
    }

    // Print final state of cells
    for (int i = 0; i < MAX_CELLS; i++) {
        if (cells[i]->alive) {
            printf("Cell %d is alive\n", i);
        } else {
            printf("Cell %d is dead\n", i);
        }
    }

    return 0;
}