//GEMINI-pro DATASET v1.0 Category: Percolation Simulator ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Grid size
#define WIDTH 20
#define HEIGHT 20

// Probability of a cell being open
#define P 0.5

// Union-find data structure
typedef struct {
    int *parent;
    int *rank;
    int count;
} UF;

// Create a new union-find data structure
UF *UF_init(int n) {
    UF *uf = malloc(sizeof(UF));
    uf->parent = malloc(n * sizeof(int));
    uf->rank = malloc(n * sizeof(int));
    uf->count = n;
    for (int i = 0; i < n; i++) {
        uf->parent[i] = i;
        uf->rank[i] = 0;
    }
    return uf;
}

// Find the root of a node
int UF_find(UF *uf, int p) {
    if (uf->parent[p] != p) {
        uf->parent[p] = UF_find(uf, uf->parent[p]);
    }
    return uf->parent[p];
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

// Create a new grid
int **grid_init() {
    int **grid = malloc(HEIGHT * sizeof(int *));
    for (int i = 0; i < HEIGHT; i++) {
        grid[i] = malloc(WIDTH * sizeof(int));
    }
    return grid;
}

// Free the grid
void grid_free(int **grid) {
    for (int i = 0; i < HEIGHT; i++) {
        free(grid[i]);
    }
    free(grid);
}

// Open a cell
void grid_open(int **grid, int x, int y) {
    grid[y][x] = 1;
}

// Check if a cell is open
int grid_is_open(int **grid, int x, int y) {
    return grid[y][x] == 1;
}

// Check if a cell is on the top row
int grid_is_on_top_row(int y) {
    return y == 0;
}

// Check if a cell is on the bottom row
int grid_is_on_bottom_row(int y) {
    return y == HEIGHT - 1;
}

// Check if a cell is on the leftmost column
int grid_is_on_leftmost_column(int x) {
    return x == 0;
}

// Check if a cell is on the rightmost column
int grid_is_on_rightmost_column(int x) {
    return x == WIDTH - 1;
}

// Get the number of open cells in a row
int grid_count_open_cells_in_row(int **grid, int y) {
    int count = 0;
    for (int x = 0; x < WIDTH; x++) {
        if (grid_is_open(grid, x, y)) {
            count++;
        }
    }
    return count;
}

// Get the number of open cells in a column
int grid_count_open_cells_in_column(int **grid, int x) {
    int count = 0;
    for (int y = 0; y < HEIGHT; y++) {
        if (grid_is_open(grid, x, y)) {
            count++;
        }
    }
    return count;
}

// Get the number of open cells in the grid
int grid_count_open_cells(int **grid) {
    int count = 0;
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            if (grid_is_open(grid, x, y)) {
                count++;
            }
        }
    }
    return count;
}

// Print the grid
void grid_print(int **grid) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            printf("%d ", grid[y][x]);
        }
        printf("\n");
    }
}

// Main function
int main() {
    // Initialize the random number generator
    srand(time(NULL));

    // Create a new grid
    int **grid = grid_init();

    // Create a new union-find data structure
    UF *uf = UF_init(WIDTH * HEIGHT);

    // Open the cells in the grid
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            if ((double)rand() / RAND_MAX <= P) {
                grid_open(grid, x, y);
                if (grid_is_on_top_row(y)) {
                    UF_union(uf, x + y * WIDTH, WIDTH * HEIGHT);
                }
                if (grid_is_on_leftmost_column(x) && grid_is_open(grid, x + 1, y)) {
                    UF_union(uf, x + y * WIDTH, (x + 1) + y * WIDTH);
                }
                if (grid_is_on_rightmost_column(x) && grid_is_open(grid, x - 1, y)) {
                    UF_union(uf, x + y * WIDTH, (x - 1) + y * WIDTH);
                }
                if (grid_is_open(grid, x, y + 1)) {
                    UF_union(uf, x + y * WIDTH, x + (y + 1) * WIDTH);
                }
            }
        }
    }

    // Print the grid
    grid_print(grid);

    // Check if the grid percolates
    int percolates = UF_find(uf, 0) == UF_find(uf, WIDTH * HEIGHT - 1);

    // Print the percolation status
    printf("Percolates: %d\n", percolates);

    // Free the grid
    grid_free(grid);

    // Free the union-find data structure
    free(uf->parent);
    free(uf->rank);
    free(uf);

    return 0;
}