//Falcon2-11B DATASET v1.0 Category: Fractal Generation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to calculate the Mandelbrot set for a given complex number
int mandelbrot(double cx, double cy) {
    double x = 0, y = 0;
    int max_iterations = 1000;
    int iteration = 0;
    
    while (x * x + y * y <= 4 && iteration < max_iterations) {
        double temp_x = 2 * x * x - y * y + cx;
        double temp_y = 2 * x * y + y;
        x = temp_x;
        y = temp_y;
        iteration++;
    }
    
    if (iteration == max_iterations) {
        return 1;
    } else {
        return 0;
    }
}

// Function to generate the Mandelbrot set for a given range of complex numbers
void generate_mandelbrot_set(double cx_min, double cy_min, double cx_max, double cy_max) {
    int width = cx_max - cx_min;
    int height = cy_max - cy_min;
    int max_iterations = 1000;
    int num_points = width * height;
    int *mandelbrot_set = malloc(num_points * sizeof(int));
    
    for (int i = 0; i < num_points; i++) {
        mandelbrot_set[i] = mandelbrot(cx_min + i % width, cy_min + i / width);
    }
    
    // Print the Mandelbrot set
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            if (mandelbrot_set[(i * height) + j] == 1) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
    
    // Free the memory
    free(mandelbrot_set);
}

int main() {
    double cx_min = -2.0;
    double cy_min = -1.5;
    double cx_max = 1.0;
    double cy_max = 1.0;
    
    generate_mandelbrot_set(cx_min, cy_min, cx_max, cy_max);
    
    return 0;
}