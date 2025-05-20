//GEMINI-pro DATASET v1.0 Category: Percolation Simulator ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structure to represent a site
typedef struct Site {
    int x;
    int y;
    int open;
} Site;

// Create a percolation grid
Site* create_grid(int n) {
    Site* grid = malloc(n * n * sizeof(Site));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            grid[i * n + j].x = i;
            grid[i * n + j].y = j;
            grid[i * n + j].open = 0;
        }
    }
    return grid;
}

// Open a site
void open_site(Site* grid, int n, int x, int y) {
    if (x < 0 || x >= n || y < 0 || y >= n) {
        return;
    }
    grid[x * n + y].open = 1;
}

// Check if a site is open
int is_open(Site* grid, int n, int x, int y) {
    if (x < 0 || x >= n || y < 0 || y >= n) {
        return 0;
    }
    return grid[x * n + y].open;
}

// Check if the grid percolates
int percolates(Site* grid, int n) {
    // Check if the top row is open
    for (int i = 0; i < n; i++) {
        if (is_open(grid, n, i, 0)) {
            // Check if the bottom row is open
            for (int j = 0; j < n; j++) {
                if (is_open(grid, n, j, n - 1)) {
                    return 1;
                }
            }
        }
    }
    return 0;
}

// Print the grid
void print_grid(Site* grid, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", grid[i * n + j].open);
        }
        printf("\n");
    }
}

// Main function
int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Create a percolation grid
    int n = 10;
    Site* grid = create_grid(n);

    // Open some sites
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (rand() % 2 == 0) {
                open_site(grid, n, i, j);
            }
        }
    }

    // Print the grid
    print_grid(grid, n);

    // Check if the grid percolates
    if (percolates(grid, n)) {
        printf("The grid percolates.\n");
    } else {
        printf("The grid does not percolate.\n");
    }

    // Free the grid
    free(grid);

    return 0;
}