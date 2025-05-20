//Gemma-7B DATASET v1.0 Category: Fractal Generation ; Style: energetic
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define WIDTH 1000
#define HEIGHT 1000

int main() {
    int x, y, i, j;
    double dx, dy, x1, x2, y1, y2;

    // Allocate memory for the image
    unsigned char *image = (unsigned char *)malloc(WIDTH * HEIGHT);

    // Set all pixels to black
    for (x = 0; x < WIDTH; x++) {
        for (y = 0; y < HEIGHT; y++) {
            image[x * HEIGHT + y] = 0;
        }
    }

    // Generate the fractal
    x1 = -2.0;
    x2 = 1.0;
    y1 = -1.0;
    y2 = 1.0;
    dx = (x2 - x1) / WIDTH;
    dy = (y2 - y1) / HEIGHT;

    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            double z = 0.0;
            int iterations = 0;

            while (z < 2.0 && iterations < 255) {
                double x_prime = x1 + i * dx;
                double y_prime = y1 + j * dy;
                double w = x_prime * x_prime + y_prime * y_prime;
                z = w + z;
                iterations++;
            }

            image[i * HEIGHT + j] = iterations;
        }
    }

    // Save the image
    FILE *file = fopen("fractal.ppm", "w");
    fprintf(file, "PPPM %d %d %d\n", WIDTH, HEIGHT, 3);
    for (x = 0; x < WIDTH; x++) {
        for (y = 0; y < HEIGHT; y++) {
            fprintf(file, "%d ", image[x * HEIGHT + y]);
        }
        fprintf(file, "\n");
    }
    fclose(file);

    // Free the memory
    free(image);

    return 0;
}