//GPT-4o-mini DATASET v1.0 Category: Percolation Simulator ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define OPEN 1
#define BLOCKED 0
#define TRUE 1
#define FALSE 0

typedef struct {
    int **grid;
    int size;
} PercolationGrid;

PercolationGrid* create_grid(int n);
void free_grid(PercolationGrid* pg);
void initialize_grid(PercolationGrid* pg);
void print_grid(PercolationGrid* pg);
void open_site(PercolationGrid* pg, int row, int col);
int is_open(PercolationGrid* pg, int row, int col);
int percolates(PercolationGrid* pg);
int dfs(PercolationGrid* pg, int row, int col, int visited[][pg->size]);

int main() {
    srand(time(NULL));
    int size = 10; // Size of the grid
    PercolationGrid* pg = create_grid(size);
    if (pg == NULL) {
        fprintf(stderr, "Failed to create percolation grid.\n");
        return EXIT_FAILURE;
    }

    initialize_grid(pg);
    print_grid(pg);

    // Randomly open sites
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (rand() % 2 == 0) {
                open_site(pg, i, j);
            }
        }
    }

    printf("\nAfter opening random sites:\n");
    print_grid(pg);

    if (percolates(pg)) {
        printf("\nThe system percolates!\n");
    } else {
        printf("\nThe system does not percolate.\n");
    }

    free_grid(pg);
    return EXIT_SUCCESS;
}

PercolationGrid* create_grid(int n) {
    PercolationGrid* pg = (PercolationGrid*)malloc(sizeof(PercolationGrid));
    if (pg == NULL) return NULL;

    pg->size = n;
    pg->grid = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        pg->grid[i] = (int*)malloc(n * sizeof(int));
    }
    return pg;
}

void free_grid(PercolationGrid* pg) {
    for (int i = 0; i < pg->size; i++) {
        free(pg->grid[i]);
    }
    free(pg->grid);
    free(pg);
}

void initialize_grid(PercolationGrid* pg) {
    for (int i = 0; i < pg->size; i++) {
        for (int j = 0; j < pg->size; j++) {
            pg->grid[i][j] = BLOCKED; // Set all sites as blocked initially
        }
    }
}

void print_grid(PercolationGrid* pg) {
    for (int i = 0; i < pg->size; i++) {
        for (int j = 0; j < pg->size; j++) {
            if (pg->grid[i][j] == OPEN) {
                printf("O ");
            } else {
                printf("X ");
            }
        }
        printf("\n");
    }
}

void open_site(PercolationGrid* pg, int row, int col) {
    if (row >= 0 && row < pg->size && col >= 0 && col < pg->size) {
        pg->grid[row][col] = OPEN; // Open the site
    }
}

int is_open(PercolationGrid* pg, int row, int col) {
    return (row >= 0 && row < pg->size && col >= 0 && col < pg->size) && (pg->grid[row][col] == OPEN);
}

int percolates(PercolationGrid* pg) {
    int visited[pg->size][pg->size];
    for (int i = 0; i < pg->size; i++) {
        for (int j = 0; j < pg->size; j++) {
            visited[i][j] = FALSE; // Initialize visit tracking
        }
    }

    for (int j = 0; j < pg->size; j++) {
        if (is_open(pg, 0, j)) {
            if (dfs(pg, 0, j, visited)) {
                return TRUE; // Found an open path to the bottom
            }
        }
    }
    return FALSE;
}

int dfs(PercolationGrid* pg, int row, int col, int visited[][pg->size]) {
    if (row == pg->size - 1) return TRUE; // Reached the last row
    if (!is_open(pg, row, col) || visited[row][col]) return FALSE;

    visited[row][col] = TRUE; // Mark as visited

    // Move in all four directions
    if (dfs(pg, row + 1, col, visited) ||
        dfs(pg, row - 1, col, visited) ||
        dfs(pg, row, col + 1, visited) ||
        dfs(pg, row, col - 1, visited)) {
        return TRUE;
    }
    
    return FALSE;
}