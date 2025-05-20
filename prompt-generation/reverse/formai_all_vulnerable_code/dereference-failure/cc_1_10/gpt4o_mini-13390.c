//GPT-4o-mini DATASET v1.0 Category: Percolation Simulator ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define EMPTY ' '
#define BLOCKED '#'
#define OPEN '.'
#define ACTIVE 'X'

typedef struct {
    int rows;
    int cols;
    char **grid;
} PercolationSystem;

PercolationSystem* createPercolationSystem(int rows, int cols) {
    PercolationSystem *system = (PercolationSystem *)malloc(sizeof(PercolationSystem));
    system->rows = rows;
    system->cols = cols;
    system->grid = (char **)malloc(rows * sizeof(char *));
    for (int i = 0; i < rows; i++) {
        system->grid[i] = (char *)malloc(cols * sizeof(char));
        for (int j = 0; j < cols; j++) {
            system->grid[i][j] = EMPTY; // Initialize grid with EMPTY spaces
        }
    }
    return system;
}

void destroyPercolationSystem(PercolationSystem *system) {
    for (int i = 0; i < system->rows; i++) {
        free(system->grid[i]);
    }
    free(system->grid);
    free(system);
}

void populateBlockedCells(PercolationSystem *system, float blockedProbability) {
    for (int i = 0; i < system->rows; i++) {
        for (int j = 0; j < system->cols; j++) {
            if ((float)rand() / RAND_MAX < blockedProbability) {
                system->grid[i][j] = BLOCKED; // Randomly fill with BLOCKED cells
            }
        }
    }
}

void displayGrid(const PercolationSystem *system) {
    for (int i = 0; i < system->rows; i++) {
        for (int j = 0; j < system->cols; j++) {
            putchar(system->grid[i][j]);
        }
        putchar('\n');
    }
}

int isWithinBounds(int row, int col, int rows, int cols) {
    return row >= 0 && row < rows && col >= 0 && col < cols;
}

void activatePercolation(PercolationSystem *system, int row, int col) {
    if (!isWithinBounds(row, col, system->rows, system->cols) || 
        system->grid[row][col] != OPEN) {
        return;
    }
    system->grid[row][col] = ACTIVE;
    activatePercolation(system, row + 1, col); // Down
    activatePercolation(system, row - 1, col); // Up
    activatePercolation(system, row, col + 1); // Right
    activatePercolation(system, row, col - 1); // Left
}

int percolates(PercolationSystem *system) {
    for (int col = 0; col < system->cols; col++) {
        if (system->grid[0][col] == OPEN) {
            activatePercolation(system, 0, col);
        }
    }
    for (int col = 0; col < system->cols; col++) {
        if (system->grid[system->rows - 1][col] == ACTIVE) {
            return 1; // Percolation occurs
        }
    }
    return 0; // No percolation
}

void simulatePercolation(int rows, int cols, float blockedProbability) {
    srand((unsigned)time(NULL));
    PercolationSystem *system = createPercolationSystem(rows, cols);
    populateBlockedCells(system, blockedProbability);
    
    printf("Initial Percolation System:\n");
    displayGrid(system);
    
    if (percolates(system)) {
        printf("The system percolates!\n");
    } else {
        printf("The system does not percolate.\n");
    }

    destroyPercolationSystem(system);
}

int main() {
    int rows = 10;
    int cols = 10; 
    float blockedProbability = 0.4; // Adjust probability as needed

    printf("Simulating Percolation:\n");
    simulatePercolation(rows, cols, blockedProbability);
    
    return 0;
}