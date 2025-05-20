//GPT-4o-mini DATASET v1.0 Category: Percolation Simulator ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

typedef struct {
    int **grid;
    int size;
} Percolation;

Percolation* create_percolation(int n) {
    Percolation *p = malloc(sizeof(Percolation));
    p->size = n;
    p->grid = malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        p->grid[i] = calloc(n, sizeof(int));
    }
    return p;
}

void free_percolation(Percolation *p) {
    for (int i = 0; i < p->size; i++) {
        free(p->grid[i]);
    }
    free(p->grid);
    free(p);
}

void open_site(Percolation *p, int row, int col) {
    if (row < 0 || row >= p->size || col < 0 || col >= p->size) {
        return; // Out of bounds
    }
    p->grid[row][col] = 1; // Mark the site as open
}

bool is_open(Percolation *p, int row, int col) {
    return p->grid[row][col] == 1;
}

bool is_full(Percolation *p, int row, int col) {
    return row >= 0 && row < p->size && col >= 0 && col < p->size && p->grid[row][col] == 2;
}

void fill_site(Percolation *p, int row, int col) {
    if (row < 0 || row >= p->size || col < 0 || col >= p->size || !is_open(p, row, col)) {
        return; // Out of bounds or site is not open
    }
    p->grid[row][col] = 2; // Mark the site as full
    fill_site(p, row + 1, col);
    fill_site(p, row - 1, col);
    fill_site(p, row, col + 1);
    fill_site(p, row, col - 1);
}

bool percolates(Percolation *p) {
    for (int col = 0; col < p->size; col++) {
        if (is_open(p, 0, col) && !is_full(p, 0, col)) {
            fill_site(p, 0, col);
        }
    }
    for (int col = 0; col < p->size; col++) {
        if (is_full(p, p->size - 1, col)) {
            return true; // Path from top to bottom found
        }
    }
    return false;
}

void print_grid(Percolation *p) {
    for (int i = 0; i < p->size; i++) {
        for (int j = 0; j < p->size; j++) {
            if (p->grid[i][j] == 0) {
                printf(". "); // Blocked site
            } else if (p->grid[i][j] == 1) {
                printf("O "); // Open site
            } else {
                printf("F "); // Full site
            }
        }
        printf("\n");
    }
}

void simulate_percolation(int size) {
    Percolation *p = create_percolation(size);
    srand(time(NULL));

    // Randomly open sites
    for (int i = 0; i < size * size / 2; i++) {
        int row = rand() % size;
        int col = rand() % size;
        open_site(p, row, col);
    }

    printf("Grid representation (O = open, F = full, . = blocked):\n");
    print_grid(p);

    if (percolates(p)) {
        printf("The system percolates!\n");
    } else {
        printf("The system does not percolate.\n");
    }

    free_percolation(p);
}

int main() {
    int grid_size;
    printf("Enter the size of the grid (e.g., 5 for a 5x5 grid): ");
    scanf("%d", &grid_size);
    simulate_percolation(grid_size);
    return 0;
}