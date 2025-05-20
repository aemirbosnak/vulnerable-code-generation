//GPT-4o-mini DATASET v1.0 Category: Percolation Simulator ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define OPEN 1
#define BLOCKED 0

typedef struct {
    int** grid;
    int size;
} Percolation;

Percolation* createPercolation(int n) {
    Percolation* perc = malloc(sizeof(Percolation));
    perc->size = n;
    perc->grid = malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        perc->grid[i] = malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            perc->grid[i][j] = BLOCKED; // Initialize all sites as blocked
        }
    }
    return perc;
}

void freePercolation(Percolation* perc) {
    for (int i = 0; i < perc->size; i++) {
        free(perc->grid[i]);
    }
    free(perc->grid);
    free(perc);
}

void openSite(Percolation* perc, int row, int col) {
    if (row >= 0 && row < perc->size && col >= 0 && col < perc->size) {
        perc->grid[row][col] = OPEN; // Open the site
    }
}

int isOpen(Percolation* perc, int row, int col) {
    if (row >= 0 && row < perc->size && col >= 0 && col < perc->size) {
        return perc->grid[row][col] == OPEN;
    }
    return 0;
}

int dfs(Percolation* perc, int row, int col, int* visited) {
    if (row == perc->size - 1) { // Reached bottom
        return 1;
    }
    
    int index = row * perc->size + col;
    if (visited[index]) return 0; // Already visited
    visited[index] = 1; // Mark as visited

    // Explore all possible directions
    if (isOpen(perc, row + 1, col) && dfs(perc, row + 1, col, visited)) return 1; // Down
    if (isOpen(perc, row - 1, col) && dfs(perc, row - 1, col, visited)) return 1; // Up
    if (isOpen(perc, row, col + 1) && dfs(perc, row, col + 1, visited)) return 1; // Right
    if (isOpen(perc, row, col - 1) && dfs(perc, row, col - 1, visited)) return 1; // Left
    
    return 0;
}

int percolates(Percolation* perc) {
    int* visited = (int*)calloc(perc->size * perc->size, sizeof(int));
    for (int col = 0; col < perc->size; col++) {
        if (isOpen(perc, 0, col)) { // Start from the top row
            if (dfs(perc, 0, col, visited)) {
                free(visited);
                return 1; // Found a path to the bottom
            }
        }
    }
    free(visited);
    return 0; // No path found
}

void printPercolation(Percolation* perc) {
    for (int i = 0; i < perc->size; i++) {
        for (int j = 0; j < perc->size; j++) {
            printf("%d ", perc->grid[i][j]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL)); // Seed random number generator
    int n;
    
    printf("Enter the size of the grid (n x n): ");
    scanf("%d", &n);
    
    Percolation* perc = createPercolation(n);
    
    int numOfSites = (n * n) / 2; // Open approximately half
    for (int i = 0; i < numOfSites; i++) {
        int row = rand() % n;
        int col = rand() % n;
        openSite(perc, row, col);
    }
    
    printf("Percolation Grid:\n");
    printPercolation(perc);
    
    if (percolates(perc)) {
        printf("The system does percolate!\n");
    } else {
        printf("The system does not percolate.\n");
    }
    
    freePercolation(perc);
    return 0;
}