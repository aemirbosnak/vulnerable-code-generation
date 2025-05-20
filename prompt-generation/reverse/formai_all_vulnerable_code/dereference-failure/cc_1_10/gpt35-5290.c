//FormAI DATASET v1.0 Category: Fractal Generation ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define constants for the size and position of the fractal
#define WIDTH 1000
#define HEIGHT 1000
#define X_MIN -2
#define X_MAX 1
#define Y_MIN -1
#define Y_MAX 1

// Define the maximum number of iterations and the escape radius for the fractal
#define MAX_ITERATIONS 1000
#define ESCAPE_RADIUS 2

// Define a function to create the fractal
void create_fractal(int** fractal) {
    // Iterate over every pixel in the fractal
    for (int x = 0; x < WIDTH; x++) {
        for (int y = 0; y < HEIGHT; y++) {
            // Convert the pixel coordinates to complex number coordinates
            double real = ((double)x / WIDTH) * (X_MAX - X_MIN) + X_MIN;
            double imag = ((double)y / HEIGHT) * (Y_MAX - Y_MIN) + Y_MIN;
            double cx = real;
            double cy = imag;
            double zx = 0;
            double zy = 0;
            int iteration = 0;
            
            // Iterate the complex function until it escapes or reaches the maximum number of iterations
            while (iteration < MAX_ITERATIONS && zx * zx + zy * zy < ESCAPE_RADIUS * ESCAPE_RADIUS) {
                double new_zx = zx * zx - zy * zy + cx;
                double new_zy = 2 * zx * zy + cy;
                zx = new_zx;
                zy = new_zy;
                iteration++;
            }
            
            // Determine the color of the pixel based on the number of iterations
            int color = 255 - iteration % 256;
            
            // Set the pixel in the fractal to the determined color
            fractal[x][y] = color;
        }
    }
}

int main() {
    // Allocate memory for the fractal
    int** fractal = malloc(WIDTH * sizeof(int*));
    for (int x = 0; x < WIDTH; x++) {
        fractal[x] = malloc(HEIGHT * sizeof(int));
    }
    
    // Create the fractal
    create_fractal(fractal);
    
    // Output the fractal as a PGM image
    printf("P2\n%d %d\n255\n", WIDTH, HEIGHT);
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            printf("%d ", fractal[x][y]);
        }
        printf("\n");
    }
    
    // Free the memory used by the fractal
    for (int x = 0; x < WIDTH; x++) {
        free(fractal[x]);
    }
    free(fractal);
    
    return 0;
}