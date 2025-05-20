//GEMINI-pro DATASET v1.0 Category: Percolation Simulator ; Style: active
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

// Grid dimensions
#define WIDTH 10
#define HEIGHT 10

// Number of open sites required for percolation
#define PERCOLATION_THRESHOLD 0.5

// Possible site states
#define CLOSED 0
#define OPEN 1

// Union-find data structure
typedef struct {
    int *id;
    int *size;
} UF;

// Initialize the union-find data structure
UF *UF_init(int n) {
    UF *uf = malloc(sizeof(UF));
    uf->id = malloc(n * sizeof(int));
    uf->size = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        uf->id[i] = i;
        uf->size[i] = 1;
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
    int root_p = UF_find(uf, p);
    int root_q = UF_find(uf, q);
    if (root_p == root_q) return;
    if (uf->size[root_p] < uf->size[root_q]) {
        uf->id[root_p] = root_q;
        uf->size[root_q] += uf->size[root_p];
    } else {
        uf->id[root_q] = root_p;
        uf->size[root_p] += uf->size[root_q];
    }
}

// Open a site at (row, col)
void open_site(int grid[HEIGHT][WIDTH], UF *uf, int row, int col) {
    // Check if the site is already open
    if (grid[row][col] == OPEN) return;

    // Open the site
    grid[row][col] = OPEN;

    // Find the roots of the trees containing the adjacent sites
    int root_top = -1;
    if (row > 0 && grid[row - 1][col] == OPEN) root_top = UF_find(uf, (row - 1) * WIDTH + col);
    int root_bottom = -1;
    if (row < HEIGHT - 1 && grid[row + 1][col] == OPEN) root_bottom = UF_find(uf, (row + 1) * WIDTH + col);
    int root_left = -1;
    if (col > 0 && grid[row][col - 1] == OPEN) root_left = UF_find(uf, row * WIDTH + col - 1);
    int root_right = -1;
    if (col < WIDTH - 1 && grid[row][col + 1] == OPEN) root_right = UF_find(uf, row * WIDTH + col + 1);

    // Merge the trees containing the adjacent sites
    if (root_top != -1) UF_union(uf, root_top, (row * WIDTH + col));
    if (root_bottom != -1) UF_union(uf, root_bottom, (row * WIDTH + col));
    if (root_left != -1) UF_union(uf, root_left, (row * WIDTH + col));
    if (root_right != -1) UF_union(uf, root_right, (row * WIDTH + col));
}

// Check if the system percolates
int percolates(UF *uf) {
    // Find the roots of the trees containing the top and bottom rows
    int root_top = UF_find(uf, 0);
    int root_bottom = UF_find(uf, (HEIGHT - 1) * WIDTH);

    // Check if the roots are the same
    return root_top == root_bottom;
}

// Print the grid
void print_grid(int grid[HEIGHT][WIDTH]) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

// Main function
int main() {
    // Initialize the random number generator
    srand(time(NULL));

    // Create the grid
    int grid[HEIGHT][WIDTH];
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            grid[i][j] = CLOSED;
        }
    }

    // Create the union-find data structure
    UF *uf = UF_init(HEIGHT * WIDTH);

    // Open sites until the system percolates
    int num_open_sites = 0;
    while (!percolates(uf)) {
        // Choose a random site to open
        int row = rand() % HEIGHT;
        int col = rand() % WIDTH;

        // Open the site
        open_site(grid, uf, row, col);

        // Increment the number of open sites
        num_open_sites++;
    }

    // Print the grid
    print_grid(grid);

    // Print the number of open sites
    printf("Number of open sites: %d\n", num_open_sites);

    // Free the union-find data structure
    free(uf->id);
    free(uf->size);
    free(uf);

    return 0;
}