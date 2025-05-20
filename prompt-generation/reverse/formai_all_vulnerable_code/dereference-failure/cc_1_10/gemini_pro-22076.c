//GEMINI-pro DATASET v1.0 Category: Percolation Simulator ; Style: unmistakable
// Percolation Simulator

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Grid dimensions
#define GRID_WIDTH 10
#define GRID_HEIGHT 10

// Probability of a site being open
#define OPEN_PROBABILITY 0.5

// Union-find data structure
typedef struct {
    int *id;    // id[i] = parent of i
    int *sz;    // sz[i] = number of objects in subtree rooted at i
    int count;  // number of components
} UF;

// Create a new union-find data structure
UF *UF_create(int n) {
    UF *uf = malloc(sizeof(UF));
    uf->id = malloc(n * sizeof(int));
    uf->sz = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        uf->id[i] = i;
        uf->sz[i] = 1;
    }
    uf->count = n;
    return uf;
}

// Find the root of the tree containing p
int UF_find(UF *uf, int p) {
    while (p != uf->id[p]) {
        uf->id[p] = uf->id[uf->id[p]];
        p = uf->id[p];
    }
    return p;
}

// Merge the trees containing p and q
void UF_union(UF *uf, int p, int q) {
    int i = UF_find(uf, p);
    int j = UF_find(uf, q);
    if (i == j) return;
    if (uf->sz[i] < uf->sz[j]) {
        uf->id[i] = j;
        uf->sz[j] += uf->sz[i];
    } else {
        uf->id[j] = i;
        uf->sz[i] += uf->sz[j];
    }
    uf->count--;
}

// Destroy the union-find data structure
void UF_destroy(UF *uf) {
    free(uf->id);
    free(uf->sz);
    free(uf);
}

// Open a site at (row, col)
void open_site(int grid[][GRID_WIDTH], int row, int col) {
    grid[row][col] = 1;
}

// Check if a site at (row, col) is open
int is_open(int grid[][GRID_WIDTH], int row, int col) {
    return grid[row][col] == 1;
}

// Check if the grid percolates
int percolates(int grid[][GRID_WIDTH]) {
    // Create a union-find data structure to track connected components
    UF *uf = UF_create(GRID_WIDTH * GRID_HEIGHT);

    // Iterate over each row and column
    for (int row = 0; row < GRID_HEIGHT; row++) {
        for (int col = 0; col < GRID_WIDTH; col++) {
            // If the site is open, connect it to its neighbors
            if (is_open(grid, row, col)) {
                if (row > 0 && is_open(grid, row - 1, col)) {
                    UF_union(uf, row * GRID_WIDTH + col, (row - 1) * GRID_WIDTH + col);
                }
                if (col > 0 && is_open(grid, row, col - 1)) {
                    UF_union(uf, row * GRID_WIDTH + col, row * GRID_WIDTH + col - 1);
                }
                if (row < GRID_HEIGHT - 1 && is_open(grid, row + 1, col)) {
                    UF_union(uf, row * GRID_WIDTH + col, (row + 1) * GRID_WIDTH + col);
                }
                if (col < GRID_WIDTH - 1 && is_open(grid, row, col + 1)) {
                    UF_union(uf, row * GRID_WIDTH + col, row * GRID_WIDTH + col + 1);
                }
            }
        }
    }

    // Check if the top and bottom rows are connected
    int top_root = UF_find(uf, 0);
    int bottom_root = UF_find(uf, (GRID_HEIGHT - 1) * GRID_WIDTH);

    // Destroy the union-find data structure
    UF_destroy(uf);

    // Return whether the grid percolates
    return top_root == bottom_root;
}

// Print the grid
void print_grid(int grid[][GRID_WIDTH]) {
    for (int row = 0; row < GRID_HEIGHT; row++) {
        for (int col = 0; col < GRID_WIDTH; col++) {
            printf("%d ", grid[row][col]);
        }
        printf("\n");
    }
}

// Main function
int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Create the grid
    int grid[GRID_HEIGHT][GRID_WIDTH];

    // Open sites randomly
    for (int row = 0; row < GRID_HEIGHT; row++) {
        for (int col = 0; col < GRID_WIDTH; col++) {
            if ((double)rand() / RAND_MAX < OPEN_PROBABILITY) {
                open_site(grid, row, col);
            }
        }
    }

    // Print the grid
    printf("Grid:\n");
    print_grid(grid);

    // Check if the grid percolates
    int does_percolate = percolates(grid);

    // Print whether the grid percolates
    printf("Does the grid percolate? %s\n", does_percolate ? "Yes" : "No");

    return 0;
}