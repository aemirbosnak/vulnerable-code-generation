//Falcon-180B DATASET v1.0 Category: Percolation Simulator ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100
#define INIT_DENSITY 0.5
#define INIT_WATER_LEVEL 0.8

enum {
    EMPTY = 0,
    FULL = 1
};

struct Cell {
    int state;
    int waterLevel;
};

struct Cell *createGrid(int size) {
    struct Cell *grid = (struct Cell *)malloc(size * sizeof(struct Cell));
    for (int i = 0; i < size; i++) {
        grid[i].state = EMPTY;
        grid[i].waterLevel = 0;
    }
    return grid;
}

void freeGrid(struct Cell *grid, int size) {
    free(grid);
}

void initGrid(struct Cell *grid, int size) {
    for (int i = 0; i < size; i++) {
        if (rand() % 2 == 0) {
            grid[i].state = FULL;
        }
    }
}

void printGrid(struct Cell *grid, int size) {
    for (int i = 0; i < size; i++) {
        if (grid[i].state == FULL) {
            printf("X");
        } else {
            printf("-");
        }
    }
    printf("\n");
}

int countNeighbors(struct Cell *grid, int x, int y, int size) {
    int count = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            int nx = (x + i + size) % size;
            int ny = (y + j + size) % size;
            if (i == 0 && j == 0) {
                continue;
            }
            if (grid[nx].state == FULL) {
                count++;
            }
        }
    }
    return count;
}

void percolate(struct Cell *grid, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (grid[i * size + j].state == FULL) {
                int neighbors = countNeighbors(grid, i, j, size);
                if (neighbors < 2) {
                    grid[i * size + j].state = EMPTY;
                }
            }
        }
    }
}

int main() {
    srand(time(NULL));
    int size = MAX_SIZE;
    struct Cell *grid = createGrid(size);
    initGrid(grid, size);
    int waterLevel = INIT_WATER_LEVEL;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (grid[i * size + j].state == FULL) {
                grid[i * size + j].waterLevel = waterLevel;
            }
        }
    }
    printGrid(grid, size);
    percolate(grid, size);
    printGrid(grid, size);
    freeGrid(grid, size);
    return 0;
}