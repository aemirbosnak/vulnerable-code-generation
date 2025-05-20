//Falcon2-11B DATASET v1.0 Category: Game of Life ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int width = 20;
    int height = 20;
    int** grid = malloc(height * sizeof(int*));
    for (int i = 0; i < height; i++) {
        grid[i] = malloc(width * sizeof(int));
    }
    
    // Initialize the grid with random values
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            grid[i][j] = rand() % 2;
        }
    }
    
    // Print the initial grid
    printf("Initial grid:\n");
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
    
    // Print the updated grid after each generation
    for (int generation = 0; generation < 5; generation++) {
        printf("Generation %d:\n", generation + 1);
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                int liveNeighbors = 0;
                
                if (i > 0) liveNeighbors += grid[i - 1][j];
                if (i < height - 1) liveNeighbors += grid[i + 1][j];
                if (j > 0) liveNeighbors += grid[i][j - 1];
                if (j < width - 1) liveNeighbors += grid[i][j + 1];
                
                if (grid[i][j] && (liveNeighbors == 2 || liveNeighbors == 3)) {
                    grid[i][j] = 1;
                } else if (!grid[i][j] && liveNeighbors == 3) {
                    grid[i][j] = 1;
                }
            }
        }
    }
    
    // Print the final grid
    printf("Final grid:\n");
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
    
    // Free the memory
    for (int i = 0; i < height; i++) {
        free(grid[i]);
    }
    free(grid);
    
    return 0;
}