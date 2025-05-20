//Falcon2-11B DATASET v1.0 Category: Fractal Generation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int width = 600;
    int height = 400;
    int iterations = 5;
    int r = 0, g = 0, b = 0;

    printf("Generating Medieval Fractal...\n");

    // Generate a 2D array to store the pixels
    int* pixels = (int*)malloc(width * height * sizeof(int));
    for (int i = 0; i < width * height; i++) {
        pixels[i] = 0;
    }

    // Iterate through the pixels and generate the fractal
    for (int i = 0; i < width * height; i++) {
        int x = i % width;
        int y = i / width;

        // Apply the Mandelbrot set formula to each pixel
        int c = 0;
        for (int j = 0; j < iterations; j++) {
            c = c * c + 1;
            if (c * c > 4) {
                break;
            }
        }

        r = 255 * (c * c - 1);
        g = 255 * (c * c - 1);
        b = 255 * (c * c - 1);

        // Set the color of the pixel
        pixels[i] = r | (g << 8) | (b << 16);
    }

    // Write the generated fractal to a file
    FILE* file = fopen("medieval_fractal.ppm", "w");
    fprintf(file, "P3\n%d %d\n255\n", width, height);

    for (int i = 0; i < width * height; i++) {
        fprintf(file, "%d %d %d\n", pixels[i], pixels[i], pixels[i]);
    }

    fclose(file);

    printf("Medieval Fractal generated successfully.\n");

    return 0;
}