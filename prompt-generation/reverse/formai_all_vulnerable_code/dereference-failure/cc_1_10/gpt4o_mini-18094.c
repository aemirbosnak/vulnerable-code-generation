//GPT-4o-mini DATASET v1.0 Category: Percolation Simulator ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define DEFAULT_SIZE 10
#define OPEN ' '
#define BLOCKED '#'

typedef struct {
    int size;
    char **grid;
    bool **visited;
} PercolationSystem;

void initializeGrid(PercolationSystem *system);
void printGrid(PercolationSystem *system);
void openSite(PercolationSystem *system, int row, int col);
bool isOpen(PercolationSystem *system, int row, int col);
int countOpenSites(PercolationSystem *system);
void depthFirstSearch(PercolationSystem *system, int row, int col);
bool percolates(PercolationSystem *system);
void cleanup(PercolationSystem *system);

int main() {
    PercolationSystem system;
    system.size = DEFAULT_SIZE;
    srand(time(NULL));
    
    initializeGrid(&system);
    printGrid(&system);
    
    // Randomly open sites in the grid
    for (int i = 0; i < system.size * 2; i++) {
        int row = rand() % system.size;
        int col = rand() % system.size;
        openSite(&system, row, col);
    }
    
    printf("\nGrid after opening random sites:\n");
    printGrid(&system);
    
    // Checking if the system percolates
    if (percolates(&system)) {
        printf("The system percolates!\n");
    } else {
        printf("The system does not percolate.\n");
    }
    
    cleanup(&system);
    return 0;
}

void initializeGrid(PercolationSystem *system) {
    system->grid = (char **)malloc(system->size * sizeof(char *));
    system->visited = (bool **)malloc(system->size * sizeof(bool *));
    
    for (int i = 0; i < system->size; i++) {
        system->grid[i] = (char *)malloc(system->size * sizeof(char));
        system->visited[i] = (bool *)malloc(system->size * sizeof(bool));
        for (int j = 0; j < system->size; j++) {
            system->grid[i][j] = BLOCKED;
            system->visited[i][j] = false;
        }
    }
}

void openSite(PercolationSystem *system, int row, int col) {
    if (row >= 0 && row < system->size && col >= 0 && col < system->size) {
        system->grid[row][col] = OPEN;
    }
}

bool isOpen(PercolationSystem *system, int row, int col) {
    return (row >= 0 && row < system->size && col >= 0 && col < system->size && system->grid[row][col] == OPEN);
}

void depthFirstSearch(PercolationSystem *system, int row, int col) {
    if (row < 0 || row >= system->size || col < 0 || col >= system->size || system->visited[row][col] || system->grid[row][col] == BLOCKED) {
        return;
    }
    
    system->visited[row][col] = true;
    
    depthFirstSearch(system, row + 1, col); // Down
    depthFirstSearch(system, row - 1, col); // Up
    depthFirstSearch(system, row, col + 1); // Right
    depthFirstSearch(system, row, col - 1); // Left
}

bool percolates(PercolationSystem *system) {
    for (int col = 0; col < system->size; col++) {
        if (isOpen(system, 0, col)) {
            depthFirstSearch(system, 0, col);
        }
    }
    
    for (int col = 0; col < system->size; col++) {
        if (system->visited[system->size - 1][col]) {
            return true;
        }
    }
    
    return false;
}

void printGrid(PercolationSystem *system) {
    for (int i = 0; i < system->size; i++) {
        for (int j = 0; j < system->size; j++) {
            printf("%c ", system->grid[i][j]);
        }
        printf("\n");
    }
}

void cleanup(PercolationSystem *system) {
    for (int i = 0; i < system->size; i++) {
        free(system->grid[i]);
        free(system->visited[i]);
    }
    free(system->grid);
    free(system->visited);
}