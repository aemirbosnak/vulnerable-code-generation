//GPT-4o-mini DATASET v1.0 Category: Percolation Simulator ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BLOCKED 0
#define OPEN 1

typedef struct {
    int width;
    int height;
    int **grid;
} PercolationSystem;

PercolationSystem* createPercolationSystem(int width, int height) {
    PercolationSystem *system = malloc(sizeof(PercolationSystem));
    system->width = width;
    system->height = height;

    system->grid = malloc(height * sizeof(int *));
    for (int i = 0; i < height; i++) {
        system->grid[i] = malloc(width * sizeof(int));
        for (int j = 0; j < width; j++) {
            system->grid[i][j] = BLOCKED; // Initialize all blocks as blocked
        }
    }
    
    return system;
}

void freePercolationSystem(PercolationSystem *system) {
    for (int i = 0; i < system->height; i++) {
        free(system->grid[i]);
    }
    free(system->grid);
    free(system);
}

void openSite(PercolationSystem *system, int x, int y) {
    if (x < 0 || x >= system->width || y < 0 || y >= system->height) {
        return; // Out of bounds
    }
    system->grid[y][x] = OPEN; // Open the site
}

int isOpen(PercolationSystem *system, int x, int y) {
    if (x < 0 || x >= system->width || y < 0 || y >= system->height) {
        return 0; // Site is out of bounds
    }
    return system->grid[y][x] == OPEN;
}

int percolates(PercolationSystem *system) {
    for (int x = 0; x < system->width; x++) {
        if (isOpen(system, x, 0) && dfs(system, x, 0)) {
            return 1; // System percolates
        }
    }
    return 0; // System does not percolate
}

int dfs(PercolationSystem *system, int x, int y) {
    if (y == system->height - 1) {
        return 1; // Reached the bottom
    }

    if (!isOpen(system, x, y)) {
        return 0; // Not an open site
    }

    // Temporarily mark the site as visited
    system->grid[y][x] = BLOCKED;

    // Check all four possible directions
    if (dfs(system, x, y + 1) || 
        dfs(system, x + 1, y) || 
        dfs(system, x - 1, y) || 
        dfs(system, x, y - 1)) {
        return 1; // Path found
    }

    return 0; // No path found
}

void generateRandomOpenSites(PercolationSystem *system, float probability) {
    for (int i = 0; i < system->height; i++) {
        for (int j = 0; j < system->width; j++) {
            if ((float) rand() / RAND_MAX < probability) {
                openSite(system, j, i);
            }
        }
    }
}

void printGrid(PercolationSystem *system) {
    for (int i = 0; i < system->height; i++) {
        for (int j = 0; j < system->width; j++) {
            if (system->grid[i][j] == OPEN) {
                printf(". ");
            } else {
                printf("# ");
            }
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL)); // Seed the random number generator
    int width = 10;
    int height = 10;
    float openProbability = 0.5;

    PercolationSystem *system = createPercolationSystem(width, height);
    
    generateRandomOpenSites(system, openProbability);
    
    printf("Percolation Grid:\n");
    printGrid(system);
    
    if (percolates(system)) {
        printf("The system percolates!\n");
    } else {
        printf("The system does not percolate.\n");
    }

    freePercolationSystem(system);
    return 0;
}