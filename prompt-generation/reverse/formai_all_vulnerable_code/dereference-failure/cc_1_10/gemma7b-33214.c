//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: rigorous
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX_CELLS 256

typedef struct Cell {
    int state;
    struct Cell* up, *right, *down, *left;
} Cell;

Cell** createGrid(int size) {
    Cell** grid = (Cell**)malloc(size * sizeof(Cell*));
    for (int r = 0; r < size; r++) {
        grid[r] = (Cell*)malloc(size * sizeof(Cell));
        for (int c = 0; c < size; c++) {
            grid[r][c].state = 0;
            grid[r][c].up = NULL;
            grid[r][c].right = NULL;
            grid[r][c].down = NULL;
            grid[r][c].left = NULL;
        }
    }
    return grid;
}

void percolate(Cell** grid, int size) {
    srand(time(NULL));
    for (int r = 0; r < size; r++) {
        for (int c = 0; c < size; c++) {
            if (grid[r][c].state == 1) {
                int rand_dir = rand() % 4;
                switch (rand_dir) {
                    case 0:
                        if (grid[r - 1][c].state == 0) grid[r - 1][c].state = 1;
                        break;
                    case 1:
                        if (grid[r][c + 1].state == 0) grid[r][c + 1].state = 1;
                        break;
                    case 2:
                        if (grid[r + 1][c].state == 0) grid[r + 1][c].state = 1;
                        break;
                    case 3:
                        if (grid[r][c - 1].state == 0) grid[r][c - 1].state = 1;
                        break;
                }
            }
        }
    }
}

void printGrid(Cell** grid, int size) {
    for (int r = 0; r < size; r++) {
        for (int c = 0; c < size; c++) {
            printf("%d ", grid[r][c].state);
        }
        printf("\n");
    }
}

int main() {
    int size = 5;
    Cell** grid = createGrid(size);
    percolate(grid, size);
    printGrid(grid, size);
    free(grid);
    return 0;
}