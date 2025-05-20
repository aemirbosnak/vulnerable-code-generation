//Falcon2-11B DATASET v1.0 Category: Fractal Generation ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265359

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <iterations>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int iterations = atoi(argv[1]);

    int width = 800;
    int height = 600;

    float image[width][height];

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            float r = (float) x / (float) width;
            float g = (float) y / (float) height;
            float b = 0.0;

            float intensity = 1.0;
            for (int i = 0; i < iterations; i++) {
                float newR = r * r - g * g + b;
                float newG = 2.0 * r * g + b;
                float newB = r * r - 2.0 * g * g + 1.0;

                r = newR;
                g = newG;
                b = newB;

                intensity *= 0.5;
            }

            image[y][x] = intensity;
        }
    }

    FILE *fp = fopen("fractal.ppm", "w");
    if (fp == NULL) {
        fprintf(stderr, "Error opening file\n");
        exit(EXIT_FAILURE);
    }

    fprintf(fp, "P6\n%d %d\n255\n", width, height);

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            fprintf(fp, "%f %f %f ", image[y][x], image[y][x], image[y][x]);
        }
        fprintf(fp, "\n");
    }

    fclose(fp);

    return 0;
}