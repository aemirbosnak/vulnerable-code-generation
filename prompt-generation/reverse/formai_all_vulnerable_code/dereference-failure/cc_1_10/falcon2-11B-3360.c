//Falcon2-11B DATASET v1.0 Category: Fractal Generation ; Style: retro
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITERATIONS 1000

void generate_fractal(int iterations, int width, int height) {
    int i, j, k;
    int size = 1;
    int x_min = 0, y_min = 0, x_max = width - 1, y_max = height - 1;
    int window_size = 3;
    int window_count = width * height / (window_size * window_size);
    int *pixels = (int *)malloc(window_count * sizeof(int));

    for (i = 0; i < window_count; i++) {
        pixels[i] = 0;
    }

    for (i = 0; i < iterations; i++) {
        for (j = 0; j < window_count; j++) {
            int x = j * window_size;
            int y = j % window_size;
            int sum = 0;

            for (k = -window_size; k <= window_size; k++) {
                int x_offset = x + k;
                int y_offset = y + k;

                if (x_offset >= 0 && x_offset < width && y_offset >= 0 && y_offset < height) {
                    sum += pixels[x_offset + y_offset * width];
                }
            }

            pixels[j] += (255 - sum) / (window_size * window_size);

            if (pixels[j] > 255) {
                pixels[j] = 255;
            } else if (pixels[j] < 0) {
                pixels[j] = 0;
            }
        }
    }

    for (j = 0; j < height; j++) {
        for (i = 0; i < width; i++) {
            int index = (j * width + i) * 3;
            int red = (int)pixels[index + 0] * 255;
            int green = (int)pixels[index + 1] * 255;
            int blue = (int)pixels[index + 2] * 255;

            printf("%d %d %d\n", red, green, blue);
        }
    }

    free(pixels);
}

int main() {
    int width = 800, height = 600;
    int iterations = MAX_ITERATIONS;

    printf("Fractal Generation Example Program\n");
    printf("Width: %d\n", width);
    printf("Height: %d\n", height);
    printf("Iterations: %d\n", iterations);
    printf("Press any key to generate the fractal...\n");
    getchar();

    generate_fractal(iterations, width, height);

    printf("Press any key to exit...\n");
    getchar();

    return 0;
}