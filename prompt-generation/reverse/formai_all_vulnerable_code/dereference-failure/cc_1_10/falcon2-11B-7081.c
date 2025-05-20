//Falcon2-11B DATASET v1.0 Category: Game of Life ; Style: modular
#include <stdio.h>
#include <stdlib.h>

void initializeGrid(int** grid, int size) {
    int i, j;
    for (i = 0; i < size; i++) {
        grid[i] = (int*)malloc(size * sizeof(int));
        for (j = 0; j < size; j++) {
            grid[i][j] = 0;
        }
    }
}

void printGrid(int** grid, int size) {
    int i, j;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

void applyRules(int** grid, int size) {
    int i, j;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            int liveNeighbors = 0;
            if (i > 0) {
                if (grid[i-1][j] == 1) {
                    liveNeighbors++;
                }
            }
            if (i < size-1) {
                if (grid[i+1][j] == 1) {
                    liveNeighbors++;
                }
            }
            if (j > 0) {
                if (grid[i][j-1] == 1) {
                    liveNeighbors++;
                }
            }
            if (j < size-1) {
                if (grid[i][j+1] == 1) {
                    liveNeighbors++;
                }
            }

            if (grid[i][j] == 1) {
                if (liveNeighbors < 2 || liveNeighbors > 3) {
                    grid[i][j] = 0;
                }
            } else if (liveNeighbors == 3) {
                grid[i][j] = 1;
            }
        }
    }
}

int main(int argc, char* argv[]) {
    int size;
    if (argc < 2) {
        printf("Usage: %s <size>\n", argv[0]);
        exit(1);
    }
    size = atoi(argv[1]);

    int** grid = (int**)malloc(size * sizeof(int*));
    initializeGrid(grid, size);

    for (int i = 0; i < size; i++) {
        printf("%s", grid[i]);
    }
    printf("\n");

    applyRules(grid, size);

    printGrid(grid, size);

    return 0;
}