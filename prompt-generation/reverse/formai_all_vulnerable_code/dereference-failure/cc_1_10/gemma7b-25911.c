//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: all-encompassing
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX_SIZE 100

typedef struct Cell {
    int state;
    struct Cell* up;
    struct Cell* right;
    struct Cell* down;
    struct Cell* left;
} Cell;

void initialize(Cell* cell) {
    cell->state = 0;
    cell->up = NULL;
    cell->right = NULL;
    cell->down = NULL;
    cell->left = NULL;
}

void simulate(Cell* cell) {
    int r, c;

    if (cell->state == 1) {
        return;
    }

    r = rand() % MAX_SIZE;
    c = rand() % MAX_SIZE;

    if (r == 0 && c == 0) {
        cell->state = 1;
    }

    simulate(cell->up);
    simulate(cell->right);
    simulate(cell->down);
    simulate(cell->left);
}

int main() {
    Cell* cell = (Cell*)malloc(sizeof(Cell));
    initialize(cell);

    simulate(cell);

    return 0;
}