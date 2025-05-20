//FormAI DATASET v1.0 Category: Fractal Generation ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 200
#define HEIGHT 200
#define MAX_ITERATIONS 1000

int main() {
    // Memory allocation for fractal data
    int* fractalData = (int*) malloc(WIDTH * HEIGHT * sizeof(int));

    // Generating fractal data
    for(int x = 0; x < WIDTH; x++) {
        for(int y = 0; y < HEIGHT; y++) {
            double xIn = ((double) x / WIDTH) * 3.5 - 2.5;
            double yIn = ((double) y / HEIGHT) * 2 - 1;

            double cx = xIn;
            double cy = yIn;
            double zx = 0;
            double zy = 0;

            int iterations = 0;

            while(zx * zx + zy * zy < 4 && iterations < MAX_ITERATIONS) {
                double zxTemp = zx * zx - zy * zy + cx;
                double zyTemp = 2 * zx * zy + cy;

                zx = zxTemp;
                zy = zyTemp;

                iterations++;
            }

            fractalData[x * HEIGHT + y] = iterations % 256;
        }
    }

    // Generating output image
    FILE* outputFile = fopen("output.ppm", "wb");
    fprintf(outputFile, "P3\n%d %d\n255\n", WIDTH, HEIGHT);

    for(int x = 0; x < WIDTH; x++) {
        for(int y = 0; y < HEIGHT; y++) {
            int color = fractalData[x * HEIGHT + y];
            fprintf(outputFile, "%d %d %d ", color, color, color);
        }
        fprintf(outputFile, "\n");
    }

    // Freeing memory and closing file
    free(fractalData);
    fclose(outputFile);

    return 0;
}