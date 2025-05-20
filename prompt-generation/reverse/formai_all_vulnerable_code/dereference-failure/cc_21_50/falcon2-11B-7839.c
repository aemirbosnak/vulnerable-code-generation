//Falcon2-11B DATASET v1.0 Category: Game of Life ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

#define ROWS 10
#define COLS 10

int main(int argc, char **argv) {
    int i, j;
    int **grid;

    grid = (int **)malloc(sizeof(int *) * ROWS);
    for (i = 0; i < ROWS; i++) {
        grid[i] = (int *)malloc(sizeof(int) * COLS);
        for (j = 0; j < COLS; j++) {
            grid[i][j] = 0;
        }
    }

    // Initialize the grid with some random cells
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            grid[i][j] = rand() % 2;
        }
    }

    // Print the initial grid
    printf("Initial grid:\n");
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    // Iterate through the grid and update the cells according to the Game of Life rules
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            int neighbors = 0;

            // Count the number of live neighbors for the current cell
            for (int k = -1; k <= 1; k += 2) {
                if (k == 0 && i == 0 && j == 0) continue;
                int neighbor = (i + k) % ROWS + 1;
                if (neighbor >= ROWS || neighbor < 0) continue;
                int neighborCol = (j + k) % COLS + 1;
                if (neighborCol >= COLS || neighborCol < 0) continue;
                if (grid[neighbor][neighborCol] == 1) neighbors++;
            }

            // Apply the Game of Life rules to the current cell
            if (grid[i][j] == 1 && neighbors == 2 || (grid[i][j] == 0 && neighbors == 3)) {
                grid[i][j] = 1;
            } else if (grid[i][j] == 1 && neighbors < 2 || (grid[i][j] == 0 && neighbors > 3)) {
                grid[i][j] = 0;
            }
        }
    }

    // Print the updated grid
    printf("Updated grid:\n");
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    // Free the memory used by the grid
    for (i = 0; i < ROWS; i++) {
        free(grid[i]);
    }
    free(grid);

    return 0;
}