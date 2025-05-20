//Falcon2-11B DATASET v1.0 Category: Percolation Simulator ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// function to check if cell is occupied or not
int isOccupied(int x, int y) {
    return rand() % 2;
}

// function to percolate the grid
void percolate(int grid[10][10], int rows, int cols) {
    int x, y, i, j;
    srand(time(0)); // seed the random number generator

    // iterate over all cells
    for (x = 0; x < rows; x++) {
        for (y = 0; y < cols; y++) {
            if (isOccupied(x, y)) {
                grid[x][y] = 0;
            }
        }
    }

    // start from top-left corner
    for (i = 0; i < rows - 1; i++) {
        for (j = 0; j < cols - 1; j++) {
            int neighbors = 0;

            // count number of occupied neighbors
            neighbors += isOccupied(x, y);
            neighbors += isOccupied(x, y + 1);
            neighbors += isOccupied(x + 1, y);
            neighbors += isOccupied(x + 1, y + 1);

            // if more than 2 neighbors are occupied, the cell is percolated
            if (neighbors > 2) {
                grid[x][y] = 1;
            }
        }
    }
}

int main() {
    int grid[10][10];
    int rows, cols, i, j;
    int c = 0;

    printf("Enter the size of the grid: ");
    scanf("%d %d", &rows, &cols);

    // initialize grid with 0s
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            grid[i][j] = 0;
        }
    }

    // print the grid
    printf("Initial grid:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    percolate(grid, rows, cols);

    // print the percolated grid
    printf("\nPercolated grid:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    return 0;
}