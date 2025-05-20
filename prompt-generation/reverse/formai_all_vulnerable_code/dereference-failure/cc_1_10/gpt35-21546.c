//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define EMPTY   0
#define BLOCKED 1
#define OPEN    2

// Function to randomly assign a state to each site in the grid
void initialize_grid(int** grid, int n, float p_block) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            float r = rand() / (float) RAND_MAX;
            if (r < p_block) {
                grid[i][j] = BLOCKED;
            } else {
                grid[i][j] = EMPTY;
            }
        }
    }
}

// Recursive function to open sites in neighboring cells
void connection_dfs(int** grid, int i, int j, int n) {
    if (i < 0 || j < 0 || i >= n || j >= n || grid[i][j] != EMPTY) {
        return;
    }
    grid[i][j] = OPEN;
    connection_dfs(grid, i-1, j, n);
    connection_dfs(grid, i+1, j, n);
    connection_dfs(grid, i, j-1, n);
    connection_dfs(grid, i, j+1, n);
}

// Function to check if the top and bottom rows are connected
int percolates(int** grid, int n) {
    int** connection = malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        connection[i] = calloc(n, sizeof(int));
    }
    for (int i = 0; i < n; i++) {
        if (grid[0][i] == OPEN) {
            connection_dfs(grid, 0, i, n);
        }
    }
    for (int i = 0; i < n; i++) {
        if (connection[n-1][i] == OPEN) {
            return 1;
        }
    }
    return 0;
}

// Function to print the grid in ASCII form
void print_grid(int** grid, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == EMPTY) {
                printf(".");
            } else if (grid[i][j] == BLOCKED) {
                printf("X");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

// Main function to run the simulator
int main(int argc, char* argv[]) {
    srand(time(NULL));
    int n = atoi(argv[1]);
    float p_block = atof(argv[2]);
    int** grid = malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        grid[i] = calloc(n, sizeof(int));
    }
    initialize_grid(grid, n, p_block);
    print_grid(grid, n);
    printf("\n");
    if (percolates(grid, n)) {
        printf("The grid percolates!\n");
    } else {
        printf("The grid does not percolate.\n");
    }
    return 0;
}