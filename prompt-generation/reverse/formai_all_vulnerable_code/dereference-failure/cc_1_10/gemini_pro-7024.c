//GEMINI-pro DATASET v1.0 Category: Fractal Generation ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Exciting Fractal Generation!
int main() {
    // Declare our fractal variables!
    int width = 800;
    int height = 600;
    double zoom = 1.0;
    double offsetX = 0.0;
    double offsetY = 0.0;
    int maxIterations = 256;

    // Create our fractal image!
    unsigned char *image = malloc(width * height * 3);

    // Generate our fractal!
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            // Calculate the complex number for this pixel.
            double cReal = (x - width / 2) / zoom + offsetX;
            double cImag = (y - height / 2) / zoom + offsetY;
            double zReal = 0.0;
            double zImag = 0.0;
            int iterations = 0;

            // Iterate the complex number.
            while (iterations < maxIterations && (zReal * zReal + zImag * zImag) < 4.0) {
                double temp = zReal;
                zReal = zReal * zReal - zImag * zImag + cReal;
                zImag = 2 * temp * zImag + cImag;
                iterations++;
            }

            // Color the pixel based on the number of iterations.
            int color = 255 * iterations / maxIterations;
            image[(y * width + x) * 3 + 0] = color; // Red
            image[(y * width + x) * 3 + 1] = color; // Green
            image[(y * width + x) * 3 + 2] = color; // Blue
        }
    }

    // Save our fractal image!
    FILE *fp = fopen("fractal.ppm", "wb");
    fprintf(fp, "P3\n%d %d\n255\n", width, height);
    fwrite(image, sizeof(unsigned char), width * height * 3, fp);
    fclose(fp);

    // Free our fractal image!
    free(image);

    // Yay! We're done!
    printf("Your fractal is ready! Check out fractal.ppm!\n");
    return 0;
}