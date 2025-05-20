//FormAI DATASET v1.0 Category: Fractal Generation ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIN_WIDTH 640
#define WIN_HEIGHT 480
#define MAX_ITERATIONS 1000

typedef struct ComplexNumber {
    double real;
    double imag;
} ComplexNumber;

int main() {
    int i, j;
    int iterations;

    // Allocate memory for the 2D array to hold the color values of each pixel
    int **colors = (int **) malloc(sizeof(int *) * WIN_HEIGHT);
    for (i = 0; i < WIN_HEIGHT; i++) {
        colors[i] = (int *) malloc(sizeof(int) * WIN_WIDTH);
    }

    // Initialize the complex plane
    ComplexNumber z, c;
    double xMin = -2, xMax = 2, yMin = -1.5, yMax = 1.5;
    double xScale = (xMax - xMin) / WIN_WIDTH;
    double yScale = (yMax - yMin) / WIN_HEIGHT;

    // Generate the fractal by iterating over each pixel on the complex plane
    for (i = 0; i < WIN_HEIGHT; i++) {
        for (j = 0; j < WIN_WIDTH; j++) {
            // Calculate the complex number corresponding to the current pixel
            z.real = xMin + j * xScale;
            z.imag = yMin + i * yScale;
            c = z;

            // Iterate z until it either escapes or the max number of iterations is reached
            iterations = 0;
            while (iterations < MAX_ITERATIONS) {
                z.real = z.real * z.real - z.imag * z.imag + c.real;
                z.imag = 2 * z.real * z.imag + c.imag;
                iterations++;

                if (z.real * z.real + z.imag * z.imag > 4) {
                    break;
                }
            }

            // Set the color of the current pixel based on the number of iterations required to escape
            if (iterations == MAX_ITERATIONS) {
                colors[i][j] = 0x000000; // Black for pixels that don't escape
            } else {
                colors[i][j] = iterations * 0xffffff / MAX_ITERATIONS; // Gray scale based on number of iterations
            }
        }
    }

    // Output the color values as a PPM image
    FILE *outputFile = fopen("fractal.ppm", "wb");
    fprintf(outputFile, "P6\n%d %d\n255\n", WIN_WIDTH, WIN_HEIGHT);
    unsigned char color[3];
    for (i = 0; i < WIN_HEIGHT; i++) {
        for (j = 0; j < WIN_WIDTH; j++) {
            color[0] = (colors[i][j] >> 16) & 0xff;
            color[1] = (colors[i][j] >> 8) & 0xff;
            color[2] = colors[i][j] & 0xff;
            fwrite(color, 1, 3, outputFile);
        }
    }
    fclose(outputFile);

    // Free dynamically allocated memory
    for (i = 0; i < WIN_HEIGHT; i++) {
        free(colors[i]);
    }
    free(colors);

    return 0;
}