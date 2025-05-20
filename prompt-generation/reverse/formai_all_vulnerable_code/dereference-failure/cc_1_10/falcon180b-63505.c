//Falcon-180B DATASET v1.0 Category: Pixel Art Generator ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define WIDTH 800
#define HEIGHT 600
#define MAX_ITERATIONS 100

int main() {
    srand(time(NULL));

    int **pixels = calloc(HEIGHT, sizeof(int *));
    for (int i = 0; i < HEIGHT; i++) {
        pixels[i] = calloc(WIDTH, sizeof(int));
    }

    for (int x = 0; x < WIDTH; x++) {
        for (int y = 0; y < HEIGHT; y++) {
            int iterations = rand() % MAX_ITERATIONS;
            int c = rand() % 256;

            for (int i = 0; i < iterations; i++) {
                int r = c >> 16;
                int g = (c >> 8) & 0xFF;
                int b = c & 0xFF;

                int r2 = r * r - g * g + b * b;
                int g2 = 2 * r * g + b * (255 - r - g);
                int b2 = 2 * r * b + g * (255 - r - g);

                c = (r2 << 16) | (g2 << 8) | b2;
            }

            pixels[y][x] = c;
        }
    }

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            printf("%06X ", pixels[y][x]);
        }
        printf("\n");
    }

    for (int i = 0; i < HEIGHT; i++) {
        free(pixels[i]);
    }
    free(pixels);

    return 0;
}