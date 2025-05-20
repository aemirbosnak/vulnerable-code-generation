//Falcon2-11B DATASET v1.0 Category: Pixel Art Generator ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char **argv) {
    // Set up the size of the grid
    int size = 5;
    
    // Create the grid
    int **grid = (int **)malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++) {
        grid[i] = (int *)malloc(size * sizeof(int));
        for (int j = 0; j < size; j++) {
            grid[i][j] = 0;
        }
    }
    
    // Set up the colors
    int red = rand() % 256;
    int green = rand() % 256;
    int blue = rand() % 256;
    
    // Loop through each pixel and set its color
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            grid[i][j] = (rand() % 2) + 1; // Set the pixel to white or black with equal probability
            if (grid[i][j] == 1) {
                grid[i][j] = red; // Set the pixel to red if it's white
            }
            else {
                grid[i][j] = green; // Set the pixel to green if it's black
            }
        }
    }
    
    // Print the grid
    printf("Pixel Art Generator\n\n");
    for (int i = 0; i < size; i++) {
        printf(" ");
        for (int j = 0; j < size; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    
    // Free the memory
    for (int i = 0; i < size; i++) {
        free(grid[i]);
    }
    free(grid);
    
    return 0;
}