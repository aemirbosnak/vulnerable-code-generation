//Falcon2-11B DATASET v1.0 Category: Game of Life ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int i, j, rows, columns;
    int **grid;

    srand(time(0)); // Seed random number generator with current time
    rows = 10;
    columns = 10;

    grid = malloc(rows * sizeof(int *));
    for (i = 0; i < rows; i++) {
        grid[i] = malloc(columns * sizeof(int));
    }

    // Initialize grid with random values
    for (i = 0; i < rows; i++) {
        for (j = 0; j < columns; j++) {
            grid[i][j] = rand() % 2; // 0 for dead, 1 for alive
        }
    }

    // Print initial grid
    printf("Initial Grid:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < columns; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < rows; i++) {
        for (j = 0; j < columns; j++) {
            // Iterate through the grid to determine the next state of each cell
            int neighbors = 0;
            for (int k = -1; k <= 1; k++) {
                for (int l = -1; l <= 1; l++) {
                    if (k == 0 && l == 0) {
                        continue; // Skip diagonal neighbors
                    }
                    int row = i + k;
                    int col = j + l;
                    if (row >= 0 && row < rows && col >= 0 && col < columns) {
                        neighbors += grid[row][col];
                    }
                }
            }

            // Apply Conway's Game of Life rules to determine cell's next state
            if (grid[i][j] == 1 && (neighbors < 2 || neighbors > 3)) {
                grid[i][j] = 0;
            } else if (grid[i][j] == 0 && neighbors == 3) {
                grid[i][j] = 1;
            }
        }
    }

    // Print final grid
    printf("\nFinal Grid:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < columns; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    // Free allocated memory
    for (i = 0; i < rows; i++) {
        free(grid[i]);
    }
    free(grid);

    return 0;
}