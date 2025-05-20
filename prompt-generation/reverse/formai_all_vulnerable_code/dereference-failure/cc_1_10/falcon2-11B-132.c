//Falcon2-11B DATASET v1.0 Category: Game of Life ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the Game of Life rules
#define LIVE 1
#define DEAD 0

void gameOfLife(int **grid, int rows, int cols) {
    // Create an empty grid
    for (int i = 0; i < rows; i++) {
        grid[i] = (int *)malloc(sizeof(int) * cols);
        for (int j = 0; j < cols; j++) {
            grid[i][j] = DEAD;
        }
    }

    // Run the Game of Life for 100 generations
    for (int i = 0; i < 100; i++) {
        // Create a copy of the current grid
        int **copyGrid = (int **)malloc(sizeof(int *) * rows);
        for (int j = 0; j < rows; j++) {
            copyGrid[j] = (int *)malloc(sizeof(int) * cols);
            for (int k = 0; k < cols; k++) {
                copyGrid[j][k] = grid[j][k];
            }
        }

        // Apply the Game of Life rules
        for (int j = 0; j < rows; j++) {
            for (int k = 0; k < cols; k++) {
                int neighbors = countNeighbors(grid, rows, cols, j, k);
                if (grid[j][k] == LIVE && neighbors < 2) {
                    copyGrid[j][k] = DEAD;
                } else if (grid[j][k] == DEAD && neighbors == 3) {
                    copyGrid[j][k] = LIVE;
                } else {
                    copyGrid[j][k] = grid[j][k];
                }
            }
        }

        // Copy the updated grid back
        for (int j = 0; j < rows; j++) {
            for (int k = 0; k < cols; k++) {
                grid[j][k] = copyGrid[j][k];
            }
        }
    }

    // Print the final grid
    for (int j = 0; j < rows; j++) {
        for (int k = 0; k < cols; k++) {
            printf("%d ", grid[j][k]);
        }
        printf("\n");
    }
}

// Count the number of live neighbors of a cell
int countNeighbors(int **grid, int rows, int cols, int i, int j) {
    int count = 0;
    for (int k = -1; k <= 1; k++) {
        for (int l = -1; l <= 1; l++) {
            if (i + k >= 0 && i + k < rows && j + l >= 0 && j + l < cols && grid[i + k][j + l] == LIVE) {
                count++;
            }
        }
    }
    return count;
}

int main() {
    int rows = 20;
    int cols = 20;

    // Allocate memory for the grid
    int **grid = (int **)malloc(sizeof(int *) * rows);
    for (int i = 0; i < rows; i++) {
        grid[i] = (int *)malloc(sizeof(int) * cols);
        for (int j = 0; j < cols; j++) {
            grid[i][j] = DEAD;
        }
    }

    // Generate a random initial grid
    srand(time(NULL));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            grid[i][j] = (rand() % 2) == 0? LIVE : DEAD;
        }
    }

    // Run the Game of Life
    gameOfLife(grid, rows, cols);

    free(grid);

    return 0;
}