//GPT-4o-mini DATASET v1.0 Category: Percolation Simulator ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TRUE 1
#define FALSE 0

typedef struct {
    int **grid;
    int size;
} PercolationSystem;

PercolationSystem* create_percolation_system(int size) {
    PercolationSystem *system = (PercolationSystem*) malloc(sizeof(PercolationSystem));
    system->size = size;
    system->grid = (int**) malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++) {
        system->grid[i] = (int*) malloc(size * sizeof(int));
        for (int j = 0; j < size; j++) {
            system->grid[i][j] = FALSE; // Initially no sites are open
        }
    }
    return system;
}

void free_percolation_system(PercolationSystem *system) {
    for (int i = 0; i < system->size; i++) {
        free(system->grid[i]);
    }
    free(system->grid);
    free(system);
}

void open_site(PercolationSystem *system, int x, int y) {
    if (x >= 0 && x < system->size && y >= 0 && y < system->size) {
        system->grid[x][y] = TRUE; // Open the site
    }
}

int is_open(PercolationSystem *system, int x, int y) {
    if (x >= 0 && x < system->size && y >= 0 && y < system->size) {
        return system->grid[x][y];
    }
    return FALSE;
}

int percolates(PercolationSystem *system) {
    for (int col = 0; col < system->size; col++) {
        if (is_open(system, 0, col)) {
            int *visited = (int*) calloc(system->size * system->size, sizeof(int));
            int isPercolating = check_percolation(system, 0, col, visited);
            free(visited);
            if (isPercolating) {
                return TRUE;
            }
        }
    }
    return FALSE;
}

int check_percolation(PercolationSystem *system, int x, int y, int *visited) {
    if (x < 0 || x >= system->size || y < 0 || y >= system->size || !is_open(system, x, y) || visited[x * system->size + y]) {
        return FALSE;
    }

    visited[x * system->size + y] = TRUE; // Mark this site as visited

    if (x == system->size - 1) {
        return TRUE; // Reached the bottom
    }

    // Check all four possible directions
    return check_percolation(system, x + 1, y, visited) ||
           check_percolation(system, x - 1, y, visited) ||
           check_percolation(system, x, y + 1, visited) ||
           check_percolation(system, x, y - 1, visited);
}

void print_grid(PercolationSystem *system) {
    for (int i = 0; i < system->size; i++) {
        for (int j = 0; j < system->size; j++) {
            printf("%c ", system->grid[i][j] ? 'O' : 'X');
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    int size = 10; // Define the size of the grid
    PercolationSystem *system = create_percolation_system(size);

    // Randomly open sites
    for (int i = 0; i < size * size / 2; i++) {
        int x = rand() % size;
        int y = rand() % size;
        open_site(system, x, y);
    }

    printf("Grid State:\n");
    print_grid(system);

    if (percolates(system)) {
        printf("The system percolates.\n");
    } else {
        printf("The system does not percolate.\n");
    }

    free_percolation_system(system);
    return 0;
}