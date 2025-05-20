//Falcon2-11B DATASET v1.0 Category: Fractal Generation ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    // Set up parameters
    int width = 1024;
    int height = 1024;
    int maxIterations = 100;
    double cx = -1.5;
    double cy = 0;
    double zoom = 2;

    // Initialize image array
    int* pixels = (int*) malloc(sizeof(int) * width * height);
    for (int i = 0; i < width * height; i++) {
        pixels[i] = 0;
    }

    // Generate fractal image
    for (int x = 0; x < width; x++) {
        for (int y = 0; y < height; y++) {
            double c = (2 * cx - width / 2) / zoom + (2 * cy - height / 2) / zoom * cos(2 * M_PI * x / width);
            double r = 0;
            double r2 = 0;
            double zx = 0;
            double zy = 1;
            for (int i = 0; i < maxIterations; i++) {
                double temp = zx * zx + zy * zy;
                if (temp > 4) {
                    pixels[i * width + x] = 255;
                    break;
                }
                double temp2 = c * c - zx * zx - zy * zy;
                if (temp2 < 4) {
                    break;
                }
                zx = 2 * zx * c + zy;
                zy = temp2;
            }
        }
    }

    // Display image
    printf("Fractal Image:\n");
    for (int i = 0; i < width * height; i++) {
        printf("%d ", pixels[i]);
    }
    printf("\n");

    // Free memory
    free(pixels);

    return 0;
}