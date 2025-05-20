//Falcon-180B DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random color
void random_color(int *r, int *g, int *b) {
    *r = rand() % 256;
    *g = rand() % 256;
    *b = rand() % 256;
}

int main() {
    int width, height, max_iterations, i, j, k, x, y, count = 0;
    int *pixels = NULL;
    time_t seed;
    struct tm *tm;

    // Get the current time
    time(&seed);
    tm = localtime(&seed);

    // Set the random seed
    srand(mktime(tm));

    // Get the screen dimensions
    width = 800;
    height = 600;

    // Allocate memory for the pixels
    pixels = malloc(width * height * sizeof(int));

    // Initialize the pixels to black
    for (i = 0; i < width * height; i++) {
        pixels[i] = 0;
    }

    // Set the maximum number of iterations
    max_iterations = 100;

    // Calculate the escape time algorithm
    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {
            i = x - width / 2;
            j = y - height / 2;
            k = 0;

            while (k < max_iterations && i * i + j * j <= 4) {
                i += (2 * pixels[(y - 1 + j) * width + x - 1 + i] - 1) * pixels[(y - 1 + j) * width + x - 1 + i] + j;
                j += (2 * pixels[(y + 1 - j) * width + x - 1 + i] - 1) * pixels[(y + 1 - j) * width + x - 1 + i] + i;
                k++;
            }

            if (k == max_iterations) {
                pixels[(y - 1 + j) * width + x - 1 + i] = rand() % 256;
            } else {
                pixels[(y - 1 + j) * width + x - 1 + i] = k % 8 * 32;
            }

            count++;
        }
    }

    // Print the number of iterations
    printf("Iterations: %d\n", count);

    // Free the memory
    free(pixels);

    return 0;
}