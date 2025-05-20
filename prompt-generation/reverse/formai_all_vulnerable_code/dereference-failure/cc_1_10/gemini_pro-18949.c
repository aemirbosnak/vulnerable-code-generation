//GEMINI-pro DATASET v1.0 Category: Fractal Generation ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 800
#define HEIGHT 600

int main() {
    // Create a new image
    unsigned char *image = malloc(WIDTH * HEIGHT);

    // Set the background color to black
    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        image[i] = 0;
    }

    // Define the fractal parameters
    double cx = -0.7;
    double cy = 0.27015;
    double zoom = 1;
    int maxIterations = 100;

    // Iterate over each pixel in the image
    for (int x = 0; x < WIDTH; x++) {
        for (int y = 0; y < HEIGHT; y++) {
            // Convert the pixel coordinates to the complex plane
            double zx = 1.5 * (x - WIDTH / 2) / (0.5 * zoom * WIDTH);
            double zy = 1.0 * (y - HEIGHT / 2) / (0.5 * zoom * HEIGHT);

            // Iterate the pixel through the Mandelbrot set
            int iteration = 0;
            while (zx * zx + zy * zy < 4 && iteration < maxIterations) {
                double temp = zx * zx - zy * zy + cx;
                zy = 2 * zx * zy + cy;
                zx = temp;
                iteration++;
            }

            // Color the pixel based on the number of iterations
            if (iteration == maxIterations) {
                image[x + y * WIDTH] = 0;
            } else {
                image[x + y * WIDTH] = 255 * iteration / maxIterations;
            }
        }
    }

    // Write the image to a file
    FILE *file = fopen("fractal.ppm", "wb");
    fprintf(file, "P6\n%d %d\n255\n", WIDTH, HEIGHT);
    fwrite(image, WIDTH * HEIGHT, 1, file);
    fclose(file);

    // Free the memory allocated for the image
    free(image);

    return 0;
}