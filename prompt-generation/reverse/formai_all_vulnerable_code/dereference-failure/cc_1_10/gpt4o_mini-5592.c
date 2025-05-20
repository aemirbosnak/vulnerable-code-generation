//GPT-4o-mini DATASET v1.0 Category: Percolation Simulator ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define SIZE 10 // Size of the grid
#define OPEN 1  // Represents an open site
#define BLOCKED 0 // Represents a blocked site

// Function to allocate a 2D array
int** allocate2DArray(int size) {
    int** array = (int**)malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++) {
        array[i] = (int*)malloc(size * sizeof(int));
    }
    return array;
}

// Function to free the allocated 2D array
void free2DArray(int** array, int size) {
    for (int i = 0; i < size; i++) {
        free(array[i]);
    }
    free(array);
}

// Function to initialize the grid randomly
void initializeGrid(int** grid, int size, double probability) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            grid[i][j] = ((double)rand() / RAND_MAX) < probability ? OPEN : BLOCKED;
        }
    }
}

// Print the grid for visualization
void printGrid(int** grid, int size) {
    printf("Percolation Grid:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

// Function to check if a site is within grid boundaries
bool isValid(int x, int y, int size) {
    return (x >= 0 && x < size && y >= 0 && y < size);
}

// Depth-First Search for Percolation
bool dfs(int** grid, int x, int y, bool** visited, int size) {
    if (!isValid(x, y, size) || visited[x][y] || grid[x][y] == BLOCKED) {
        return false;
    }

    visited[x][y] = true; // Mark this cell as visited

    // If we reach the last row, we found a path
    if (x == size - 1) {
        return true;
    }

    // Explore neighboring cells: up, down, left, right
    return dfs(grid, x + 1, y, visited, size) ||
           dfs(grid, x - 1, y, visited, size) ||
           dfs(grid, x, y + 1, visited, size) ||
           dfs(grid, x, y - 1, visited, size);
}

// Function to check if the system percolates
bool percolates(int** grid, int size) {
    bool** visited = (bool**)malloc(size * sizeof(bool*));
    for (int i = 0; i < size; i++) {
        visited[i] = (bool*)malloc(size * sizeof(bool));
        for (int j = 0; j < size; j++) {
            visited[i][j] = false;
        }
    }

    // Start DFS from each open cell in the first row
    for (int j = 0; j < size; j++) {
        if (grid[0][j] == OPEN) {
            if (dfs(grid, 0, j, visited, size)) {
                free2DArray(visited, size);
                return true; // Found a path from top to bottom
            }
        }
    }

    free2DArray(visited, size);
    return false; // No path was found
}

// Main function to run the Percolation Simulator
int main() {
    srand(time(NULL));
    int** grid = allocate2DArray(SIZE);
    double probability;

    printf("Enter the probability of an open site (0.0 to 1.0): ");
    scanf("%lf", &probability);

    // Initialize and print the grid
    initializeGrid(grid, SIZE, probability);
    printGrid(grid, SIZE);

    // Check if the system percolates
    if (percolates(grid, SIZE)) {
        printf("The system percolates!\n");
    } else {
        printf("The system does not percolate.\n");
    }

    // Free the allocated memory
    free2DArray(grid, SIZE);
    return 0;
}