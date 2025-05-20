//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 20

#define MAX_WATER 5

typedef struct Cell {
    int water;
    struct Cell* up;
    struct Cell* right;
    struct Cell* down;
    struct Cell* left;
} Cell;

void initialize_cell(Cell* cell) {
    cell->water = 0;
    cell->up = NULL;
    cell->right = NULL;
    cell->down = NULL;
    cell->left = NULL;
}

void fill_cell(Cell* cell) {
    cell->water = MAX_WATER;
}

void simulate_percolation(Cell* cell) {
    if (cell->water > 0) {
        fill_cell(cell->up);
        fill_cell(cell->right);
        fill_cell(cell->down);
        fill_cell(cell->left);
    }
}

int main() {
    srand(time(NULL));

    Cell* cells = (Cell*)malloc(WIDTH * HEIGHT * sizeof(Cell));
    initialize_cell(cells);

    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        if (rand() % 2 == 0) {
            fill_cell(cells + i);
        }
    }

    simulate_percolation(cells);

    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        printf("%d ", cells[i].water);
    }

    printf("\n");

    free(cells);

    return 0;
}