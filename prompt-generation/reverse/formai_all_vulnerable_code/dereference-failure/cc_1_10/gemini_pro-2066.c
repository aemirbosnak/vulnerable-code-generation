//GEMINI-pro DATASET v1.0 Category: Percolation Simulator ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Grid dimensions
#define WIDTH 20
#define HEIGHT 20

// Probability of a site being open
#define P 0.5

// Union-find data structure
struct UF {
    int *id;
    int *sz;
    int count;
};

// Create a new union-find data structure
struct UF *UF_create(int n) {
    struct UF *uf = malloc(sizeof(struct UF));
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
int UF_find(struct UF *uf, int p) {
    while (p != uf->id[p]) {
        uf->id[p] = uf->id[uf->id[p]];
        p = uf->id[p];
    }
    return p;
}

// Merge the trees containing p and q
void UF_union(struct UF *uf, int p, int q) {
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
    uf->count--;
}

// Create a grid of sites
int **create_grid(void) {
    int **grid = malloc(HEIGHT * sizeof(int *));
    for (int i = 0; i < HEIGHT; i++) {
        grid[i] = malloc(WIDTH * sizeof(int));
    }
    return grid;
}

// Open a site
void open_site(int **grid, int x, int y) {
    grid[y][x] = 1;
}

// Check if a site is open
int is_open(int **grid, int x, int y) {
    return grid[y][x] == 1;
}

// Check if two sites are connected
int is_connected(struct UF *uf, int p, int q) {
    return UF_find(uf, p) == UF_find(uf, q);
}

// Simulate percolation
int percolate(int **grid) {
    // Create a union-find data structure
    struct UF *uf = UF_create(WIDTH * HEIGHT);

    // Iterate over the grid
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            // If the site is open
            if (is_open(grid, x, y)) {
                // Open the site
                open_site(grid, x, y);

                // Union the site with its neighbors
                if (x > 0 && is_open(grid, x - 1, y)) {
                    UF_union(uf, x + y * WIDTH, (x - 1) + y * WIDTH);
                }
                if (x < WIDTH - 1 && is_open(grid, x + 1, y)) {
                    UF_union(uf, x + y * WIDTH, (x + 1) + y * WIDTH);
                }
                if (y > 0 && is_open(grid, x, y - 1)) {
                    UF_union(uf, x + y * WIDTH, x + (y - 1) * WIDTH);
                }
                if (y < HEIGHT - 1 && is_open(grid, x, y + 1)) {
                    UF_union(uf, x + y * WIDTH, x + (y + 1) * WIDTH);
                }
            }
        }
    }

    // Check if the system percolates
    int percolates = 0;
    for (int i = 0; i < WIDTH; i++) {
        if (is_connected(uf, i, WIDTH * HEIGHT - 1)) {
            percolates = 1;
            break;
        }
    }

    // Free the union-find data structure
    free(uf->id);
    free(uf->sz);
    free(uf);

    return percolates;
}

// Print the grid
void print_grid(int **grid) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            printf("%d ", grid[y][x]);
        }
        printf("\n");
    }
}

int main(void) {
    // Initialize the random number generator
    srand(time(NULL));

    // Create a grid
    int **grid = create_grid();

    // Open sites
    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        int x = rand() % WIDTH;
        int y = rand() % HEIGHT;
        open_site(grid, x, y);
    }

    // Check if the system percolates
    int percolates = percolate(grid);

    // Print the grid
    print_grid(grid);

    // Print the result
    printf("The system %s percolate.\n", percolates ? "does" : "does not");

    // Free the grid
    for (int i = 0; i < HEIGHT; i++) {
        free(grid[i]);
    }
    free(grid);

    return 0;
}