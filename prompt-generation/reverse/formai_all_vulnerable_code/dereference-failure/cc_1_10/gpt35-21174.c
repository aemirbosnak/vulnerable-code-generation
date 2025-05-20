//FormAI DATASET v1.0 Category: Fractal Generation ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// Function to generate C Fractal
void C_fractal(int N, int H, int W, int maxDepth, int startX, int startY, char **fractal) {

    if (maxDepth < 1) { 
        return; // Stop recursion
    }

    int midX = W/2 + startX; // Calculate the mid-point of the shape
    int endY = startY + pow(2, maxDepth-1); // Calculate the end point of the top of the shape

    // Draw the top of the shape
    for(int i = startX; i < midX; i++) {
        fractal[startY][i] = '*';
    }

    // Draw the left side of the shape
    for(int i = startY; i < endY; i++) {
        fractal[i][startX] = '*';
    }

    // Draw the right side of the shape
    for(int i = startY; i < endY; i++) {
        fractal[i][W-1] = '*';
    }

    // Draw the bottom of the shape
    for(int i = startX; i <= midX; i++) {
        fractal[endY][i] = '*';
    }

    // Generate smaller C Fractals within each quadrant
    C_fractal(N/2, H, W, maxDepth-1, startX, startY, fractal); 
    C_fractal(N/2, H, W, maxDepth-1, midX, startY, fractal);
    C_fractal(N/2, H, W, maxDepth-1, startX, endY, fractal);
    C_fractal(N/2, H, W, maxDepth-1, midX, endY, fractal);

}

int main() {

    // The size of the grid
    int N = 32;
    int H = N; // For a square
    int W = N;

    // The starting point
    int startX = 0;
    int startY = 0;

    // The maximum recursive depth
    int maxDepth = 5;

    // Allocate 2D char array to store output grid
    char **fractal = (char**) malloc(H * sizeof(char*));
    for(int i = 0; i < H; i++) {
        fractal[i] = (char*) malloc(W * sizeof(char));
        for(int j = 0; j < W; j++) {
            fractal[i][j] = ' '; // Initialize all elements to blank space
        }
    }

    // Generate the fractal
    C_fractal(N, H, W, maxDepth, startX, startY, fractal);

    // Print the fractal grid
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            printf("%c", fractal[i][j]);
        }
        printf("\n"); // Move to new line after each row
    }

    // Free allocated memory
    for(int i = 0; i < H; i++) {
        free(fractal[i]);
    }
    free(fractal);

    return 0;
}