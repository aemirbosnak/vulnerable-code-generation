//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
 * Function to print the 2D grid.
 */
void print_grid(bool **grid, int size) {
    for(int i=0; i<size; i++) {
        for(int j=0; j<size; j++) {
            printf("%c ", grid[i][j] ? '#' : '-');
        }
        printf("\n");
    }
    printf("\n");
}

/*
 * Function to check if a site is open or not.
 */
bool is_open(bool **grid, int row, int col) {
    return grid[row][col];
}

/*
 * Function to open a site.
 */
void open_site(bool **grid, int row, int col) {
    grid[row][col] = true;
}

/*
 * Function to check if the system percolates.
 */
bool percolates(bool **grid, int size) {
    for(int j=0; j<size; j++) {
        if(grid[0][j]) {
            for(int i=0; i<size; i++) {
                if(grid[size-1][i]) {
                    return true;
                }
            }
        }
    }
    return false;
}

int main() {
    int size;
    printf("Enter the size of the grid: ");
    scanf("%d", &size);

    // Dynamically allocate 2D array.
    bool** grid = (bool**) malloc(size * sizeof(bool*));
    for(int i=0; i<size; i++) {
        grid[i] = (bool*) malloc(size * sizeof(bool));
        for(int j=0; j<size; j++) {
            grid[i][j] = false;
        }
    }

    // Print the initial grid.
    print_grid(grid, size);

    // Open random sites until the system percolates.
    while(!percolates(grid, size)) {
        int row = rand() % size;
        int col = rand() % size;
        if(!is_open(grid, row, col)) {
            open_site(grid, row, col);
        }
    }

    // Print the final grid.
    print_grid(grid, size);

    // Free memory.
    for(int i=0; i<size; i++) {
        free(grid[i]);
    }
    free(grid);

    return 0;
}