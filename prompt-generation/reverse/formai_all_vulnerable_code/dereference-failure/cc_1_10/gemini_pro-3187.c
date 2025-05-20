//GEMINI-pro DATASET v1.0 Category: Percolation Simulator ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Grid dimensions
#define GRID_WIDTH 20
#define GRID_HEIGHT 20

// Probability of a site being open
#define P_OPEN 0.5

// Union-find data structure
typedef struct {
    int *parent;
    int *rank;
    int count;
} UF;

// Create a new union-find data structure
UF *UF_create(int n) {
    UF *uf = malloc(sizeof(UF));
    uf->parent = malloc(sizeof(int) * n);
    uf->rank = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        uf->parent[i] = i;
        uf->rank[i] = 0;
    }
    uf->count = n;
    return uf;
}

// Destroy a union-find data structure
void UF_destroy(UF *uf) {
    free(uf->parent);
    free(uf->rank);
    free(uf);
}

// Find the root of a node
int UF_find(UF *uf, int p) {
    while (p != uf->parent[p]) {
        uf->parent[p] = uf->parent[uf->parent[p]];
        p = uf->parent[p];
    }
    return p;
}

// Union two nodes
void UF_union(UF *uf, int p, int q) {
    int rootP = UF_find(uf, p);
    int rootQ = UF_find(uf, q);
    if (rootP == rootQ) return;

    if (uf->rank[rootP] < uf->rank[rootQ]) {
        uf->parent[rootP] = rootQ;
    } else if (uf->rank[rootP] > uf->rank[rootQ]) {
        uf->parent[rootQ] = rootP;
    } else {
        uf->parent[rootQ] = rootP;
        uf->rank[rootP]++;
    }
    uf->count--;
}

// Generate a random grid of open and closed sites
int **generate_grid(int width, int height) {
    int **grid = malloc(sizeof(int *) * height);
    for (int i = 0; i < height; i++) {
        grid[i] = malloc(sizeof(int) * width);
        for (int j = 0; j < width; j++) {
            grid[i][j] = (rand() < RAND_MAX * P_OPEN) ? 1 : 0;
        }
    }
    return grid;
}

// Print the grid
void print_grid(int **grid, int width, int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

// Check if the grid percolates
int check_percolation(int **grid, int width, int height) {
    // Create a union-find data structure
    UF *uf = UF_create(width * height);

    // Iterate over the grid
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            // If the site is open
            if (grid[i][j]) {
                // Union the site with its neighbors
                if (i > 0 && grid[i - 1][j]) UF_union(uf, i * width + j, (i - 1) * width + j);
                if (i < height - 1 && grid[i + 1][j]) UF_union(uf, i * width + j, (i + 1) * width + j);
                if (j > 0 && grid[i][j - 1]) UF_union(uf, i * width + j, i * width + (j - 1));
                if (j < width - 1 && grid[i][j + 1]) UF_union(uf, i * width + j, i * width + (j + 1));
            }
        }
    }

    // Check if the top and bottom of the grid are connected
    int top_root = UF_find(uf, 0);
    int bottom_root = UF_find(uf, (height - 1) * width + (width - 1));

    // Destroy the union-find data structure
    UF_destroy(uf);

    // Return whether the grid percolates
    return top_root == bottom_root;
}

// Main function
int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Generate a grid
    int **grid = generate_grid(GRID_WIDTH, GRID_HEIGHT);

    // Print the grid
    print_grid(grid, GRID_WIDTH, GRID_HEIGHT);

    // Check if the grid percolates
    int percolates = check_percolation(grid, GRID_WIDTH, GRID_HEIGHT);

    // Print the result
    printf("Grid percolates: %s\n", percolates ? "yes" : "no");

    // Free the grid
    for (int i = 0; i < GRID_HEIGHT; i++) {
        free(grid[i]);
    }
    free(grid);

    return 0;
}