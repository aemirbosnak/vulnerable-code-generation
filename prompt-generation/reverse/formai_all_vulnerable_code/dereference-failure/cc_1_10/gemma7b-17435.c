//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

#define MAX_CELLS 100

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

void set_neighbor(Cell* cell, Cell* neighbor) {
    cell->neighbors = neighbor;
}

void simulate_game(Cell** cells) {
    for (int i = 0; i < MAX_CELLS; i++) {
        int num_neighbors = 0;
        Cell* neighbor = cells[i]->neighbors;
        while (neighbor) {
            if (neighbor->alive) {
                num_neighbors++;
            }
            neighbor = neighbor->neighbors;
        }

        if (cells[i]->alive) {
            if (num_neighbors < 2) {
                cells[i]->alive = 0;
            }
        } else if (num_neighbors == 3) {
            cells[i]->alive = 1;
        }
    }
}

int main() {
    Cell** cells = NULL;
    initialize_game(&cells);

    // Set up the game board
    cells[0]->alive = 1;
    cells[1]->alive = 1;
    cells[2]->alive = 1;
    cells[5]->alive = 1;
    cells[6]->alive = 1;

    // Simulate the game
    simulate_game(cells);

    // Print the game board
    for (int i = 0; i < MAX_CELLS; i++) {
        if (cells[i]->alive) {
            printf("O ");
        } else {
            printf(". ");
        }
    }

    return 0;
}