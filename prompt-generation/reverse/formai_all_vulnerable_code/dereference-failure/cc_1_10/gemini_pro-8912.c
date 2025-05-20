//GEMINI-pro DATASET v1.0 Category: Percolation Simulator ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Grid dimensions
#define WIDTH 10
#define HEIGHT 10

// Probability of a site being open
#define P 0.5

// Union-find data structure
typedef struct {
    int *id;
    int *size;
    int count;
} UnionFind;

// Create a new union-find data structure
UnionFind *UFCreate(int n) {
    UnionFind *uf = malloc(sizeof(UnionFind));
    uf->id = malloc(n * sizeof(int));
    uf->size = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        uf->id[i] = i;
        uf->size[i] = 1;
    }
    uf->count = n;
    return uf;
}

// Find the root of the tree containing p
int UFRoot(UnionFind *uf, int p) {
    while (uf->id[p] != p) {
        uf->id[p] = uf->id[uf->id[p]];
        p = uf->id[p];
    }
    return p;
}

// Merge the trees containing p and q
void UFUnion(UnionFind *uf, int p, int q) {
    int rootP = UFRoot(uf, p);
    int rootQ = UFRoot(uf, q);
    if (rootP == rootQ) {
        return;
    }
    if (uf->size[rootP] < uf->size[rootQ]) {
        uf->id[rootP] = rootQ;
        uf->size[rootQ] += uf->size[rootP];
    } else {
        uf->id[rootQ] = rootP;
        uf->size[rootP] += uf->size[rootQ];
    }
    uf->count--;
}

// Create a new grid
int **gridCreate(int width, int height) {
    int **grid = malloc(height * sizeof(int *));
    for (int i = 0; i < height; i++) {
        grid[i] = malloc(width * sizeof(int));
    }
    return grid;
}

// Open a site at (row, col)
void gridOpen(int **grid, int row, int col) {
    grid[row][col] = 1;
}

// Check if a site at (row, col) is open
int gridIsOpen(int **grid, int row, int col) {
    return grid[row][col] == 1;
}

// Check if the grid percolates
int gridPercolates(int **grid, int width, int height) {
    // Create a union-find data structure to track connected components
    UnionFind *uf = UFCreate(width * height);

    // Iterate over the grid
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            // If the site is open, connect it to its neighbors
            if (gridIsOpen(grid, i, j)) {
                // Connect to the site above
                if (i > 0 && gridIsOpen(grid, i - 1, j)) {
                    UFUnion(uf, i * width + j, (i - 1) * width + j);
                }
                // Connect to the site to the right
                if (j + 1 < width && gridIsOpen(grid, i, j + 1)) {
                    UFUnion(uf, i * width + j, i * width + j + 1);
                }
                // Connect to the site below
                if (i + 1 < height && gridIsOpen(grid, i + 1, j)) {
                    UFUnion(uf, i * width + j, (i + 1) * width + j);
                }
                // Connect to the site to the left
                if (j > 0 && gridIsOpen(grid, i, j - 1)) {
                    UFUnion(uf, i * width + j, i * width + j - 1);
                }
            }
        }
    }

    // Check if the top and bottom rows are connected
    int topRoot = UFRoot(uf, 0);
    int bottomRoot = UFRoot(uf, (height - 1) * width);
    int percolates = topRoot == bottomRoot;

    // Free the union-find data structure
    free(uf->id);
    free(uf->size);
    free(uf);

    return percolates;
}

// Print the grid
void gridPrint(int **grid, int width, int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

// Free the grid
void gridFree(int **grid, int height) {
    for (int i = 0; i < height; i++) {
        free(grid[i]);
    }
    free(grid);
}

// Main function
int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Create a new grid
    int **grid = gridCreate(WIDTH, HEIGHT);

    // Open sites randomly
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if ((double)rand() / RAND_MAX < P) {
                gridOpen(grid, i, j);
            }
        }
    }

    // Print the grid
    gridPrint(grid, WIDTH, HEIGHT);

    // Check if the grid percolates
    int percolates = gridPercolates(grid, WIDTH, HEIGHT);
    if (percolates) {
        printf("The grid percolates.\n");
    } else {
        printf("The grid does not percolate.\n");
    }

    // Free the grid
    gridFree(grid, HEIGHT);

    return 0;
}