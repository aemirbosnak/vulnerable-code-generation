//Falcon2-11B DATASET v1.0 Category: Percolation Simulator ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structure to represent a square in the grid
typedef struct {
    int x;
    int y;
    int waterLevel;
} Square;

// Function to initialize the grid with random water levels for each square
void initializeGrid(int gridSize, Square** grid) {
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridSize; j++) {
            int randWaterLevel = rand() % 2 + 1;
            grid[i][j].waterLevel = randWaterLevel;
            grid[i][j].x = i;
            grid[i][j].y = j;
        }
    }
}

// Function to simulate the percolation process for each square
void simulatePercolation(Square** grid, int gridSize, int iterations) {
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridSize; j++) {
            int neighbors = 0;
            
            // Count the number of neighboring squares with water
            for (int dx = -1; dx <= 1; dx++) {
                for (int dy = -1; dy <= 1; dy++) {
                    int nx = i + dx;
                    int ny = j + dy;
                    
                    if (nx >= 0 && nx < gridSize && ny >= 0 && ny < gridSize) {
                        if (grid[nx][ny].waterLevel == 1) {
                            neighbors++;
                        }
                    }
                }
            }
            
            // Update the water level of the current square based on the number of neighbors
            if (neighbors == 2 || neighbors == gridSize * gridSize - 1) {
                grid[i][j].waterLevel = 1;
            } else if (neighbors == 0) {
                grid[i][j].waterLevel = 0;
            }
        }
    }
}

// Function to print the final state of the grid
void printGrid(Square** grid, int gridSize) {
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridSize; j++) {
            if (grid[i][j].waterLevel == 1) {
                printf("W");
            } else {
                printf(".");
            }
        }
        printf("\n");
    }
}

// Main function
int main() {
    int gridSize = 10;
    Square** grid = malloc(gridSize * sizeof(Square*));
    srand(time(NULL));
    
    // Initialize the grid
    initializeGrid(gridSize, grid);
    
    // Simulate the percolation process for 100 iterations
    for (int i = 0; i < 100; i++) {
        simulatePercolation(grid, gridSize, 1);
    }
    
    // Print the final state of the grid
    printf("Final State:\n");
    printGrid(grid, gridSize);
    
    // Free the allocated memory
    free(grid);
    
    return 0;
}