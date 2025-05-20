//Falcon-180B DATASET v1.0 Category: Game of Life ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 100
#define HEIGHT 50
#define MAX_GENERATIONS 500

typedef struct {
    int x;
    int y;
} Cell;

Cell* createGrid() {
    Cell* grid = malloc(WIDTH * HEIGHT * sizeof(Cell));
    srand(time(NULL));
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            grid[i * HEIGHT + j].x = i;
            grid[i * HEIGHT + j].y = j;
        }
    }
    return grid;
}

void printGrid(Cell* grid) {
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            printf("%d ", grid[i * HEIGHT + j].x);
        }
        printf("\n");
    }
}

void nextGeneration(Cell* grid) {
    Cell* newGrid = malloc(WIDTH * HEIGHT * sizeof(Cell));
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            int neighbors = 0;
            for (int k = -1; k <= 1; k++) {
                for (int l = -1; l <= 1; l++) {
                    if ((k == 0 && l == 0) || (k == i && l == j)) {
                        continue;
                    }
                    int x = i + k;
                    int y = j + l;
                    if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT && grid[x * HEIGHT + y].x == 1) {
                        neighbors++;
                    }
                }
            }
            if (grid[i * HEIGHT + j].x == 1) {
                if (neighbors < 2 || neighbors > 3) {
                    newGrid[i * HEIGHT + j].x = 0;
                } else {
                    newGrid[i * HEIGHT + j].x = 1;
                }
            } else {
                if (neighbors == 3) {
                    newGrid[i * HEIGHT + j].x = 1;
                } else {
                    newGrid[i * HEIGHT + j].x = 0;
                }
            }
        }
    }
    free(grid);
    grid = newGrid;
}

int main() {
    Cell* grid = createGrid();
    int generation = 0;
    while (generation < MAX_GENERATIONS) {
        printGrid(grid);
        nextGeneration(grid);
        generation++;
    }
    free(grid);
    return 0;
}