//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CELL_SIZE 10
#define GRID_SIZE 20

typedef struct Cell {
    int x;
    int y;
    int state;
} Cell;

void initializeGrid(Cell **grid, int size) {
    grid = (Cell *)malloc(size * sizeof(Cell));
    for (int i = 0; i < size; i++) {
        grid[i] = (Cell *)malloc(sizeof(Cell));
        grid[i]->x = i;
        grid[i]->y = -1;
        grid[i]->state = 0;
    }
}

void updateCell(Cell **grid, int x, int y, int state) {
    grid[x]->state = state;
    grid[x]->y = y;
}

int main() {
    srand(time(NULL));
    Cell **grid = NULL;
    initializeGrid(&grid, GRID_SIZE);

    // Randomly assign some cells to the "alive" state
    for (int i = 0; i < GRID_SIZE; i++) {
        updateCell(grid, rand() % CELL_SIZE, -1, 1);
    }

    // Simulate game of life for 10 generations
    for (int generation = 0; generation < 10; generation++) {
        for (int x = 0; x < CELL_SIZE; x++) {
            for (int y = 0; y < GRID_SIZE; y++) {
                int numAliveNeighbors = 0;
                for (int dx = -1; dx <= 1; dx++) {
                    for (int dy = -1; dy <= 1; dy++) {
                        if (x + dx >= 0 && x + dx < CELL_SIZE && y + dy >= 0 && y + dy < GRID_SIZE) {
                            if (grid[x + dx]->state == 1) {
                                numAliveNeighbors++;
                            }
                        }
                    }
                }

                if (grid[x]->state == 1) {
                    if (numAliveNeighbors < 2) {
                        updateCell(grid, x, y, 0);
                    }
                } else if (numAliveNeighbors == 3) {
                    updateCell(grid, x, y, 1);
                }
            }
        }
    }

    // Print the final grid
    for (int x = 0; x < CELL_SIZE; x++) {
        for (int y = 0; y < GRID_SIZE; y++) {
            printf("%d ", grid[x]->state);
        }
        printf("\n");
    }

    return 0;
}