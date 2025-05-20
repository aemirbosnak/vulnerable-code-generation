//GPT-4o-mini DATASET v1.0 Category: Percolation Simulator ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define BLOCKED 0
#define OPEN 1

typedef struct {
    int size;
    int **grid;
    bool **visited;
} Percolation;

Percolation* createPercolation(int size) {
    Percolation *percolation = (Percolation *)malloc(sizeof(Percolation));
    percolation->size = size;
    percolation->grid = (int **)malloc(size * sizeof(int *));
    percolation->visited = (bool **)malloc(size * sizeof(bool *));
    
    for (int i = 0; i < size; i++) {
        percolation->grid[i] = (int *)malloc(size * sizeof(int));
        percolation->visited[i] = (bool *)malloc(size * sizeof(bool));
        for (int j = 0; j < size; j++) {
            percolation->grid[i][j] = (rand() % 2); // Randomly assign OPEN or BLOCKED
            percolation->visited[i][j] = false;
        }
    }
    return percolation;
}

void freePercolation(Percolation *percolation) {
    for (int i = 0; i < percolation->size; i++) {
        free(percolation->grid[i]);
        free(percolation->visited[i]);
    }
    free(percolation->grid);
    free(percolation->visited);
    free(percolation);
}

bool isSafe(int x, int y, int size, bool **visited, int **grid) {
    return (x >= 0 && x < size && y >= 0 && y < size && !visited[x][y] && grid[x][y] == OPEN);
}

void dfs(Percolation *percolation, int x, int y) {
    if (x == percolation->size - 1) {
        return; // Reached the bottom row
    }
    percolation->visited[x][y] = true;
    
    int directions[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}}; // Down, Right, Up, Left
    for (int i = 0; i < 4; i++) {
        int newX = x + directions[i][0];
        int newY = y + directions[i][1];
        if (isSafe(newX, newY, percolation->size, percolation->visited, percolation->grid)) {
            dfs(percolation, newX, newY);
        }
    }
}

bool doesPercolate(Percolation *percolation) {
    for (int j = 0; j < percolation->size; j++) {
        if (percolation->grid[0][j] == OPEN && !percolation->visited[0][j]) {
            dfs(percolation, 0, j);
        }
    }
    // Check if any cell in the last row is visited
    for (int j = 0; j < percolation->size; j++) {
        if (percolation->visited[percolation->size - 1][j]) {
            return true;
        }
    }
    return false;
}

void printGrid(Percolation *percolation) {
    for (int i = 0; i < percolation->size; i++) {
        for (int j = 0; j < percolation->size; j++) {
            printf("%d ", percolation->grid[i][j]);
        }
        printf("\n");
    }
}

void resetVisited(Percolation *percolation) {
    for (int i = 0; i < percolation->size; i++) {
        for (int j = 0; j < percolation->size; j++) {
            percolation->visited[i][j] = false;
        }
    }
}

int main() {
    srand(time(NULL));
    int gridSize = 10; // size of the grid
    Percolation *percolation = createPercolation(gridSize);
    
    printf("Initial Grid:\n");
    printGrid(percolation);
    
    if (doesPercolate(percolation)) {
        printf("The system percolates!\n");
    } else {
        printf("The system does not percolate.\n");
    }
    
    resetVisited(percolation);
    
    freePercolation(percolation);
    return 0;
}