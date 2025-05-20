//GEMINI-pro DATASET v1.0 Category: Percolation Simulator ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Grid dimensions
#define WIDTH 20
#define HEIGHT 20

// Probability of a site being open
#define P 0.5

// Union-find data structure
typedef struct {
    int *id;
    int *sz;
} UF;

// Create a new union-find data structure
UF *UF_new(int n) {
    UF *uf = malloc(sizeof(UF));
    uf->id = malloc(n * sizeof(int));
    uf->sz = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        uf->id[i] = i;
        uf->sz[i] = 1;
    }
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
    int pRoot = UF_find(uf, p);
    int qRoot = UF_find(uf, q);
    if (pRoot == qRoot) return;
    if (uf->sz[pRoot] < uf->sz[qRoot]) {
        uf->id[pRoot] = qRoot;
        uf->sz[qRoot] += uf->sz[pRoot];
    } else {
        uf->id[qRoot] = pRoot;
        uf->sz[pRoot] += uf->sz[qRoot];
    }
}

// Generate a random grid of open and closed sites
int **generate_grid() {
    int **grid = malloc(HEIGHT * sizeof(int *));
    for (int i = 0; i < HEIGHT; i++) {
        grid[i] = malloc(WIDTH * sizeof(int));
        for (int j = 0; j < WIDTH; j++) {
            grid[i][j] = (rand() < (RAND_MAX * P)) ? 1 : 0;
        }
    }
    return grid;
}

// Print the grid
void print_grid(int **grid) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

// Percolate the grid
int percolate(int **grid) {
    // Create a union-find data structure to track connected components
    UF *uf = UF_new(WIDTH * HEIGHT);

    // Iterate over the grid
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            // If the site is open, connect it to its neighbors
            if (grid[i][j]) {
                if (i > 0 && grid[i - 1][j]) UF_union(uf, i * WIDTH + j, (i - 1) * WIDTH + j);
                if (j > 0 && grid[i][j - 1]) UF_union(uf, i * WIDTH + j, i * WIDTH + j - 1);
                if (i < HEIGHT - 1 && grid[i + 1][j]) UF_union(uf, i * WIDTH + j, (i + 1) * WIDTH + j);
                if (j < WIDTH - 1 && grid[i][j + 1]) UF_union(uf, i * WIDTH + j, i * WIDTH + j + 1);
            }
        }
    }

    // Check if the top and bottom rows are connected
    int top = UF_find(uf, 0);
    int bottom = UF_find(uf, (HEIGHT - 1) * WIDTH + (WIDTH - 1));
    return top == bottom;
}

// Main function
int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Generate a random grid
    int **grid = generate_grid();

    // Print the grid
    printf("Grid:\n");
    print_grid(grid);

    // Percolate the grid
    int percolated = percolate(grid);

    // Print the result
    printf("\nPercolated: %d\n", percolated);

    // Free the grid
    for (int i = 0; i < HEIGHT; i++) {
        free(grid[i]);
    }
    free(grid);

    return 0;
}