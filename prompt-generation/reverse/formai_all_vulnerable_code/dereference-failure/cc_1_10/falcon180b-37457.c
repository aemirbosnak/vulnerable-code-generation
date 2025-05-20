//Falcon-180B DATASET v1.0 Category: Fractal Generation ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_ITER 1000
#define MAX_WIDTH 800
#define MAX_HEIGHT 600

// Function to calculate Mandelbrot fractal
void mandelbrot(int x, int y, int iter, int max_iter, int *buffer) {
    int i;
    double real = x / MAX_WIDTH * 3.0;
    double imag = y / MAX_HEIGHT * 2.0;
    double x_squared = 0.0;
    double y_squared = 0.0;
    double xy = 0.0;

    for (i = 0; i < max_iter; i++) {
        xy = x_squared - y_squared + real;
        x_squared = xy * xy;
        y_squared = x_squared + y_squared;
        if (x_squared + y_squared > 4.0) {
            break;
        }
    }

    if (i == max_iter) {
        buffer[y * MAX_WIDTH + x] = 0;
    } else {
        buffer[y * MAX_WIDTH + x] = iter;
    }
}

// Function to render fractal image
void render(int *buffer, int width, int height, FILE *file) {
    int i, j;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            fprintf(file, "%d ", buffer[i * width + j]);
        }
        fprintf(file, "\n");
    }
}

// Main function
int main(int argc, char *argv[]) {
    int width, height, max_iter;
    int *buffer;

    // Parse command line arguments
    if (argc!= 4) {
        printf("Usage: %s <width> <height> <max_iter>\n", argv[0]);
        return 1;
    }

    width = atoi(argv[1]);
    height = atoi(argv[2]);
    max_iter = atoi(argv[3]);

    // Allocate memory for buffer
    buffer = malloc(height * width * sizeof(int));

    // Generate fractal
    mandelbrot(0, 0, 0, max_iter, buffer);

    // Render fractal image
    render(buffer, width, height, stdout);

    // Free memory
    free(buffer);

    return 0;
}