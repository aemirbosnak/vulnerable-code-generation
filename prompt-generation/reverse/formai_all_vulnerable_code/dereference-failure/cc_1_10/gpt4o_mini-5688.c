//GPT-4o-mini DATASET v1.0 Category: Percolation Simulator ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define SIZE 20 // Define the grid size
#define PROBABILITY 0.4 // Probability to open a site

// Function to generate a random number in the range [0, 1)
double randInRange() {
    return (double)rand() / RAND_MAX;
}

// Define the grid
typedef struct {
    bool **grid;
    bool **full;
    int size;
} Percolation;

Percolation* createPercolation(int size) {
    Percolation *p = malloc(sizeof(Percolation));
    p->size = size;
    p->grid = malloc(size * sizeof(bool*));
    p->full = malloc(size * sizeof(bool*));

    for (int i = 0; i < size; i++) {
        p->grid[i] = malloc(size * sizeof(bool));
        p->full[i] = malloc(size * sizeof(bool));
        for (int j = 0; j < size; j++) {
            p->grid[i][j] = false; // All sites are blocked initially
            p->full[i][j] = false; // No sites are full initially
        }
    }
    return p;
}

// Function to open a site
void openSite(Percolation *p, int row, int col) {
    if (row < 0 || row >= p->size || col < 0 || col >= p->size) {
        return; // Out of bounds
    }
    p->grid[row][col] = true; // Open the site
}

// Function to check if there is a path from top to bottom
bool isConnected(Percolation *p, int row, int col) {
    if (row < 0 || row >= p->size || col < 0 || col >= p->size) {
        return false; // Out of bounds
    }
    if (!p->grid[row][col] || p->full[row][col]) {
        return false; // Site is blocked or already full
    }
    if (row == p->size - 1) {
        return true; // Reached the bottom row
    }
    p->full[row][col] = true; // Mark as full

    // Explore 4 directions
    return isConnected(p, row - 1, col) || isConnected(p, row + 1, col) || 
           isConnected(p, row, col - 1) || isConnected(p, row, col + 1);
}

// Function to percolate the system
bool percolates(Percolation *p) {
    for (int col = 0; col < p->size; col++) {
        if (p->grid[0][col]) { // Only check if the site is open
            if (isConnected(p, 0, col)) {
                return true; // A connection has been found
            }
        }
    }
    return false; // No connection was found
}

// Cleanup function
void freePercolation(Percolation *p) {
    for (int i = 0; i < p->size; i++) {
        free(p->grid[i]);
        free(p->full[i]);
    }
    free(p->grid);
    free(p->full);
    free(p);
}

// Main program function
int main() {
    srand(time(NULL)); // Seed for random
    Percolation *p = createPercolation(SIZE);
    
    // Open sites based on probability
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (randInRange() < PROBABILITY) {
                openSite(p, i, j);
            }
        }
    }

    // Display grid
    printf("Percolation grid:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf(p->grid[i][j] ? " O " : " X ");
        }
        printf("\n");
    }

    // Check if system percolates
    if (percolates(p)) {
        printf("The system percolates!\n");
    } else {
        printf("The system does not percolate.\n");
    }

    // Cleanup
    freePercolation(p);
    return 0;
}