//FormAI DATASET v1.0 Category: Fractal Generation ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ITERATIONS 500
#define DIMENSIONS 1000
#define ESCAPE_RADIUS 2.0

int main(int argc, char const *argv[]) {
    // Ensure the user provides the required parameters
    if (argc != 2) {
        printf("ERROR: Expected one argument (a seed for the random number generator)\n");
        return 1;
    }
    // Initialize random number generator with provided seed
    srand(atoi(argv[1]));

    // Create a 2D array to store the fractal
    float fractal[DIMENSIONS][DIMENSIONS];

    // Initialize every element to zero
    for (int i = 0; i < DIMENSIONS; i++) {
        for (int j = 0; j < DIMENSIONS; j++) {
            fractal[i][j] = 0;
        }
    }

    // Choose a random point in the complex plane
    float x = rand() / (float)RAND_MAX * 4.0 - 2.0;
    float y = rand() / (float)RAND_MAX * 4.0 - 2.0;

    // Generate the fractal by iterating over all points in the complex plane
    for (int i = 0; i < DIMENSIONS; i++) {
        for (int j = 0; j < DIMENSIONS; j++) {
            float a = (j - DIMENSIONS / 2) / (float)(DIMENSIONS / 4);
            float b = (i - DIMENSIONS / 2) / (float)(DIMENSIONS / 4);
            float ca = a + x;
            float cb = b + y;

            float zx = 0;
            float zy = 0;
            int iteration = 0;
            while (iteration < MAX_ITERATIONS) {
                float new_zx = zx * zx - zy * zy + ca;
                float new_zy = 2 * zx * zy + cb;
                if (new_zx * new_zx + new_zy * new_zy > ESCAPE_RADIUS * ESCAPE_RADIUS) {
                    // The point has escaped to infinity; color it based on how long it took to escape
                    fractal[i][j] = (float)iteration / MAX_ITERATIONS;
                    break;
                }
                zx = new_zx;
                zy = new_zy;
                iteration++;
            }
        }
    }

    // Output the fractal as a PPM image
    printf("P3\n%d %d\n255\n", DIMENSIONS, DIMENSIONS);
    for (int i = 0; i < DIMENSIONS; i++) {
        for (int j = 0; j < DIMENSIONS; j++) {
            int red = (int)(255 * fractal[i][j]);
            int green = (int)(255 * fractal[i][j]);
            int blue = (int)(255 * fractal[i][j]);
            printf("%d %d %d ", red, green, blue);
        }
        printf("\n");
    }

    return 0;
}