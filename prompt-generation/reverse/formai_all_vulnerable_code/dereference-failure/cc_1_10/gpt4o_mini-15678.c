//GPT-4o-mini DATASET v1.0 Category: Percolation Simulator ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define OPEN 1
#define BLOCKED 0

typedef struct {
    int **grid;
    int size;
} PercolationSystem;

// Function to create a percolation system with a given size
PercolationSystem* create_percolation(int size) {
    PercolationSystem *system = (PercolationSystem*)malloc(sizeof(PercolationSystem));
    system->size = size;
    system->grid = (int**)malloc(size * sizeof(int*));
    
    for (int i = 0; i < size; i++) {
        system->grid[i] = (int*)malloc(size * sizeof(int));
        for (int j = 0; j < size; j++) {
            system->grid[i][j] = BLOCKED;
        }
    }
    return system;
}

// Function to free the allocated memory for the percolation system
void destroy_percolation(PercolationSystem *system) {
    for (int i = 0; i < system->size; i++) {
        free(system->grid[i]);
    }
    free(system->grid);
    free(system);
}

// Function to randomly open a site in the grid
void open_site(PercolationSystem *system, int x, int y) {
    if (x >= 0 && x < system->size && y >= 0 && y < system->size) {
        system->grid[x][y] = OPEN;
    }
}

// Function to check if a site is open
int is_open(PercolationSystem *system, int x, int y) {
    if (x >= 0 && x < system->size && y >= 0 && y < system->size) {
        return system->grid[x][y] == OPEN;
    }
    return 0;
}

// Function to print the grid status
void print_grid(PercolationSystem *system) {
    for (int i = 0; i < system->size; i++) {
        for (int j = 0; j < system->size; j++) {
            if (system->grid[i][j] == OPEN) {
                printf("1 ");
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

// DFS function to check if there is a path from top to bottom
int dfs(PercolationSystem *system, int x, int y, int *visited) {
    if (x == system->size - 1) return 1; // Reached the bottom row
    if (x < 0 || x >= system->size || y < 0 || y >= system->size) return 0;
    if (!is_open(system, x, y) || visited[x * system->size + y]) return 0;

    visited[x * system->size + y] = 1; // Mark as visited

    // Move in all directions
    if (dfs(system, x + 1, y, visited)) return 1; // Down
    if (dfs(system, x - 1, y, visited)) return 1; // Up
    if (dfs(system, x, y + 1, visited)) return 1; // Right
    if (dfs(system, x, y - 1, visited)) return 1; // Left

    return 0;
}

// Function to check if the system percolates
int percolates(PercolationSystem *system) {
    int *visited = (int*)calloc(system->size * system->size, sizeof(int));
    int can_percolate = 0;

    for (int j = 0; j < system->size; j++) {
        if (is_open(system, 0, j)) {
            if (dfs(system, 0, j, visited)) {
                can_percolate = 1;
                break;
            }
        }
    }

    free(visited);
    return can_percolate;
}

// Main function to run the simulation
int main() {
    srand(time(NULL)); // Seed for random number generation
    int size = 10; // Size of the percolation grid
    PercolationSystem *system = create_percolation(size);

    // Randomly open sites
    for (int i = 0; i < size * size * 0.5; i++) { // Open about 50% of sites
        int x = rand() % size;
        int y = rand() % size;
        open_site(system, x, y);
    }

    printf("Percolation Grid:\n");
    print_grid(system);

    if (percolates(system)) {
        printf("The system percolates!\n");
    } else {
        printf("The system does not percolate.\n");
    }

    destroy_percolation(system);
    return 0;
}