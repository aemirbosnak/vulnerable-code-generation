//Falcon2-11B DATASET v1.0 Category: Fractal Generation ; Style: ultraprecise
#include <stdio.h>
#include <math.h>

// Mandelbrot set fractal generation function
void mandelbrot(int width, int height, double *image) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            double c = (double) x / (double) width;
            double s = (double) y / (double) height;
            double z = 0;
            int iterations = 0;
            double max = 2;

            while (z * z + c * z < 4 && max > 2) {
                z = z * z + c * z;
                max = (max > abs(z))? max : abs(z);
                iterations++;
            }

            if (iterations <= 255)
                image[y * width + x] = iterations;
            else
                image[y * width + x] = 255;
        }
    }
}

// Main function
int main() {
    int width = 1024;
    int height = 1024;
    double *image = malloc(width * height * sizeof(double));

    mandelbrot(width, height, image);

    // Display the image
    printf("Mandelbrot Set:\n");
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            if (image[y * width + x] <= 255)
                printf("%d", image[y * width + x]);
            else
                printf(" ");
        }
        printf("\n");
    }

    free(image);
    return 0;
}